// MFC_BorrowBookShow_DBclick.cpp: 实现文件
//

#include "pch.h"
#include "MFC_LibraryLendingSystem.h"
#include "MFC_BorrowBookShow_DBclick.h"
#include "afxdialogex.h"


// MFC_BorrowBookShow_DBclick 对话框

IMPLEMENT_DYNAMIC(MFC_BorrowBookShow_DBclick, CDialogEx)

MFC_BorrowBookShow_DBclick::MFC_BorrowBookShow_DBclick(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_BorrowBookShow_DBclick, pParent)
    , m_number_B(_T(""))
    , m_name_B(_T(""))
    , m_author_B(_T(""))
    , m_publisher_B(_T(""))
    , m_totalNum_B(_T(""))
    , m_borrowNum_B(_T(""))
    , m_pubDay_B(_T(""))
{

}

MFC_BorrowBookShow_DBclick::~MFC_BorrowBookShow_DBclick()
{
}

void MFC_BorrowBookShow_DBclick::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_number_B);
    DDX_Text(pDX, IDC_EDIT2, m_name_B);
    DDX_Text(pDX, IDC_EDIT3, m_author_B);
    DDX_Text(pDX, IDC_EDIT4, m_publisher_B);
    DDX_Text(pDX, IDC_EDIT5, m_totalNum_B);
    DDX_Text(pDX, IDC_EDIT6, m_borrowNum_B);
    DDX_Text(pDX, IDC_EDIT7, m_pubDay_B);
    DDX_Control(pDX, IDOK, m_borrow_Button);
}


BEGIN_MESSAGE_MAP(MFC_BorrowBookShow_DBclick, CDialogEx)
    ON_EN_CHANGE(IDC_EDIT1, &MFC_BorrowBookShow_DBclick::OnEnChangeEdit1)
    ON_BN_CLICKED(IDOK, &MFC_BorrowBookShow_DBclick::OnBnClickedOk)
END_MESSAGE_MAP()


// MFC_BorrowBookShow_DBclick 消息处理程序


void MFC_BorrowBookShow_DBclick::OnEnChangeEdit1()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialogEx::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码
}


BOOL MFC_BorrowBookShow_DBclick::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    vector<CString> vcs = g_clickBook.getInfo();
    m_number_B = vcs[0];
    m_name_B = vcs[1];
    m_author_B = vcs[2];
    m_publisher_B = vcs[3];
    m_totalNum_B = vcs[4];
    m_borrowNum_B = vcs[5];
    m_pubDay_B = vcs[6];
    UpdateData(false);

    if (m_totalNum_B == m_borrowNum_B) {
        m_borrow_Button.EnableWindow(false);
    }

    // TODO:  在此添加额外的初始化

    return TRUE;  // return TRUE unless you set the focus to a control
                              // 异常: OCX 属性页应返回 FALSE
}


void MFC_BorrowBookShow_DBclick::OnBnClickedOk()
{
    // TODO: 在此添加控件通知处理程序代码
    g_students[g_student.id].borrowBook(g_clickBook);
    g_books.lend(g_clickBook);
    CDialogEx::OnOK();
}




