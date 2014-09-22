#pragma once

#include <QtCore/QPoint>
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/format.hpp>
using namespace boost;

#include <deque>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <map>
using namespace std;

#include "Map.h"
#define Infinity 0xFFFFFF

typedef std::shared_ptr< QPoint > Sp_Point_t;


class CSearcher
{
public:
	CSearcher(void);
	~CSearcher(void);

private:
	struct Edge
	{
		// 源顶点 
		Sp_Point_t Pt1;
		// 目的顶点
		Sp_Point_t Pt2;
		// 边数据
		size_t Data;

		Edge(const Sp_Point_t &p1, const Sp_Point_t &p2, size_t Data)
		{
			Pt1 = p1;
			Pt2 = p2;
			this->Data = Data;
		}
	};


public:
	//搜过的顶点的集合
	vector<Sp_Point_t> m_Points;
	
	//接过的顶点的前驱顶点的集合
	unordered_map<Sp_Point_t, Sp_Point_t> m_Parents;
	
	//在最短路径搜索算法中， 用作“最短路径”估计
	//盲目搜索算法中，用作“距离”
	unordered_map<Sp_Point_t, size_t> m_Distances;

	//顶点的访问顺序序号
	unordered_map<Sp_Point_t, size_t> m_VisitOrders;
	
	//目的顶点对象
	Sp_Point_t m_ptDst;
	
	//清除结果
	inline void ClearResult();

public:
	void Heuristic(Map_t &Map, const QPoint &ptSrc, const QPoint &ptDst);
	void Dijkstra(const Map_t &Map, const QPoint &ptSrc, const QPoint &ptDst);


private:
	inline static string ToString(const QPoint &pt);
	inline static string ToString(const std::shared_ptr<QPoint> &pt);

	//取得指定顶点的所有邻居顶点
	inline static vector<Sp_Point_t> GetAdjacentVertexes(Map_t Map, unordered_set<string> &Visited, const Sp_Point_t &pt);

	//创建图
	//vertexes 图顶点的集合
	//Edges 图边的集合
	inline void CreateGraph(const Map_t &Map, unordered_map<string, Sp_Point_t> &Vertexes, unordered_map<string, size_t> &Edges);
	inline void CreateGraph(const Map_t &Map, unordered_map<string, Sp_Point_t> &Vertexes, vector<Edge> &Edges);

	//邻接表 图边数据类型
	typedef pair< Sp_Point_t, size_t> AdjEdge_t;
	//邻接表，图顶点数据类型
	typedef pair< Sp_Point_t, vector<AdjEdge_t>> AdjVertex_t;

	inline void CreateGraph(const Map_t &Map, unordered_map<Sp_Point_t, AdjVertex_t> &Graph);

	//初始化单源最短路径搜索

	inline void InitSingleSource( const unordered_map<string, Sp_Point_t> &Vertexes,
		const QPoint &ptSrc,
		unordered_map< Sp_Point_t, size_t> &ShortestPath,
		unordered_map< Sp_Point_t, Sp_Point_t> &Parents);
	inline void InitSingleSource( const unordered_map<string, Sp_Point_t> &Vertexes,
		const Sp_Point_t &ptSrc,
		unordered_map<Sp_Point_t, size_t> &ShortestPath,
		unordered_map<Sp_Point_t,Sp_Point_t> &Parents);
	inline void Relax(const Sp_Point_t &Pt1,
		const Sp_Point_t & Pt2,
		const int nWeight,
		unordered_map<Sp_Point_t, size_t> &ShortestPath, 
		unordered_map<Sp_Point_t, Sp_Point_t> &Parents);
	
	float GetDistance(const QPoint &pt1, const QPoint &pt2);
	
private:
	size_t m_nCounter;
	size_t m_nMapWidth;
	size_t m_nMapHeight;


	
};

