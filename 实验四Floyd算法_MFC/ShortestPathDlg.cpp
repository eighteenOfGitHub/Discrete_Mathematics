// ShortestPathDlg.cpp : implementation file
/*******************************************************
/*******************************************************
// Author of the program:
// Wang Xiaohua, School of computer and information,HFUT
/*******************************************************
/*******************************************************/

#include<iostream>
#include "stdafx.h"
#include "ShortestPath.h"
#include "ShortestPathDlg.h"
#include <complex>
#include <vector>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

std::vector <CVertex> m_vecVertex;
std::vector <CEdge> m_vecEdge;
std::vector <int> m_vecPathVertex;
std::stringstream strout;

#define MAX 40
#define   INFINITY  500000

int num;	//用于存储变量vexnum
int ver_from, verfrom;	//记录源点
int ver_to, to;		//记录终点
int ver_cnt = 0;		//记录路径上的节点数
bool var_directed = false;		//全局变量存储有向图还是无向图，默认为无向图

template <typename Type>
class Graph
{
private: int  arcs[MAX][MAX], D[MAX],pre[MAX];		////arcs邻接矩阵；D[MAX]，dijkstra路径长度；pre[MAX]，前驱顶点
	     int res_vexs_dij[MAX];	//记录Dijkstra算法输出的顶点序列
	     int  P[50][50][50];
		 Type a, b, vexs[100];
		 int   v0, v1;		//v0起点，v1终点

		 int  Distance[MAX][MAX][30], R[MAX][MAX][30];//Distance和R分别为floyd-warshall算法距离和路径矩阵
		 int  arcnum, vexnum, weight;		////arcnum边数，vexnum顶点数，weight权值
		 int res_vexs[MAX];
		 int res_vexnum;//计数器记录最后路径上有几个中间顶点
public:
	void Creat_Graph();
	void Show_ShortestPath_DIJ();
	void ShortestPath_DIJ();
	void Show_ShortestPath_Floyd();
	void ShortestPath_FLOYD();
	void Out(int a, int b,int vexN);
	void init_source(int v);
	void ChangeWeight(int u,int v);
	int Weight(int a, int b);
};

template <typename Type>
void Graph<Type>::Creat_Graph()
{
	int i,j,x,y;
	arcnum = m_vecEdge.size();
	vexnum=0;  
	res_vexnum = 0;  
	for (i=0; i<MAX; ++i)
		res_vexs[i] = 0;
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
		{
			arcs[i][j]=INFINITY;	
			Distance[i][j][0]=INFINITY;   
			R[i][j][0]=j;                 
		}

	for(i=1;i<=arcnum;i++)
	{
		a = m_vecEdge[i-1].m_from;
		b = m_vecEdge[i-1].m_to;
		weight = m_vecEdge[i-1].m_weight;

		x=0;  y=0;
		for(j=1;j<=vexnum;j++)
		{
			if(vexs[j]==a)
			{
				x=j;   
				continue;
			}
			else if(vexs[j]==b)
			{
				y=j;  
				continue;
			}
		}
		if(x==0)
		{    
			vexs[++vexnum]=a;  
			x=vexnum;
		}
		if(y==0) 
		{
			vexs[++vexnum]=b; 
			y=vexnum;
		}

		if (var_directed)
			arcs[x][y]=weight;
		else
		{
			arcs[x][y]=weight;
			arcs[y][x]=weight;
		}
	}
	a = 0;
	for( std::vector< CVertex >::iterator itv_ver = m_vecVertex.begin();
		itv_ver != m_vecVertex.end(); ++itv_ver )
	{
		if( itv_ver->m_bFrom )
		{
			a = itv_ver->m_idx;
			break;
		}
	}

	for(i=1;i<=vexnum;i++)
	{
		if(vexs[i]==a)
		{
			v0 = i; 
			break;
		}
	}

	for( std::vector< CVertex >::iterator itv = m_vecVertex.begin();
		itv != m_vecVertex.end(); ++itv )
	{
		if( itv->m_bTo )
		{
			a = itv->m_idx;
			break;
		}
	}

	for(i=1;i<=vexnum;i++)
	{
		if(vexs[i]==a)
		{
			v1 = i; 
			break;
		}
	}

	for( i=0;i<100;i++ )
		if ( vexs[i]==ver_from )
		{
			ver_from = i;		
			break;
		}

	for( i=0;i<100;i++ )
		if ( vexs[i]==ver_to )
		{
			to = i;		
			break;
		}	
				
}
/*********************************************************
//用于返回界面上两个顶点之间的权值，使之更加直观
*********************************************************/
template <typename Type>
int Graph<Type>::Weight(int a, int b)
{
	int i,u,v;
	for (i=0;i<100;i++)
	{
		if ( vexs[i]==a ) 
		{
			u=i;
			break;
		}
	}
	for (i=0;i<100;i++)
	{
		if ( vexs[i]==b )
		{
			v=i;
			break;
		}
	}
	return arcs[u][v];
}


/****************************************************
//该函数用于Floyd-Warshall算法的具体实现：
//需要计算距离矩阵Distance[][][]和路径矩阵R[][][]
//循环变量的取值与界面上输入的顶点序号对应,顶点总数用vexnum表示
//函数Weight(u,v)记录顶点u,v之间的权值
*****************************************************/
template <typename Type>
void Graph<Type>::ShortestPath_FLOYD()
{
	int i, j, k;
	//请写出Floyd-Warshall算法的程序代码

	for (int i = 1; i <= vexnum; i++)			//初始化dis和path
		for (int j = 1; j <= vexnum; j++) {
			Distance[i][j][0] = arcs[i][j];
			if (i == j) {
				Distance[i][j][0] = 0;
			}
			R[i][j][0] = -1;
		}

	/***************Floyd核心算法****************/
	for (int k = 1; k <= vexnum; k++) {				//遍历每个点作为中间点
		for (int i = 1; i <= vexnum; i++) {			//初始化dis和path
			for (int j = 1; j <= vexnum; j++) {
				Distance[i][j][k] = Distance[i][j][k - 1];
				R[i][j][k] = R[i][j][k - 1];
			}
		}
		for (int i = 1; i <= vexnum; i++) {				//遍历每条边
			for (int j = 1; j <= vexnum; j++) {
				if (Distance[i][k][k] + Distance[k][j][k] < Distance[i][j][k]) {
					Distance[i][j][k] = Distance[i][k][k] + Distance[k][j][k];			//松弛操作
					R[i][j][k] = k;												//保存j前驱结点k
				}
			}
		}
	}
}


/**********************************************************************
//以下函数采用递归方法从R[][][]矩阵中求解一组值：
//这组值返回的是用户从界面上选定的源点到终点的最短路径上的所有中间点的标号，
//采用从左右两边追溯的方法实现。求解结果需要存储到res_vexs数组里面，以备
//后面的函数输出路径
**********************************************************************/
template <typename Type>
void Graph<Type>::Out(int a, int b,int vexN)	//vexN需要等于vexnum	
{
	//对存放路径顶点标号的数组的赋值可参考：res_vexs[res_vexnum++]=？？？
	//其中res_vexnum在前面的类中已定义
	
    //请根据路径中间点的查找策略写出代码
	if (R[a][b][vexN] == -1) {
		return;
	}
	else {
		int mid = R[a][b][vexN];
		Out(a, mid, vexN);
		res_vexs[res_vexnum++] = mid;
		Out(mid, b, vexN);
	}
}

///***************************************************************************
//该函数输出用Floyd-Warshall算法求出的最短路径，调用Out(, , ,)函数输出路径顶点
/*****************************************************************************/
template <typename Type>
void Graph<Type>::Show_ShortestPath_Floyd()		
{
	int i, k, j=0, x=0, y=0;
	for (i=1; i<=vexnum; ++i)
	{
		if (i == v0)
		{
			x = vexs[i];
			continue;
		}

		if (i != v1)
			continue;
		else
			y = vexs[i];		
	}
	Out(x, y,vexnum);		//调用Out求解最短路径上所有顶点的标号

	if(Distance[x][y][vexnum]!=INFINITY)		
	{
		strout<<"从顶点"<<x<<"到"<<y<<"的最短路径\r\n"<<"(Floyd-Warshall算法)为："<<"\r\n\r\n";
		strout<<x<<"\r\n";	  //先输出源点
		m_vecPathVertex.push_back(x);		//先将源点加入到m_vecPathVertex里
		for (k=1; k<=res_vexnum; ++k)
		{
			strout<<"-->";
			if (j<= res_vexnum)
			{
				strout<<res_vexs[j]<<"\r\n";
				m_vecPathVertex.push_back(res_vexs[j]);
				j++;
			}
		}
		strout<<"-->"<<y<<"\r\n";



		for (int k = 1; k <= vexnum; k++) {
			for (int i = 1; i <= vexnum; i++) {				//遍历每条边
				for (int j = 1; j <= vexnum; j++) {
					strout << Distance[i][j][k] << " ";
				}
				strout << "\r\n";
			}
			strout << "\r\n";
		}
		for (int k = 1; k <= vexnum; k++) {
			for (int i = 1; i <= vexnum; i++) {				//遍历每条边
				for (int j = 1; j <= vexnum; j++) {
					strout << R[i][j][k] << " ";
				}
				strout << "\r\n";
			}
			strout << "\r\n";
		}

		strout << v0 << y;
		m_vecPathVertex.push_back(y);		//最后将终点加入到m_vecPathVertex里去
		strout<<"\r\n"<<"其最短的路径长度为："<<Distance[x][y][vexnum]<<"\r\n\r\n";
	}   
	else
	{
		strout<<"无法从源点"<<vexs[v0]<<"到达顶点"<<vexs[i]<<"."<<"\r\n";
	}
}

/////////////////////////////////////////////////////////////////////////////
// CShortestPathDlg dialog

CShortestPathDlg::CShortestPathDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShortestPathDlg::IDD, pParent)
	, m_ope(0)
	, m_bLBtnDown(false)
	, m_nSelect(0)
	, m_nEdgeFrom(0)
	, directed(false)	//默认为无向图
{
	//{{AFX_DATA_INIT(CShortestPathDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShortestPathDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShortestPathDlg)
	DDX_Control(pDX, IDC_DRAW, m_staticDraw);
	DDX_Control(pDX, IDC_EDIT_RES, m_editRes);
	DDX_Control(pDX, IDC_EDIT_INFO, m_editInfo);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShortestPathDlg, CDialog)
	//{{AFX_MSG_MAP(CShortestPathDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_VERT, OnButtonVert)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON_MOVE, OnButtonMove)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON_DEL, OnButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_FROM, OnButtonFrom)
	ON_BN_CLICKED(IDC_BUTTON_EDGE, OnButtonEdge)
	ON_BN_CLICKED(IDC_BUTTON_CAL, OnButtonCal)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_EN_CHANGE(IDC_EDIT_INFO, OnChangeEditInfo)
	ON_EN_CHANGE(IDC_EDIT_RES, OnChangeEditRes)
	ON_BN_CLICKED(IDC_RADIO_Directed, OnRADIODirected)
	ON_BN_CLICKED(IDC_RADIO_Undirected, OnRADIOUndirected)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShortestPathDlg message handlers

BOOL CShortestPathDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_editInfo.SetWindowText("无");
	m_staticDraw.GetWindowRect(m_rectDraw);
	m_staticDraw.GetWindowRect(m_rectReDraw);
	
	m_rectReDraw.top -= CVertex::s_size;
	
	m_rectDraw.left += CVertex::s_size;
	m_rectDraw.right -= CVertex::s_size;
	m_rectDraw.bottom -= 3*CVertex::s_size;
	
	((CButton*)GetDlgItem(IDC_RADIO_Floyd))->SetCheck(TRUE);
//	((CButton*)GetDlgItem(IDC_RADIO_Undirected))->SetCheck(TRUE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShortestPathDlg::DrawArrow(CPoint first, CPoint next, COLORREF color)
{
	CClientDC cdc(this);
	CPen fillPen(PS_SOLID, 1, color);
	CPen *oldPen = cdc.SelectObject(&fillPen);
	
	double a=next.x-first.x;
	double b=next.y-first.y;
	double c=sqrt(a*a+b*b);
	double sin=b/c;
	double cos=a/c;
	CPoint chg_first(first.x+10*cos,first.y+10*sin);
	CPoint chg_next(next.x-10*cos,next.y-10*sin);
	cdc.MoveTo(chg_first);
	cdc.LineTo(chg_next);
	if (directed)
	{
		CPoint chg_next1(next.x-20*cos,next.y-20*sin);
		CPoint chg_p11(chg_next1.x+3*sin,chg_next1.y-3*cos);
		CPoint chg_p12(chg_next1.x-3*sin,chg_next1.y+3*cos);
		cdc.MoveTo(chg_next);
		cdc.LineTo(chg_p11);
		cdc.MoveTo(chg_next);
		cdc.LineTo(chg_p12);
	}
	cdc.SelectObject(oldPen);
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShortestPathDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
		CClientDC cdc(this);
		
		// draw vertex
		for( std::vector< CVertex >::iterator i_vertex = m_vecVertex.begin();
		i_vertex != m_vecVertex.end(); ++i_vertex )
		{
			int size = i_vertex->m_size;
			int x = i_vertex->m_x;
			int y = i_vertex->m_y;
			WCHAR wno[8];
			_itow(i_vertex->m_idx, wno, 10);
			
			CBrush fillBrush(i_vertex->m_color);
			CBrush *oldBursh = cdc.SelectObject(&fillBrush);
			cdc.Ellipse(x-size, y-size, x+size, y+size);
			cdc.SelectObject(&oldBursh);
			
			if( i_vertex->m_idx < 10 )
			{
				cdc.TextOut(x-size+7, y-size+4, wno);
			}
			else
			{
				cdc.TextOut(x-size+4, y-size+4, wno);
			}
			
		}
		
		// draw edge
		for( std::vector< CEdge >::iterator i = m_vecEdge.begin();
		i != m_vecEdge.end(); ++i )
		{
			int from = i->m_from;
			int to = i->m_to;
			int weight = i->m_weight;
			
			CVertex *verFrom = PickVertex(from);
			CVertex *verTo = PickVertex(to);
			
			if( verFrom != 0 && verTo != 0 )
			{
				CPoint first;
				first.x = verFrom->m_x;
				first.y = verFrom->m_y;
				
				CPoint next;
				next.x = verTo->m_x;
				next.y = verTo->m_y;
				
				DrawArrow(first, next, i->m_color);
				
				WCHAR wno[8];
				swprintf(wno, L"%d", weight);
				cdc.TextOut((first.x+next.x)/2-4, (first.y+next.y)/2-4, wno);	
			}
		}
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShortestPathDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CShortestPathDlg::OnButtonVert() 
{
	// TODO: Add your control notification handler code here
	m_ope = OPE_VERTEX;
	m_editInfo.SetWindowText("添加顶点");
}

void CShortestPathDlg::OnButtonMove() 
{
	// TODO: Add your control notification handler code here
	m_ope = OPE_MOVE;
	m_editInfo.SetWindowText("移动顶点");
}

void CShortestPathDlg::OnButtonDel() 
{
	// TODO: Add your control notification handler code here
	m_ope = OPE_DEL;
	m_editInfo.SetWindowText("删除顶点");
}

void CShortestPathDlg::OnButtonFrom() 
{
	// TODO: Add your control notification handler code here
	m_ope = OPE_FROM;
	m_editInfo.SetWindowText("选择源点");
}

void CShortestPathDlg::OnButtonEdge() 
{
	// TODO: Add your control notification handler code here
	m_ope = OPE_EDGE;
	m_nEdgeFrom = 0;
	m_editInfo.SetWindowText("添加边");
}

void CShortestPathDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	m_ope = OPE_TO;
	m_editInfo.SetWindowText("选择终点");
}

CVertex *CShortestPathDlg::PickVerSelect()
{
	for( std::vector< CVertex >::iterator i = m_vecVertex.begin();
	i != m_vecVertex.end(); ++i )
	{
		if( m_nSelect == i->m_idx )
		{
			return &(*i);
		}
	}
	return 0;
}

CVertex *CShortestPathDlg::PickVertex(int idx)
{
	for( std::vector< CVertex >::iterator i = m_vecVertex.begin();
	i != m_vecVertex.end(); ++i )
	{
		if( idx == i->m_idx )
		{
			return &(*i);
		}
	}
	return 0;
}

void CShortestPathDlg::ResortVertexIdx()
{
	int idx = 0;
	for( std::vector< CVertex >::iterator i = m_vecVertex.begin();
	i != m_vecVertex.end(); ++i )
	{
		++idx;
		
		for( std::vector< CEdge >::iterator j = m_vecEdge.begin();
		j != m_vecEdge.end(); ++j )
		{
			if( j->m_from == i->m_idx )
			{
				j->m_from = idx;
			}
			if( j->m_to == i->m_idx )
			{
				j->m_to = idx;
			}
		}
		
		i->m_idx = idx;
	}
	
	CVertex::s_idx = idx;
}

void CShortestPathDlg::CasDelEdge(int idx)
{
	std::vector< CEdge >::iterator i = m_vecEdge.begin();
	while( i != m_vecEdge.end() )
	{
		if( i->m_from == idx || i->m_to == idx )
		{
			i = m_vecEdge.erase(i);
		}
		else
		{
			++i;
		}
	}
}

void CShortestPathDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnLButtonDown(nFlags, point);
	if( PtInRect(m_rectDraw, point) )
	{
		if( m_ope == OPE_VERTEX )
		{
			CVertex::s_idx++;

			CVertex ver;
			ver.m_x = point.x;
			ver.m_y = point.y;

			m_vecVertex.push_back(ver);
			
			InvalidateRect(m_rectReDraw,TRUE);
		}
		else if( m_ope == OPE_MOVE )
		{
			if( m_nSelect == 0 )
			{
				for( std::vector< CVertex >::iterator i = m_vecVertex.begin();
					i != m_vecVertex.end(); ++i )
				{
					CRect rect(i->m_x-i->m_size, i->m_y-i->m_size, i->m_x+i->m_size, i->m_y+i->m_size);
					if( rect.PtInRect(point) )
					{
						m_nSelect = i->m_idx;
						break;
					}
					m_nSelect = 0;
				}
			}
			else
			{
				m_nSelect = 0;
			}

		}
		else if( m_ope == OPE_DEL )
		{
			std::vector< CVertex >::iterator pick = m_vecVertex.end();
			for( std::vector< CVertex >::iterator i = m_vecVertex.begin();
				i != m_vecVertex.end(); ++i )
			{
				CRect rect(i->m_x-i->m_size, i->m_y-i->m_size, i->m_x+i->m_size, i->m_y+i->m_size);
				if( rect.PtInRect(point) )
				{
					pick = i;
					break;
				}
			}

			if( pick != m_vecVertex.end() )
			{
				CasDelEdge(pick->m_idx);
				m_vecVertex.erase(pick);

				m_nSelect = 0;
				ResortVertexIdx();

				InvalidateRect(m_rectReDraw,TRUE);
			}
		}
		else if( m_ope == OPE_FROM )
		{
			std::vector< CVertex >::iterator pick = m_vecVertex.end();
			for( std::vector< CVertex >::iterator i = m_vecVertex.begin();
				i != m_vecVertex.end(); ++i )
			{
				CRect rect(i->m_x-i->m_size, i->m_y-i->m_size, i->m_x+i->m_size, i->m_y+i->m_size);
				if( rect.PtInRect(point) )
				{
					pick = i;
				}
			}

			if( pick != m_vecVertex.end() )
			{
				for( std::vector< CVertex >::iterator i = m_vecVertex.begin();
					i != m_vecVertex.end(); ++i )
				{
					if( i->m_bFrom == true )
					{
						i->m_bFrom = false;
						i->m_color = RGB(255,255,255);
					}
				}

				pick->m_bFrom = true;
				pick->m_color = RGB(255,0,0);
				m_nSelect = 0;
				ver_from = pick->m_idx;
				verfrom = pick->m_idx;	//因为循环从0开始

				InvalidateRect(m_rectReDraw,TRUE);
			}
		}
		else if( m_ope == OPE_TO )
		{
			std::vector< CVertex >::iterator pick = m_vecVertex.end();
			for( std::vector< CVertex >::iterator i = m_vecVertex.begin();
				i != m_vecVertex.end(); ++i )
			{
				CRect rect(i->m_x-i->m_size, i->m_y-i->m_size, i->m_x+i->m_size, i->m_y+i->m_size);
				if( rect.PtInRect(point) )
				{
					pick = i;
				}
			}

			if( pick != m_vecVertex.end() )
			{
				for( std::vector< CVertex >::iterator i = m_vecVertex.begin();
					i != m_vecVertex.end(); ++i )
				{
					if( i->m_bTo == true )
					{
						i->m_bTo = false;
						i->m_color = RGB(255,255,255);
					}
				}

				pick->m_bTo = true;
				pick->m_color = RGB(0,0,255);
				m_nSelect = 0;
				ver_to = pick->m_idx;

				InvalidateRect(m_rectReDraw,TRUE);
			}
		}
		else if( m_ope == OPE_EDGE )
		{
			for( std::vector< CVertex >::iterator i = m_vecVertex.begin();
				i != m_vecVertex.end(); ++i )
			{
				CRect rect(i->m_x-i->m_size, i->m_y-i->m_size, i->m_x+i->m_size, i->m_y+i->m_size);
				if( rect.PtInRect(point) )
				{
					if( m_nEdgeFrom == 0 )
					{
						m_nEdgeFrom = i->m_idx;
					}
					else
					{
						if( m_nEdgeFrom == i->m_idx )
						{
							break;
						}

						CDlgInput dlgin;
						dlgin.DoModal();

						int weight = atoi(dlgin.m_wight.GetBuffer(10));

						CEdge edge;
						edge.m_from = m_nEdgeFrom;
						edge.m_to = i->m_idx;
						edge.m_weight = weight;

						if( edge.m_from != 0 && edge.m_to != 0 )
						{
							bool bAdd = true;
							for( std::vector< CEdge >::iterator ite = m_vecEdge.begin();
								ite != m_vecEdge.end(); ++ite )
							{
								if( ite->m_from == edge.m_from && ite->m_to == edge.m_to )
								{
									ite->m_weight = edge.m_weight;
									bAdd = false;
									break;
								}
							}

							if( bAdd )
							{
								m_vecEdge.push_back(edge);
							}

						}

						m_nEdgeFrom = 0;

						InvalidateRect(m_rectReDraw,TRUE);
					}

					break;
				}
			}
		}
	}
}

void CShortestPathDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default	
	CDialog::OnMouseMove(nFlags, point);
	if( PtInRect(m_rectDraw, point) && m_ope == OPE_MOVE && m_nSelect != 0 )
	{
		CVertex *ver = PickVerSelect();
		
		if( ver != 0 )
		{
			ver->m_x = point.x;
			ver->m_y = point.y;
			
			InvalidateRect(m_rectReDraw, TRUE);
		}
		else
		{
			m_nSelect = 0;
		}
		
	}
}

void CShortestPathDlg::OnButtonCal() 
{
	// TODO: Add your control notification handler code here
	int bCal = 0;
	for( std::vector< CVertex >::iterator itv = m_vecVertex.begin();
		itv != m_vecVertex.end(); ++itv )
	{
		if( itv->m_bFrom )
		{
			bCal++;
		}

		if( itv->m_bTo )
		{
			bCal++;
		}
	}

	if( bCal < 2 )
	{
		MessageBox("没有选择源点或终点！","警告");
		return;
	}

	strout.str("");
	ver_cnt = 0;
	m_vecPathVertex.clear();
	Graph <int> G;
	G.Creat_Graph();
	if (((CButton*)GetDlgItem(IDC_RADIO_Floyd))->GetCheck() == 1)
	{
		G.ShortestPath_FLOYD();
		G.Show_ShortestPath_Floyd();

		// clear all edge color
		for( std::vector< CEdge >::iterator ive = m_vecEdge.begin();
			ive != m_vecEdge.end(); ++ive)
		{
			ive->m_color = RGB(0,0,0);
		}

		// set path color
		for( std::vector< int >::iterator ivp = m_vecPathVertex.begin(); 
			ivp != m_vecPathVertex.end(); ++ivp)
		{
			int from = *ivp;

			if( ivp+1 == m_vecPathVertex.end() )
			{
				break;
			}

			int to = *(ivp+1);

			for( std::vector< CEdge >::iterator ive = m_vecEdge.begin();
				ive != m_vecEdge.end(); ++ive)
			{

					if (var_directed)
					{
						if( ive->m_from == from && ive->m_to == to )
						{
							ive->m_color = RGB(0,255,255);
							break;
						}
					}
					else
					{
						if ( ive->m_from == from && ive->m_to == to || ive->m_from == to && ive->m_to == from )
						{
							ive->m_color = RGB(0,255,255);
							break;
						}
					}
			}
		}
	}
	InvalidateRect(m_rectReDraw, TRUE);
	m_editRes.SetWindowText(strout.str().c_str());
}

void CShortestPathDlg::OnChangeEditInfo() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CShortestPathDlg::OnChangeEditRes() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CShortestPathDlg::OnRADIODirected() 
{
	// TODO: Add your control notification handler code here
	directed = true;
	var_directed = true;
}

void CShortestPathDlg::OnRADIOUndirected() 
{
	// TODO: Add your control notification handler code here
	directed = false;
	var_directed = false;
}

void CShortestPathDlg::OnButtonClear() 
{
}
