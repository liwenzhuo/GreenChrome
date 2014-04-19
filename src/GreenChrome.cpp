#define UNICODE
#define _UNICODE

#pragma comment(linker, "/OPT:NOWIN98")

#include "GreenChrome.h"

bool isEndWith(const wchar_t *path,const wchar_t* ext)
{
	if(!path || !ext) return false;
	int len1 = wcslen(path);
	int len2 = wcslen(ext);
	if(len2>len1) return false;
	return !_memicmp(path + len1 - len2,ext,len2*sizeof(wchar_t));
}

#define IS_FlAG(A,B) ((A)&(B))==(B)

HRESULT ResolveIt(TCHAR *lpszLinkFile, TCHAR *lpszPath, int iPathBufferSize)   
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

EXTERNC BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID pv)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		LoadSysDll();//保持系统dll原有功能
		
		CoInitialize(NULL);

		//exe全路径
		wchar_t fullPath[MAX_PATH];
		GetModuleFileName(NULL, fullPath, MAX_PATH);
		
		//exe所在路径
		wchar_t exePath[MAX_PATH];
		wcscpy(exePath, fullPath);
		PathRemoveFileSpec(exePath);

		//ini路径
		wchar_t iniPath[MAX_PATH];
		wcscpy(iniPath, exePath);
		wcscat(iniPath, L"\\GreenChrome.ini");

		// 生成默认ini文件
		if(!PathFileExists(iniPath))
		{
			FILE *fp = _wfopen(iniPath, L"wb");
			if(fp)
			{
				fwrite(DefaultConfig, sizeof(DefaultConfig), 1, fp);
				fclose(fp);
			}
		}

		//自动给任务栏pin的快捷方式加上只读属性
		wchar_t lnkPath[MAX_PATH];
		ExpandEnvironmentStrings(L"%appdata%\\Microsoft\\Internet Explorer\\Quick Launch\\User Pinned\\TaskBar\\", lnkPath, MAX_PATH);
		
		TCHAR find[MAX_PATH];
		_tcscpy(find, lnkPath);
		_tcscat(find, _T("*.*"));
		WIN32_FIND_DATA ffbuf;
		HANDLE hfind = FindFirstFile(find, &ffbuf);
		if (hfind != INVALID_HANDLE_VALUE)
		{
			do
			{
				if( isEndWith(ffbuf.cFileName, L".lnk") )
				{
					TCHAR absolute_path[MAX_PATH];
					wsprintf(absolute_path, _T("%s%s"), lnkPath, ffbuf.cFileName);

					DWORD dwAttrs = GetFileAttributes(absolute_path);
					if( !IS_FlAG(dwAttrs, FILE_ATTRIBUTE_READONLY) ) //尚未设置只读
					{
						TCHAR szLinkFileExePath[MAX_PATH]={0};
						ResolveIt(absolute_path, szLinkFileExePath, MAX_PATH);

						if(wcsicmp(szLinkFileExePath, fullPath)==0) //lnk文件刚好指向chrome
						{
							SetFileAttributes(absolute_path, dwAttrs | FILE_ATTRIBUTE_READONLY); 
						}
					}
					
				}
			}
			while (FindNextFile(hfind, &ffbuf));
			FindClose(hfind);
		}

		//构造命令行
		wchar_t *command = GetCommandLine();

		if( wcsstr(command,L"--use-green-chrome") || wcsstr(command,L"--type=renderer") || wcsstr(command,L"--type=service") || wcsstr(command,L"--type=plugin") || wcsstr(command,L"--type=utility") )
		{
			//OutputDebugStringW(L"GreenChrome 没事儿干");
		}
		else
		{
			//OutputDebugStringW(command);
			wchar_t *MyCommandLine = (wchar_t *)malloc(1024*20);
			int i;
			int nArgs;
			LPWSTR *szArglist = CommandLineToArgvW(command, &nArgs);
			for(i=0; i<nArgs; i++)
			{
				if(i==0)
				{
					wcscpy(MyCommandLine, L"\"");
					wcscat(MyCommandLine, szArglist[i]);
					wcscat(MyCommandLine, L"\"");

					wcscat(MyCommandLine, L" ");
					wcscat(MyCommandLine, L"--use-green-chrome");

					wchar_t *AddList = (wchar_t *)malloc(1024*20);
					wchar_t *temp = (wchar_t *)malloc(1024*20);
					int AddListLen;
					AddListLen = GetPrivateProfileSection(L"追加参数", AddList, 1024*20, iniPath);

					StringSplit CommandList(AddList,0,AddListLen);
					for(int j=0;j<CommandList.GetCount();j++)
					{
						StringSplit add_cmd(CommandList.GetIndex(j),'=');
						if(add_cmd.GetCount()==2) // xxx=bbb
						{
							if( !wcsstr(command,add_cmd.GetIndex(0)) )
							{
								wcscat(MyCommandLine, L" ");
								wcscat(MyCommandLine, add_cmd.GetIndex(0));
								wcscat(MyCommandLine, L"=");

								ExpandEnvironmentStrings(add_cmd.GetIndex(1), temp, 1024*20);
								wchar_t *_temp = replace(temp, L"%app%", exePath);
								if(wcschr(_temp,' ') && _temp[0]!='\"')
								{
									wcscat(MyCommandLine, L"\"");
									wcscat(MyCommandLine, _temp);
									wcscat(MyCommandLine, L"\"");
								}
								else
								{
									wcscat(MyCommandLine, _temp);
								}
								free(_temp);
							}
						}
						else //不含等号  xxxxx
						{
							if( !wcsstr(command,CommandList.GetIndex(j)) )
							{
								wcscat(MyCommandLine, L" ");
								if(wcschr(CommandList.GetIndex(j),' ') && CommandList.GetIndex(j)[0]!='\"')
								{
									wcscat(MyCommandLine, L"\"");
									wcscat(MyCommandLine, CommandList.GetIndex(j));
									wcscat(MyCommandLine, L"\"");

								}
								else
								{
									wcscat(MyCommandLine, CommandList.GetIndex(j));
								}
							}
						}
					}
					free(temp);
					free(AddList);
				}
				else
				{
					wcscat(MyCommandLine, L" \"");
					wcscat(MyCommandLine, szArglist[i]);
					wcscat(MyCommandLine, L"\"");
				}
			}
			LocalFree(szArglist);

			//启动进程
			STARTUPINFO si = {0};
			PROCESS_INFORMATION pi = {0};

			si.cb = sizeof(STARTUPINFO);
			GetStartupInfo(&si);

			//OutputDebugStringW(MyCommandLine);
			if( !CreateProcess(NULL, MyCommandLine, NULL, NULL, TRUE, 0, NULL, 0, &si, &pi) )
			{
				//失败
				//OutputDebugStringW(L"GreenChrome 启动新进程失败");
			}
			else
			{
				CloseHandle(pi.hProcess);
				CloseHandle(pi.hThread);
				//OutputDebugStringW(L"GreenChrome 功成身退");
				ExitProcess(NULL);
			}

			free(MyCommandLine);
		}
	}
	return TRUE;
}
