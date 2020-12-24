#ifndef CREATEWORRIARB_H
#define CREATEWORRIARB_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class CreateWorriarB: public QGraphicsPixmapItem {
public:
    CreateWorriarB(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};
#endif // CREATEWORRIARB_H
