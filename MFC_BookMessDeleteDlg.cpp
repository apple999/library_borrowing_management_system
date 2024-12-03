// MFC_BookMessDeleteDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_BookMessDeleteDlg.h"
#include "afxdialogex.h"


// MFC_BookMessDeleteDlg 对话框

IMPLEMENT_DYNAMIC(MFC_BookMessDeleteDlg, CDialogEx)

MFC_BookMessDeleteDlg::MFC_BookMessDeleteDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BookMessDeleteDlg, pParent)
{

}

MFC_BookMessDeleteDlg::~MFC_BookMessDeleteDlg()
{
}

void MFC_BookMessDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MFC_BookMessDeleteDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &MFC_BookMessDeleteDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MFC_BookMessDeleteDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// MFC_BookMessDeleteDlg 消息处理程序


void MFC_BookMessDeleteDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void MFC_BookMessDeleteDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码

	CDialogEx::OnCancel();
}
