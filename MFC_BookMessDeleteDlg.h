#pragma once


// MFC_BookMessDeleteDlg 对话框

class MFC_BookMessDeleteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_BookMessDeleteDlg)

public:
	MFC_BookMessDeleteDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_BookMessDeleteDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BookMessDeleteDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
