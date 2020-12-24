#ifndef SCORETOWIN_H
#define SCORETOWIN_H

#include <QGraphicsTextItem>

class ScoreToWin: public QGraphicsTextItem{
public:
    ScoreToWin(QGraphicsItem * parent=0);
    int setScore(int scr);
private:
    int score;
};

#endif // SCORETOWIN_H
