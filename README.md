#################################################################################
Author:fly
Email:fairytalefu@outlook.com
Time: 2016.4.2.16.18
###############################################################################
项目名称：ubuntu14.04 Qt5.6中用label打开并显示一张图片
1.采用两个按钮（Open&Close）和一个label（显示图像）
2.期间用到了QFileDialog::getOpenFileName（）
###### QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"/home",tr("Images (*.png *.xpm *.jpg *.bmp)"));
## QImage* img=new QImage;
## img->load(filename);
## QMessageBox::information(this,tr("打开图像失败"),tr("打开图像失败!"));
显示图像
## ui->label->setPixmap(QPixmap::fromImage(*img)); 改变图像大小ui->label->resize(ui->label->pixmap()->size());
