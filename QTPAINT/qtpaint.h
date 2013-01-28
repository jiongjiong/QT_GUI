#ifndef QTPAINT_H
#define QTPAINT_H

#include <QtGui/QWidget>
#include "ui_qtpaint.h"
#include <qevent.h> 


class QTPAINT : public QWidget
{
	Q_OBJECT

public:
	QTPAINT(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QTPAINT();
	void paintEvent(QPaintEvent *e) ;

	void  draw(QPainter *painter);

	void drawtowercrane(QPainter *painter,int Ox,int Oy,int r,int angle,int length,int flag);




protected:

	void timerEvent( QTimerEvent *event );

private:
	int angle;
	int length;
	int m_TimerId;
	int angle2,length2;
	int angle3,length3;
//private slots:
//		void mousePressEvent(QMouseEvent *event);
//		void mouseMoveEvent(QMouseEvent *);
//		void mouseReleaseEvent(QMouseEvent *);
//private:
//	QPixmap pix;
//	QPoint lastPoint;
//	QPoint endPoint;
//	QPixmap tempPix; //临时画布
//	bool isDrawing;   //标志是否正在绘图

private:
	Ui::QTPAINTClass ui;
};

#endif // QTPAINT_H
