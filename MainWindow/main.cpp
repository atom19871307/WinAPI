#undef UNICODE
#include<Windows.h>

CONST CHAR g_sz_CLASS_NAME[] = "Main Window PV_522";  // dassi anuny
 
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	/*
	//------------------------------------------------------------------
	
	//hInstance - это экземпляр * .exe - файла нашей программы, загруженный в ОЗУ;
	//hPrevInst - предыдущий загруженный экземпляр.В современных OC Windows этот параметр HE используется
	//	LPSTR - LongPointer to STRing;
	//lpCmdLine - это командная строка, с которой запустилась программа.При запеске без параметов в lpCmdLine хранится только имя исполняемого файла программы.
	//	Через этот параметр в программу можно передать начальные данные,
	//	напимер, в текстовый редактор - имя открываемого файла, в браузер,
	//	URL открываемого ресурса, в проигрыватель - файл с фильмом или музыкой;
	//nCmdShow - режим отображения окна : развернуто на весь экран, свернуто в окно, свернуто 
	//--------------------------------------------------------------------
	*/
	//գլխավոր պատուհան 
	//1 պատուհանի գռանցում
	//	1․1 հաըտարառել դասսի պատուհանը
	//	1․2 ստեխցել և


		WNDCLASSEX wClass;
		ZeroMemory(&wClass, sizeof(wClass));
		wClass.style = NULL;
		wClass.cbSize = sizeof(wClass);
		wClass.cbClsExtra = 0;
		wClass.cbWndExtra = 0;
		 
		wClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		wClass.hCursor = LoadIcon(NULL, IDC_ARROW);
		wClass.hbrBackground = (HBRUSH)COLOR_WINDOW;

		wClass.hInstance = hinstance;
		wClass.lpszMenuName = NULL;
		wClass.lpszClassName = g_sz_CLASS_NAME;
		wClass.lpfnWndProc = WndProc;
		
		//1.3
		if (!RegisterClassEx(&wClass))
		{
			MessageBox(NULL, "Class registration failed", NULL, MB_OK | MB_ICONERROR);
			return 0;
		}
		
	//2 պատուհանի ստեղցւմ
		HWND hwnd = CreateWindowEx
		(
			NULL,
			g_sz_CLASS_NAME,
			g_sz_CLASS_NAME,
			WS_OVERLAPPEDWINDOW,

			CW_USEDEFAULT, CW_USEDEFAULT,
			CW_USEDEFAULT, CW_USEDEFAULT,
			NULL,
			NULL,
			hinstance,
			NULL
		);

		if (hwnd == NULL)
		{
			MessageBox(NULL, "Window creation failed", NULL, MB_OK | MB_ICONERROR);
			return 0;
		}
		ShowWindow(hwnd, nCmdShow);
		MSG msg;
		while (GetMessage(&msg, NULL,0,0)>0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return msg.wParam;


	//3 եսեմեսի բացելու ցիկլ 

		//--------------------

	return 0;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		break;
	case WM_COMMAND:
		break;
	case WM_DESTROY:
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return FALSE;
}