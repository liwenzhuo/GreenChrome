
bool isEndWith(const wchar_t *path,const wchar_t* ext)
{
	if(!path || !ext) return false;
	int len1 = wcslen(path);
	int len2 = wcslen(ext);
	if(len2>len1) return false;
	return !_memicmp(path + len1 - len2,ext,len2*sizeof(wchar_t));
}

#define IS_FlAG(A,B) ((A)&(B))==(B)

HRESULT ResolveIt(wchar_t *lpszLinkFile, wchar_t *lpszPath, int iPathBufferSize)
{
	IShellLink* psl;
	WIN32_FIND_DATA wfd;

	*lpszPath = '\0';
	HRESULT hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (LPVOID*)&psl);
	if (SUCCEEDED(hres))
	{
		IPersistFile* ppf;
		hres = psl->QueryInterface(IID_IPersistFile, (void**)&ppf);
		if (SUCCEEDED(hres))
		{
			hres = ppf->Load(lpszLinkFile, STGM_READ);
			if (SUCCEEDED(hres))
			{
				hres = psl->Resolve(NULL, 0);

				if (SUCCEEDED(hres))
				{
					hres = psl->GetPath(lpszPath, MAX_PATH, (WIN32_FIND_DATA*)&wfd, SLGP_RAWPATH);
				}
			}
			ppf->Release();
		}
		psl->Release();
	}
	return hres;
}

void AutoLockLnk(wchar_t *fullPath)
{
	wchar_t lnkPath[MAX_PATH];
	ExpandEnvironmentStrings(L"%appdata%\\Microsoft\\Internet Explorer\\Quick Launch\\User Pinned\\TaskBar\\", lnkPath, MAX_PATH);

	wchar_t find[MAX_PATH];
	_tcscpy(find, lnkPath);
	_tcscat(find, L"*.*");
	WIN32_FIND_DATA ffbuf;
	HANDLE hfind = FindFirstFile(find, &ffbuf);
	if (hfind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if( isEndWith(ffbuf.cFileName, L".lnk") )
			{
				wchar_t absolute_path[MAX_PATH];
				wsprintf(absolute_path, L"%s%s", lnkPath, ffbuf.cFileName);

				DWORD dwAttrs = GetFileAttributes(absolute_path);
				if( !IS_FlAG(dwAttrs, FILE_ATTRIBUTE_READONLY) ) //尚未设置只读
				{
					wchar_t szLinkFileExePath[MAX_PATH]={0};
					ResolveIt(absolute_path, szLinkFileExePath, MAX_PATH);

					if(_wcsicmp(szLinkFileExePath, fullPath)==0) //lnk文件刚好指向Chrome
					{
						SetFileAttributes(absolute_path, dwAttrs | FILE_ATTRIBUTE_READONLY);
					}
				}

			}
		}
		while (FindNextFile(hfind, &ffbuf));
		FindClose(hfind);
	}
}