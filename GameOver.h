#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QString>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class GameOver: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    GameOver(QGraphicsItem * parent=0);
};

#endif // GAMEOVER_H
