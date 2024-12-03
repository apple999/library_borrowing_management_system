#pragma once


// MFC_BookManage 对话框

class MFC_BookManage : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_BookManage)

public:
	MFC_BookManage(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_BookManage();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BookManageDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_BookList;
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	void Reflash();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnEnChangeEdit1();
	BOOL m_num_B_Box;
	BOOL m_name_B_Box;
	BOOL m_author_B_Box;
	BOOL m_publisher_B_Box;
	BOOL m_pubDay_B_Box;
	CString m_find_input_B;
	Books copy_books;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult);
};
