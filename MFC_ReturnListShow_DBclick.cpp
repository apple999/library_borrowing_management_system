// MFC_ReturnListShow_DBclick.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_ReturnListShow_DBclick.h"
#include "afxdialogex.h"


// MFC_ReturnListShow_DBclick 对话框

IMPLEMENT_DYNAMIC(MFC_ReturnListShow_DBclick, CDialogEx)

MFC_ReturnListShow_DBclick::MFC_ReturnListShow_DBclick(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ReturnListShow_DBclick, pParent)
	, m_bookNum(_T(""))
	, m_bookName(_T(""))
	, m_bookPublisher(_T(""))
	, m_bookAuthor(_T(""))
	, m_bookPublishday(_T(""))
	, m_bookBorrowday(_T(""))
{

}

MFC_ReturnListShow_DBclick::~MFC_ReturnListShow_DBclick()
{
}

void MFC_ReturnListShow_DBclick::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_bookNum);
	DDX_Text(pDX, IDC_EDIT2, m_bookName);
	DDX_Text(pDX, IDC_EDIT3, m_bookPublisher);
	DDX_Text(pDX, IDC_EDIT6, m_bookAuthor);
	DDX_Text(pDX, IDC_EDIT4, m_bookPublishday);
	DDX_Text(pDX, IDC_EDIT5, m_bookBorrowday);
}


BEGIN_MESSAGE_MAP(MFC_ReturnListShow_DBclick, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MFC_ReturnListShow_DBclick::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &MFC_ReturnListShow_DBclick::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MFC_ReturnListShow_DBclick::OnBnClickedCancel)
END_MESSAGE_MAP()


// MFC_ReturnListShow_DBclick 消息处理程序


BOOL MFC_ReturnListShow_DBclick::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	vector<CString> vcs_ = g_books[g_clickBorrowBook.first].getInfo();
	m_bookNum = vcs_[0];
	m_bookName =vcs_[1];
	m_bookPublisher=vcs_[2];
	m_bookAuthor=vcs_[3];
	m_bookPublishday=vcs_[6];
	m_bookBorrowday=T2C(g_clickBorrowBook.second);
	UpdateData(false);
	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void MFC_ReturnListShow_DBclick::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	g_students[g_student.id].renew(g_clickBorrowBook);
	CDialogEx::OnOK();
}//续借


void MFC_ReturnListShow_DBclick::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	g_books.back(g_books[g_clickBorrowBook.first]);//图书管理员	
	g_students[g_student.id].returnBook(g_clickBorrowBook);//学生

	CDialogEx::OnOK();
}


void MFC_ReturnListShow_DBclick::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
