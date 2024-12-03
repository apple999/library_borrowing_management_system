#pragma once


// MFC_StudentMessAddALotDlg 对话框

class MFC_StudentMessAddALotDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_StudentMessAddALotDlg)

public:
	MFC_StudentMessAddALotDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFC_StudentMessAddALotDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_StudentMessAddALotDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	//Students copys_copy_students;
};
