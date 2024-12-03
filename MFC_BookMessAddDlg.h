#pragma once


// MFC_BookMessAddDlg 对话框

class MFC_BookMessAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_BookMessAddDlg)

public:
	MFC_BookMessAddDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_BookMessAddDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BookMessAddDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_num_B;
	CString m_name_B;
	CString m_author_B;
	CString m_publisher_B;
	CString m_totalNum_B;
	CString m_borrow_Num_B;
	CString m_pubDay_B;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit7();
	virtual BOOL OnInitDialog();
	CEdit m_pubDay_B_Edit;
};
