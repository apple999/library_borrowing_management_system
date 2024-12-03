#pragma once


// MFC_StudentMessShow_DBclick 对话框

class MFC_StudentMessShow_DBclick : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_StudentMessShow_DBclick)

public:
	MFC_StudentMessShow_DBclick(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_StudentMessShow_DBclick();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_StudentMessShow_DBclick };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_id_S;
	CString m_name_S;
	CString m_major_S;
	CString m_classes_S;
	CString m_phone_S;
	afx_msg void OnBnClickedButton1();
	// 学号输入框
	CEdit m_id_S_Edit;
	afx_msg void OnBnClickedButton2();
	CEdit m_name_S_Edit;
	CEdit m_major_S_Edit;
	CEdit m_classes_S_Edit;
	CEdit m_phone_S_Edit;
	afx_msg void OnEnChangeEdit1();
	CButton m_Confirm_S;
	CButton m_Cancel_S;
	afx_msg void OnBnClickedOk();
	CButton m_Change_S;
	afx_msg void OnBnClickedButton3();
	CButton s_stuborrow_list;
	afx_msg void OnBnClickedButton4();
};
