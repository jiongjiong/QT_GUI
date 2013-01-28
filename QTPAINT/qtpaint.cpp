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
	//resize(600,500);    //窗口大小设置为600*500
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
	/*画塔机背景色*/ 
	painter->setPen(Qt::NoPen); 
	painter->setBrush(QBrush(Qt::white,Qt::SolidPattern));
	painter->drawRect(-100,-100,600,600);

	/*画三台塔机*/
	drawtowercrane(painter,0,0,70,angle,length,0);

	drawtowercrane(painter,-150,-150,160,angle2,length2,1);
	drawtowercrane(painter,80,90,60,angle3,length3,2);

	/*画窗口背景色*/
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
//	//// 建立QPainter    
//	//QPainter painter(this);    // 設定筆觸為點狀線    
//	//painter.setPen(Qt::DotLine);    // 指定x、y、width、height繪製線條    
//	//painter.drawLine(10, 10, 100, 10);        // 設定筆刷為藍色、對角斜線樣式    
//	//painter.setBrush(QBrush(Qt::blue, Qt::BDiagPattern));    // 指定x、y、width、height繪製矩形    
//	//painter.drawRect(10, 20, 100, 50);        // 設定線形漸層，x1,y1為起點，x2,y2為終點    
//	//QLinearGradient gradient(50, 100, 300, 350);    // 設定漸層顏色過渡    
//	//gradient.setColorAt(0.0, Qt::white);    
//	//gradient.setColorAt(0.2, Qt::green);    
//	//gradient.setColorAt(1.0, Qt::black);    // 以漸層物件建立筆刷    
//	//painter.setBrush(QBrush(gradient));    // 繪製圓角矩形    
//	//painter.drawRoundRect(10, 80, 100, 50);    // 繪製扇形，單位為 1/16 角度，下例為 45 度 到 300 度    
//	//painter.drawPie(10, 150, 100, 50, 45 * 16, 300 * 16);    // 繪製圖片           
//	//painter.drawPixmap(150, 10, QPixmap("caterpillar.jpg"));    // 繪製填滿圖形    
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
//	if(isDrawing)     //如果正在绘图
//	{
//		tempPix = pix;    //将以前pix中的内容复制到tempPix中，这样实现了交互绘图
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
//	if(event->button()==Qt::LeftButton) //鼠标左键按下
//	{
//		lastPoint = event->pos();
//		isDrawing = true;   //正在绘图
//	}
//}
//
//
//void QTPAINT::mouseMoveEvent(QMouseEvent *event)
//{
//	if(event->buttons()&Qt::LeftButton) //鼠标左键按下的同时移动鼠标
//	{
//		endPoint = event->pos();
//		update();
//	}
//}
//
//
//void QTPAINT::mouseReleaseEvent(QMouseEvent *event)
//{
//	if(event->button() == Qt::LeftButton) //鼠标左键释放
//	{
//		endPoint = event->pos();
//		isDrawing = false;    //结束绘图
//		update();
//	}
//}