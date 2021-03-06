#include <windows.h>
#include <gdiplus.h>

#include "MainWindow.h"


int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hInstPrev,_In_opt_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	int res = MainWindow::Register(hInstance);

	DWORD err = GetLastError();

	MainWindow wnd(hInstance);
	wnd.CreateWnd();

	MSG msg = {0};

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int) msg.wParam;
}