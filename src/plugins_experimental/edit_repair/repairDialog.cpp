#include <GL/glew.h>
#include "repairDialog.h"
#include "ui_repairDialog.h"
//#include <QtGui>

void RepairDialog::closeEvent ( QCloseEvent * /*event*/ )
{
    emit closing();
}

Qt::CheckState RepairDialog::checkBoxShowPointsState()
{
    return ui->checkBoxShowPoints->checkState();
}

void RepairDialog::SetToothinfoText(QString str)
{
    ui->toothinfo->setText(str);
}

void RepairDialog::ToothinfoAdjustSize()
{
    ui->toothinfo->adjustSize();
}


RepairDialog::RepairDialog(QWidget *parent,EditRepairPlugin *_edit):
    QDockWidget(parent),
    ui(new Ui::RepairDialog)
{
    ui->setupUi(this);

    this->setFeatures(QDockWidget::AllDockWidgetFeatures);
    this->setAllowedAreas(Qt::LeftDockWidgetArea);

    QPoint p=parent->mapToGlobal(QPoint(0,0));
    this->setGeometry(p.x()+(parent->width()-width()),p.y()+58,width(),height() );
    this->setFloating(true);
    //this->edit = _edit;

}

RepairDialog::~RepairDialog()
{
    delete ui;
}

//void RepairDialog::paintEvent(QPaintEvent *event){
//	QPainter painter(this);
//	QColor color;
//	QRect section;
//	float colorBarLength=343.0;//������ɫ���ĳ���
//
//	int x = 300;
//	int y = 50;
//
//	////------����Ϊgray��ɫ��---------//
//	//for(int i=0;i<=colorBarLength;i++)// gray
//	//{
//	//	//color.setRgbF(i/colorBarLength,i/colorBarLength,i/colorBarLength);//Ҳ����ʹ�����ַ���
//	//	color.setHsv(0,0,(colorBarLength-i)/colorBarLength*255);
//	//	section.setRect(150,50+i*1,20,1);
//	//	painter.fillRect(section,color);
//	//}
//
//	//------����Ϊjet��ɫ��---------//
//	float tempLength=colorBarLength/4;
//	for(int i=0;i<tempLength/2;i++)// jet
//	{
//		color.setRgbF(0,0,(tempLength/2+i)/tempLength);
//		section.setRect(x,colorBarLength+y-i*1,20,1);
//		painter.fillRect(section,color);
//	}
//	for(int i=tempLength/2+1;i<tempLength/2+tempLength;i++)// jet
//	{
//		color.setRgbF(0,(i-tempLength/2)/tempLength,1);
//		section.setRect(x,colorBarLength+y-i*1,20,1);
//		painter.fillRect(section,color);
//	}
//	for(int i=tempLength/2+tempLength+1;i<tempLength/2+2*tempLength;i++)// jet
//	{
//		color.setRgbF((i-tempLength-tempLength/2)/tempLength,1,(tempLength*2+tempLength/2-i)/tempLength);
//		section.setRect(x,colorBarLength+y-i*1,20,1);
//		painter.fillRect(section,color);
//	}
//	for(int i=tempLength/2+2*tempLength+1;i<tempLength/2+3*tempLength;i++)// jet
//	{
//		color.setRgbF(1,(tempLength*3+tempLength/2-i)/tempLength,0);
//		section.setRect(x,colorBarLength+y-i*1,20,1);
//		painter.fillRect(section,color);
//	}
//	for(int i=tempLength/2+3*tempLength+1;i<colorBarLength;i++)// jet
//	{
//		color.setRgbF((colorBarLength-i+tempLength/2)/(tempLength),0,0);
//		section.setRect(x,colorBarLength+y-i*1,20,1);
//		painter.fillRect(section,color);
//	}
//	//------����Ϊhsv��ɫ��---------//
//	for(int i=0;i<=colorBarLength;i++)// hsv
//	{
//		color.setHsvF(i/colorBarLength,1,1);
//		section.setRect(x+50,colorBarLength+y-i*1,20,1);
//		painter.fillRect(section,color);
//	}
//	////------����Ϊhot��ɫ��---------//
//	//tempLength=colorBarLength/2.5;
//	//for(int i=0;i<tempLength/2;i++)// hot
//	//{
//	//	color.setRgbF((tempLength/2+i)/tempLength,0,0);
//	//	section.setRect(300,colorBarLength+50-i*1,20,1);
//	//	painter.fillRect(section,color);
//	//}
//	//for(int i=tempLength/2+1;i<tempLength/2+tempLength;i++)// hot
//	//{
//	//	color.setRgbF(1,(i-tempLength/2)/tempLength,0);
//	//	section.setRect(300,colorBarLength+50-i*1,20,1);
//	//	painter.fillRect(section,color);
//	//}
//
//	//for(int i=tempLength/2+tempLength+1;i<colorBarLength;i++)// hot
//	//{
//	//	color.setRgbF(1,1,(i-tempLength/2-tempLength)/(colorBarLength-tempLength/2-tempLength+20));
//	//	section.setRect(300,colorBarLength+50-i*1,20,1);
//	//	painter.fillRect(section,color);
//	//}
//	//---------���ñ߿�--------------//
//	//�̶�ֵ�Ļ��ƿ����Լ���ƣ�ʹ��drawText��������,�̶ȵĻ��ƿ���ʹ��drawLine����
//	/*painter.setPen(Qt::black);
//	painter.drawRect(150,50,20,colorBarLength);
//	painter.setFont(QFont(QString::fromLocal8Bit("����"),10,-1,false));
//	painter.drawText(150,40,QString("Gray"));  */
//
//	painter.drawRect(x,y,20,colorBarLength);
//	painter.setFont(QFont(QString::fromLocal8Bit("����"),10,-1,false));
//	painter.drawText(x,40,QString("Jet"));
//
//	painter.drawRect(x+50,y,20,colorBarLength);
//	painter.setFont(QFont(QString::fromLocal8Bit("����"),10,-1,false));
//	painter.drawText(x+50,40,QString("Hsv"));
//
///*	painter.drawRect(300,50,20,colorBarLength);
//	painter.setFont(QFont(QString::fromLocal8Bit("����"),10,-1,false));
//	painter.drawText(300,40,QString("Hot")); */
//	// painter.drawText(150,320,QStringLiteral(" 0"));
//}
