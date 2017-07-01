
// MFC-ReceiveDataProcessDlg.h : header file
//

#pragma once

// CMFCReceiveDataProcessDlg dialog
class CMFCReceiveDataProcessDlg : public CDialogEx
{
// Construction
public:
	CMFCReceiveDataProcessDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCRECEIVEDATAPROCESS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	LRESULT ReceiveData(WPARAM wParam, LPARAM lParam);

	afx_msg void OnBnClickedClose();
};
