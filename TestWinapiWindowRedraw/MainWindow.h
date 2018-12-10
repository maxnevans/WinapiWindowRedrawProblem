#pragma once
#include <windows.h>
#include <gdiplus.h>
#include "BaseWindow.h"

class MainWindow : public BaseWindow {
public:
	MainWindow(HINSTANCE hInstance, int nCmdShow);
	static int Register(HINSTANCE hInstance);

private:
	int WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
	int wWidth;
	int wHeight;
	int dWidth;
	int dHeight;
	int cWidth;
	int cHeight;

	int nCmdShow;

	static constexpr wchar_t CLASS_NAME[]	= L"MainWindow";
	static constexpr wchar_t WND_NAME[]		= L"USB Monitor";
	static constexpr int WND_INIT_WIDTH		= 1280;
	static constexpr int WND_INIT_HEIGHT	= 720;
	static constexpr DWORD WND_STYLE		= WS_OVERLAPPEDWINDOW | WS_VISIBLE & ~(WS_MAXIMIZEBOX);
};