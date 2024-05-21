#include "StdAfx.h"
#include "Edge.h"


CEdge::CEdge(void)
{
	m_from = 0;
	m_to = 0;
	m_weight = 0;
	m_color = RGB(0,0,0);
}


CEdge::~CEdge(void)
{
}