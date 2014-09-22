#include "Searcher.h"


CSearcher::CSearcher(void)
{
}


CSearcher::~CSearcher(void)
{
}

void CSearcher::ClearResult()
{
	m_nCounter = 0;
	m_Parents.clear();
	m_Points.clear();
	m_Distances.clear();
	m_VisitOrders.clear();
	m_ptDst.reset();
	
}

std::string CSearcher::ToString( const QPoint &pt )
{
	format fmt("%d#%d");
	fmt.bind_arg(1, pt.x());
	fmt.bind_arg(2, pt.y());
	return fmt.str();
}

std::string CSearcher::ToString( const std::shared_ptr<QPoint> &pt )
{
	format fmt("%d#%d");
	fmt.bind_arg(1, pt.get()->x());
	fmt.bind_arg(2, pt.get()->y());
	return fmt.str();
}

vector<Sp_Point_t> CSearcher::GetAdjacentVertexes( Map_t Map, unordered_set<string> &Visited, const Sp_Point_t &pt )
{
	vector<Sp_Point_t> AdjacentVertexes;

	//获取8连接相邻顶点

	//上
	Sp_Point_t ptTest = std::make_shared<QPoint>(pt->x(),pt->y()-1);
	if (Map[ptTest->y()][ptTest->x()] == 0 &&
		Visited.find(ToString(ptTest)) == Visited.end())
	{
		AdjacentVertexes.push_back(ptTest);
	}
	//右上
	ptTest = std::make_shared<QPoint>(pt->x() +1, pt->y()-1);
	if (Map[ptTest->y()][ptTest->x()] == 0 &&
		Visited.find(ToString(ptTest)) == Visited.end())
	{
		AdjacentVertexes.push_back(ptTest);
	}
	// 右
	ptTest = std::make_shared<QPoint>(pt->x() +1, pt->y());
	if (Map[ptTest->y()][ptTest->x()] == 0 &&
		Visited.find(ToString(ptTest)) == Visited.end())
	{
		AdjacentVertexes.push_back(ptTest);
	}

	//右下
	ptTest = std::make_shared<QPoint>(pt->x() +1, pt->y()+1);
	if (Map[ptTest->y()][ptTest->x()] == 0 &&
		Visited.find(ToString(ptTest)) == Visited.end())
	{
		AdjacentVertexes.push_back(ptTest);
	}
	//下 
	ptTest = std::make_shared<QPoint>(pt->x(), pt->y()+1);
	if (Map[ptTest->y()][ptTest->x()] == 0 &&
		Visited.find(ToString(ptTest)) == Visited.end())
	{
		AdjacentVertexes.push_back(ptTest);
	}

	//左下
	ptTest = std::make_shared<QPoint>(pt->x() -1, pt->y()+1);
	if (Map[ptTest->y()][ptTest->x()] == 0 &&
		Visited.find(ToString(ptTest)) == Visited.end())
	{
		AdjacentVertexes.push_back(ptTest);
	}

	//左
	ptTest = std::make_shared<QPoint>(pt->x() -1, pt->y());
	if (Map[ptTest->y()][ptTest->x()] == 0 &&
		Visited.find(ToString(ptTest)) == Visited.end())
	{
		AdjacentVertexes.push_back(ptTest);
	}
	//左上
	ptTest = std::make_shared<QPoint>(pt->x() -1, pt->y()-1);
	if (Map[ptTest->y()][ptTest->x()] == 0 &&
		Visited.find(ToString(ptTest)) == Visited.end())
	{
		AdjacentVertexes.push_back(ptTest);
	}

	return AdjacentVertexes;
	
}

void CSearcher::CreateGraph( const Map_t &Map, 
							unordered_map<string, Sp_Point_t> &Vertexes, 
							unordered_map<string, size_t> &Edges )
{

}

void CSearcher::CreateGraph( const Map_t &Map, 
							unordered_map<string, Sp_Point_t> &Vertexes, 
							vector<Edge> &Edges )
{

}

void CSearcher::CreateGraph( const Map_t &Map, 
							unordered_map<Sp_Point_t, AdjVertex_t> &Graph )
{

}

void CSearcher::InitSingleSource( const unordered_map<string, Sp_Point_t> &Vertexes, 
								 const QPoint &ptSrc, 
								 unordered_map< Sp_Point_t, size_t> &ShortestPath, 
								 unordered_map< Sp_Point_t, Sp_Point_t> &Parents )
{
	Sp_Point_t pS = Vertexes.find( ToString( ptSrc ) )->second ;

	for( BOOST_AUTO( it , Vertexes.begin() ) ; it != Vertexes.end() ; ++it )
	{
		ShortestPath[ it->second ] = Infinity ;
	}
	ShortestPath[ pS ] = 0 ;
	Parents[ pS ] = pS ;
}

void CSearcher::InitSingleSource( const unordered_map<string, Sp_Point_t> &Vertexes, 
								 const Sp_Point_t &ptSrc, 
								 unordered_map<Sp_Point_t, size_t> &ShortestPath, 
								 unordered_map<Sp_Point_t,Sp_Point_t> &Parents )
{
	for (BOOST_AUTO(it, Vertexes.begin()); it != Vertexes.end(); ++it)
	{
		ShortestPath[ it->second ] = Infinity;

	}
	ShortestPath[ptSrc] = 0;
	Parents[ptSrc] = ptSrc;
	
}

void CSearcher::Relax( const Sp_Point_t &Pt1, const Sp_Point_t & Pt2, const int nWeight, unordered_map<Sp_Point_t, size_t> &ShortestPath, unordered_map<Sp_Point_t, Sp_Point_t> &Parents )
{
	unordered_map<Sp_Point_t , size_t>::iterator it1 = ShortestPath.find(Pt1);
	unordered_map<Sp_Point_t , size_t>::iterator it2 = ShortestPath.find(Pt2);

	size_t nTest = it1->second + nWeight;

	//song chi 
	if (it2->second > nTest)
	{
		it2->second = nTest;
		Parents[Pt2] = Pt1;
	}

}

float CSearcher::GetDistance( const QPoint &pt1, const QPoint &pt2 )
{
	int x = pt1.x() - pt2.x();
	int y = pt1.y() - pt2.y();

	return sqrt((float)(x*x + y*y));
}

void CSearcher::Heuristic( Map_t &Map, const QPoint &ptSrc, const QPoint &ptDst )
{
	ClearResult();
	size_t nCounter = 0;
	Sp_Point_t pt = std::make_shared<QPoint>(ptSrc);

	unordered_set<string> Visited;
	
	deque<Sp_Point_t> Deque;

	//入工作栈
	Deque.push_back(pt);
	//记录当前顶点的前驱顶点
	m_Parents[pt] = pt;

	//设置访问标记
	Visited.insert(ToString(pt));
	
	//访问顶点
	m_VisitOrders[pt] = nCounter++;
    if (*pt == ptDst)
    {
		m_ptDst = pt;
		return;
    }

	for (; Deque.size()>0;)
	{
		// 从OPEN 表选择一个节点
		Sp_Point_t ptCurrent;
		BOOST_AUTO(itPos, Deque.begin());
		float Min = GetDistance(*(*itPos), ptDst);
		for (BOOST_AUTO(it, Deque.begin());it!= Deque.end(); ++it)
		{
			float nD = GetDistance(*(*it), ptDst);
			if(Min > nD)
			{
				Min = nD;
				itPos = it;
				
			}
		}
		ptCurrent = *itPos;
		Deque.erase(itPos);

		//取得指定顶点的所有邻居顶点
		vector<Sp_Point_t> AdjacentVertexes = GetAdjacentVertexes(Map, Visited, ptCurrent);

		for (BOOST_AUTO(it, AdjacentVertexes.begin()); it != AdjacentVertexes.end(); ++it)
		{
			Sp_Point_t pt = *it;
			//入工作栈
			Deque.push_back(pt);
			//设置访问标记 
			Visited.insert(ToString(pt));
			//记录当前顶点的前驱顶点
			m_Parents[pt] = ptCurrent;
			//记录距离值

			//距离值不正确
			m_Distances[pt] = m_Distances[ptCurrent]+1;
			//把当前顶点加放访问路径序列
			m_Points.push_back(pt);

			// 访问顶点
			m_VisitOrders[pt] = nCounter++;
			if(*pt == ptDst)
			{
				m_ptDst = pt;
				return;
			}
			
		}
		


	}


	
	
}

void CSearcher::Dijkstra( const Map_t &Map, const QPoint &ptSrc, const QPoint &ptDst )
{

}
