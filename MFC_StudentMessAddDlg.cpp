// MFC_StudentMessAddDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_StudentMessAddDlg.h"
#include "afxdialogex.h"


// MFC_StudentMessAddDlg 对话框

IMPLEMENT_DYNAMIC(MFC_StudentMessAddDlg, CDialogEx)

MFC_StudentMessAddDlg::MFC_StudentMessAddDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_StudentMessAddDlg, pParent)
	, m_id_S(_T(""))
	, m_name_S(_T(""))
	, m_major_S(_T(""))
	, m_classes_S(_T(""))
	, m_phone_S(_T(""))
{

}

MFC_StudentMessAddDlg::~MFC_StudentMessAddDlg()
{
}

void MFC_StudentMessAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_id_S);
	DDX_Text(pDX, IDC_EDIT2, m_name_S);
	DDX_Text(pDX, IDC_EDIT4, m_major_S);
	DDX_Text(pDX, IDC_EDIT5, m_classes_S);
	DDX_Text(pDX, IDC_EDIT6, m_phone_S);
}


BEGIN_MESSAGE_MAP(MFC_StudentMessAddDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &MFC_StudentMessAddDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &MFC_StudentMessAddDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT6, &MFC_StudentMessAddDlg::OnEnChangeEdit6)
END_MESSAGE_MAP()


// MFC_StudentMessAddDlg 消息处理程序


void MFC_StudentMessAddDlg::OnBnClickedOk()
{
	UpdateData();
	if (!(m_id_S.GetLength() && m_name_S.GetLength() && m_major_S.GetLength() && m_classes_S.GetLength() && m_phone_S.GetLength())) {
		MessageBox(_T("不能为空！！"));
		return;
	}
	g_student = Student(C2S(m_id_S), C2S(m_name_S), C2S(m_major_S), C2S(m_classes_S), C2S(m_phone_S));
	MessageBox(_T("添加成功！"));
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void MFC_StudentMessAddDlg::OnBnClickedButton1()
{
	ShowWindow(SW_HIDE);
	INT_PTR MFC_StudentMessAddALotDlg_Dlg_nReturn;
	MFC_StudentMessAddALotDlg MFC_StudentMessAddALotDlg_Dlg;
	MFC_StudentMessAddALotDlg_Dlg_nReturn = MFC_StudentMessAddALotDlg_Dlg.DoModal();
	if (MFC_StudentMessAddALotDlg_Dlg_nReturn == IDCANCEL) {
		return;
	}
	g_StudentList.clear();
	for (auto& [_, stu] : copy_students) g_StudentList.push_back(stu);
	CDialogEx::OnCancel();
	// TODO: 在此添加控件通知处理程序代码
}


void MFC_StudentMessAddDlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
