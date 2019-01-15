#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>
#include <QPointer>
#include <QTime>
#include "airplane.h"
#include "airport.h"

class Controller : public QGraphicsView{

Q_OBJECT

public:
    Controller(int width, int height);

    void run(int width, int height);
    void mousePressEvent(QMouseEvent* event);
    void keyPressEvent(QKeyEvent* event);

public slots:
    void update();

private:
    QGraphicsScene* scene;
    QVector<Airport*> airports;

    QPointer<Airplane> focused_plane;

    const static int width;
    const static int height;

};

#endif // CONTROLLER_H
