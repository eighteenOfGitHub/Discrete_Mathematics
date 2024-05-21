#include "StdAfx.h"
#include "Vertex.h"

int CVertex::s_idx = 0;
int CVertex::s_size = 12;

CVertex::CVertex(void)
{
	m_bShow = true;
	m_bFrom = false;
	m_bTo = false;
	m_color = RGB(255,255,255);
	m_size = s_size;
	m_idx = s_idx;
}


CVertex::~CVertex(void)
{
}
