#include <QApplication>
#include "Game.h"
#include <ctime>
Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(NULL));
    game=new Game();
    game->show();
    return a.exec();
}
