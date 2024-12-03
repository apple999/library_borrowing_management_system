#pragma once


// MFC_AdminMenu 对话框

class MFC_AdminMenu : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_AdminMenu)

public:
	MFC_AdminMenu(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_AdminMenu();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AdminMenuDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnClose();
	afx_msg void OnEnChangeEdit1();
	CString m_show_window;
	virtual BOOL OnInitDialog();
};
