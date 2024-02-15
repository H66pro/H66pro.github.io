#include <iostream>
#include "windows.h"
LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName [] = TEXT("MyWindows");
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;      //  声明一个窗口类对象

    //  窗口类对象的属性
    wndclass.style = CS_HREDRAW | CS_VREDRAW;                           //  窗口样式
    wndclass.lpszClassName = szAppName;                                 //  窗口类名
    wndclass.lpszMenuName = NULL;                                       //  窗口菜单：无
    wndclass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);    //  窗口背景颜色
    wndclass.lpfnWndProc = WndProc;                                     //  窗口处理函数
    wndclass.cbWndExtra = 0;                                            //  窗口实例扩展：无
    wndclass.hInstance = hInstance;                                     //  窗口实例句柄
    wndclass.hIcon = LoadIcon( NULL, IDI_APPLICATION);  //  窗口最小化图标：使用缺省图标
    wndclass.hCursor = LoadCursor( NULL, IDC_ARROW);    //  窗口采用箭头光标

    if ( !RegisterClass( &wndclass) ){
            //  注册窗口类，失败提示
            MessageBox( NULL, TEXT("窗口注册失败!"), TEXT("错误"), MB_OK | MB_ICONERROR);
            return 0;
    }

    hwnd = CreateWindowEx(
            WS_EX_LAYERED | WS_EX_TOOLWINDOW,
            szAppName,
            reinterpret_cast<LPCSTR>(L""),
            WS_POPUP | WS_THICKFRAME,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            NULL,
            NULL,
            hInstance,
            NULL
            );

    ShowWindow( hwnd, iCmdShow);
    UpdateWindow( hwnd);
    while( GetMessage( &msg, NULL, 0, 0) ){
        TranslateMessage( &msg);
        DispatchMessage( &msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc ( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;

    switch (message) {
        case WM_CREATE:
            MessageBox( hwnd, TEXT("窗口创建完成"), TEXT("我的窗口"), MB_OK | MB_ICONINFORMATION);
            return 0;

        case WM_PAINT:
            hdc = BeginPaint( hwnd, &ps);
            GetClientRect( hwnd, &rect);
            DrawText( hdc, TEXT("HELLOWORLD!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
            EndPaint( hwnd, &ps);
            return 0;

        case WM_LBUTTONDOWN:
            MessageBox( hwnd, TEXT("左键按下"), TEXT("单击"), MB_OK | MB_ICONINFORMATION);
            return 0;

        case WM_DESTROY:
            MessageBox( hwnd, TEXT("关闭程序"), TEXT("EXIT"), MB_OK | MB_ICONINFORMATION);
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc( hwnd, message, wParam, lParam);
}
