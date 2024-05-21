#pragma once
class CEdge
{
public:
	CEdge(void);
	~CEdge(void);

	int m_from, m_to;
	COLORREF m_color;
	int m_weight;
};
