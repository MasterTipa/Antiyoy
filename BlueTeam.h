#ifndef BLUETEAM_H
#define BLUETEAM_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class BlueTeam: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    BlueTeam(QGraphicsItem * parent=0);
};

#endif // REDTEAM_H
