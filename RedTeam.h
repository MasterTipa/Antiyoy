#ifndef REDTEAM_H
#define REDTEAM_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class RedTeam: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    RedTeam(QGraphicsItem * parent=0);
};

#endif // REDTEAM_H
