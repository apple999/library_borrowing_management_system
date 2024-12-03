#pragma once


// MFC_ReturnList 对话框

class MFC_ReturnList : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_ReturnList)

public:
	MFC_ReturnList(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_ReturnList();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ReturnListDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_BookList;
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
};
