// MFC_MenuLogFalse.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_MenuLogFalse.h"
#include "afxdialogex.h"


// MFC_MenuLogFalse 对话框

IMPLEMENT_DYNAMIC(MFC_MenuLogFalse, CDialogEx)

MFC_MenuLogFalse::MFC_MenuLogFalse(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LoginFalseDlg, pParent)
{

}

MFC_MenuLogFalse::~MFC_MenuLogFalse()
{
}

void MFC_MenuLogFalse::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MFC_MenuLogFalse, CDialogEx)
	ON_BN_CLICKED(IDOK, &MFC_MenuLogFalse::OnBnClickedOk)
END_MESSAGE_MAP()


// MFC_MenuLogFalse 消息处理程序


void MFC_MenuLogFalse::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
