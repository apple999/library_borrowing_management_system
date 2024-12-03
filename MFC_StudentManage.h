#pragma once


// MFC_StudentManage 对话框

class MFC_StudentManage : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_StudentManage)

public:
	MFC_StudentManage(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_StudentManage();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_StudentManageDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_StudentList;
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	BOOL m_id_S_Box;
	BOOL m_name_S_Box;
	BOOL m_major_S_Box;
	BOOL m_classes_S_Box;
	BOOL m_phone_S_Box;
	CString m_find_input_S;
	afx_msg void OnBnClickedCancel();
	void Reflash();
	
	afx_msg void OnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult);
};
