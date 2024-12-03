#pragma once


// MFC_StudentMessDeleteDlg 对话框

class MFC_StudentMessDeleteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_StudentMessDeleteDlg)

public:
	MFC_StudentMessDeleteDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_StudentMessDeleteDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_StudentMessDeleteDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
