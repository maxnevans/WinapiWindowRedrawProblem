#pragma once
#include <windows.h>

class BaseWindow
{
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
protected:
	BaseWindow();
	BaseWindow(CWS cws);
	static LRESULT CALLBACK internal_WndProc(HWND hWnd, int msg, WORD wParam, LONG lParam);
	void ResetCWS(CWS cws);
public:
	virtual int WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
	void CreateWnd();
protected:
	CWS cws;
	HWND hWnd;
	HINSTANCE hInstance;
};

