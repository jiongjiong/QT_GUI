#include "qtpaint.h"
#include <QPainter>
QTPAINT::QTPAINT(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
	,angle(0)
	,length(0)
	,m_TimerId(0)
	,angle2(2)
	,length2(2)
	,angle3(3)
	,length3(3)

{
	ui.setupUi(this);
	//resize(600,500);    //���ڴ�С����Ϊ600*500
	//pix = QPixmap(200,200);
	//pix.fill(Qt::white);
	//isDrawing = false;

	m_TimerId = startTimer(100);


}

QTPAINT::~QTPAINT()
{

}

void QTPAINT::paintEvent(QPaintEvent *)
{ 

	QPainter painter(this);

	painter.setRenderHint(QPainter::Antialiasing,true);
	painter.setViewport(10,34,400,400);
	painter.setWindow(-100,-100,400,400);
	draw(&painter);
}
void QTPAINT::draw(QPainter *painter)
{
	/*����������ɫ*/ 
	painter->setPen(Qt::NoPen); 
	painter->setBrush(QBrush(Qt::white,Qt::SolidPattern));
	painter->drawRect(-100,-100,600,600);

	/*����̨����*/
	drawtowercrane(painter,0,0,70,angle,length,0);

	drawtowercrane(painter,-150,-150,160,angle2,length2,1);
	drawtowercrane(painter,80,90,60,angle3,length3,2);

	/*�����ڱ���ɫ*/
	painter->setPen(Qt::NoPen);
	painter->setBrush(Qt::yellow);
	painter->drawRect(-200,-200,400,100);
	painter->drawRect(-200,-200,100,400);
	painter->drawRect(100,-200,200,400);
	painter->drawRect(-200,100,400,100);
}
void QTPAINT::drawtowercrane(QPainter *painter,int Ox,int Oy,int r,int angle,int length,int flag)
{
	angle=angle-90; 
	if(flag == 0) 
		painter->setPen(QPen(Qt::red,1,Qt::SolidLine));
	else if(flag == 1) 
		painter->setPen(QPen(Qt::green,1,Qt::DashLine));
	else
		painter->setPen(QPen(Qt::black,1,Qt::DashLine));

	painter->setBrush(Qt::NoBrush);
	painter->drawEllipse(Ox-r,Oy-r,2*r,2*r);

	painter->setPen(Qt::black);
	painter->setBrush(Qt::black);
	painter->drawEllipse(Ox-3,Oy-3,6,6);

	painter->setPen(QPen(Qt::black,1,Qt::DashDotLine));
	painter->setBrush(Qt::Dense4Pattern);
	painter->translate(Ox,Oy);
	painter->rotate(-angle);
	painter->translate(-Ox,-Oy);
	painter->drawRoundRect(Ox-2,Oy-r,4,r+r/4);

	painter->setPen(QPen(Qt::blue,1,Qt::SolidLine));
	painter->setBrush(QBrush(Qt::blue,Qt::SolidPattern));
	painter->drawRect(Ox-5,Oy-length-5,10,10);
	painter->translate(Ox,Oy);
	painter->rotate(angle);
	painter->translate(-Ox,-Oy);
}
void QTPAINT::timerEvent(QTimerEvent *)//updatetowercrane()
{ 
	char buff[]="east\n"; 
	angle++;
	(angle2+=2);
	(angle3+=3);
	//write(fd,&buff,5);
	//AngleEdit->setText(QString::number(angle));
	//repaint();
	update(10,34,200,200);
	qDebug("timerEvent");

} 
//void QTPAINT::paintEvent(QPaintEvent *e) 
//{
//
//	//// ����QPainter    
//	//QPainter painter(this);    // �O���P�|���c�    
//	//painter.setPen(Qt::DotLine);    // ָ��x��y��width��height�L�u���l    
//	//painter.drawLine(10, 10, 100, 10);        // �O���Pˢ���{ɫ������б����ʽ    
//	//painter.setBrush(QBrush(Qt::blue, Qt::BDiagPattern));    // ָ��x��y��width��height�L�u����    
//	//painter.drawRect(10, 20, 100, 50);        // �O�����Νu�ӣ�x1,y1�����c��x2,y2��K�c    
//	//QLinearGradient gradient(50, 100, 300, 350);    // �O���u���ɫ�^��    
//	//gradient.setColorAt(0.0, Qt::white);    
//	//gradient.setColorAt(0.2, Qt::green);    
//	//gradient.setColorAt(1.0, Qt::black);    // �ԝu����������Pˢ    
//	//painter.setBrush(QBrush(gradient));    // �L�u�A�Ǿ���    
//	//painter.drawRoundRect(10, 80, 100, 50);    // �L�u���Σ���λ�� 1/16 �Ƕȣ������� 45 �� �� 300 ��    
//	//painter.drawPie(10, 150, 100, 50, 45 * 16, 300 * 16);    // �L�u�DƬ           
//	//painter.drawPixmap(150, 10, QPixmap("caterpillar.jpg"));    // �L�u��M�D��    
//	//painter.drawTiledPixmap(150, 170, 185, 25, QPixmap("caterpillar_smaill.gif"));
//
//
//
//	//QPainter painter(this);  
//	//int x,y,w,h;  
//	//x = lastPoint.x();  
//	//y = lastPoint.y();  
//	//w = endPoint.x() - x;  
//	//h = endPoint.y() - y;  
//	//painter.drawRect(x,y,w,h);  
//
//	//int x,y,w,h;  
//	//x = lastPoint.x();  
//	//y = lastPoint.y();  
//	//w = endPoint.x() - x;  
//	//h = endPoint.y() - y;  
//	//QPainter pp(&pix);  
//	//pp.drawRect(x,y,w,h);  
//	//QPainter painter(this);  
//	//painter.drawPixmap(0,0,pix);
//
//
//	int x,y,w,h;
//	x = lastPoint.x();
//	y = lastPoint.y();
//	w = endPoint.x() - x;
//	h = endPoint.y() - y;
//
//	QPainter painter(this);
//	if(isDrawing)     //������ڻ�ͼ
//	{
//		tempPix = pix;    //����ǰpix�е����ݸ��Ƶ�tempPix�У�����ʵ���˽�����ͼ
//		QPainter pp(&tempPix);
//		pp.drawRect(x,y,w,h);
//		painter.drawPixmap(0,0,tempPix);
//	}
//	else
//	{
//		QPainter pp(&pix);
//		pp.drawRect(x,y,w,h);
//		painter.drawPixmap(0,0,pix);
//	}
//
//
//}
//
//void QTPAINT::mousePressEvent(QMouseEvent *event)
//{
//	if(event->button()==Qt::LeftButton) //����������
//	{
//		lastPoint = event->pos();
//		isDrawing = true;   //���ڻ�ͼ
//	}
//}
//
//
//void QTPAINT::mouseMoveEvent(QMouseEvent *event)
//{
//	if(event->buttons()&Qt::LeftButton) //���������µ�ͬʱ�ƶ����
//	{
//		endPoint = event->pos();
//		update();
//	}
//}
//
//
//void QTPAINT::mouseReleaseEvent(QMouseEvent *event)
//{
//	if(event->button() == Qt::LeftButton) //�������ͷ�
//	{
//		endPoint = event->pos();
//		isDrawing = false;    //������ͼ
//		update();
//	}
//}