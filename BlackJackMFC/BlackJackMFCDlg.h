
// BlackJackMFCDlg.h : header file
//

#pragma once


// CBlackJackMFCDlg dialog
class CBlackJackMFCDlg : public CDialogEx
{
// Construction
public:
	CBlackJackMFCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BLACKJACKMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();

	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnStnClickedMystatic();
	afx_msg void OnBnClickedplay();
	afx_msg void OnBnClickedhit();
	afx_msg void OnBnClickedstand();
	afx_msg void OnStnClickedPc1();
	afx_msg void OnStnClickedPc2();
	afx_msg void OnStnClickedPc3();
	afx_msg void OnStnClickedDc1();
	afx_msg void OnStnClickedDc2();
	afx_msg void OnStnClickedDc3();
	afx_msg void OnStnClickedDc4();
	afx_msg void OnStnClickedPc4();
	int PlayerBet;
};
