
// BlackJackMFCDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "BlackJackMFC.h"
#include "BlackJackMFCDlg.h"
#include "afxdialogex.h"
#include "Deck.h"
#include "Value.h"
#include "Suit.h"
#include <sstream>
#include "BlackJack.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



BlackJack game = BlackJack();


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
    void WinEnable(int ID, bool TF) {
        CWnd* button = GetDlgItem(ID);
        button->EnableWindow(TF);
    }

    void setText(int ID, std::string text) {
        UpdateData(TRUE);

        CWnd* text1 = GetDlgItem(ID);
        if (text1) {
            SetDlgItemText(ID, L"HELLO");
        }
        UpdateData(FALSE);
    }

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBlackJackMFCDlg dialog



CBlackJackMFCDlg::CBlackJackMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BLACKJACKMFC_DIALOG, pParent)

    , PlayerBet(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBlackJackMFCDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);

    DDX_Text(pDX, IDC_EDIT2, PlayerBet);
	DDV_MinMaxInt(pDX, PlayerBet, 0, INT_MAX);
}

BEGIN_MESSAGE_MAP(CBlackJackMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDOK, &CBlackJackMFCDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CBlackJackMFCDlg::OnBnClickedCancel)
	//ON_BN_CLICKED(IDC_BUTTON1, &CBlackJackMFCDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &CBlackJackMFCDlg::OnEnChangeEdit2)
	//ON_EN_CHANGE(IDC_EDIT1, &CBlackJackMFCDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT5, &CBlackJackMFCDlg::OnEnChangeEdit5)
	ON_STN_CLICKED(IDC_MYSTATIC, &CBlackJackMFCDlg::OnStnClickedMystatic)
	ON_BN_CLICKED(play, &CBlackJackMFCDlg::OnBnClickedplay)
    ON_BN_CLICKED(hit, &CBlackJackMFCDlg::OnBnClickedhit)
    ON_BN_CLICKED(stand, &CBlackJackMFCDlg::OnBnClickedstand)
    ON_STN_CLICKED(IDC_PC1, &CBlackJackMFCDlg::OnStnClickedPc1)
    ON_STN_CLICKED(IDC_PC2, &CBlackJackMFCDlg::OnStnClickedPc2)
    ON_STN_CLICKED(IDC_PC3, &CBlackJackMFCDlg::OnStnClickedPc3)
    ON_STN_CLICKED(IDC_PC4, &CBlackJackMFCDlg::OnStnClickedPc4)
    ON_STN_CLICKED(IDC_DC1, &CBlackJackMFCDlg::OnStnClickedDc1)
    ON_STN_CLICKED(IDC_DC2, &CBlackJackMFCDlg::OnStnClickedDc2)
    ON_STN_CLICKED(IDC_DC3, &CBlackJackMFCDlg::OnStnClickedDc3)
    ON_STN_CLICKED(IDC_DC4, &CBlackJackMFCDlg::OnStnClickedDc4)
    
END_MESSAGE_MAP()


// CBlackJackMFCDlg message handlers

BOOL CBlackJackMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBlackJackMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
        CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBlackJackMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBlackJackMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBlackJackMFCDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CWnd * text = GetDlgItem(IDC_MYSTATIC);
	if (text) {
		SetDlgItemText(IDC_MYSTATIC, L"HELLO");
	}
	UpdateData(FALSE);
	//CDialogEx::OnOK();
}


void CBlackJackMFCDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CBlackJackMFCDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}


void CBlackJackMFCDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CBlackJackMFCDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CBlackJackMFCDlg::OnEnChangeEdit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CBlackJackMFCDlg::OnStnClickedMystatic()
{
	// TODO: Add your control notification handler code here
}


void CBlackJackMFCDlg::OnBnClickedplay()
{
    game.PLAY();
	// TODO: Add your control notification handler code here
}


void CBlackJackMFCDlg::OnBnClickedhit()
{
    game.HIT();
    // TODO: Add your control notification handler code here
}


void CBlackJackMFCDlg::OnBnClickedstand()
{
    game.STAND();
    // TODO: Add your control notification handler code here
}


void CBlackJackMFCDlg::OnStnClickedPc1()
{
    // TODO: Add your control notification handler code here
}


void CBlackJackMFCDlg::OnStnClickedPc2()
{
    // TODO: Add your control notification handler code here
}


void CBlackJackMFCDlg::OnStnClickedPc3()
{
    // TODO: Add your control notification handler code here
}

void CBlackJackMFCDlg::OnStnClickedPc4()
{
    // TODO: Add your control notification handler code here
}

void CBlackJackMFCDlg::OnStnClickedDc1()
{
    // TODO: Add your control notification handler code here
}


void CBlackJackMFCDlg::OnStnClickedDc2()
{
    // TODO: Add your control notification handler code here
}


void CBlackJackMFCDlg::OnStnClickedDc3()
{
    // TODO: Add your control notification handler code here
}


void CBlackJackMFCDlg::OnStnClickedDc4()
{
    // TODO: Add your control notification handler code here
}



