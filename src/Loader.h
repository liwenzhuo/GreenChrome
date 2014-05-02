#define TRAMPOLINE_SIZE 0x100

//
PBYTE TrampolineAlloc(PBYTE pSystemFunction, DWORD size)
{
	PBYTE pTrampoline = NULL;

	PBYTE pLower = pSystemFunction;
	pLower = pLower < (PBYTE)(DWORD_PTR)0x0000000080000000 ?
						(PBYTE)(0x1) : (PBYTE)(pLower - (PBYTE)0x7fff0000);
	PBYTE pUpper = pSystemFunction;
	pUpper = pUpper < (PBYTE)(DWORD_PTR)0xffffffff80000000 ?
		(PBYTE)(pUpper + (DWORD_PTR)0x7ff80000) : (PBYTE)(DWORD_PTR)0xfffffffffff80000;

	SYSTEM_INFO sSysInfo;
	::GetSystemInfo(&sSysInfo);

	for (PBYTE pbAlloc = pLower; pbAlloc < pUpper;) {
		// determine current state
		MEMORY_BASIC_INFORMATION mbi;
		if (!VirtualQuery(pbAlloc, &mbi, sizeof(mbi)))
			break;
		// free & large enough?
		if (mbi.State == MEM_FREE && mbi.RegionSize >= size && mbi.RegionSize >= sSysInfo.dwAllocationGranularity) {
			// yes, align the pointer to the 64K boundary first
			pbAlloc = (PBYTE)(ULONG_PTR((ULONG_PTR(pbAlloc) + (sSysInfo.dwAllocationGranularity-1)) / sSysInfo.dwAllocationGranularity) * sSysInfo.dwAllocationGranularity);
			// and then try to allocate it
			pTrampoline = (PBYTE)VirtualAlloc(pbAlloc, size, MEM_COMMIT|MEM_RESERVE, PAGE_EXECUTE_READ);
			if (pTrampoline) {
				break;
			}
		}
		// continue the search
		pbAlloc = (PBYTE)mbi.BaseAddress + mbi.RegionSize;
	}

	return pTrampoline;
}

bool Write64Jump(PBYTE BaseAddress, MWORD Function, MWORD OldFunction)
{
	BYTE sub_rsp[] = {0x48, 0x83, 0xEC, 0x28};
	BYTE add_rsp[] = {0x48, 0x83, 0xC4, 0x28};

	BYTE move[] = {0x48, 0xB8};
	BYTE call[] = {0xFF, 0xD0};

	BYTE jump[] = {0xE9};

	WriteMemory(BaseAddress, sub_rsp, sizeof(sub_rsp));
	BaseAddress += sizeof(sub_rsp);

	WriteMemory(BaseAddress, move, sizeof(move));
	BaseAddress += sizeof(move);

	WriteMemory(BaseAddress, (PBYTE)&Function, sizeof(MWORD));
	BaseAddress += sizeof(MWORD);

	WriteMemory(BaseAddress, call, sizeof(call));
	BaseAddress += sizeof(call);

	WriteMemory(BaseAddress, add_rsp, sizeof(add_rsp));
	BaseAddress += sizeof(add_rsp);

	WriteMemory(BaseAddress, jump, sizeof(jump));
	BaseAddress += sizeof(jump);

	DWORD offset = OldFunction - (MWORD)BaseAddress - 4;
	return WriteMemory(BaseAddress, (PBYTE)&offset, sizeof(offset));
}

void Loader() { __asm__ (".byte 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90"); }

bool Write32Jump(PBYTE BaseAddress, MWORD Function, MWORD OldFunction)
{
	BYTE call[] = {0xE8};
	BYTE jump[] = {0xE9};

	WriteMemory(BaseAddress, call, sizeof(call));
	BaseAddress += sizeof(call);

	DWORD offset = Function - (MWORD)BaseAddress - 4;
	WriteMemory(BaseAddress, (PBYTE)&offset, sizeof(offset));
	BaseAddress += sizeof(offset);

	WriteMemory(BaseAddress, jump, sizeof(jump));
	BaseAddress += sizeof(jump);

	offset = OldFunction - (MWORD)BaseAddress - 4;
	return WriteMemory(BaseAddress, (PBYTE)&offset, sizeof(offset));
}

void InstallLoader()
{
	//获取程序入口点
	MODULEINFO mi;
	GetModuleInformation(GetCurrentProcess(), GetModuleHandle(NULL), &mi, sizeof(MODULEINFO));
	PBYTE entry = (PBYTE)mi.EntryPoint;

#ifdef _WIN64

	BYTE verify[9];
	if ( ReadMemory(entry, verify, sizeof(verify)) )
	{
		if( *(DWORD*)(verify+1)==0xE828EC83 ) //sub rsp,0x28 call xxx
		{
			PBYTE pTrampoline = TrampolineAlloc((PBYTE)entry, TRAMPOLINE_SIZE);
			if(pTrampoline)
			{
				MWORD original = (MWORD)entry + *(DWORD*)(verify+5) + 9;

				if( Write64Jump(pTrampoline, (MWORD)GreenChrome, original) )
				{
					DWORD address = pTrampoline - entry - 9;
					WriteMemory(entry+5, (PBYTE)&address, sizeof(address));
				}
			}
		}
	}
#else
	//检查入口点是否是E8
	BYTE read[5];
	if ( ReadMemory(entry, read, sizeof(read)) )
	{
		if(read[0]==0xE8)
		{
			MWORD original = (MWORD)entry + *(DWORD*)(read+1) + 5;

			if( Write32Jump((PBYTE)&Loader, (MWORD)GreenChrome, original) )
			{
				DWORD address = (MWORD)Loader - (MWORD)entry - 5;
				WriteMemory(entry+1, (PBYTE)&address, sizeof(address));
			}
		}
	}
#endif // _WIN64
}
