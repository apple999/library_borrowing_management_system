#pragma once


// MFC_BorrowList 对话框

class MFC_BorrowList : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_BorrowList)

public:
	MFC_BorrowList(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_BorrowList();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BorrowListDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_BookList;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedOk();
};
