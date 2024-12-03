// MFC_StudentManage.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_StudentManage.h"
#include "afxdialogex.h"


// MFC_StudentManage 对话框


IMPLEMENT_DYNAMIC(MFC_StudentManage, CDialogEx)

MFC_StudentManage::MFC_StudentManage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_StudentManageDlg, pParent)
	, m_id_S_Box(FALSE)
	, m_name_S_Box(FALSE)
	, m_major_S_Box(FALSE)
	, m_classes_S_Box(FALSE)
	, m_phone_S_Box(FALSE)
	, m_find_input_S(_T(""))
{

}

MFC_StudentManage::~MFC_StudentManage()
{
}

void MFC_StudentManage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_StudentList);
	DDX_Check(pDX, IDC_CHECK4, m_id_S_Box);
	DDX_Check(pDX, IDC_CHECK1, m_name_S_Box);
	DDX_Check(pDX, IDC_CHECK3, m_major_S_Box);
	DDX_Check(pDX, IDC_CHECK2, m_classes_S_Box);
	DDX_Check(pDX, IDC_CHECK5, m_phone_S_Box);
	DDX_Text(pDX, IDC_EDIT1, m_find_input_S);
}


BEGIN_MESSAGE_MAP(MFC_StudentManage, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &MFC_StudentManage::OnLvnItemchangedList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &MFC_StudentManage::OnDblclkList1)
	ON_BN_CLICKED(IDOK, &MFC_StudentManage::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &MFC_StudentManage::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MFC_StudentManage::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &MFC_StudentManage::OnBnClickedCancel)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST1, &MFC_StudentManage::OnColumnclickList1)
END_MESSAGE_MAP()


// MFC_StudentManage 消息处理程序
void MFC_StudentManage::Reflash() {
	CDialogEx::OnInitDialog();
	m_StudentList.DeleteAllItems();
	for (auto& str : studentTitle) {
		m_StudentList.DeleteColumn(0);
	}
	// TODO:  在此添加额外的初始化

	CRect rect;
	m_StudentList.GetClientRect(&rect);
	m_StudentList.SetExtendedStyle(m_StudentList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	const int perWth = rect.Width() / studentTitle.size();

	int cnt = 0;
	for (auto& str : studentTitle) {
		m_StudentList.InsertColumn(cnt++, S2C(str), LVCFMT_CENTER, perWth);
	}	
	int row = 0;
	for (auto& stu : g_StudentList) {
		vector<CString> vcs = stu.getInfo();
		m_StudentList.InsertItem(row, vcs.front());
		int col = 1;
		for (auto p = vcs.begin() + 1; p != vcs.end(); ++p) {
			m_StudentList.SetItemText(row, col, *p);
			col++;
		}
		++row;//尾插（如果cnt不增加，则为头插）			
	}
}

BOOL MFC_StudentManage::OnInitDialog()
{
	copy_students = g_students;
	g_StudentList.clear();
	for (auto& [_, stu] : g_students)
		g_StudentList.push_back(stu);

	Reflash();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void MFC_StudentManage::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

//加的


void MFC_StudentManage::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	int selPos = m_StudentList.GetNextItem(-1, LVIS_SELECTED);
	if (selPos == -1)return;
	g_clickStudent = g_StudentList[selPos];
	string tempId = g_clickStudent.id;
	INT_PTR MFC_StudentMessShow_DBclick_nReturn;
	MFC_StudentMessShow_DBclick MFC_StudentMessShow_DBclick_Dlg;
	MFC_StudentMessShow_DBclick_nReturn = MFC_StudentMessShow_DBclick_Dlg.DoModal();
	if (IDCANCEL == MFC_StudentMessShow_DBclick_nReturn) {
		return;
	}
	if (g_clickStudent.id == "") {		//点击删除按钮
		g_StudentList.erase(g_StudentList.begin() + selPos);
		copy_students.erase(tempId);
		//g_accounts.erase(tempId);
	}
	else {
		g_StudentList[selPos] = g_clickStudent;	//修改
		copy_students.erase(tempId);
		copy_students.insert(g_clickStudent);
	}
	Reflash();
}



void MFC_StudentManage::OnBnClickedOk()
{
	g_students = copy_students;
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void MFC_StudentManage::OnBnClickedButton1()
{
	INT_PTR MFC_StudentMessAddDlg_nReturn;
	MFC_StudentMessAddDlg MFC_StudentMessAddDlg_Dlg;
	MFC_StudentMessAddDlg_nReturn = MFC_StudentMessAddDlg_Dlg.DoModal();
	if (IDCANCEL == MFC_StudentMessAddDlg_nReturn) {
		Reflash();
		return;
	}
	g_StudentList.push_back(g_student);	//增加
	copy_students.insert(g_student);
	Reflash();
	// TODO: 在此添加控件通知处理程序代码
}


void MFC_StudentManage::OnBnClickedButton2()
{
	UpdateData();
	m_StudentList.DeleteAllItems();
	g_StudentList.clear();
	string str = C2S(m_find_input_S);
	for (auto [_, stu] : copy_students) {
		if (str.empty() ||
			stu.findId(str)&&m_id_S_Box ||
			stu.findClasses(str)&&m_classes_S_Box ||
			stu.findMajor(str)&&m_major_S_Box ||
			stu.findName(str)&&m_name_S_Box ||
			stu.findPhone(str) && m_phone_S_Box) {
			g_StudentList.push_back(stu);
		}
	}
	Reflash();
	// TODO: 在此添加控件通知处理程序代码
}


void MFC_StudentManage::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


static int CALLBACK myComp(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort) {
	return !(int)lParamSort ? (*(CString*)lParam1 < *(CString*)lParam2) : (*(CString*)lParam1 > *(CString*)lParam2);
} 

void MFC_StudentManage::OnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	
	int n = m_StudentList.GetItemCount();
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
		ItemData[i] = m_StudentList.GetItemText(i, colClick) + m_StudentList.GetItemText(i, 0);
		m_StudentList.SetItemData(i, reinterpret_cast<DWORD_PTR> (&ItemData[i]));
	}
	sort(g_StudentList.begin(), g_StudentList.end(), [&](const Student& a, const Student& b) {
		auto&& va = a.getInfo(), && vb = b.getInfo();
		CString x = va[colClick] + va[0], y = vb[colClick] + vb[0];
		return sortFunc ? x < y : x > y;
		});
	m_StudentList.SortItems(myComp, sortFunc);
	
	*pResult = 0;
}


