#include "MainWindow.h"

MainWindow::MainWindow(HINSTANCE hInstance, int nCmdShow)
{
	this->hWnd = NULL;

	this->wWidth = WND_INIT_WIDTH;
	this->wHeight = WND_INIT_HEIGHT;


	HWND hDesk = GetDesktopWindow();
	RECT rect;
	GetWindowRect(hDesk, &rect);

	this->dWidth = rect.right;
	this->dHeight = rect.bottom;

	this->cws = { 0 };
	this->cws.lpClassName = CLASS_NAME;
	this->cws.lpWindowName = WND_NAME;
	this->cws.dwStyle = WND_STYLE;
	this->cws.x = (this->dWidth - this->wWidth) / 2;
	this->cws.y = (this->dHeight - this->wHeight) / 2;
	this->cws.nWidth = WND_INIT_WIDTH;
	this->cws.nHeight = WND_INIT_HEIGHT;
	this->cws.hWndParent = NULL;
	this->cws.hInstance = hInstance;
	this->cws.lpParam = 0;
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
		this->cws.lpClassName,
		this->cws.lpWindowName,
		this->cws.dwStyle,
		this->cws.x, this->cws.y,
		this->cws.nWidth, this->cws.nHeight,
		this->cws.hWndParent,
		this->cws.hMenu,
		this->cws.hInstance,
		this->cws.lpParam
	);
	if (this->hWnd == NULL) {
		wchar_t strBuf[256];
		DWORD err = GetLastError();
		wsprintf(strBuf, L"Could not create window [%s] '%s'. Error: %d.", this->cws.lpClassName, this->cws.lpWindowName, err);
		MessageBox(NULL, strBuf, L"Create Window Error", MB_OK | MB_ICONERROR);
		return;
	}
	SetWindowLong(this->hWnd, GWLP_USERDATA, (long)this);
	UpdateWindow(this->hWnd);
}