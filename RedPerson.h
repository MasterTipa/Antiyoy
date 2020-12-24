#ifndef REDPERSON_H
#define REDPERSON_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class RedPerson: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    RedPerson(QGraphicsItem * parent=0);
   void push();
   void generation();
};
#endif // REDPERSON_H
