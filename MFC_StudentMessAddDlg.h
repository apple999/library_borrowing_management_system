#pragma once


// MFC_StudentMessAddDlg 对话框

class MFC_StudentMessAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_StudentMessAddDlg)

public:
	MFC_StudentMessAddDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_StudentMessAddDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_StudentMessAddDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_id_S;
	CString m_name_S;
	CString m_major_S;
	CString m_classes_S;
	CString m_phone_S;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit6();
};
