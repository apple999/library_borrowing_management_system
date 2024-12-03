#pragma once


// MFC_BookManage_DBclick 对话框

class MFC_BookManage_DBclick : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_BookManage_DBclick)

public:
	MFC_BookManage_DBclick(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_BookManage_DBclick();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BookManageShow_DBclick };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_book_num;
	CEdit book_num;
	CEdit book_name;
	CString m_book_name;
	CEdit book_author;
	CString m_book_author;
	CEdit book_publisher;
	CString m_book_publisher;
	CEdit book_total;
	CString m_book_total;
	CEdit book_borrownum;
	CString m_book_borrownum;
	CEdit book_publishdate;
	CString m_book_publishdate;
	afx_msg void OnEnChangeEdit7();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CButton Edit_change;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton2();
	CButton m_Confirm_Button;
	afx_msg void OnEnChangeEdit4();
};
