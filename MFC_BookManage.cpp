// MFC_BookManage.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_BookManage.h"
#include "afxdialogex.h"


// MFC_BookManage 对话框

IMPLEMENT_DYNAMIC(MFC_BookManage, CDialogEx)

MFC_BookManage::MFC_BookManage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BookManageDlg, pParent)
	, m_num_B_Box(FALSE)
	, m_name_B_Box(FALSE)
	, m_author_B_Box(FALSE)
	, m_publisher_B_Box(FALSE)
	, m_pubDay_B_Box(FALSE)
	, m_find_input_B(_T(""))
	, copy_books(g_books)
{
}

MFC_BookManage::~MFC_BookManage()
{
}

void MFC_BookManage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_BookList);
	DDX_Check(pDX, IDC_CHECK4, m_num_B_Box);
	DDX_Check(pDX, IDC_CHECK1, m_name_B_Box);
	DDX_Check(pDX, IDC_CHECK3, m_author_B_Box);
	DDX_Check(pDX, IDC_CHECK2, m_publisher_B_Box);
	DDX_Check(pDX, IDC_CHECK5, m_pubDay_B_Box);
	DDX_Text(pDX, IDC_EDIT1, m_find_input_B);
}


BEGIN_MESSAGE_MAP(MFC_BookManage, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &MFC_BookManage::OnLvnItemchangedList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &MFC_BookManage::OnDblclkList1)
	ON_BN_CLICKED(IDOK, &MFC_BookManage::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MFC_BookManage::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON2, &MFC_BookManage::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHECK4, &MFC_BookManage::OnBnClickedCheck4)
	ON_EN_CHANGE(IDC_EDIT1, &MFC_BookManage::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &MFC_BookManage::OnBnClickedButton1)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST1, &MFC_BookManage::OnColumnclickList1)
END_MESSAGE_MAP()


// MFC_BookManage 消息处理程序


BOOL MFC_BookManage::OnInitDialog()
{
	g_listBook.clear();	//g_listBook为显示的列表
	for (const auto& [_, book] : g_books) {
		g_listBook.push_back(book);
	}
	Reflash();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE

}


void MFC_BookManage::Reflash() {
	CDialogEx::OnInitDialog();
	m_BookList.DeleteAllItems();
	for (auto& str : bookTitle) {
		m_BookList.DeleteColumn(0);
	}
	// TODO:  在此添加额外的初始化

	CRect rect;
	m_BookList.GetClientRect(&rect);
	m_BookList.SetExtendedStyle(m_BookList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	const int perWth = rect.Width() / bookTitle.size();

	int cnt = 0;
	for (auto& str : bookTitle) {
		m_BookList.InsertColumn(cnt++, S2C(str), LVCFMT_CENTER, perWth);
	}
	int row = 0;
	for (auto& book : g_listBook) {
		vector<CString> vcs = book.getInfo();
		m_BookList.InsertItem(row, vcs.front());
		int col = 1;
		for (auto p = vcs.begin() + 1; p != vcs.end(); ++p) {
			m_BookList.SetItemText(row, col, *p);
			col++;
		}
		++row;//尾插（如果cnt不增加，则为头插）			
	}
}

void MFC_BookManage::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void MFC_BookManage::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	int selPos = m_BookList.GetNextItem(-1, LVIS_SELECTED);
	if (selPos == -1)return;
	g_clickBook = g_listBook[selPos];
	string tempId = g_clickBook.number;
	INT_PTR MFC_BookManage_DBclick_nReturn;
	MFC_BookManage_DBclick MFC_BookManage_DBclick_Dlg;
	MFC_BookManage_DBclick_nReturn = MFC_BookManage_DBclick_Dlg.DoModal();
	if (IDCANCEL == MFC_BookManage_DBclick_nReturn)
		return;
	//修改
	if (g_clickBook.number == "") {		//点击删除按钮
		g_listBook.erase(g_listBook.begin() + selPos);
		copy_books.erase(tempId);
		//g_accounts.erase(tempId);
	}
	else {
		g_listBook[selPos] = g_clickBook;	//修改
		copy_books.erase(tempId);
		copy_books.insert(g_clickBook);
	}
	Reflash();
}





void MFC_BookManage::OnBnClickedOk()
{
	g_books = copy_books;
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

void MFC_BookManage::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void MFC_BookManage::OnBnClickedButton2()
{
	UpdateData();
	m_BookList.DeleteAllItems();
	g_listBook.clear();
	string str = C2S(m_find_input_B);
	for (auto [_, book] : copy_books) {
		if (str.empty() ||
			book.findNumber(str) && m_num_B_Box ||
			book.finName(str) && m_name_B_Box ||
			book.findAuthor(str) && m_author_B_Box ||
			book.findPublisher(str) && m_publisher_B_Box ||
			book.findPubDay(str) && m_pubDay_B_Box
			) {
			g_listBook.push_back(book);
		}
	}
	Reflash();
	// TODO: 在此添加控件通知处理程序代码
}

void MFC_BookManage::OnBnClickedCheck4()
{
	// TODO: 在此添加控件通知处理程序代码
}

static int CALLBACK myComp(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort) {
	return !(int)lParamSort ? (*(CString*)lParam1 < *(CString*)lParam2) : (*(CString*)lParam1 > *(CString*)lParam2);
}


void MFC_BookManage::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void MFC_BookManage::OnBnClickedButton1()
{
	INT_PTR MFC_BookMessAddDlg_nReturn;
	MFC_BookMessAddDlg MFC_BookMessAddDlg_Dlg;
	MFC_BookMessAddDlg_nReturn = MFC_BookMessAddDlg_Dlg.DoModal();
	if (IDCANCEL == MFC_BookMessAddDlg_nReturn) {
		return;
	}
	g_listBook.push_back(g_book);	//增加
	copy_books.insert(g_book);
	Reflash();
	// TODO: 在此添加控件通知处理程序代码
}

void MFC_BookManage::OnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	int n = m_BookList.GetItemCount();
	CArray<CString, CString> ItemData;
	ItemData.SetSize(n);
	static int sortFunc = 0, colClick = 0;
	if (colClick != pNMLV->iSubItem) {
		sortFunc = 0;
		colClick = pNMLV->iSubItem;
	}
	else
		sortFunc ^= 1;

	for (int i = 0; i < n; ++i) {
		ItemData[i] = m_BookList.GetItemText(i, colClick) + m_BookList.GetItemText(i, 0);
		m_BookList.SetItemData(i, reinterpret_cast<DWORD_PTR> (&ItemData[i]));
	}
	sort(g_listBook.begin(), g_listBook.end(), [&](const Book& a, const Book& b) {
		auto&& va = a.getInfo(), && vb = b.getInfo();
		CString x = va[colClick] + va[0], y = vb[colClick] + vb[0];
		return sortFunc ? x < y : x > y;
		});
	m_BookList.SortItems(myComp, sortFunc);

	*pResult = 0;
}
