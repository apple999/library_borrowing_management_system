#pragma once


// MFC_BorrowBookShow_DBclick 对话框

class MFC_BorrowBookShow_DBclick : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_BorrowBookShow_DBclick)

public:
	MFC_BorrowBookShow_DBclick(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_BorrowBookShow_DBclick();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BorrowBookShow_DBclick };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	virtual BOOL OnInitDialog();
	// 书号
	CString m_number_B;
	// 书名
	CString m_name_B;
	// 作者
	CString m_author_B;
	// 出版社
	CString m_publisher_B;
	// 总本数
	CString m_totalNum_B;
	// 已借阅本数
	CString m_borrowNum_B;
	// 出版日期
	CString m_pubDay_B;
	afx_msg void OnBnClickedOk();
	CButton m_borrow_Button;
};
