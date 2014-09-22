#include "CMaps.h"


CMaps::CMaps(void)
{
	m_nHeight = 0;
	m_nWidth = 0;
}


CMaps::~CMaps(void)
{
}

void CMaps::Resize( size_t MapWidth, size_t MapHeight )
{
	m_Map.clear();

	m_nWidth = MapWidth;
	m_nHeight= MapHeight;

	for ( size_t row = 0; row < MapHeight; ++row)
	{
		m_Map.push_back(vector<size_t >(MapWidth, 0));
		
	}

	for (size_t i=0; i<MapWidth; ++i)
	{
		m_Map[0][i] = 1;
		m_Map[MapHeight - 1][i] = 1;
	}

	for( size_t i = 1 ; i < MapHeight - 1 ; ++i )
	{
		m_Map[ i ][ 0 ] = 1 ;
		m_Map[ i ][ MapWidth - 1 ] = 1 ;
	}


	for(size_t i = 1; i < MapHeight - 1; ++i)
	{
		for(size_t j = 1;  j<MapWidth -1; ++j)
		{
			m_Map[i][j] = 0;
		}
	}

}

void CMaps::Clear()
{
	Resize(m_nWidth, m_nHeight);
}

vector< size_t >& CMaps::operator[]( size_t nRow )
{
	return m_Map[nRow];
}

const vector< size_t >& CMaps::operator[]( size_t nRow ) const
{
	return m_Map[ nRow ];
}

size_t CMaps::GetWidth() const
{
	return m_nWidth;
}

size_t CMaps::GetHeight() const
{
	return m_nHeight;
}
