typedef	struct
{
	DWORD ExitStatus;
	DWORD PebBaseAddress;
	DWORD AffinityMask;
	DWORD BasePriority;
	ULONG UniqueProcessId;
	ULONG InheritedFromUniqueProcessId;
} PROCESS_BASIC_INFORMATION;

typedef	LONG (WINAPI *PROCNTQSIP)(HANDLE,UINT,PVOID,ULONG,PULONG);

DWORD GetParentProcessID()
{
	PROCNTQSIP NtQueryInformationProcess = (PROCNTQSIP)GetProcAddress(GetModuleHandleA("ntdll"), "NtQueryInformationProcess");
	if (NtQueryInformationProcess)
	{
		PROCESS_BASIC_INFORMATION pbi;
		LONG status = NtQueryInformationProcess(GetCurrentProcess(), NULL, (PVOID)&pbi, sizeof(PROCESS_BASIC_INFORMATION), NULL);
		if(!status)
		{
			return pbi.InheritedFromUniqueProcessId;
		}
	}
	return 0;
}

#define BUFSIZE 512
void DevicePathToWin32Path(wchar_t *strDevicePath)
{
	wchar_t szTemp[BUFSIZE];

	if (GetLogicalDriveStringsW(BUFSIZE-1, szTemp))
	{
		wchar_t szName[MAX_PATH];
		wchar_t szDrive[3] = L" :";
		wchar_t* p = szTemp;
		do
		{
			*szDrive = *p;
			if (QueryDosDeviceW(szDrive, szName, MAX_PATH))
			{
				UINT uNameLen = wcslen(szName);
				if (_wcsnicmp(strDevicePath, szName, uNameLen)==0)
				{
					wchar_t szTempFile[MAX_PATH];
					wsprintfW(szTempFile, L"%s%s", szDrive, strDevicePath + uNameLen);
					wcscpy(strDevicePath, szTempFile);
				}
			}
			while (*p++);
		}
		while (*p);
	}
}

bool GetParentPath(wchar_t* path)
{
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, GetParentProcessID());
	if(hProcess)
	{
		GetProcessImageFileNameW(hProcess, path, MAX_PATH);
		CloseHandle(hProcess);

		DevicePathToWin32Path(path);
		return true;
	}
	return false;
}