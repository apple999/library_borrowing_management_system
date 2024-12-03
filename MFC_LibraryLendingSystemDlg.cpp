
// MFC_LibraryLendingSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_LibraryLendingSystemDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCLibraryLendingSystemDlg 对话框



CMFCLibraryLendingSystemDlg::CMFCLibraryLendingSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MainMenuDlg, pParent)
	, m_menu_loginID(_T(""))
	, m_menu_loginPassword(_T(""))
	, m_menu_PasswordShow_flag(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCLibraryLendingSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_menu_loginID);
	DDX_Text(pDX, IDC_EDIT2, m_menu_loginPassword);
	DDX_Check(pDX, IDC_CHECK1, m_menu_PasswordShow_flag);
	DDX_Control(pDX, IDC_EDIT2, m_menu_Password);
}

BEGIN_MESSAGE_MAP(CMFCLibraryLendingSystemDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCLibraryLendingSystemDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCLibraryLendingSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCLibraryLendingSystemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCLibraryLendingSystemDlg::OnBnClickedCheck1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCLibraryLendingSystemDlg::OnEnChangeEdit2)
	ON_STN_CLICKED(MFC_MENU_TITLE, &CMFCLibraryLendingSystemDlg::OnStnClickedMenuTitle)
END_MESSAGE_MAP()


// CMFCLibraryLendingSystemDlg 消息处理程序

BOOL CMFCLibraryLendingSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	g_accounts.init();
	g_books.init();
	g_students.init();

	CRect rect;
	GetWindowRect(&rect);
	SetWindowPos(&wndNoTopMost, rect.left, rect.top, rect.right, rect.bottom,SWP_SHOWWINDOW);
	CenterWindow();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCLibraryLendingSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCLibraryLendingSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCLibraryLendingSystemDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCLibraryLendingSystemDlg::OnBnClickedButton1()
{
	CRect rect;
	GetWindowRect(&rect);
	//账号匹配；
	//不匹配，弹错误窗口；
	//匹配进入下一级
	UpdateData();
	int flag = g_accounts.login(account(C2S(m_menu_loginID), C2S(m_menu_loginPassword)));
	if (flag == 1)flag &= g_students.count(C2S(m_menu_loginID));
	/* 0登录失败 1用户 2管理员 */
	if (flag == 0) {
		MFC_MenuLogFalse menuLogDlg;
		menuLogDlg.DoModal();
	}
	else if (flag == 1) {
		g_student = g_students[C2S(m_menu_loginID)];

		ShowWindow(SW_HIDE);

		INT_PTR MFC_BorrowMenu_nReturn;
		MFC_BorrowMenu BorrowMenuDlg;
		MFC_BorrowMenu_nReturn = BorrowMenuDlg.DoModal();
		if (IDCANCEL == MFC_BorrowMenu_nReturn)
			OnCancel();

		ShowWindow(SW_SHOW);
		CenterWindow();
	}
	else {
		ShowWindow(SW_HIDE);

		INT_PTR MFC_AdminMenu_nReturn;
		MFC_AdminMenu AdminMenuDlg;
		MFC_AdminMenu_nReturn = AdminMenuDlg.DoModal();
		if (IDCANCEL == MFC_AdminMenu_nReturn)
			OnCancel();
		
		ShowWindow(SW_SHOW);
		CenterWindow();
	}
	m_menu_loginID = "";
	m_menu_loginPassword = "";
	UpdateData(false);
	// 
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCLibraryLendingSystemDlg::OnBnClickedButton2()
{
	CDialog::OnCancel();
	// TODO: 在此添加控件通知处理程序代码
}

void CMFCLibraryLendingSystemDlg::OnBnClickedCheck1()
{
	UpdateData();
	if (m_menu_PasswordShow_flag) {
		m_menu_Password.SetPasswordChar(0);
		m_menu_Password.ModifyStyle(ES_PASSWORD, 0);
		//UpdateData(false);
	}
	else {
		m_menu_Password.ModifyStyle(0, ES_PASSWORD);
		m_menu_Password.SetPasswordChar(9679);//大圆点
		//UpdateData(false);
	}
	m_menu_Password.SetFocus();
	// TODO: 在此添加控件通知处理程序代码
}

void CMFCLibraryLendingSystemDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCLibraryLendingSystemDlg::OnStnClickedMenuTitle()
{
	// TODO: 在此添加控件通知处理程序代码
}
