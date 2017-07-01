
// MFC-ReceiveDataProcessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC-ReceiveDataProcess.h"
#include "MFC-ReceiveDataProcessDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCReceiveDataProcessDlg dialog

CMFCReceiveDataProcessDlg::CMFCReceiveDataProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCRECEIVEDATAPROCESS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCReceiveDataProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCReceiveDataProcessDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_COPYDATA, ReceiveData)
	ON_BN_CLICKED(IDCLOSE, &CMFCReceiveDataProcessDlg::OnBnClickedClose)
END_MESSAGE_MAP()

// CMFCReceiveDataProcessDlg message handlers

BOOL CMFCReceiveDataProcessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCReceiveDataProcessDlg::OnPaint()
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
HCURSOR CMFCReceiveDataProcessDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CMFCReceiveDataProcessDlg::ReceiveData(WPARAM wParam, LPARAM lParam)
{
	COPYDATASTRUCT* cds = (COPYDATASTRUCT*)lParam;
	
	if (cds->dwData == 1) {
		((CWnd*)GetDlgItem(IDC_RECEIVEDMSG))->SetWindowText((LPCTSTR)cds->lpData);
	}

	return TRUE;
}

void CMFCReceiveDataProcessDlg::OnBnClickedClose()
{
	CDialogEx::OnCancel();
}
