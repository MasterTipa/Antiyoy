#ifndef CREATEWORRIARR_H
#define CREATEWORRIARR_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class CreateWorriarR: public QGraphicsPixmapItem {
public:
    CreateWorriarR(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};


#endif // CREATEWORRIARR_H
