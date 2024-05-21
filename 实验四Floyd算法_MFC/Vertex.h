#pragma once
class CVertex
{
public:
	CVertex(void);
	~CVertex(void);

	static int s_idx;
	static int s_size;

	int m_x, m_y, m_size;
	COLORREF m_color; 
	int m_idx;
	bool m_bShow;
	bool m_bFrom;
	bool m_bTo;
};
