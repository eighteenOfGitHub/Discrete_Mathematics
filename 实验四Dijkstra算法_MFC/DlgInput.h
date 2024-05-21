#if !defined(AFX_DLGINPUT_H__0A015598_C0A4_43D9_A457_3D7BDA7D0450__INCLUDED_)
#define AFX_DLGINPUT_H__0A015598_C0A4_43D9_A457_3D7BDA7D0450__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgInput.h : header file
//
#include "afxwin.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgInput dialog

class CDlgInput : public CDialog
{
// Construction
public:
	CDlgInput(CWnd* pParent = NULL);   // standard constructor
	
	CString m_wight;
// Dialog Data
	//{{AFX_DATA(CDlgInput)
	enum { IDD = IDD_DIALOG_INPUT };
	CEdit	m_editWight;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgInput)
	afx_msg void OnChangeEdit1();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGINPUT_H__0A015598_C0A4_43D9_A457_3D7BDA7D0450__INCLUDED_)
