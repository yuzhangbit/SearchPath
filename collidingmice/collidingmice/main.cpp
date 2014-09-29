#include "collidingmice.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsView>
#include <QtGui>

#include <math.h>
#include "Mouse.h"

static const int MouseCount = 7;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	/*collidingmice w;
	w.show();*/

	qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

	QGraphicsScene scene;
	scene.setSceneRect(-300, -300, 600, 600);
	scene.setItemIndexMethod(QGraphicsScene::NoIndex);
	for (int i = 0; i<MouseCount; ++i)
	{
		Mouse *mouse = new Mouse;
		mouse->setPos(::sin((i*6.28) / MouseCount)*200,
					  ::cos((i*6.28) / MouseCount)*200);
		scene.addItem(mouse);
	}

	QGraphicsView view(&scene);
	view.setRenderHint(QPainter::Antialiasing);
	view.setBackgroundBrush(QPixmap("Resources/cheese.jpg"));
	view.setCacheMode(QGraphicsView::CacheBackground);
	view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	view.setDragMode(QGraphicsView::ScrollHandDrag);
	view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Colliding Mice"));
	view.resize(400, 300);
	view.show();

	QTimer timer;
	QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
	timer.start(1000/33);



	return a.exec();
}
