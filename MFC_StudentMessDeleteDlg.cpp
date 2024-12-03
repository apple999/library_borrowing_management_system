// MFC_StudentMessDeleteDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_StudentMessDeleteDlg.h"
#include "afxdialogex.h"


// MFC_StudentMessDeleteDlg 对话框

IMPLEMENT_DYNAMIC(MFC_StudentMessDeleteDlg, CDialogEx)

MFC_StudentMessDeleteDlg::MFC_StudentMessDeleteDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_StudentMessDeleteDlg, pParent)
{

}

MFC_StudentMessDeleteDlg::~MFC_StudentMessDeleteDlg()
{
}

void MFC_StudentMessDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MFC_StudentMessDeleteDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &MFC_StudentMessDeleteDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// MFC_StudentMessDeleteDlg 消息处理程序


void MFC_StudentMessDeleteDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
