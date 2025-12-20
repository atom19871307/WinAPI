#include<Windows.h>
INT WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	MessageBox
	(
		NULL, 
		"Hello Windows!",
		"MessageBox", 
		MB_YESNOCANCEL | MB_ICONINFORMATION | MB_HELP | MB_DEFBUTTON3 | MB_SYSTEMMODAL | MB_TASKMODAL
	);
	return 0;
}