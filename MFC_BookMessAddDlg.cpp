// MFC_BookMessAddDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_BookMessAddDlg.h"
#include "afxdialogex.h"


// MFC_BookMessAddDlg 对话框

IMPLEMENT_DYNAMIC(MFC_BookMessAddDlg, CDialogEx)

MFC_BookMessAddDlg::MFC_BookMessAddDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BookMessAddDlg, pParent)
	, m_num_B(_T(""))
	, m_name_B(_T(""))
	, m_author_B(_T(""))
	, m_publisher_B(_T(""))
	, m_totalNum_B(_T(""))
	, m_borrow_Num_B(_T(""))
	, m_pubDay_B(_T(""))
{

}

MFC_BookMessAddDlg::~MFC_BookMessAddDlg()
{
}

void MFC_BookMessAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_num_B);
	DDX_Text(pDX, IDC_EDIT2, m_name_B);
	DDX_Text(pDX, IDC_EDIT3, m_author_B);
	DDX_Text(pDX, IDC_EDIT4, m_publisher_B);
	DDX_Text(pDX, IDC_EDIT5, m_totalNum_B);
	DDX_Text(pDX, IDC_EDIT6, m_borrow_Num_B);
	DDX_Text(pDX, IDC_EDIT7, m_pubDay_B);
	DDX_Control(pDX, IDC_EDIT7, m_pubDay_B_Edit);
}


BEGIN_MESSAGE_MAP(MFC_BookMessAddDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &MFC_BookMessAddDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT7, &MFC_BookMessAddDlg::OnEnChangeEdit7)
END_MESSAGE_MAP()


// MFC_BookMessAddDlg 消息处理程序


void MFC_BookMessAddDlg::OnBnClickedOk()
{

	UpdateData();
	if (!(m_num_B.GetLength() && m_name_B.GetLength() && m_author_B.GetLength() && m_publisher_B.GetLength() && m_totalNum_B.GetLength() && m_borrow_Num_B.GetLength() && m_pubDay_B.GetLength())) {
		MessageBox(_T("不能为空！！"));
		return;
	}
	if (m_pubDay_B.GetLength() != 8) {
		MessageBox(_T("输入的日期格式有误！！"));
		return;
	}
	g_book = Book(C2S(m_num_B), C2S(m_name_B), C2S(m_author_B), C2S(m_publisher_B), C2I(m_totalNum_B), C2I(m_borrow_Num_B), C2T(m_pubDay_B));
	MessageBox(_T("添加成功！"));
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void MFC_BookMessAddDlg::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


BOOL MFC_BookMessAddDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_pubDay_B_Edit.SetLimitText(8);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
