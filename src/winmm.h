#pragma once

#define  _CRT_SECURE_NO_WARNINGS

// 声明导出函数
#pragma comment(linker, "/EXPORT:CloseDriver=_My_Fun1,@1")
#pragma comment(linker, "/EXPORT:DefDriverProc=_My_Fun2,@2")
#pragma comment(linker, "/EXPORT:DriverCallback=_My_Fun3,@3")
#pragma comment(linker, "/EXPORT:DrvGetModuleHandle=_My_Fun4,@4")
#pragma comment(linker, "/EXPORT:GetDriverModuleHandle=_My_Fun5,@5")
#pragma comment(linker, "/EXPORT:NotifyCallbackData=_My_Fun6,@6")
#pragma comment(linker, "/EXPORT:OpenDriver=_My_Fun7,@7")
#pragma comment(linker, "/EXPORT:PlaySound=_My_Fun8,@8")
#pragma comment(linker, "/EXPORT:PlaySoundA=_My_Fun9,@9")
#pragma comment(linker, "/EXPORT:PlaySoundW=_My_Fun10,@10")
#pragma comment(linker, "/EXPORT:SendDriverMessage=_My_Fun11,@11")
#pragma comment(linker, "/EXPORT:WOW32DriverCallback=_My_Fun12,@12")
#pragma comment(linker, "/EXPORT:WOW32ResolveMultiMediaHandle=_My_Fun13,@13")
#pragma comment(linker, "/EXPORT:WOWAppExit=_My_Fun14,@14")
#pragma comment(linker, "/EXPORT:aux32Message=_My_Fun15,@15")
#pragma comment(linker, "/EXPORT:auxGetDevCapsA=_My_Fun16,@16")
#pragma comment(linker, "/EXPORT:auxGetDevCapsW=_My_Fun17,@17")
#pragma comment(linker, "/EXPORT:auxGetNumDevs=_My_Fun18,@18")
#pragma comment(linker, "/EXPORT:auxGetVolume=_My_Fun19,@19")
#pragma comment(linker, "/EXPORT:auxOutMessage=_My_Fun20,@20")
#pragma comment(linker, "/EXPORT:auxSetVolume=_My_Fun21,@21")
#pragma comment(linker, "/EXPORT:joy32Message=_My_Fun22,@22")
#pragma comment(linker, "/EXPORT:joyConfigChanged=_My_Fun23,@23")
#pragma comment(linker, "/EXPORT:joyGetDevCapsA=_My_Fun24,@24")
#pragma comment(linker, "/EXPORT:joyGetDevCapsW=_My_Fun25,@25")
#pragma comment(linker, "/EXPORT:joyGetNumDevs=_My_Fun26,@26")
#pragma comment(linker, "/EXPORT:joyGetPos=_My_Fun27,@27")
#pragma comment(linker, "/EXPORT:joyGetPosEx=_My_Fun28,@28")
#pragma comment(linker, "/EXPORT:joyGetThreshold=_My_Fun29,@29")
#pragma comment(linker, "/EXPORT:joyReleaseCapture=_My_Fun30,@30")
#pragma comment(linker, "/EXPORT:joySetCapture=_My_Fun31,@31")
#pragma comment(linker, "/EXPORT:joySetThreshold=_My_Fun32,@32")
#pragma comment(linker, "/EXPORT:mci32Message=_My_Fun33,@33")
#pragma comment(linker, "/EXPORT:mciDriverNotify=_My_Fun34,@34")
#pragma comment(linker, "/EXPORT:mciDriverYield=_My_Fun35,@35")
#pragma comment(linker, "/EXPORT:mciExecute=_My_Fun36,@36")
#pragma comment(linker, "/EXPORT:mciFreeCommandResource=_My_Fun37,@37")
#pragma comment(linker, "/EXPORT:mciGetCreatorTask=_My_Fun38,@38")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDA=_My_Fun39,@39")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDA=_My_Fun40,@40")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDW=_My_Fun41,@41")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDW=_My_Fun42,@42")
#pragma comment(linker, "/EXPORT:mciGetDriverData=_My_Fun43,@43")
#pragma comment(linker, "/EXPORT:mciGetErrorStringA=_My_Fun44,@44")
#pragma comment(linker, "/EXPORT:mciGetErrorStringW=_My_Fun45,@45")
#pragma comment(linker, "/EXPORT:mciGetYieldProc=_My_Fun46,@46")
#pragma comment(linker, "/EXPORT:mciLoadCommandResource=_My_Fun47,@47")
#pragma comment(linker, "/EXPORT:mciSendCommandA=_My_Fun48,@48")
#pragma comment(linker, "/EXPORT:mciSendCommandW=_My_Fun49,@49")
#pragma comment(linker, "/EXPORT:mciSendStringA=_My_Fun50,@50")
#pragma comment(linker, "/EXPORT:mciSendStringW=_My_Fun51,@51")
#pragma comment(linker, "/EXPORT:mciSetDriverData=_My_Fun52,@52")
#pragma comment(linker, "/EXPORT:mciSetYieldProc=_My_Fun53,@53")
#pragma comment(linker, "/EXPORT:mid32Message=_My_Fun54,@54")
#pragma comment(linker, "/EXPORT:midiConnect=_My_Fun55,@55")
#pragma comment(linker, "/EXPORT:midiDisconnect=_My_Fun56,@56")
#pragma comment(linker, "/EXPORT:midiInAddBuffer=_My_Fun57,@57")
#pragma comment(linker, "/EXPORT:midiInClose=_My_Fun58,@58")
#pragma comment(linker, "/EXPORT:midiInGetDevCapsA=_My_Fun59,@59")
#pragma comment(linker, "/EXPORT:midiInGetDevCapsW=_My_Fun60,@60")
#pragma comment(linker, "/EXPORT:midiInGetErrorTextA=_My_Fun61,@61")
#pragma comment(linker, "/EXPORT:midiInGetErrorTextW=_My_Fun62,@62")
#pragma comment(linker, "/EXPORT:midiInGetID=_My_Fun63,@63")
#pragma comment(linker, "/EXPORT:midiInGetNumDevs=_My_Fun64,@64")
#pragma comment(linker, "/EXPORT:midiInMessage=_My_Fun65,@65")
#pragma comment(linker, "/EXPORT:midiInOpen=_My_Fun66,@66")
#pragma comment(linker, "/EXPORT:midiInPrepareHeader=_My_Fun67,@67")
#pragma comment(linker, "/EXPORT:midiInReset=_My_Fun68,@68")
#pragma comment(linker, "/EXPORT:midiInStart=_My_Fun69,@69")
#pragma comment(linker, "/EXPORT:midiInStop=_My_Fun70,@70")
#pragma comment(linker, "/EXPORT:midiInUnprepareHeader=_My_Fun71,@71")
#pragma comment(linker, "/EXPORT:midiOutCacheDrumPatches=_My_Fun72,@72")
#pragma comment(linker, "/EXPORT:midiOutCachePatches=_My_Fun73,@73")
#pragma comment(linker, "/EXPORT:midiOutClose=_My_Fun74,@74")
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsA=_My_Fun75,@75")
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsW=_My_Fun76,@76")
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextA=_My_Fun77,@77")
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextW=_My_Fun78,@78")
#pragma comment(linker, "/EXPORT:midiOutGetID=_My_Fun79,@79")
#pragma comment(linker, "/EXPORT:midiOutGetNumDevs=_My_Fun80,@80")
#pragma comment(linker, "/EXPORT:midiOutGetVolume=_My_Fun81,@81")
#pragma comment(linker, "/EXPORT:midiOutLongMsg=_My_Fun82,@82")
#pragma comment(linker, "/EXPORT:midiOutMessage=_My_Fun83,@83")
#pragma comment(linker, "/EXPORT:midiOutOpen=_My_Fun84,@84")
#pragma comment(linker, "/EXPORT:midiOutPrepareHeader=_My_Fun85,@85")
#pragma comment(linker, "/EXPORT:midiOutReset=_My_Fun86,@86")
#pragma comment(linker, "/EXPORT:midiOutSetVolume=_My_Fun87,@87")
#pragma comment(linker, "/EXPORT:midiOutShortMsg=_My_Fun88,@88")
#pragma comment(linker, "/EXPORT:midiOutUnprepareHeader=_My_Fun89,@89")
#pragma comment(linker, "/EXPORT:midiStreamClose=_My_Fun90,@90")
#pragma comment(linker, "/EXPORT:midiStreamOpen=_My_Fun91,@91")
#pragma comment(linker, "/EXPORT:midiStreamOut=_My_Fun92,@92")
#pragma comment(linker, "/EXPORT:midiStreamPause=_My_Fun93,@93")
#pragma comment(linker, "/EXPORT:midiStreamPosition=_My_Fun94,@94")
#pragma comment(linker, "/EXPORT:midiStreamProperty=_My_Fun95,@95")
#pragma comment(linker, "/EXPORT:midiStreamRestart=_My_Fun96,@96")
#pragma comment(linker, "/EXPORT:midiStreamStop=_My_Fun97,@97")
#pragma comment(linker, "/EXPORT:mixerClose=_My_Fun98,@98")
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsA=_My_Fun99,@99")
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsW=_My_Fun100,@100")
#pragma comment(linker, "/EXPORT:mixerGetDevCapsA=_My_Fun101,@101")
#pragma comment(linker, "/EXPORT:mixerGetDevCapsW=_My_Fun102,@102")
#pragma comment(linker, "/EXPORT:mixerGetID=_My_Fun103,@103")
#pragma comment(linker, "/EXPORT:mixerGetLineControlsA=_My_Fun104,@104")
#pragma comment(linker, "/EXPORT:mixerGetLineControlsW=_My_Fun105,@105")
#pragma comment(linker, "/EXPORT:mixerGetLineInfoA=_My_Fun106,@106")
#pragma comment(linker, "/EXPORT:mixerGetLineInfoW=_My_Fun107,@107")
#pragma comment(linker, "/EXPORT:mixerGetNumDevs=_My_Fun108,@108")
#pragma comment(linker, "/EXPORT:mixerMessage=_My_Fun109,@109")
#pragma comment(linker, "/EXPORT:mixerOpen=_My_Fun110,@110")
#pragma comment(linker, "/EXPORT:mixerSetControlDetails=_My_Fun111,@111")
#pragma comment(linker, "/EXPORT:mmDrvInstall=_My_Fun112,@112")
#pragma comment(linker, "/EXPORT:mmGetCurrentTask=_My_Fun113,@113")
#pragma comment(linker, "/EXPORT:mmTaskBlock=_My_Fun114,@114")
#pragma comment(linker, "/EXPORT:mmTaskCreate=_My_Fun115,@115")
#pragma comment(linker, "/EXPORT:mmTaskSignal=_My_Fun116,@116")
#pragma comment(linker, "/EXPORT:mmTaskYield=_My_Fun117,@117")
#pragma comment(linker, "/EXPORT:mmioAdvance=_My_Fun118,@118")
#pragma comment(linker, "/EXPORT:mmioAscend=_My_Fun119,@119")
#pragma comment(linker, "/EXPORT:mmioClose=_My_Fun120,@120")
#pragma comment(linker, "/EXPORT:mmioCreateChunk=_My_Fun121,@121")
#pragma comment(linker, "/EXPORT:mmioDescend=_My_Fun122,@122")
#pragma comment(linker, "/EXPORT:mmioFlush=_My_Fun123,@123")
#pragma comment(linker, "/EXPORT:mmioGetInfo=_My_Fun124,@124")
#pragma comment(linker, "/EXPORT:mmioInstallIOProcA=_My_Fun125,@125")
#pragma comment(linker, "/EXPORT:mmioInstallIOProcW=_My_Fun126,@126")
#pragma comment(linker, "/EXPORT:mmioOpenA=_My_Fun127,@127")
#pragma comment(linker, "/EXPORT:mmioOpenW=_My_Fun128,@128")
#pragma comment(linker, "/EXPORT:mmioRead=_My_Fun129,@129")
#pragma comment(linker, "/EXPORT:mmioRenameA=_My_Fun130,@130")
#pragma comment(linker, "/EXPORT:mmioRenameW=_My_Fun131,@131")
#pragma comment(linker, "/EXPORT:mmioSeek=_My_Fun132,@132")
#pragma comment(linker, "/EXPORT:mmioSendMessage=_My_Fun133,@133")
#pragma comment(linker, "/EXPORT:mmioSetBuffer=_My_Fun134,@134")
#pragma comment(linker, "/EXPORT:mmioSetInfo=_My_Fun135,@135")
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCA=_My_Fun136,@136")
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCW=_My_Fun137,@137")
#pragma comment(linker, "/EXPORT:mmioWrite=_My_Fun138,@138")
#pragma comment(linker, "/EXPORT:mmsystemGetVersion=_My_Fun139,@139")
#pragma comment(linker, "/EXPORT:mod32Message=_My_Fun140,@140")
#pragma comment(linker, "/EXPORT:mxd32Message=_My_Fun141,@141")
#pragma comment(linker, "/EXPORT:sndPlaySoundA=_My_Fun142,@142")
#pragma comment(linker, "/EXPORT:sndPlaySoundW=_My_Fun143,@143")
#pragma comment(linker, "/EXPORT:tid32Message=_My_Fun144,@144")
#pragma comment(linker, "/EXPORT:timeBeginPeriod=_My_Fun145,@145")
#pragma comment(linker, "/EXPORT:timeEndPeriod=_My_Fun146,@146")
#pragma comment(linker, "/EXPORT:timeGetDevCaps=_My_Fun147,@147")
#pragma comment(linker, "/EXPORT:timeGetSystemTime=_My_Fun148,@148")
#pragma comment(linker, "/EXPORT:timeGetTime=_My_Fun149,@149")
#pragma comment(linker, "/EXPORT:timeKillEvent=_My_Fun150,@150")
#pragma comment(linker, "/EXPORT:timeSetEvent=_My_Fun151,@151")
#pragma comment(linker, "/EXPORT:waveInAddBuffer=_My_Fun152,@152")
#pragma comment(linker, "/EXPORT:waveInClose=_My_Fun153,@153")
#pragma comment(linker, "/EXPORT:waveInGetDevCapsA=_My_Fun154,@154")
#pragma comment(linker, "/EXPORT:waveInGetDevCapsW=_My_Fun155,@155")
#pragma comment(linker, "/EXPORT:waveInGetErrorTextA=_My_Fun156,@156")
#pragma comment(linker, "/EXPORT:waveInGetErrorTextW=_My_Fun157,@157")
#pragma comment(linker, "/EXPORT:waveInGetID=_My_Fun158,@158")
#pragma comment(linker, "/EXPORT:waveInGetNumDevs=_My_Fun159,@159")
#pragma comment(linker, "/EXPORT:waveInGetPosition=_My_Fun160,@160")
#pragma comment(linker, "/EXPORT:waveInMessage=_My_Fun161,@161")
#pragma comment(linker, "/EXPORT:waveInOpen=_My_Fun162,@162")
#pragma comment(linker, "/EXPORT:waveInPrepareHeader=_My_Fun163,@163")
#pragma comment(linker, "/EXPORT:waveInReset=_My_Fun164,@164")
#pragma comment(linker, "/EXPORT:waveInStart=_My_Fun165,@165")
#pragma comment(linker, "/EXPORT:waveInStop=_My_Fun166,@166")
#pragma comment(linker, "/EXPORT:waveInUnprepareHeader=_My_Fun167,@167")
#pragma comment(linker, "/EXPORT:waveOutBreakLoop=_My_Fun168,@168")
#pragma comment(linker, "/EXPORT:waveOutClose=_My_Fun169,@169")
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsA=_My_Fun170,@170")
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsW=_My_Fun171,@171")
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextA=_My_Fun172,@172")
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextW=_My_Fun173,@173")
#pragma comment(linker, "/EXPORT:waveOutGetID=_My_Fun174,@174")
#pragma comment(linker, "/EXPORT:waveOutGetNumDevs=_My_Fun175,@175")
#pragma comment(linker, "/EXPORT:waveOutGetPitch=_My_Fun176,@176")
#pragma comment(linker, "/EXPORT:waveOutGetPlaybackRate=_My_Fun177,@177")
#pragma comment(linker, "/EXPORT:waveOutGetPosition=_My_Fun178,@178")
#pragma comment(linker, "/EXPORT:waveOutGetVolume=_My_Fun179,@179")
#pragma comment(linker, "/EXPORT:waveOutMessage=_My_Fun180,@180")
#pragma comment(linker, "/EXPORT:waveOutOpen=_My_Fun181,@181")
#pragma comment(linker, "/EXPORT:waveOutPause=_My_Fun182,@182")
#pragma comment(linker, "/EXPORT:waveOutPrepareHeader=_My_Fun183,@183")
#pragma comment(linker, "/EXPORT:waveOutReset=_My_Fun184,@184")
#pragma comment(linker, "/EXPORT:waveOutRestart=_My_Fun185,@185")
#pragma comment(linker, "/EXPORT:waveOutSetPitch=_My_Fun186,@186")
#pragma comment(linker, "/EXPORT:waveOutSetPlaybackRate=_My_Fun187,@187")
#pragma comment(linker, "/EXPORT:waveOutSetVolume=_My_Fun188,@188")
#pragma comment(linker, "/EXPORT:waveOutUnprepareHeader=_My_Fun189,@189")
#pragma comment(linker, "/EXPORT:waveOutWrite=_My_Fun190,@190")
#pragma comment(linker, "/EXPORT:wid32Message=_My_Fun191,@191")
#pragma comment(linker, "/EXPORT:wod32Message=_My_Fun192,@192")

// 函数实现,写成宏,简化代码量
#define IMPL_STUB_FUNC(n) \
	DWORD g_dwFunPtr##n=0; \
	extern "C" void _declspec(naked) My_Fun##n() \
{ \
	__asm jmp DWORD PTR[g_dwFunPtr##n] \
}

// 实现跳板函数
IMPL_STUB_FUNC(1);
IMPL_STUB_FUNC(2);
IMPL_STUB_FUNC(3);
IMPL_STUB_FUNC(4);
IMPL_STUB_FUNC(5);
IMPL_STUB_FUNC(6);
IMPL_STUB_FUNC(7);
IMPL_STUB_FUNC(8);
IMPL_STUB_FUNC(9);
IMPL_STUB_FUNC(10);
IMPL_STUB_FUNC(11);
IMPL_STUB_FUNC(12);
IMPL_STUB_FUNC(13);
IMPL_STUB_FUNC(14);
IMPL_STUB_FUNC(15);
IMPL_STUB_FUNC(16);
IMPL_STUB_FUNC(17);
IMPL_STUB_FUNC(18);
IMPL_STUB_FUNC(19);
IMPL_STUB_FUNC(20);
IMPL_STUB_FUNC(21);
IMPL_STUB_FUNC(22);
IMPL_STUB_FUNC(23);
IMPL_STUB_FUNC(24);
IMPL_STUB_FUNC(25);
IMPL_STUB_FUNC(26);
IMPL_STUB_FUNC(27);
IMPL_STUB_FUNC(28);
IMPL_STUB_FUNC(29);
IMPL_STUB_FUNC(30);
IMPL_STUB_FUNC(31);
IMPL_STUB_FUNC(32);
IMPL_STUB_FUNC(33);
IMPL_STUB_FUNC(34);
IMPL_STUB_FUNC(35);
IMPL_STUB_FUNC(36);
IMPL_STUB_FUNC(37);
IMPL_STUB_FUNC(38);
IMPL_STUB_FUNC(39);
IMPL_STUB_FUNC(40);
IMPL_STUB_FUNC(41);
IMPL_STUB_FUNC(42);
IMPL_STUB_FUNC(43);
IMPL_STUB_FUNC(44);
IMPL_STUB_FUNC(45);
IMPL_STUB_FUNC(46);
IMPL_STUB_FUNC(47);
IMPL_STUB_FUNC(48);
IMPL_STUB_FUNC(49);
IMPL_STUB_FUNC(50);
IMPL_STUB_FUNC(51);
IMPL_STUB_FUNC(52);
IMPL_STUB_FUNC(53);
IMPL_STUB_FUNC(54);
IMPL_STUB_FUNC(55);
IMPL_STUB_FUNC(56);
IMPL_STUB_FUNC(57);
IMPL_STUB_FUNC(58);
IMPL_STUB_FUNC(59);
IMPL_STUB_FUNC(60);
IMPL_STUB_FUNC(61);
IMPL_STUB_FUNC(62);
IMPL_STUB_FUNC(63);
IMPL_STUB_FUNC(64);
IMPL_STUB_FUNC(65);
IMPL_STUB_FUNC(66);
IMPL_STUB_FUNC(67);
IMPL_STUB_FUNC(68);
IMPL_STUB_FUNC(69);
IMPL_STUB_FUNC(70);
IMPL_STUB_FUNC(71);
IMPL_STUB_FUNC(72);
IMPL_STUB_FUNC(73);
IMPL_STUB_FUNC(74);
IMPL_STUB_FUNC(75);
IMPL_STUB_FUNC(76);
IMPL_STUB_FUNC(77);
IMPL_STUB_FUNC(78);
IMPL_STUB_FUNC(79);
IMPL_STUB_FUNC(80);
IMPL_STUB_FUNC(81);
IMPL_STUB_FUNC(82);
IMPL_STUB_FUNC(83);
IMPL_STUB_FUNC(84);
IMPL_STUB_FUNC(85);
IMPL_STUB_FUNC(86);
IMPL_STUB_FUNC(87);
IMPL_STUB_FUNC(88);
IMPL_STUB_FUNC(89);
IMPL_STUB_FUNC(90);
IMPL_STUB_FUNC(91);
IMPL_STUB_FUNC(92);
IMPL_STUB_FUNC(93);
IMPL_STUB_FUNC(94);
IMPL_STUB_FUNC(95);
IMPL_STUB_FUNC(96);
IMPL_STUB_FUNC(97);
IMPL_STUB_FUNC(98);
IMPL_STUB_FUNC(99);
IMPL_STUB_FUNC(100);
IMPL_STUB_FUNC(101);
IMPL_STUB_FUNC(102);
IMPL_STUB_FUNC(103);
IMPL_STUB_FUNC(104);
IMPL_STUB_FUNC(105);
IMPL_STUB_FUNC(106);
IMPL_STUB_FUNC(107);
IMPL_STUB_FUNC(108);
IMPL_STUB_FUNC(109);
IMPL_STUB_FUNC(110);
IMPL_STUB_FUNC(111);
IMPL_STUB_FUNC(112);
IMPL_STUB_FUNC(113);
IMPL_STUB_FUNC(114);
IMPL_STUB_FUNC(115);
IMPL_STUB_FUNC(116);
IMPL_STUB_FUNC(117);
IMPL_STUB_FUNC(118);
IMPL_STUB_FUNC(119);
IMPL_STUB_FUNC(120);
IMPL_STUB_FUNC(121);
IMPL_STUB_FUNC(122);
IMPL_STUB_FUNC(123);
IMPL_STUB_FUNC(124);
IMPL_STUB_FUNC(125);
IMPL_STUB_FUNC(126);
IMPL_STUB_FUNC(127);
IMPL_STUB_FUNC(128);
IMPL_STUB_FUNC(129);
IMPL_STUB_FUNC(130);
IMPL_STUB_FUNC(131);
IMPL_STUB_FUNC(132);
IMPL_STUB_FUNC(133);
IMPL_STUB_FUNC(134);
IMPL_STUB_FUNC(135);
IMPL_STUB_FUNC(136);
IMPL_STUB_FUNC(137);
IMPL_STUB_FUNC(138);
IMPL_STUB_FUNC(139);
IMPL_STUB_FUNC(140);
IMPL_STUB_FUNC(141);
IMPL_STUB_FUNC(142);
IMPL_STUB_FUNC(143);
IMPL_STUB_FUNC(144);
IMPL_STUB_FUNC(145);
IMPL_STUB_FUNC(146);
IMPL_STUB_FUNC(147);
IMPL_STUB_FUNC(148);
IMPL_STUB_FUNC(149);
IMPL_STUB_FUNC(150);
IMPL_STUB_FUNC(151);
IMPL_STUB_FUNC(152);
IMPL_STUB_FUNC(153);
IMPL_STUB_FUNC(154);
IMPL_STUB_FUNC(155);
IMPL_STUB_FUNC(156);
IMPL_STUB_FUNC(157);
IMPL_STUB_FUNC(158);
IMPL_STUB_FUNC(159);
IMPL_STUB_FUNC(160);
IMPL_STUB_FUNC(161);
IMPL_STUB_FUNC(162);
IMPL_STUB_FUNC(163);
IMPL_STUB_FUNC(164);
IMPL_STUB_FUNC(165);
IMPL_STUB_FUNC(166);
IMPL_STUB_FUNC(167);
IMPL_STUB_FUNC(168);
IMPL_STUB_FUNC(169);
IMPL_STUB_FUNC(170);
IMPL_STUB_FUNC(171);
IMPL_STUB_FUNC(172);
IMPL_STUB_FUNC(173);
IMPL_STUB_FUNC(174);
IMPL_STUB_FUNC(175);
IMPL_STUB_FUNC(176);
IMPL_STUB_FUNC(177);
IMPL_STUB_FUNC(178);
IMPL_STUB_FUNC(179);
IMPL_STUB_FUNC(180);
IMPL_STUB_FUNC(181);
IMPL_STUB_FUNC(182);
IMPL_STUB_FUNC(183);
IMPL_STUB_FUNC(184);
IMPL_STUB_FUNC(185);
IMPL_STUB_FUNC(186);
IMPL_STUB_FUNC(187);
IMPL_STUB_FUNC(188);
IMPL_STUB_FUNC(189);
IMPL_STUB_FUNC(190);
IMPL_STUB_FUNC(191);
IMPL_STUB_FUNC(192);

#define INIT_STUB_FUNC(n,name) \
	g_dwFunPtr##n = (DWORD)GetProcAddress(hDll,name);

// 加载系统dll,初始化函数指针
void LoadSysDll()
{
	TCHAR szDLL[MAX_PATH+1];
	GetSystemDirectory(szDLL,MAX_PATH);
	lstrcat(szDLL,TEXT("\\winmm.dll"));

	HINSTANCE hDll=LoadLibrary(szDLL);
	if (hDll!=NULL)
	{
		INIT_STUB_FUNC(1,"CloseDriver");
		INIT_STUB_FUNC(2,"DefDriverProc");
		INIT_STUB_FUNC(3,"DriverCallback");
		INIT_STUB_FUNC(4,"DrvGetModuleHandle");
		INIT_STUB_FUNC(5,"GetDriverModuleHandle");
		INIT_STUB_FUNC(6,"NotifyCallbackData");
		INIT_STUB_FUNC(7,"OpenDriver");
		INIT_STUB_FUNC(8,"PlaySound");
		INIT_STUB_FUNC(9,"PlaySoundA");
		INIT_STUB_FUNC(10,"PlaySoundW");
		INIT_STUB_FUNC(11,"SendDriverMessage");
		INIT_STUB_FUNC(12,"WOW32DriverCallback");
		INIT_STUB_FUNC(13,"WOW32ResolveMultiMediaHandle");
		INIT_STUB_FUNC(14,"WOWAppExit");
		INIT_STUB_FUNC(15,"aux32Message");
		INIT_STUB_FUNC(16,"auxGetDevCapsA");
		INIT_STUB_FUNC(17,"auxGetDevCapsW");
		INIT_STUB_FUNC(18,"auxGetNumDevs");
		INIT_STUB_FUNC(19,"auxGetVolume");
		INIT_STUB_FUNC(20,"auxOutMessage");
		INIT_STUB_FUNC(21,"auxSetVolume");
		INIT_STUB_FUNC(22,"joy32Message");
		INIT_STUB_FUNC(23,"joyConfigChanged");
		INIT_STUB_FUNC(24,"joyGetDevCapsA");
		INIT_STUB_FUNC(25,"joyGetDevCapsW");
		INIT_STUB_FUNC(26,"joyGetNumDevs");
		INIT_STUB_FUNC(27,"joyGetPos");
		INIT_STUB_FUNC(28,"joyGetPosEx");
		INIT_STUB_FUNC(29,"joyGetThreshold");
		INIT_STUB_FUNC(30,"joyReleaseCapture");
		INIT_STUB_FUNC(31,"joySetCapture");
		INIT_STUB_FUNC(32,"joySetThreshold");
		INIT_STUB_FUNC(33,"mci32Message");
		INIT_STUB_FUNC(34,"mciDriverNotify");
		INIT_STUB_FUNC(35,"mciDriverYield");
		INIT_STUB_FUNC(36,"mciExecute");
		INIT_STUB_FUNC(37,"mciFreeCommandResource");
		INIT_STUB_FUNC(38,"mciGetCreatorTask");
		INIT_STUB_FUNC(39,"mciGetDeviceIDA");
		INIT_STUB_FUNC(40,"mciGetDeviceIDFromElementIDA");
		INIT_STUB_FUNC(41,"mciGetDeviceIDFromElementIDW");
		INIT_STUB_FUNC(42,"mciGetDeviceIDW");
		INIT_STUB_FUNC(43,"mciGetDriverData");
		INIT_STUB_FUNC(44,"mciGetErrorStringA");
		INIT_STUB_FUNC(45,"mciGetErrorStringW");
		INIT_STUB_FUNC(46,"mciGetYieldProc");
		INIT_STUB_FUNC(47,"mciLoadCommandResource");
		INIT_STUB_FUNC(48,"mciSendCommandA");
		INIT_STUB_FUNC(49,"mciSendCommandW");
		INIT_STUB_FUNC(50,"mciSendStringA");
		INIT_STUB_FUNC(51,"mciSendStringW");
		INIT_STUB_FUNC(52,"mciSetDriverData");
		INIT_STUB_FUNC(53,"mciSetYieldProc");
		INIT_STUB_FUNC(54,"mid32Message");
		INIT_STUB_FUNC(55,"midiConnect");
		INIT_STUB_FUNC(56,"midiDisconnect");
		INIT_STUB_FUNC(57,"midiInAddBuffer");
		INIT_STUB_FUNC(58,"midiInClose");
		INIT_STUB_FUNC(59,"midiInGetDevCapsA");
		INIT_STUB_FUNC(60,"midiInGetDevCapsW");
		INIT_STUB_FUNC(61,"midiInGetErrorTextA");
		INIT_STUB_FUNC(62,"midiInGetErrorTextW");
		INIT_STUB_FUNC(63,"midiInGetID");
		INIT_STUB_FUNC(64,"midiInGetNumDevs");
		INIT_STUB_FUNC(65,"midiInMessage");
		INIT_STUB_FUNC(66,"midiInOpen");
		INIT_STUB_FUNC(67,"midiInPrepareHeader");
		INIT_STUB_FUNC(68,"midiInReset");
		INIT_STUB_FUNC(69,"midiInStart");
		INIT_STUB_FUNC(70,"midiInStop");
		INIT_STUB_FUNC(71,"midiInUnprepareHeader");
		INIT_STUB_FUNC(72,"midiOutCacheDrumPatches");
		INIT_STUB_FUNC(73,"midiOutCachePatches");
		INIT_STUB_FUNC(74,"midiOutClose");
		INIT_STUB_FUNC(75,"midiOutGetDevCapsA");
		INIT_STUB_FUNC(76,"midiOutGetDevCapsW");
		INIT_STUB_FUNC(77,"midiOutGetErrorTextA");
		INIT_STUB_FUNC(78,"midiOutGetErrorTextW");
		INIT_STUB_FUNC(79,"midiOutGetID");
		INIT_STUB_FUNC(80,"midiOutGetNumDevs");
		INIT_STUB_FUNC(81,"midiOutGetVolume");
		INIT_STUB_FUNC(82,"midiOutLongMsg");
		INIT_STUB_FUNC(83,"midiOutMessage");
		INIT_STUB_FUNC(84,"midiOutOpen");
		INIT_STUB_FUNC(85,"midiOutPrepareHeader");
		INIT_STUB_FUNC(86,"midiOutReset");
		INIT_STUB_FUNC(87,"midiOutSetVolume");
		INIT_STUB_FUNC(88,"midiOutShortMsg");
		INIT_STUB_FUNC(89,"midiOutUnprepareHeader");
		INIT_STUB_FUNC(90,"midiStreamClose");
		INIT_STUB_FUNC(91,"midiStreamOpen");
		INIT_STUB_FUNC(92,"midiStreamOut");
		INIT_STUB_FUNC(93,"midiStreamPause");
		INIT_STUB_FUNC(94,"midiStreamPosition");
		INIT_STUB_FUNC(95,"midiStreamProperty");
		INIT_STUB_FUNC(96,"midiStreamRestart");
		INIT_STUB_FUNC(97,"midiStreamStop");
		INIT_STUB_FUNC(98,"mixerClose");
		INIT_STUB_FUNC(99,"mixerGetControlDetailsA");
		INIT_STUB_FUNC(100,"mixerGetControlDetailsW");
		INIT_STUB_FUNC(101,"mixerGetDevCapsA");
		INIT_STUB_FUNC(102,"mixerGetDevCapsW");
		INIT_STUB_FUNC(103,"mixerGetID");
		INIT_STUB_FUNC(104,"mixerGetLineControlsA");
		INIT_STUB_FUNC(105,"mixerGetLineControlsW");
		INIT_STUB_FUNC(106,"mixerGetLineInfoA");
		INIT_STUB_FUNC(107,"mixerGetLineInfoW");
		INIT_STUB_FUNC(108,"mixerGetNumDevs");
		INIT_STUB_FUNC(109,"mixerMessage");
		INIT_STUB_FUNC(110,"mixerOpen");
		INIT_STUB_FUNC(111,"mixerSetControlDetails");
		INIT_STUB_FUNC(112,"mmDrvInstall");
		INIT_STUB_FUNC(113,"mmGetCurrentTask");
		INIT_STUB_FUNC(114,"mmTaskBlock");
		INIT_STUB_FUNC(115,"mmTaskCreate");
		INIT_STUB_FUNC(116,"mmTaskSignal");
		INIT_STUB_FUNC(117,"mmTaskYield");
		INIT_STUB_FUNC(118,"mmioAdvance");
		INIT_STUB_FUNC(119,"mmioAscend");
		INIT_STUB_FUNC(120,"mmioClose");
		INIT_STUB_FUNC(121,"mmioCreateChunk");
		INIT_STUB_FUNC(122,"mmioDescend");
		INIT_STUB_FUNC(123,"mmioFlush");
		INIT_STUB_FUNC(124,"mmioGetInfo");
		INIT_STUB_FUNC(125,"mmioInstallIOProcA");
		INIT_STUB_FUNC(126,"mmioInstallIOProcW");
		INIT_STUB_FUNC(127,"mmioOpenA");
		INIT_STUB_FUNC(128,"mmioOpenW");
		INIT_STUB_FUNC(129,"mmioRead");
		INIT_STUB_FUNC(130,"mmioRenameA");
		INIT_STUB_FUNC(131,"mmioRenameW");
		INIT_STUB_FUNC(132,"mmioSeek");
		INIT_STUB_FUNC(133,"mmioSendMessage");
		INIT_STUB_FUNC(134,"mmioSetBuffer");
		INIT_STUB_FUNC(135,"mmioSetInfo");
		INIT_STUB_FUNC(136,"mmioStringToFOURCCA");
		INIT_STUB_FUNC(137,"mmioStringToFOURCCW");
		INIT_STUB_FUNC(138,"mmioWrite");
		INIT_STUB_FUNC(139,"mmsystemGetVersion");
		INIT_STUB_FUNC(140,"mod32Message");
		INIT_STUB_FUNC(141,"mxd32Message");
		INIT_STUB_FUNC(142,"sndPlaySoundA");
		INIT_STUB_FUNC(143,"sndPlaySoundW");
		INIT_STUB_FUNC(144,"tid32Message");
		INIT_STUB_FUNC(145,"timeBeginPeriod");
		INIT_STUB_FUNC(146,"timeEndPeriod");
		INIT_STUB_FUNC(147,"timeGetDevCaps");
		INIT_STUB_FUNC(148,"timeGetSystemTime");
		INIT_STUB_FUNC(149,"timeGetTime");
		INIT_STUB_FUNC(150,"timeKillEvent");
		INIT_STUB_FUNC(151,"timeSetEvent");
		INIT_STUB_FUNC(152,"waveInAddBuffer");
		INIT_STUB_FUNC(153,"waveInClose");
		INIT_STUB_FUNC(154,"waveInGetDevCapsA");
		INIT_STUB_FUNC(155,"waveInGetDevCapsW");
		INIT_STUB_FUNC(156,"waveInGetErrorTextA");
		INIT_STUB_FUNC(157,"waveInGetErrorTextW");
		INIT_STUB_FUNC(158,"waveInGetID");
		INIT_STUB_FUNC(159,"waveInGetNumDevs");
		INIT_STUB_FUNC(160,"waveInGetPosition");
		INIT_STUB_FUNC(161,"waveInMessage");
		INIT_STUB_FUNC(162,"waveInOpen");
		INIT_STUB_FUNC(163,"waveInPrepareHeader");
		INIT_STUB_FUNC(164,"waveInReset");
		INIT_STUB_FUNC(165,"waveInStart");
		INIT_STUB_FUNC(166,"waveInStop");
		INIT_STUB_FUNC(167,"waveInUnprepareHeader");
		INIT_STUB_FUNC(168,"waveOutBreakLoop");
		INIT_STUB_FUNC(169,"waveOutClose");
		INIT_STUB_FUNC(170,"waveOutGetDevCapsA");
		INIT_STUB_FUNC(171,"waveOutGetDevCapsW");
		INIT_STUB_FUNC(172,"waveOutGetErrorTextA");
		INIT_STUB_FUNC(173,"waveOutGetErrorTextW");
		INIT_STUB_FUNC(174,"waveOutGetID");
		INIT_STUB_FUNC(175,"waveOutGetNumDevs");
		INIT_STUB_FUNC(176,"waveOutGetPitch");
		INIT_STUB_FUNC(177,"waveOutGetPlaybackRate");
		INIT_STUB_FUNC(178,"waveOutGetPosition");
		INIT_STUB_FUNC(179,"waveOutGetVolume");
		INIT_STUB_FUNC(180,"waveOutMessage");
		INIT_STUB_FUNC(181,"waveOutOpen");
		INIT_STUB_FUNC(182,"waveOutPause");
		INIT_STUB_FUNC(183,"waveOutPrepareHeader");
		INIT_STUB_FUNC(184,"waveOutReset");
		INIT_STUB_FUNC(185,"waveOutRestart");
		INIT_STUB_FUNC(186,"waveOutSetPitch");
		INIT_STUB_FUNC(187,"waveOutSetPlaybackRate");
		INIT_STUB_FUNC(188,"waveOutSetVolume");
		INIT_STUB_FUNC(189,"waveOutUnprepareHeader");
		INIT_STUB_FUNC(190,"waveOutWrite");
		INIT_STUB_FUNC(191,"wid32Message");
		INIT_STUB_FUNC(192,"wod32Message");
	}
}

