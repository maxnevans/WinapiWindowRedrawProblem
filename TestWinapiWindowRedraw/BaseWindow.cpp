#include "BaseWindow.h"

BaseWindow::BaseWindow() {
	this->cws = { 0 };
	this->hInstance = 0;
	this->hWnd = NULL;
}

BaseWindow::BaseWindow(CWS cws)
{
	this->cws = cws;
	this->hInstance = cws.hInstance;
	this->hWnd = NULL;
}

LRESULT CALLBACK BaseWindow::internal_WndProc(HWND hWnd, int msg, WORD wParam, LONG lParam) {
	BaseWindow *c = (BaseWindow *)GetWindowLong(hWnd, GWLP_USERDATA);

	if (c == NULL)
		return DefWindowProc(hWnd, msg, wParam, lParam);

	return c->WndProc(hWnd, msg, wParam, lParam);
}

void BaseWindow::CreateWnd() {
	this->hWnd = CreateWindow(
		cws.lpClassName,
		cws.lpWindowName,
		cws.dwStyle,
		cws.x, cws.y,
		cws.nWidth, cws.nHeight,
		cws.hWndParent,
		cws.hMenu,
		cws.hInstance,
		cws.lpParam
	);
	if (this->hWnd == NULL) {
		wchar_t strBuf[256];
		DWORD err = GetLastError();
		wsprintf(strBuf, L"Could not create window [%s] '%s'. Error: %d.", cws.lpClassName , cws.lpWindowName, err);
		MessageBox(NULL, strBuf, L"Create Window Error", MB_OK | MB_ICONERROR);
		return;
	}
	SetWindowLong(this->hWnd, GWLP_USERDATA, (long)this);
	UpdateWindow(this->hWnd);
}

void BaseWindow::ResetCWS(CWS cws) {
	this->cws = cws;
	this->hInstance = cws.hInstance;
}
