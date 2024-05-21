// ShortestPath.h : main header file for the SHORTESTPATH application
//

#if !defined(AFX_SHORTESTPATH_H__6F9E428E_8767_47B9_B871_205D194B5DFB__INCLUDED_)
#define AFX_SHORTESTPATH_H__6F9E428E_8767_47B9_B871_205D194B5DFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShortestPathApp:
// See ShortestPath.cpp for the implementation of this class
//

class CShortestPathApp : public CWinApp
{
public:
	CShortestPathApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShortestPathApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShortestPathApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHORTESTPATH_H__6F9E428E_8767_47B9_B871_205D194B5DFB__INCLUDED_)

extern CShortestPathApp theApp;