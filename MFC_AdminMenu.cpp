// MFC_AdminMenu.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_AdminMenu.h"
#include "afxdialogex.h"


// MFC_AdminMenu 对话框

IMPLEMENT_DYNAMIC(MFC_AdminMenu, CDialogEx)

MFC_AdminMenu::MFC_AdminMenu(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AdminMenuDlg, pParent)
	, m_show_window(_T(""))
{

}

MFC_AdminMenu::~MFC_AdminMenu()
{
}

void MFC_AdminMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_show_window);
}


BEGIN_MESSAGE_MAP(MFC_AdminMenu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MFC_AdminMenu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MFC_AdminMenu::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &MFC_AdminMenu::OnBnClickedCancel)
	ON_WM_CLOSE()
	ON_EN_CHANGE(IDC_EDIT1, &MFC_AdminMenu::OnEnChangeEdit1)
END_MESSAGE_MAP()


// MFC_AdminMenu 消息处理程序


void MFC_AdminMenu::OnBnClickedButton1()
{
	INT_PTR MFC_BookManage_nReturn;
	MFC_BookManage BookManageDlg;
	MFC_BookManage_nReturn = BookManageDlg.DoModal();
	if (IDCANCEL == MFC_BookManage_nReturn) {
		return;
	}
	// TODO: 在此添加控件通知处理程序代码
}


void MFC_AdminMenu::OnBnClickedButton2()
{
	INT_PTR MFC_StudentManage_nReturn;
	MFC_StudentManage StudentManageDlg;
	MFC_StudentManage_nReturn = StudentManageDlg.DoModal();
	if (IDCANCEL == MFC_StudentManage_nReturn) {
		return;
	}
	
	// TODO: 在此添加控件通知处理程序代码
}


void MFC_AdminMenu::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void MFC_AdminMenu::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnCancel();
}


void MFC_AdminMenu::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
}


BOOL MFC_AdminMenu::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	m_show_window = "欢迎管理员";
	UpdateData(false);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
