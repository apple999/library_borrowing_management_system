// MFC_StudentMessAddALotDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_StudentMessAddALotDlg.h"
#include "afxdialogex.h"


// MFC_StudentMessAddALotDlg 对话框

IMPLEMENT_DYNAMIC(MFC_StudentMessAddALotDlg, CDialogEx)

MFC_StudentMessAddALotDlg::MFC_StudentMessAddALotDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_StudentMessAddALotDlg, pParent)
{

}

MFC_StudentMessAddALotDlg::~MFC_StudentMessAddALotDlg()
{
}

void MFC_StudentMessAddALotDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MFC_StudentMessAddALotDlg, CDialogEx)
	ON_WM_DROPFILES()
	ON_BN_CLICKED(IDOK, &MFC_StudentMessAddALotDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// MFC_StudentMessAddALotDlg 消息处理程序


void MFC_StudentMessAddALotDlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	char filePathName[10][200];
	string filePathNameS;
	UINT numOfFiles = DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);
	for (UINT i = 0; i < numOfFiles; i++) {
		DragQueryFile(hDropInfo, i, (LPTSTR)filePathName[i], _MAX_PATH);
		AfxMessageBox((LPCTSTR)filePathName[i]);
	}

	/*for (UINT i = 0; i < numOfFiles; i++) {
		copys_copy_students.load(C2S((LPCTSTR)filePathName[i]));
	}*/
	for (UINT i = 0; i < numOfFiles; i++) {
		copy_students.load(C2S((LPCTSTR)filePathName[i]));
	}
	DragFinish(hDropInfo);
	CDialogEx::OnDropFiles(hDropInfo);
}


void MFC_StudentMessAddALotDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

void MFC_StudentMessAddALotDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


BOOL MFC_StudentMessAddALotDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
