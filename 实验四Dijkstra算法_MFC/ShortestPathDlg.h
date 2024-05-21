// ShortestPathDlg.h : header file
//

#if !defined(AFX_SHORTESTPATHDLG_H__017D6C6B_9CF9_4300_BAA0_4839D3995C46__INCLUDED_)
#define AFX_SHORTESTPATHDLG_H__017D6C6B_9CF9_4300_BAA0_4839D3995C46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "afxwin.h"
#include "DlgInput.h"
#include "Vertex.h"
#include "Edge.h"

#define OPE_VERTEX 1
#define OPE_EDGE 2
#define OPE_MOVE 3
#define OPE_DEL 4
#define OPE_FROM 5
#define OPE_TO 6
/////////////////////////////////////////////////////////////////////////////
// CShortestPathDlg dialog

class CShortestPathDlg : public CDialog
{
// Construction
public:
	CShortestPathDlg(CWnd* pParent = NULL);	// standard constructor
	
	CRect m_rectReDraw;
	CRect m_rectDraw;
// Dialog Data
	//{{AFX_DATA(CShortestPathDlg)
	enum { IDD = IDD_SHORTESTPATH_DIALOG };
	CButton	m_staticDraw;
	CEdit	m_editRes;
	CEdit	m_editInfo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShortestPathDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void DrawArrow(CPoint first, CPoint next, COLORREF color);
	void CasDelEdge(int idx);
	void ResortVertexIdx();
	CVertex * PickVertex(int idx);
	CVertex * PickVerSelect();
	int m_nEdgeFrom;
	int m_nSelect;
	bool m_bLBtnDown;
	int m_ope;
	HICON m_hIcon;
	bool directed;	//记录是有向图还是无向图

	// Generated message map functions
	//{{AFX_MSG(CShortestPathDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonVert();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnButtonMove();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnButtonDel();
	afx_msg void OnButtonFrom();
	afx_msg void OnButtonEdge();
	afx_msg void OnButtonCal();
	afx_msg void OnButton1();
	afx_msg void OnChangeEditInfo();
	afx_msg void OnChangeEditRes();
	afx_msg void OnRADIODirected();
	afx_msg void OnRADIOUndirected();
	afx_msg void OnButtonClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHORTESTPATHDLG_H__017D6C6B_9CF9_4300_BAA0_4839D3995C46__INCLUDED_)
