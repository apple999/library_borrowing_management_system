
// MFC_LibraryLendingSystemDlg.h: 头文件
//

#pragma once


// CMFCLibraryLendingSystemDlg 对话框
class CMFCLibraryLendingSystemDlg : public CDialogEx
{
// 构造
public:
	CMFCLibraryLendingSystemDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MainMenuDlg };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();

	CBrush m_brush;
	CFont m_font;
	CString m_menu_loginID;
	CString m_menu_loginPassword;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCheck1();
	BOOL m_menu_PasswordShow_flag;
	CEdit m_menu_Password;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnStnClickedMenuTitle();
};
