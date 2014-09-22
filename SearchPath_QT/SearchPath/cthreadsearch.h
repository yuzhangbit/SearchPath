#ifndef CTHREADSEARCH_H
#define CTHREADSEARCH_H

#include <QThread>
#include <QMutex>

class MainWindow;


class CThreadSearch : public QThread
{
	Q_OBJECT

public:
	explicit CThreadSearch(QObject *parent = 0);
	~CThreadSearch();



public:
	MainWindow *m_pMainWindow;
	
	QMutex m_Mutex;

private:
	int m_Seed;
	void run();

	
	
};

#endif // CTHREADSEARCH_H
