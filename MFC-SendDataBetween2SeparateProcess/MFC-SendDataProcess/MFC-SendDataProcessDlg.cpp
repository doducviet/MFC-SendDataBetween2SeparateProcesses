
// MFC-SendDataProcessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC-SendDataProcess.h"
#include "MFC-SendDataProcessDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCSendDataProcessDlg dialog

CMFCSendDataProcessDlg::CMFCSendDataProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCSENDDATAPROCESS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCSendDataProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCSendDataProcessDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDSEND, &CMFCSendDataProcessDlg::OnBnClickedSend)
	ON_BN_CLICKED(IDCLOSE, &CMFCSendDataProcessDlg::OnBnClickedClose)
END_MESSAGE_MAP()

// CMFCSendDataProcessDlg message handlers

BOOL CMFCSendDataProcessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	((CWnd*)GetDlgItem(IDC_EDIT_DATATOSEND))->SetWindowText(_T("Data send from MFC-SendDataProcess !!!"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCSendDataProcessDlg::OnPaint()
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
HCURSOR CMFCSendDataProcessDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCSendDataProcessDlg::OnBnClickedSend()
{
	CString windowTitle = _T("MFC-ReceiveDataProcess");
	CString dataToSend;

	HWND hWnd = ::FindWindow(NULL, windowTitle);
	if (hWnd != NULL) {
		((CWnd*)GetDlgItem(IDC_EDIT_DATATOSEND))->GetWindowText(dataToSend);

		COPYDATASTRUCT cds;
		cds.dwData = 1;	// Use to compare case at MFC-Receive Data Process, can be any value
		cds.cbData = 1024;
		cds.lpData = (void*)dataToSend.GetBuffer(); // Data

		::SendMessage(hWnd, WM_COPYDATA, (WPARAM)hWnd, (LPARAM)(LPVOID)&cds);
	}
}

void CMFCSendDataProcessDlg::OnBnClickedClose()
{
	CDialogEx::OnCancel();
}