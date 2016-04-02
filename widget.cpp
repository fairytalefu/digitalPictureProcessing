#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Open_clicked()
{
    QString filename;
    filename=QFileDialog::getOpenFileName(this,tr("选择图像"),"",tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));
    if(filename.isEmpty())
    {
       return ;
    }
    else
    {
       QImage* img=new QImage;

    if(! ( img->load(filename) ) ) //加载图像
    {
       QMessageBox::information(this,
       tr("打开图像失败"),
       tr("打开图像失败!"));
       delete img;
       return;
    }
//    QImage imgScaled ;
//    imgScaled = img->scaled(ui->label->size(),Qt::KeepAspectRatio);
//    imgScaled = img->QImage::scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio);
//    ui->label->setPixmap(QPixmap::fromImage(imgScaled));
      ui->label->setPixmap(QPixmap::fromImage(*img));
      ui->label->resize(ui->label->pixmap()->size());
    }

}

void Widget::on_Close_clicked()
{
    close();
}

