#pragma once
#include <windows.h>
#include <gdiplus.h>

#define CLASS_NAME  L"TestClass"
#define WND_NAME L"Window Title Here"
#define WND_WIDTH 1280
#define WND_HEIGHT 720

class MainWindow {
public:
	MainWindow(HINSTANCE hInstance);
	static int Register(HINSTANCE hInstance);
	void CreateWnd();

protected:
	int WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK internal_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:

	HWND hWnd;
	HINSTANCE hInstance;
};