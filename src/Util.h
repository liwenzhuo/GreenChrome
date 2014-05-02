

bool ReadMemory(PBYTE BaseAddress, PBYTE Buffer, DWORD nSize)
{
	DWORD ProtectFlag = 0;
	if (VirtualProtectEx(GetCurrentProcess(), BaseAddress, nSize, PAGE_EXECUTE_READWRITE, &ProtectFlag))
	{
		memcpy(Buffer, BaseAddress, nSize);
		VirtualProtectEx(GetCurrentProcess(), BaseAddress, nSize, ProtectFlag, &ProtectFlag);
		return true;
	}
	return false;
}

bool WriteMemory(PBYTE BaseAddress, PBYTE Buffer, DWORD nSize)
{
	DWORD ProtectFlag = 0;
	if (VirtualProtectEx(GetCurrentProcess(), BaseAddress, nSize, PAGE_EXECUTE_READWRITE, &ProtectFlag))
	{
		memcpy(BaseAddress, Buffer, nSize);
		FlushInstructionCache(GetCurrentProcess(), BaseAddress, nSize);
		VirtualProtectEx(GetCurrentProcess(), BaseAddress, nSize, ProtectFlag, &ProtectFlag);
		return true;
	}
	return false;
}

wchar_t * replace(wchar_t *source,const wchar_t *sub,const wchar_t *rep)
{
	if (0 == source) return _wcsdup(L"");
	if (0 == *sub) return _wcsdup(source);

	wchar_t *pc1, *pc2;
	const wchar_t *pc3;

	int isub = wcslen(sub);
	int irep = wcslen(rep);
	int isource = wcslen(source);

	wchar_t* result = (wchar_t *)malloc(sizeof(wchar_t) * (( irep > isub ? isource / isub * irep : isource ) + 10) );
	pc1 = result;
	while (*source != 0)
	{
		pc2 = source;
		pc3 = sub;

		while (*pc2 == *pc3 && *pc3 != 0 && *pc2 != 0)
			pc2++, pc3++;
		// 寻找子串
		if (0 == *pc3)
		{
			pc3 = rep;
			//追加替代串到结果串
			while (*pc3 != 0)
				*pc1++ = *pc3++;
			pc2--;
			source = pc2;
		}
		else
			*pc1++ = *source;
		source++;
	}
	*pc1 = 0;
	return result;
}
