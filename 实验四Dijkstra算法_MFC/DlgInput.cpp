// DlgInput.cpp : implementation file
//

#include "stdafx.h"
#include "ShortestPath.h"
#include "DlgInput.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgInput dialog


CDlgInput::CDlgInput(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgInput)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgInput)
	DDX_Control(pDX, IDC_EDIT1, m_editWight);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgInput, CDialog)
	//{{AFX_MSG_MAP(CDlgInput)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgInput message handlers

void CDlgInput::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CDlgInput::OnOK() 
{
	// TODO: Add extra validation here
	m_editWight.GetWindowText(m_wight);
	CDialog::OnOK();
}
