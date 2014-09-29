#ifndef COLLIDINGMICE_H
#define COLLIDINGMICE_H

#include <QtWidgets/QWidget>
#include "ui_collidingmice.h"

class collidingmice : public QWidget
{
	Q_OBJECT

public:
	collidingmice(QWidget *parent = 0);
	~collidingmice();

private:
	Ui::collidingmiceClass ui;
};

#endif // COLLIDINGMICE_H
