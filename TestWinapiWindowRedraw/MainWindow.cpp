#include "MainWindow.h"

MainWindow::MainWindow(HINSTANCE hInstance)
{
	this->hWnd = NULL;
	this->hInstance = hInstance;
}

int MainWindow::Register(HINSTANCE hInstance) {

	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.hInstance = hInstance;
	wcex.lpszClassName = CLASS_NAME;
	wcex.lpfnWndProc = (WNDPROC)MainWindow::internal_WndProc;
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);

	return (int)RegisterClassEx(&wcex);
}

int MainWindow::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}

LRESULT CALLBACK MainWindow::internal_WndProc(HWND hWnd, int msg, WORD wParam, LONG lParam) {
	MainWindow *c = (MainWindow *)GetWindowLong(hWnd, GWLP_USERDATA);

	if (c == NULL)
		return DefWindowProc(hWnd, msg, wParam, lParam);

	return c->WndProc(hWnd, msg, wParam, lParam);
}

void MainWindow::CreateWnd() {
	this->hWnd = CreateWindow(
		CLASS_NAME,
		WND_NAME,
		WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		0,0,
		WND_WIDTH, WND_HEIGHT,
		NULL,
		NULL, 
		this->hInstance,
		NULL
	);
	if (this->hWnd == NULL) {
		wchar_t strBuf[256];
		DWORD err = GetLastError();
		wsprintf(strBuf, L"Error: %d.", err);
		MessageBox(NULL, strBuf, L"Create Window Error", MB_OK | MB_ICONERROR);
		return;
	}
	SetWindowLong(this->hWnd, GWLP_USERDATA, (long)this);
	UpdateWindow(this->hWnd);
}