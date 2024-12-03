#pragma once


// MFC_StudentBorrowList 对话框

class MFC_StudentBorrowList : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_StudentBorrowList)

public:
	MFC_StudentBorrowList(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_StudentBorrowList();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_StudentBorrowList };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	CListCtrl m_BookList;
	afx_msg void OnBnClickedCancel();
};
