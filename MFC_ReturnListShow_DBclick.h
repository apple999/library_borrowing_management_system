#pragma once


// MFC_ReturnListShow_DBclick 对话框

class MFC_ReturnListShow_DBclick : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_ReturnListShow_DBclick)

public:
	MFC_ReturnListShow_DBclick(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_ReturnListShow_DBclick();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ReturnListShow_DBclick };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	CString m_bookNum;
	CString m_bookName;
	CString m_bookPublisher;
	CString m_bookAuthor;
	CString m_bookPublishday;
	CString m_bookBorrowday;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
