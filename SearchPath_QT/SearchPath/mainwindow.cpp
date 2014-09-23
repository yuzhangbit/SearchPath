#include "mainwindow.h"
#include <QtWidgets/QMessageBox>
#include <QtGui>
#include <QtCore>
#include <QDesktopWidget>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost;


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	label = new QLabel;

	


	setWindowTitle(tr("Search Path"));
	setWindowIcon(QIcon("myApp.ico"));
		
	ui.menuBar->setVisible(true);
	
	m_threadSearch.m_pMainWindow = this ;

	ui.statusBar->setVisible(false);

	ui.statusBar->showMessage(tr("ready"));
	



	
	
	
	
	m_Zoom = 1 ;
	m_ptSrc.setX(2);
	m_ptSrc.setY(2);
	m_ptDst.setX(1);
	m_ptDst.setY(1);

	//获取本应用程序的路径 
	QString strAppDirPath = QCoreApplication::applicationDirPath();
	
	//加载默认地图
	//QString strDefaultMapPath = strAppDirPath + tr("/DefaultMap.sp");

	QString strDefaultMapPath = tr("DefaultMap.sp");
	

	LoadMap(strDefaultMapPath);

	// 设置窗口出现在屏幕中央
	move ((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);


	// 显示地图信息
	ShowMapInfo() ;

	Render() ;

	
		
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_btnStart_clicked()
{
	m_threadSearch.start();
}

void MainWindow::on_chkShowAllPath_toggled( bool checked )
{
	QMessageBox::information(this,"title","show path");
	Render();
}

void MainWindow::on_actionQuit_triggered()
{
	QApplication::quit();
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionOpen_triggered()
{

}

void MainWindow::on_actionResetStart_triggered( bool checked )
{
	if( checked == true)
	{
		ui.actionResetStart->setChecked(true);
		ui.actionResetDes->setChecked(false);
		ui.actionAddObstacle->setChecked(false);
		ui.actionRemoveObs->setChecked(false);
	}
}

void MainWindow::on_actionResetDestination_triggered( bool checked )
{
	if(checked == true)
	{
		ui.actionResetStart->setChecked(false);
		ui.actionResetDes->setChecked(true);
		ui.actionAddObstacle->setChecked(false);
		ui.actionRemoveObs->setChecked(false);
	}
}

void MainWindow::on_actionAddObs_triggered( bool checked )
{
	if (checked == true)
	{
		ui.actionResetStart->setChecked(false);
		ui.actionResetDes->setChecked(false);
		ui.actionAddObstacle->setChecked(true);
		ui.actionRemoveObs->setChecked(false);
	}
}

void MainWindow::on_actionDelObs_triggered( bool checked )
{
	if (checked == true)
	{
		ui.actionResetStart->setChecked(false);
		ui.actionResetDes->setChecked(false);
		ui.actionAddObstacle->setChecked(false);
		ui.actionRemoveObs->setChecked(true);
	}
}

void MainWindow::on_actionSearchOrder_triggered( bool checked )
{
	if (checked)
	{
		ui.actionPathLength->setChecked(false);
	}
	Render();
}

void MainWindow::on_actionNew_triggered()
{

}

void MainWindow::on_actionClearPath_triggered()
{
	m_Searcher.ClearResult();
	Render();
	//on Render
}

void MainWindow::on_actionAbout_triggered()
{

}

void MainWindow::on_actionPathLength_triggered( bool checked )
{
	if (checked)
	{
		ui.actionSearchOrder->setChecked(false);
	}
	Render();
}

void MainWindow::on_actionEnlargement_triggered()
{

}

void MainWindow::on_actionReduction_triggered()
{

}

void MainWindow::on_actionZoom100_triggered()
{

}

void MainWindow::paintEvent( QPaintEvent * )
{
	
	
	QPainter Painter(this);
	QRect rectTarget;
	rectTarget.setRect(0,0,
		m_Pixmap.width() * m_Zoom,
		m_Pixmap.height() * m_Zoom);
	Painter.drawPixmap(rectTarget, m_Pixmap);
	//ui.label->setPixmap(m_Pixmap);


	

	
}

void MainWindow::mousePressEvent( QMouseEvent * event)
{
	const size_t nMapWidth = m_Map.GetWidth();
	const size_t nMapHeight = m_Map.GetHeight();

	if (event->button() & Qt::LeftButton)
	{
		// left botton of mouse 
		QPoint pt(event->x() /(SquareSize * m_Zoom),
			event->y() / (SquareSize * m_Zoom));
		if( pt.x() >= nMapWidth || pt.y() >= nMapHeight)
		{
			// mouse is outside of the map
			return;
			
		}
		bool bOperation = true;

		//重设起点
		if (ui.actionResetStart->isChecked())
		{
			if(m_Map[pt.y()][pt.x()] == 1)
				return;
			m_ptSrc = pt;
			m_Searcher.ClearResult();

		}
		//重设目的点
		else if (ui.actionResetDes->isChecked())
		{
			if (m_Map[pt.y()][pt.x()] == 1)
			{
				return;
			}
			m_ptDst = pt;
			m_Searcher.ClearResult();

		}
		//增加障碍物
		else if(ui.actionAddObstacle->isChecked())
		{
			m_Map[pt.y()][pt.x()] = 1;
			m_Searcher.ClearResult();
		}

		//删除障碍物
		else if(ui.actionRemoveObs->isChecked())
		{
			if (pt.x() == 0 || pt.x() >= nMapWidth -1 ||
				pt.y() == 0 || pt.y() >= nMapHeight -1)
			{
				return;
			}
			m_Map[pt.y()][pt.x()] = 0;
			m_Searcher.ClearResult();
		}
		else
		{
			bOperation = false;

		}
		if(bOperation)
		{
			ui.statusBar->showMessage(tr("操作已完成"));
		}
		Render();
	}
	else if (event->button() & Qt::RightButton)
	{
		//右键菜单
		
	}
}

void MainWindow::wheelEvent( QWheelEvent *event )
{

}

void MainWindow::StartSearch()
{
	timer timer;
	bool bRet = false;
	m_Searcher.Heuristic(m_Map, m_ptSrc, m_ptDst);

	//状态栏显示
	QString strInfo;
	int nElapsed = int(timer.elapsed()*1000);
	QString strElapsed;
	QString strTemp = QString("%1").arg(strElapsed);

	label->setText(strInfo);

	Render();
	
}

void MainWindow::ShowMapInfo()
{
	// 设置窗口标题 
	QString strTitle = QString(tr("search path test- map size: %1 x %2  scaling: %3%")).arg(m_Map.GetWidth()).arg(m_Map.GetHeight()).arg(m_Zoom*100);
	setWindowTitle(strTitle);
}

bool MainWindow::LoadMap( const QString & stringFilePath )
{
	QFile File(stringFilePath);
	if (File.open(QIODevice::ReadOnly) == false)
	{
		return false;
	}
	uint nLen;
	char *pData = NULL;
	QDataStream in(&File);

	nLen = File.size();
	in.readBytes(pData, nLen);

	vector<string> Lines, strs2;
	split(Lines, pData, is_any_of("\n"));
	delete []pData;

	split(strs2, Lines[0], is_any_of(","));
	
	//读取地图
	size_t nWidth = ::atoi(strs2[0].c_str());
	size_t nHeight = ::atoi(strs2[1].c_str());
	m_Map.Resize(nWidth, nHeight);
	split(strs2, Lines[1], is_any_of(","));
	size_t nCounter = 0;
	for (size_t row = 0;row<m_Map.GetHeight(); ++row)
	{
		for (size_t col = 0; col<m_Map.GetWidth(); ++col)
		{
			m_Map[row][col] = ::atoi(strs2[nCounter].c_str());
			++nCounter;

		}
	}
	split(strs2, Lines[2], is_any_of(","));
	m_ptSrc.setX(::atoi(strs2[0].c_str()));
	m_ptSrc.setY(::atoi(strs2[1].c_str()));
	
	split(strs2, Lines[3], is_any_of(","));
	m_ptSrc.setX(::atoi(strs2[0].c_str()));
	m_ptSrc.setY(::atoi(strs2[1].c_str()));


	//读入缩放信息
	m_Zoom = ::atof(Lines[4].c_str());
	
	return true;

	
	

}

void MainWindow::InitMap( Map_t &Map, size_t nWidth, size_t nHeight )
{
	for (size_t i = 0; i<nWidth; ++i)
	{
		Map[0][i] = 1;
		Map[nHeight-1][i] = 1;
		
	}
	for(size_t i=1; i<nHeight-1; ++i)
	{
		Map[i][0]=1;
		Map[i][nWidth -1] =1;
	}
	for(size_t i=1; i<nHeight-1; ++i)
	{
		for(size_t j=1; j<nWidth-1;++j)
		{
			Map[i][j] = 0;
		}
	}
}

void MainWindow::Render()
{
	Render( m_Map , m_Searcher ) ;
}

void MainWindow::Render( const Map_t &Map, const CSearcher &Searcher )
{

	const size_t nMapWidth = Map.GetWidth() ;
	const size_t nMapHeight = Map.GetHeight() ;

	m_Pixmap= QPixmap( nMapWidth * SquareSize , nMapHeight * SquareSize ) ;

	QPainter Painter( &m_Pixmap ) ;

	// 取得计算结果
	const vector< Sp_Point_t > &Points = Searcher.m_Points ;
	unordered_map< Sp_Point_t , Sp_Point_t > Parents = Searcher.m_Parents ;
	unordered_map< Sp_Point_t , size_t > Distances = Searcher.m_Distances ;
	unordered_map< Sp_Point_t , size_t > VisitOrders = Searcher.m_VisitOrders ;


	QRect rectTarget ;
	QRect rectTargetTemp ;

	// 画整个背景
	Painter.setBrush( QBrush( Qt::darkGray ) );
	Painter.drawRect( 0 , 0 , width() , height() );

	Painter.setPen( Qt::green );

	// 画地图背景
	rectTargetTemp.setRect( 0 , 0 , nMapWidth * SquareSize , nMapHeight * SquareSize );
	QPixmap barrier( tr( "Resources/Images/thoroughfare.png" ) ) ;
	Painter.drawPixmap( rectTargetTemp , barrier );

	// 画地图
	for( size_t i = 0 ; i < nMapHeight ; ++i )
	{
		for( size_t j = 0 ; j < nMapWidth ; ++j )
		{
			QRect target( j * SquareSize , i * SquareSize , SquareSize , SquareSize ) ;
			int n = Map[ i ][ j ] ;
			if( n == 1 )
			{
				QPixmap barrier( tr( "Resources/Images/barrier.png" ) ) ;
				Painter.drawPixmap( target , barrier );
				// Painter.setBrush( Qt::black );
			}
		}
	}

	// 画起点
	QPixmap start( tr( "Resources/Images/start.png" ) ) ;
	rectTarget.setRect( m_ptSrc.x() * SquareSize , m_ptSrc.y() * SquareSize , SquareSize , SquareSize ) ;
	Painter.drawPixmap( rectTarget , start );

	// 终点
	QPixmap destination( tr( "Resources/Images/destination.png" ) ) ;
	rectTarget.setRect( m_ptDst.x() * SquareSize , m_ptDst.y() * SquareSize , SquareSize , SquareSize );
	Painter.drawPixmap( rectTarget , destination );


	// 画到达目的地的路径
	if( m_Searcher.m_ptDst != 0 )
	{
		QPen Pen( QColor( 255 , 255 , 255 , 100 ) , 10 ) ;
		Painter.setPen( Pen );
		std::shared_ptr< QPoint > pt2 ;
		for(  std::shared_ptr< QPoint > pt = Searcher.m_ptDst , pt2 = Parents[ pt ] ;
			pt2 != pt ;
			pt = pt2 , pt2 = Parents[ pt ]
		)
		{
			Painter.drawLine( pt->x() * SquareSize + SquareSize / 2,
				pt->y() * SquareSize + SquareSize / 2 ,
				pt2->x() * SquareSize + SquareSize / 2,
				pt2->y() * SquareSize + SquareSize / 2
				);
		}
	}


	//  画路径树
	if( ui.actionSearchOrder->isChecked() == true ||
		ui.actionPathLength->isChecked() )
	{
		unordered_map< Sp_Point_t , size_t > *pNumMap = 0 ;
		if( ui.actionPathLength->isChecked() )
		{
			pNumMap = &Distances ;
		}
		else if( ui.actionSearchOrder->isChecked() )
		{
			pNumMap = &VisitOrders ;
		}

		// 画所有经过的路径
		int nCounter= 0 ;
		Painter.setPen( Qt::blue );
		Painter.setBrush( Qt::red );

		for( BOOST_AUTO( it , Parents.begin() ) ; it != Parents.end() ; ++it )
		{
			// Painter.drawRect( Path[ i ]->x() * 20 , Path[ i ]->y() * 20 , 20 , 20 );

			std::shared_ptr< QPoint > pt1 = it->first ;
			std::shared_ptr< QPoint > pt2 = it->second ;

			// QPen Pen( Qt::lightGray , 2 ) ;
			QPen Pen( QColor( 255 , 255 , 255 , 150 ), 2 ) ;
			Painter.setPen( Pen );
			Painter.drawLine( pt1->x() * SquareSize + SquareSize / 2 ,
				pt1->y() * SquareSize + SquareSize / 2 ,
				pt2->x() * SquareSize + SquareSize / 2,
				pt2->y() * SquareSize + SquareSize / 2
				);

			// 画路径长度 或是 访问顺序
			Painter.setPen( Qt::yellow );
			format fmt( "%d") ;
			fmt.bind_arg( 1 , (*pNumMap)[ pt1 ] ) ;
			Painter.drawText( pt1->x() * SquareSize + SquareSize / 2 ,
				pt1->y() * SquareSize + SquareSize - SquareSize / 2 ,
				fmt.str().c_str() );

		}
	}


	

	this->update();
}






