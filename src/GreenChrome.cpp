#define UNICODE
#define _UNICODE

#pragma comment(linker, "/OPT:NOWIN98")

#include "GreenChrome.h"


EXTERNC BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID pv)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		LoadSysDll();//保持系统dll原有功能

		wchar_t exePath[MAX_PATH];
		GetModuleFileName(NULL, exePath, MAX_PATH);
		PathRemoveFileSpec(exePath);

		wchar_t iniPath[MAX_PATH];

		wcscpy(iniPath, exePath);
		wcscat(iniPath, L"\\GreenChrome.ini");

		if(!PathFileExists(iniPath))
		{
			// 生成默认配置文件
			FILE *fp = _wfopen(iniPath, L"wb");
			if(fp)
			{
				fwrite(DefaultConfig, sizeof(DefaultConfig), 1, fp);
				fclose(fp);
			}
		}

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
