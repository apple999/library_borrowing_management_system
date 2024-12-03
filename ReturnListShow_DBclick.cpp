// ReturnListShow_DBclick.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "ReturnListShow_DBclick.h"
#include "afxdialogex.h"


// ReturnListShow_DBclick 对话框

IMPLEMENT_DYNAMIC(ReturnListShow_DBclick, CDialogEx)

ReturnListShow_DBclick::ReturnListShow_DBclick(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ReturnListShow_DBclick, pParent)
{

}

ReturnListShow_DBclick::~ReturnListShow_DBclick()
{
}

void ReturnListShow_DBclick::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ReturnListShow_DBclick, CDialogEx)
	ON_BN_CLICKED(IDOK, &ReturnListShow_DBclick::OnBnClickedOk)
END_MESSAGE_MAP()


// ReturnListShow_DBclick 消息处理程序


void ReturnListShow_DBclick::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
