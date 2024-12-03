// MFC_ReturnList.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_ReturnList.h"
#include "afxdialogex.h"


// MFC_ReturnList 对话框

IMPLEMENT_DYNAMIC(MFC_ReturnList, CDialogEx)

MFC_ReturnList::MFC_ReturnList(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ReturnListDlg, pParent)
{

}

MFC_ReturnList::~MFC_ReturnList()
{
}

void MFC_ReturnList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_BookList);
}


BEGIN_MESSAGE_MAP(MFC_ReturnList, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &MFC_ReturnList::OnLvnItemchangedList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &MFC_ReturnList::OnDblclkList1)
END_MESSAGE_MAP()


// MFC_ReturnList 消息处理程序


BOOL MFC_ReturnList::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_BookList.DeleteAllItems();//删表项
	for (auto& str : borrowBookTitle) {
		m_BookList.DeleteColumn(0);//删表头
	}
	
	CRect rect;
	m_BookList.GetClientRect(&rect);
	m_BookList.SetExtendedStyle(m_BookList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	const int perWth = rect.Width() / borrowBookTitle.size();
	int cnt = 0;
	for (auto& str : borrowBookTitle) {
		m_BookList.InsertColumn(cnt++, S2C(str), LVCFMT_CENTER, perWth);
	}
	g_listBook.clear();	//g_listBook为显示的列表
	int row = 0;
	for (auto& [bk, time] : g_students[g_student.id].myBorrowList) {
		vector<CString> vcs_ = g_books[bk].getInfo();
		vector<CString> vcs;
		vcs.push_back(vcs_[0]);
		vcs.push_back(vcs_[1]);
		vcs.push_back(vcs_[2]);
		vcs.push_back(vcs_[3]);
		vcs.push_back(vcs_[6]);
		vcs.push_back(T2C(time));
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


void MFC_ReturnList::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void MFC_ReturnList::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	int selPos = m_BookList.GetNextItem(-1, LVIS_SELECTED);
	if (selPos == -1)return;
	g_clickBorrowBook = g_students[g_student.id].myBorrowList[selPos];

	INT_PTR MFC_ReturnListShow_DBclick_nReturn;
	MFC_ReturnListShow_DBclick MFC_ReturnListShow_DBclick_DIg;
	MFC_ReturnListShow_DBclick_nReturn = MFC_ReturnListShow_DBclick_DIg.DoModal();
	if (IDCANCEL == MFC_ReturnListShow_DBclick_nReturn)
		return;
	
	OnInitDialog();
	*pResult = 0;
}
