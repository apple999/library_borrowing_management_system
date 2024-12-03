// MFC_BookManage_DBclick.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_BookManage_DBclick.h"
#include "afxdialogex.h"


// MFC_BookManage_DBclick 对话框

IMPLEMENT_DYNAMIC(MFC_BookManage_DBclick, CDialogEx)

MFC_BookManage_DBclick::MFC_BookManage_DBclick(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BookManageShow_DBclick, pParent)
	, m_book_num(_T(""))
	, m_book_name(_T(""))
	, m_book_author(_T(""))
	, m_book_publisher(_T(""))
	, m_book_total(_T(""))
	, m_book_borrownum(_T(""))
	, m_book_publishdate(_T(""))
{

}

MFC_BookManage_DBclick::~MFC_BookManage_DBclick()
{
}

void MFC_BookManage_DBclick::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_book_num);
	DDX_Control(pDX, IDC_EDIT1, book_num);
	DDX_Control(pDX, IDC_EDIT2, book_name);
	DDX_Text(pDX, IDC_EDIT2, m_book_name);
	DDX_Control(pDX, IDC_EDIT3, book_author);
	DDX_Text(pDX, IDC_EDIT3, m_book_author);
	DDX_Control(pDX, IDC_EDIT4, book_publisher);
	DDX_Text(pDX, IDC_EDIT4, m_book_publisher);
	DDX_Control(pDX, IDC_EDIT5, book_total);
	DDX_Text(pDX, IDC_EDIT5, m_book_total);
	DDX_Control(pDX, IDC_EDIT6, book_borrownum);
	DDX_Text(pDX, IDC_EDIT6, m_book_borrownum);
	DDX_Control(pDX, IDC_EDIT7, book_publishdate);
	DDX_Text(pDX, IDC_EDIT7, m_book_publishdate);
	DDX_Control(pDX, IDC_BUTTON1, Edit_change);
	DDX_Control(pDX, IDOK, m_Confirm_Button);
}


BEGIN_MESSAGE_MAP(MFC_BookManage_DBclick, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT7, &MFC_BookManage_DBclick::OnEnChangeEdit7)
	ON_BN_CLICKED(IDC_BUTTON1, &MFC_BookManage_DBclick::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &MFC_BookManage_DBclick::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &MFC_BookManage_DBclick::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &MFC_BookManage_DBclick::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT4, &MFC_BookManage_DBclick::OnEnChangeEdit4)
END_MESSAGE_MAP()


// MFC_BookManage_DBclick 消息处理程序


void MFC_BookManage_DBclick::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


BOOL MFC_BookManage_DBclick::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	vector<CString> vcs = g_clickBook.getInfo();
	m_book_num = vcs[0];
	m_book_name = vcs[1];
	m_book_author = vcs[2];
	m_book_publisher = vcs[3];
	m_book_total = vcs[4];
	m_book_borrownum = vcs[5];
	m_book_publishdate = vcs[6];
	UpdateData(false);
	m_Confirm_Button.ShowWindow(SW_HIDE);
	// TODO:  在此添加额外的初始化
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void MFC_BookManage_DBclick::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//book_num.SetReadOnly(false);
	book_name.SetReadOnly(false);
	book_author.SetReadOnly(false);
	book_publisher.SetReadOnly(false);
	book_total.SetReadOnly(false);
	book_borrownum.SetReadOnly(false);
	book_publishdate.SetReadOnly(false);
	Edit_change.ShowWindow(SW_HIDE);
	m_Confirm_Button.ShowWindow(SW_SHOW);
}


void MFC_BookManage_DBclick::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

//......
void MFC_BookManage_DBclick::OnBnClickedOk()
{
	UpdateData(true);
	if (!(m_book_num.GetLength() && m_book_name.GetLength() && m_book_author.GetLength() && m_book_publisher.GetLength() && m_book_total.GetLength() && m_book_borrownum.GetLength() && m_book_publishdate.GetLength())) {
		MessageBox(_T("不能为空！！"));
		return;
	}
	if (m_book_publishdate.GetLength() != 8) {
		MessageBox(_T("输入的日期格式有误！！"));
		return;
	}
	g_clickBook = Book(C2S(m_book_num), C2S(m_book_name), C2S(m_book_author), C2S(m_book_publisher), C2I(m_book_total), C2I(m_book_borrownum), C2T(m_book_publishdate));
	// TODO: 在此添加控件通知处理程序代码
	book_name.SetReadOnly();
	book_author.SetReadOnly();
	book_publisher.SetReadOnly();
	book_total.SetReadOnly();
	book_borrownum.SetReadOnly();
	book_publishdate.SetReadOnly();
	m_Confirm_Button.ShowWindow(SW_HIDE);
	Edit_change.ShowWindow(SW_SHOW);
	//return;
	CDialogEx::OnOK();
}


void MFC_BookManage_DBclick::OnBnClickedButton2()
{
		// TODO: 在此添加控件通知处理程序代码
	INT_PTR MFC_BookMessDeleteDlg_nReturn;
	MFC_BookMessDeleteDlg MFC_BookMessDeleteDlg_Dlg;
	MFC_BookMessDeleteDlg_nReturn = MFC_BookMessDeleteDlg_Dlg.DoModal();
	if (MFC_BookMessDeleteDlg_nReturn == IDCANCEL) {
		return;
	}
	g_clickBook = Book("", C2S(m_book_name), C2S(m_book_author), C2S(m_book_publisher), C2I(m_book_total), C2I(m_book_borrownum), C2T(m_book_publishdate).tm_year, C2T(m_book_publishdate).tm_mon, C2T(m_book_publishdate).tm_mday);
	CDialogEx::OnOK();

}


void MFC_BookManage_DBclick::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
