// MFC_StudentMessShow_DBclick.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_StudentMessShow_DBclick.h"
#include "afxdialogex.h"


// MFC_StudentMessShow_DBclick 对话框

IMPLEMENT_DYNAMIC(MFC_StudentMessShow_DBclick, CDialogEx)

MFC_StudentMessShow_DBclick::MFC_StudentMessShow_DBclick(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_StudentMessShow_DBclick, pParent)
	, m_id_S(_T(""))
	, m_name_S(_T(""))
	, m_major_S(_T(""))
	, m_classes_S(_T(""))
	, m_phone_S(_T(""))
{

}

MFC_StudentMessShow_DBclick::~MFC_StudentMessShow_DBclick()
{
}

void MFC_StudentMessShow_DBclick::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_id_S);
	DDX_Text(pDX, IDC_EDIT2, m_name_S);
	DDX_Text(pDX, IDC_EDIT4, m_major_S);
	DDX_Text(pDX, IDC_EDIT5, m_classes_S);
	DDX_Text(pDX, IDC_EDIT6, m_phone_S);
	DDX_Control(pDX, IDC_EDIT1, m_id_S_Edit);
	DDX_Control(pDX, IDC_EDIT2, m_name_S_Edit);
	DDX_Control(pDX, IDC_EDIT4, m_major_S_Edit);
	DDX_Control(pDX, IDC_EDIT5, m_classes_S_Edit);
	DDX_Control(pDX, IDC_EDIT6, m_phone_S_Edit);
	DDX_Control(pDX, IDC_BUTTON2, m_Confirm_S);
	DDX_Control(pDX, IDOK, m_Cancel_S);
	DDX_Control(pDX, IDC_BUTTON1, m_Change_S);
	DDX_Control(pDX, IDC_BUTTON4, s_stuborrow_list);
}


BEGIN_MESSAGE_MAP(MFC_StudentMessShow_DBclick, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MFC_StudentMessShow_DBclick::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MFC_StudentMessShow_DBclick::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &MFC_StudentMessShow_DBclick::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &MFC_StudentMessShow_DBclick::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &MFC_StudentMessShow_DBclick::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &MFC_StudentMessShow_DBclick::OnBnClickedButton4)
END_MESSAGE_MAP()


// MFC_StudentMessShow_DBclick 消息处理程序


BOOL MFC_StudentMessShow_DBclick::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	vector<CString> vcs = g_clickStudent.getInfo();
	m_id_S = vcs[0];
	m_name_S = vcs[1];
	m_major_S = vcs[2];
	m_classes_S = vcs[3];
	m_phone_S = vcs[4];

	UpdateData(false);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void MFC_StudentMessShow_DBclick::OnBnClickedButton1()
{
	//m_id_S_Edit.SetReadOnly(false);
	m_name_S_Edit.SetReadOnly(false);
	m_major_S_Edit.SetReadOnly(false);
	m_classes_S_Edit.SetReadOnly(false);
	m_phone_S_Edit.SetReadOnly(false);
	m_Confirm_S.ShowWindow(SW_SHOW);
	m_Change_S.ShowWindow(SW_HIDE);
	// TODO: 在此添加控件通知处理程序代码
	
}


void MFC_StudentMessShow_DBclick::OnBnClickedButton2()
{
	UpdateData();
	if (!(m_id_S.GetLength() && m_name_S.GetLength() && m_major_S.GetLength() && m_classes_S.GetLength() && m_phone_S.GetLength())) {
		MessageBox(_T("不能为空！！"));
		return;
	}
	if (m_phone_S.GetLength() > 20) {
		MessageBox(_T("电话号码过长！！"));
		return;
	}
	g_student = Student(C2S(m_id_S), C2S(m_name_S), C2S(m_major_S), C2S(m_classes_S), C2S(m_phone_S));
	//m_id_S_Edit.SetReadOnly();
	m_name_S_Edit.SetReadOnly();
	m_major_S_Edit.SetReadOnly();
	m_classes_S_Edit.SetReadOnly();
	m_phone_S_Edit.SetReadOnly();
	m_Confirm_S.ShowWindow(SW_HIDE);
	m_Change_S.ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
	g_clickStudent = Student(C2S(m_id_S), C2S(m_name_S), C2S(m_major_S), C2S(m_classes_S), C2S(m_phone_S));
	//return;
	CDialogEx::OnOK();
}


void MFC_StudentMessShow_DBclick::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void MFC_StudentMessShow_DBclick::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码w
	g_clickStudent = Student(C2S(m_id_S), C2S(m_name_S), C2S(m_major_S), C2S(m_classes_S), C2S(m_phone_S));
	CDialogEx::OnCancel();
}



void MFC_StudentMessShow_DBclick::OnBnClickedButton3()
{
	INT_PTR MFC_StudentMessDeleteDlg_nReturn;
	MFC_StudentMessDeleteDlg MFC_StudentMessDeleteDlg;
	MFC_StudentMessDeleteDlg_nReturn = MFC_StudentMessDeleteDlg.DoModal();
	if (IDCANCEL == MFC_StudentMessDeleteDlg_nReturn)
		return;
	g_clickStudent = Student("", C2S(m_name_S), C2S(m_major_S), C2S(m_classes_S), C2S(m_phone_S));

	CDialogEx::OnOK();
	// TODO: 在此添加控件通知处理程序代码
}


void MFC_StudentMessShow_DBclick::OnBnClickedButton4()
{
	INT_PTR MFC_StudentBorrowList_nReturn;
	MFC_StudentBorrowList MFC_StudentBorrowListDIg;
	MFC_StudentBorrowList_nReturn = MFC_StudentBorrowListDIg.DoModal();
	if (IDCANCEL == MFC_StudentBorrowList_nReturn) {
		return;
	}
	
	// TODO: 在此添加控件通知处理程序代码
}
