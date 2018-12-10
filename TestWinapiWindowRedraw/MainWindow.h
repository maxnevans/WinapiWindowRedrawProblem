#pragma once
#include <windows.h>
#include <gdiplus.h>

class MainWindow {
public:
	typedef struct _CreateWindowStruct {
		LPCTSTR lpClassName;
		LPCTSTR lpWindowName;
		DWORD dwStyle;
		int x;
		int y;
		int nWidth;
		int nHeight;
		HWND hWndParent;
		HMENU hMenu;
		HINSTANCE hInstance;
		LPVOID lpParam;
	} CWS, *PCWS;
public:
	MainWindow(HINSTANCE hInstance, int nCmdShow);
	static int Register(HINSTANCE hInstance);
	void CreateWnd();

protected:
	int WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK internal_WndProc(HWND hWnd, int msg, WORD wParam, LONG lParam);

private:
	int wWidth;
	int wHeight;
	int dWidth;
	int dHeight;
	int cWidth;
	int cHeight;

	int nCmdShow;
	CWS cws;
	HWND hWnd;
	HINSTANCE hInstance;

	static constexpr wchar_t CLASS_NAME[]	= L"TestClass";
	static constexpr wchar_t WND_NAME[]		= L"Window Title Here";
	static constexpr int WND_INIT_WIDTH		= 1280;
	static constexpr int WND_INIT_HEIGHT	= 720;
	static constexpr DWORD WND_STYLE		= WS_OVERLAPPEDWINDOW | WS_VISIBLE;
};