#include <iostream>
#include "windows.h"
LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName [] = TEXT("MyWindows");
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;      //  ����һ�����������

    //  ��������������
    wndclass.style = CS_HREDRAW | CS_VREDRAW;                           //  ������ʽ
    wndclass.lpszClassName = szAppName;                                 //  ��������
    wndclass.lpszMenuName = NULL;                                       //  ���ڲ˵�����
    wndclass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);    //  ���ڱ�����ɫ
    wndclass.lpfnWndProc = WndProc;                                     //  ���ڴ�����
    wndclass.cbWndExtra = 0;                                            //  ����ʵ����չ����
    wndclass.hInstance = hInstance;                                     //  ����ʵ�����
    wndclass.hIcon = LoadIcon( NULL, IDI_APPLICATION);  //  ������С��ͼ�꣺ʹ��ȱʡͼ��
    wndclass.hCursor = LoadCursor( NULL, IDC_ARROW);    //  ���ڲ��ü�ͷ���

    if ( !RegisterClass( &wndclass) ){
            //  ע�ᴰ���࣬ʧ����ʾ
            MessageBox( NULL, TEXT("����ע��ʧ��!"), TEXT("����"), MB_OK | MB_ICONERROR);
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
            MessageBox( hwnd, TEXT("���ڴ������"), TEXT("�ҵĴ���"), MB_OK | MB_ICONINFORMATION);
            return 0;

        case WM_PAINT:
            hdc = BeginPaint( hwnd, &ps);
            GetClientRect( hwnd, &rect);
            DrawText( hdc, TEXT("HELLOWORLD!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
            EndPaint( hwnd, &ps);
            return 0;

        case WM_LBUTTONDOWN:
            MessageBox( hwnd, TEXT("�������"), TEXT("����"), MB_OK | MB_ICONINFORMATION);
            return 0;

        case WM_DESTROY:
            MessageBox( hwnd, TEXT("�رճ���"), TEXT("EXIT"), MB_OK | MB_ICONINFORMATION);
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc( hwnd, message, wParam, lParam);
}
