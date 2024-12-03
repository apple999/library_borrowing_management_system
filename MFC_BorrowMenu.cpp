// MFC_BorrowMenu.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_BorrowMenu.h"
#include "afxdialogex.h"


// MFC_BorrowMenu 对话框

IMPLEMENT_DYNAMIC(MFC_BorrowMenu, CDialogEx)

MFC_BorrowMenu::MFC_BorrowMenu(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BorrowMenuDlg, pParent)
	, m_id_S(_T(""))
	, m_name_S(_T(""))
	, m_major_S(_T(""))
	, m_classes_S(_T(""))
	, m_phone_S(_T(""))
{

}

MFC_BorrowMenu::~MFC_BorrowMenu()
{
}

void MFC_BorrowMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_id_S);
	DDX_Text(pDX, IDC_EDIT3, m_name_S);
	DDX_Text(pDX, IDC_EDIT4, m_major_S);
	DDX_Text(pDX, IDC_EDIT5, m_classes_S);
	DDX_Text(pDX, IDC_EDIT6, m_phone_S);
	DDX_Control(pDX, IDC_BUTTON1, m_borrow_Button);
}


BEGIN_MESSAGE_MAP(MFC_BorrowMenu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MFC_BorrowMenu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MFC_BorrowMenu::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &MFC_BorrowMenu::OnBnClickedCancel)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// MFC_BorrowMenu 消息处理程序

/* 借书 */
void MFC_BorrowMenu::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	

	INT_PTR MFC_BorrwList_nReturn;
	MFC_BorrowList BorrowListDlg;
	MFC_BorrwList_nReturn = BorrowListDlg.DoModal();
	if (IDCANCEL == MFC_BorrwList_nReturn) {
		return;
	}
	Reflash();
}


/* 还书 */
void MFC_BorrowMenu::OnBnClickedButton2()
{
	INT_PTR MFC_ReturnList_nReturn;
	MFC_ReturnList ReturnListDlg;
	MFC_ReturnList_nReturn = ReturnListDlg.DoModal();
	if (IDCANCEL == MFC_ReturnList_nReturn) {
		return;
	}
	Reflash();
	// TODO: 在此添加控件通知处理程序代码
}

/* 登出 */
void MFC_BorrowMenu::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void MFC_BorrowMenu::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnCancel();
}

void MFC_BorrowMenu::Reflash() {
	int flag = 0;
	for (auto&& item : g_students[g_student.id].myBorrowList) {
		time_t timep;
		time(&timep);
		item.second.tm_wday = 0;
		item.second.tm_hour = 0;
		item.second.tm_min = 0;
		item.second.tm_sec = 0;
		item.second.tm_isdst = 0;
		item.second.tm_yday = 0;
		time_t timep2 = mktime(&item.second);
		if (timep - timep2 > 1209600) {
			m_borrow_Button.EnableWindow(false);
			m_borrow_Button.SetWindowText(_T("还书后再借阅"));
			MessageBox(_T("您有书没有按时还，请尽快还书！"));
			flag = 1;
			break;
		}
	}
	if (!flag) {
		m_borrow_Button.EnableWindow(true);
		m_borrow_Button.SetWindowText(_T("借书"));
	}
}

BOOL MFC_BorrowMenu::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	vector<CString> vct = g_student.getInfo();
	m_id_S = vct[0];
	m_name_S = vct[1];
	m_major_S = vct[2];
	m_classes_S = vct[3];
	m_phone_S = vct[4];
	UpdateData(false);
	Reflash();
	


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
