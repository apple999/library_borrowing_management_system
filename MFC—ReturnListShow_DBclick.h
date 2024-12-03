#pragma once


// MFC—ReturnListShow_DBclick 对话框

class MFC—ReturnListShow_DBclick : public CDialogEx
{
	DECLARE_DYNAMIC(MFC—ReturnListShow_DBclick)

public:
	MFC—ReturnListShow_DBclick(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC—ReturnListShow_DBclick();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ReturnListShow_DBclick };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
