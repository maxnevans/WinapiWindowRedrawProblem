#include "MainWindow.h"

MainWindow::MainWindow(HINSTANCE hInstance, int nCmdShow)
	:
	BaseWindow()
{

	this->wWidth = WND_INIT_WIDTH;
	this->wHeight = WND_INIT_HEIGHT;


	HWND hDesk = GetDesktopWindow();
	RECT rect;
	GetWindowRect(hDesk, &rect);

	this->dWidth = rect.right;
	this->dHeight = rect.bottom;

	CWS cws = { 0 };
	cws.lpClassName = CLASS_NAME;
	cws.lpWindowName = WND_NAME;
	cws.dwStyle = WND_STYLE;
	cws.x = (this->dWidth - this->wWidth) / 2;
	cws.y = (this->dHeight - this->wHeight) / 2;
	cws.nWidth = WND_INIT_WIDTH;
	cws.nHeight = WND_INIT_HEIGHT;
	cws.hWndParent = NULL;
	cws.hInstance = hInstance;
	cws.lpParam = 0;
	this->ResetCWS(cws);
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