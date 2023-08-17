// Plus_Windows.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "Plus_Windows.h"

#define MAX_LOADSTRING 100
#define IDB_ONEBOTTON 3301  
#define IDB_TWOBOTTON 3302  
#define IDB_THREEBOTTON 3303

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
HWND Pvz_hWnd = FindWindow(L"MainWindow", L"植物大战僵尸中文版");

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PLUSWINDOWS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_MENU1));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PLUSWINDOWS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PLUSWINDOWS);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中
   HWND hWnd = CreateWindowW(szWindowClass,NULL, WS_POPUP,
      785, 15, 200, 570, nullptr, nullptr, hInstance, nullptr);// | WS_BORDER | WS_CLIPCHILDREN | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_SIZEBOX
   SetParent(hWnd, Pvz_hWnd);
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

    HWND hWndButton1 = CreateWindow(L"Button",        /*子窗口类名称*/
       L"P",                    /*按钮上的文字*/
       WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,     /*按钮类型*/
       10, 10, 180, 50,                  /*位置*/
       hWnd,                                      /*父窗口句柄*/
       (HMENU)IDB_ONEBOTTON,                        /*按钮ID,一个自定义整型常量*/
       hInst, NULL);

   if (!hWndButton1) MessageBox(NULL, L"创建按钮失败", L"Message", MB_OK | MB_ICONERROR);
   ShowWindow(hWndButton1, SW_SHOW);
   UpdateWindow(hWndButton1);

   HWND hWndButton2 = CreateWindow(L"Button",        /*子窗口类名称*/
       L"V",                    /*按钮上的文字*/
       WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,     /*按钮类型*/
       10, 60, 180, 50,                  /*位置*/
       hWnd,                                      /*父窗口句柄*/
       (HMENU)IDB_TWOBOTTON,                        /*按钮ID,一个自定义整型常量*/
       hInst, NULL);

   if (!hWndButton2) MessageBox(NULL, L"创建按钮失败", L"Message", MB_OK | MB_ICONERROR);
   ShowWindow(hWndButton2, SW_SHOW);
   UpdateWindow(hWndButton2);

   HWND hWndButton3 = CreateWindow(L"Button",        /*子窗口类名称*/
       L"Z",                    /*按钮上的文字*/
       WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,     /*按钮类型*/
       10, 110, 180, 50,                  /*位置*/
       hWnd,                                      /*父窗口句柄*/
       (HMENU)IDB_THREEBOTTON,                        /*按钮ID,一个自定义整型常量*/
       hInst, NULL);

   if (!hWndButton3) MessageBox(NULL, L"创建按钮失败", L"Message", MB_OK | MB_ICONERROR);
   ShowWindow(hWndButton3, SW_SHOW);
   UpdateWindow(hWndButton3);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
                /*            
                case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
                */
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
   
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDB_ONEBOTTON:
                MessageBox(hWnd, L"您点击了第一个按钮。", L"提示", MB_OK | MB_ICONINFORMATION);
                break;
            case IDB_TWOBOTTON:
                MessageBox(hWnd, L"您点击了第二个按钮。", L"提示", MB_OK | MB_ICONINFORMATION);
                break;
            case IDB_THREEBOTTON:
                MessageBox(hWnd, L"您点击了第三个按钮。", L"提示", MB_OK | MB_ICONINFORMATION);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
    
}
// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
