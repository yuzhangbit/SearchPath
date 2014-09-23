#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <QtCore/QPoint>

#include <boost/timer.hpp>
#include <QtGui/QPaintEvent>
#include <QtGui/QMouseEvent>
#include <QtGui/QWheelEvent>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QVBoxLayout>
#include <QtGui/QPainter>
#include <QtWidgets/QLabel>

#include "Map.h"
#include "CMaps.h"
#include "cthreadsearch.h"
#include "Searcher.h"

using namespace boost;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;
	QWidget *test;

private slots:
	void on_btnStart_clicked();
	void on_chkShowAllPath_toggled(bool checked);
	void on_actionQuit_triggered();
	void on_actionSave_triggered();
	void on_actionOpen_triggered();
	void on_actionResetStart_triggered(bool checked);
	void on_actionResetDestination_triggered(bool checked);
	void on_actionAddObs_triggered(bool checked);
	void on_actionDelObs_triggered(bool checked);
	void on_actionSearchOrder_triggered(bool checked);
	void on_actionNew_triggered();
	void on_actionClearPath_triggered();
	void on_actionAbout_triggered();
	void on_actionPathLength_triggered(bool checked);
	void on_actionEnlargement_triggered();
	void on_actionReduction_triggered();
	void on_actionZoom100_triggered();
	void wheelEvent(QWheelEvent *event);

public:


	void StartSearch();

private:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
    
	

private:

	void ShowMapInfo();
	bool LoadMap(const QString & strFilePath);
	void InitMap( Map_t &Map, size_t nWidth, size_t nHeight);
	void Render();
	void Render(const Map_t &Map, const CSearcher &Searcher);

	
	
#define SquareSize 25
	float m_Zoom;
	QPoint m_ptSrc;
	QPoint m_ptDst;
	QMutex m_Mutex;

	Map_t m_Map;
	CThreadSearch m_threadSearch;
	CSearcher m_Searcher ;
	
	QVBoxLayout *BoxLayout;
	QLabel *label;
	



	

private:
	// ¿Î∆¡Õº–Œ∂‘œÛ
	QPixmap m_Pixmap;



};

#endif // MAINWINDOW_H
