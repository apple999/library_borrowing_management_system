#pragma once


// ReturnListShow_DBclick 对话框

class ReturnListShow_DBclick : public CDialogEx
{
	DECLARE_DYNAMIC(ReturnListShow_DBclick)

public:
	ReturnListShow_DBclick(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ReturnListShow_DBclick();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ReturnListShow_DBclick };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
