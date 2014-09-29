#pragma once

#include <QtWidgets/QGraphicsItem>

class Mouse :
	public QGraphicsItem
{
public:
	Mouse(void);
	~Mouse(void);

public:
	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
				QWidget *widget);

protected:
	void advance(int step);
	
private:
	qreal angle;
	qreal speed;
	qreal mouseEyeDirection;
	QColor color;
};

