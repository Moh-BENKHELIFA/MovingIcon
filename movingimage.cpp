#include "movingimage.h"
#include "ui_movingimage.h"
#include "QtWidgets"
#include <iostream>



int oldX;
int oldY;
boolean moving;
int DETECTION_AREA = 20;


MovingImage::MovingImage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MovingImage)
{
    ui->setupUi(this);
    setMouseTracking(true);
    setAttribute(Qt::WA_AcceptTouchEvents, true);
}

MovingImage::~MovingImage()
{
    delete ui;
}

void MovingImage::moveImage(int offsetX, int offsetY){
    QLabel * image = ui->IritImage;
    if(moving){
        image->move(image->pos().x() + offsetX, image->pos().y() + offsetY);
        detectCollision(image->pos().x(), image->pos().y());
        repaint();
    }
}

void MovingImage::mousePressEvent(QMouseEvent *event){
//    QLabel * image = ui->IritImage;

//    if(event->button() == Qt::LeftButton){
//        oldX = event->pos().x();
//        oldY = event->pos().y();
//        moving = image->pos().x() <= event->pos().x() &&
//                 image->pos().y()<= event->pos().y() &&
//                 image->pos().x()+image->width() >= event->pos().x() &&
//                 image->pos().y()+image->height() >= event->pos().y();
//    }
}

void MovingImage::mouseMoveEvent(QMouseEvent *event){
//    moveImage(event->pos().x()-oldX, event->pos().y() - oldY);
//    oldX = event->pos().x();
//    oldY = event->pos().y();
 }

bool MovingImage::event(QEvent *event){

    switch (event->type()) {
        case QEvent::TouchBegin:{
            QTouchEvent *t = static_cast<QTouchEvent *>(event);

            std::cout<<"TouchSequenceBegin: "<<t->points().count()<<std::endl;

            std::cout<< "Touch!"<<std::endl;
            std::cout<< "xPos: "<< t->points().first().position().x()<< std::endl;
            std::cout<< "yPos: "<< t->points().first().position().y()<<std::endl;
            std::cout<< "Ellipse Width: "<< t->points().first().ellipseDiameters().width()<<std::endl;
            std::cout<< "Ellipse Height: "<< t->points().first().ellipseDiameters().height()<<std::endl;
            std::cout<< "isEmpty: "<< t->points().first().ellipseDiameters().isEmpty()<<std::endl;
            std::cout<< "isValid: "<< t->points().first().ellipseDiameters().isValid()<<std::endl;
            std::cout<< "isNull: "<< t->points().first().ellipseDiameters().isNull()<<std::endl;
            std::cout<< "pressure: "<< t->points().first().pressure()<<std::endl;
            std::cout<< "rotation: "<< t->points().first().rotation()<<std::endl;
            std::cout<< "velocity: "<< t->points().first().velocity().x()<<std::endl;
            std::cout<< "velocity: "<< t->points().first().velocity().toPoint().y()<<std::endl;



            const auto touchPoints = static_cast<QTouchEvent *>(event)->points();
            for (const QTouchEvent::TouchPoint &touchPoint : touchPoints) {
                QSizeF diams = touchPoint.ellipseDiameters();

            }


            return true;
        }
    case QEvent::TouchUpdate:{
        QTouchEvent *t = static_cast<QTouchEvent *>(event);

        std::cout<< "pressure: "<< t->points().first().pressure()<<std::endl;

        return true;
    }
        default:
            // call base implementation
            return QMainWindow::event(event);
        }

}

void MovingImage::detectCollision(int x, int y){
    QLabel * irit = ui->IritImage;
    QLabel * eit = ui->EITImage;


    boolean hitbox = x <= eit->pos().x() + eit->width() + DETECTION_AREA &&
                     irit->pos().y()<= eit->pos().y() + eit->height() + DETECTION_AREA &&
                     x+irit->width() >= eit->pos().x() - DETECTION_AREA &&
                     irit->pos().y()+irit->height() >= eit->pos().y()- DETECTION_AREA;

    qDebug() << hitbox;

    if(hitbox && x <= eit->pos().x() + eit->width() + DETECTION_AREA){
        int offsetX = x - (eit->pos().x() + eit->width() + DETECTION_AREA);
        eit->move(eit->pos().x() + offsetX, eit->pos().y());
    }
    /*if(hitbox && irit->pos().y()<= eit->pos().y() + eit->height() + DETECTION_AREA ){
        int offsetY = irit->pos().y() - (eit->pos().y() + eit->height() + DETECTION_AREA);
        eit->move(eit->pos().x(), (eit->pos().y() + offsetY));

    }if(irit->pos().x()+irit->width() >= eit->pos().x() - DETECTION_AREA){

    } if(hitbox && irit->pos().y()+irit->height() >= eit->pos().y()- DETECTION_AREA){
        int offsetY = irit->pos().y() + irit->height() - eit->pos().y() - DETECTION_AREA;
        eit->move(eit->pos().x(), (eit->pos().y() + offsetY));
    }*/

}
