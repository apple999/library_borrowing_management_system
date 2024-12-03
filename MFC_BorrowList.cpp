// MFC_BorrowList.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_BorrowList.h"
#include "afxdialogex.h"


// MFC_BorrowList 对话框

IMPLEMENT_DYNAMIC(MFC_BorrowList, CDialogEx)

MFC_BorrowList::MFC_BorrowList(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BorrowListDlg, pParent)
{

}

MFC_BorrowList::~MFC_BorrowList()
{
}

void MFC_BorrowList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_BookList);
}


BEGIN_MESSAGE_MAP(MFC_BorrowList, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &MFC_BorrowList::OnLvnItemchangedList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &MFC_BorrowList::OnNMDblclkList1)
	ON_BN_CLICKED(IDOK, &MFC_BorrowList::OnBnClickedOk)
END_MESSAGE_MAP()


// MFC_BorrowList 消息处理程序


BOOL MFC_BorrowList::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_BookList.DeleteAllItems();//删表项
	for (auto& str : bookTitle) {
		m_BookList.DeleteColumn(0);//删表头
	}

	// TODO:  在此添加额外的初始化
	g_listBook.clear();


	CRect rect;
	m_BookList.GetClientRect(&rect);
	m_BookList.SetExtendedStyle(m_BookList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP | LVS_EX_TWOCLICKACTIVATE );
	const int perWth = rect.Width() / bookTitle.size();
	int cnt = 0;
	for (auto& str : bookTitle) {
		m_BookList.InsertColumn(cnt++, S2C(str), LVCFMT_CENTER, perWth);
	}
	int row = 0;
	for (auto& [_, bk]: g_books) {
		g_listBook.push_back(bk);
		vector<CString> vcs = bk.getInfo();
		m_BookList.InsertItem(row, vcs.front());
		int col = 1;
		for (auto p = vcs.begin() + 1; p != vcs.end(); ++p) {
			m_BookList.SetItemText(row, col, *p);
			col++;
		}
		++row;//尾插（如果cnt不增加，则为头插）			
	}



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void MFC_BorrowList::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void MFC_BorrowList::OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	int selPos = m_BookList.GetNextItem(-1, LVIS_SELECTED);
	if (selPos == -1)return;
	g_clickBook = g_listBook[selPos];

	INT_PTR MFC_BorrowBookShow_DBclick_nReturn;
	MFC_BorrowBookShow_DBclick BorrowBookShow_DBclick_Dlg;
	MFC_BorrowBookShow_DBclick_nReturn = BorrowBookShow_DBclick_Dlg.DoModal();
	if (IDCANCEL == MFC_BorrowBookShow_DBclick_nReturn)
		return;
	
	OnInitDialog();
}


void MFC_BorrowList::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
