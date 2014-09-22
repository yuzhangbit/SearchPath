#include "cthreadsearch.h"
#include "mainwindow.h"

CThreadSearch::CThreadSearch(QObject *parent)
	: QThread(parent)
{
	m_pMainWindow = NULL;
	m_Seed = rand();
	
}

CThreadSearch::~CThreadSearch()
{

}

void CThreadSearch::run()
{
	::srand( ++m_Seed);
	m_Mutex.lock();
	m_pMainWindow->StartSearch();
	m_Mutex.unlock();

}
