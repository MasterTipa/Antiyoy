#ifndef RANDOMMAP_H
#define RANDOMMAP_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class RandomMap: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    RandomMap(QGraphicsItem * parent=0);
};

#endif // RANDOMMAP_H
