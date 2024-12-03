#pragma once


// MFC_BorrowMenu 对话框

class MFC_BorrowMenu : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_BorrowMenu)

public:
	MFC_BorrowMenu(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_BorrowMenu();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BorrowMenuDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnClose();
	// 学号
	CString m_id_S;
	// 姓名
	CString m_name_S;
	// 专业
	CString m_major_S;
	// 班级
	CString m_classes_S;
	// 电话号码
	CString m_phone_S;
	virtual BOOL OnInitDialog();
	CButton m_borrow_Button;
	void Reflash();
};
