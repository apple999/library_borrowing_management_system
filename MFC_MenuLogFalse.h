#pragma once


// MFC_MenuLogFalse 对话框

class MFC_MenuLogFalse : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_MenuLogFalse)

public:
	MFC_MenuLogFalse(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_MenuLogFalse();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LoginFalseDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
