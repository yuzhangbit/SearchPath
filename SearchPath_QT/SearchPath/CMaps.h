#pragma once

#include <QtCore/QPoint>


#include <vector>
using namespace std;

//地图外默认是障碍物

class CMaps
{
public:
	CMaps(void);
	~CMaps(void);

public:


	vector< vector<size_t>> m_Map;
	

	// 起点
	QPoint m_ptSrc;
	// 终点
	QPoint m_ptDst;

	vector< size_t >& operator[] (size_t nRow);
	const vector< size_t >& operator[] (size_t nRow) const;


	size_t GetWidth() const;
	size_t GetHeight() const;
	

public:
	void Resize(size_t nWidth, size_t nHeight);
	void Clear();
private:
	size_t m_nWidth;
	size_t m_nHeight;
	
	



};

