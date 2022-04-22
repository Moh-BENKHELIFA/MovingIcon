#ifndef MOVINGIMAGE_H
#define MOVINGIMAGE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MovingImage; }
QT_END_NAMESPACE

class MovingImage : public QMainWindow
{
    Q_OBJECT

public:
    MovingImage(QWidget *parent = nullptr);
    ~MovingImage();

private:
    Ui::MovingImage *ui;
    void moveImage(int x, int y);
    bool event(QEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void detectCollision(int x, int y);



};
#endif // MOVINGIMAGE_H
