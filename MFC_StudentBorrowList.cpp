// MFC_StudentBorrowList.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_StudentBorrowList.h"
#include "afxdialogex.h"


// MFC_StudentBorrowList 对话框

IMPLEMENT_DYNAMIC(MFC_StudentBorrowList, CDialogEx)

MFC_StudentBorrowList::MFC_StudentBorrowList(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_StudentBorrowList, pParent)
{

}

MFC_StudentBorrowList::~MFC_StudentBorrowList()
{
}

void MFC_StudentBorrowList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_BookList);
}


BEGIN_MESSAGE_MAP(MFC_StudentBorrowList, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &MFC_StudentBorrowList::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDCANCEL, &MFC_StudentBorrowList::OnBnClickedCancel)
END_MESSAGE_MAP()

// MFC_StudentBorrowList 消息处理程序



void MFC_StudentBorrowList::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


BOOL MFC_StudentBorrowList::OnInitDialog()
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
	for (auto& [bk, time] : g_students[g_clickStudent.id].myBorrowList) {
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


void MFC_StudentBorrowList::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
