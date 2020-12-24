#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>
#include <stdlib.h>


Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1005,1005);
    setScene(scene);
    setBackgroundBrush(QBrush(QImage(":/background/background.jpg")));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1005,1005);

    way=false;
    cursor=nullptr;
    buildR=nullptr;
    buildB=nullptr;
    gameOver=nullptr;
    setMouseTracking(true);

    random_map();

    set_start_position_red(rand()%10,rand()%10);

    set_start_position_blue(rand()%10,rand()%10);

    scoreR = new ScoreR();
    scoreR->setPos(scoreR->x()+15,scoreR->y()+10);
    scene->addItem(scoreR);

    scoreB = new ScoreB();
    scoreB->setPos(scoreB->x()+850,scoreB->y()+10);
    scene->addItem(scoreB);

    scoreToWin = new ScoreToWin();
    scoreToWin->setPos(scoreToWin->x()+400,scoreToWin->y()+10);
    scoreToWin->setScore(lands/2);
    scene->addItem(scoreToWin);

    show();
}
void Game::setCursor(QString filename)
{
    if (cursor)
    {
       scene->removeItem(cursor);
       delete(cursor);
    }
    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
}

void Game::mouseMoveEvent(QMouseEvent * event)
{
    if (cursor){
        cursor->setPos(event->pos());
    }
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if (!way){
                if (buildR && maps[event->x()/100][event->y()/100]!='w'
                            && maps[event->x()/100][event->y()/100]!='B'
                             && (coordinate[2]!=event->x()/100 || coordinate[3]!=event->y()/100))
                                 {
                                    if (maps[event->x()/100+1][event->y()/100]=='r'     ||  maps[event->x()/100][event->y()/100+1]=='r'||
                                        maps[event->x()/100-1][event->y()/100]=='r'     ||  maps[event->x()/100][event->y()/100-1]=='r')
                                            {
                                                buildR->setPos((event->x()/100)*100+5,(event->y()/100)*100+5);
                                                coordinate[0]=event->x()/100;
                                                coordinate[1]=event->y()/100;

                                                if (maps[event->x()/100][event->y()/100]=='b'||maps[event->x()/100][event->y()/100]=='s')
                                                        {
                                                             if (maps[event->x()/100][event->y()/100]=='b')
                                                                     scoreB->decrease();
                                                             scoreR->increase();
                                                             maps[event->x()/100][event->y()/100]='r';
                                                             RedTeam * map=new RedTeam();
                                                             map->setPos(event->x()/100*100+5,event->y()/100*100+5);
                                                             scene->addItem(map);
                                                         }
                                                scene->addItem(buildR);
                                                if (gameover==true)
                                                    {
                                                         gameOver=new GameOver();
                                                         scene->addItem(gameOver);
                                                         winTextR=new WinTextR();
                                                         winTextR->setPos(225,600);
                                                         scene->addItem(winTextR);
                                                    };
                                                 cursor=nullptr;
                                                 buildR=nullptr;
                                                 way=true;
                                             }
                                   }
     else
                                   {
                                       QGraphicsView::mousePressEvent(event);
                                    }
            }
else
    if (way)
    {
        if (buildB && maps[event->x()/100][event->y()/100]!='w'
                    && maps[event->x()/100][event->y()/100]!='R'
                     && (coordinate[0]!=event->x()/100 || coordinate[1]!=event->y()/100))
                        {
                             if (maps[event->x()/100+1][event->y()/100]=='b'||maps[event->x()/100][event->y()/100+1]=='b'||
                                 maps[event->x()/100-1][event->y()/100]=='b'||maps[event->x()/100][event->y()/100-1]=='b')
                                     {
                                         buildB->setPos((event->x()/100)*100+5,(event->y()/100)*100+5);
                                         coordinate[2]=event->x()/100;
                                         coordinate[3]=event->y()/100;
                                         if (maps[event->x()/100][event->y()/100]=='r'||maps[event->x()/100][event->y()/100]=='s')
                                             {
                                                  if (maps[event->x()/100][event->y()/100]=='r')
                                                        scoreR->decrease();
                                                  scoreB->increase();
                                                  maps[event->x()/100][event->y()/100]='b';
                                                  BlueTeam * map=new BlueTeam();
                                                  map->setPos(event->x()/100*100+5,event->y()/100*100+5);
                                                  scene->addItem(map);
                                              }
                                           scene->addItem(buildB);
                                           if (gameover==true)
                                                 {
                                                     gameOver=new GameOver();
                                                     scene->addItem(gameOver);
                                                     winTextB=new WinTextB();
                                                     winTextB->setPos(225,600);
                                                     scene->addItem(winTextB);
                                                   };
                                            cursor=nullptr;
                                            buildB=nullptr;
                                            way=false;
                                        }
                        }
        else
                        {
                             QGraphicsView::mousePressEvent(event);
                         }
    }
}

void Game::set_start_position_red(int n_dot,int m_dot)
{
    if (maps[n_dot][m_dot]=='s' && maps[n_dot][m_dot]!='b'
            && maps[n_dot][m_dot]!='B' && sch1>0)
                {
                     way=false;
                     maps[n_dot][m_dot]='r';
                     sch1--;
                     RedTeam * map=new RedTeam();
                     map->setPos(n_dot*100+5,m_dot*100+5);
                     scene->addItem(map);
                     if (sch1==0)
                        {
                             coordinate[0]=n_dot;
                             coordinate[1]=m_dot;
                             CreateWorriarR* player=new CreateWorriarR();
                             player->setPos(n_dot*100+5,m_dot*100+5);
                             scene->addItem(player);
                             way=true;
                        }
                     if (sch1>0 && n_dot+1<10) set_start_position_red(n_dot+1,m_dot);
                     if (sch1>0 && n_dot-1>=0) set_start_position_red(n_dot-1,m_dot);
                     if (sch1>0 && m_dot+1<10) set_start_position_red(n_dot,m_dot+1);
                     if (sch1>0 && m_dot-1>=0) set_start_position_red(n_dot,m_dot-1);
                 }
    else
        if (sch1>0) set_start_position_red(rand()%10,rand()%10);
    return;
}

void Game::set_start_position_blue(int n_dot,int m_dot)
{
    if (maps[n_dot][m_dot]=='s' && maps[n_dot][m_dot]!='r'
            && maps[n_dot][m_dot]!='R' && sch2>0)
                {
                    way=true;
                    maps[n_dot][m_dot]='b';
                    sch2--;
                    BlueTeam * map=new BlueTeam();
                    map->setPos(n_dot*100+5,m_dot*100+5);
                    scene->addItem(map);
                    if (sch2==0)
                          {
                               coordinate[2]=n_dot;
                               coordinate[3]=m_dot;
                               CreateWorriarB* player=new CreateWorriarB();
                               player->setPos(n_dot*100+5,m_dot*100+5);
                               scene->addItem(player);
                               way=false;
                            }
                    if (sch2>0 && n_dot-1>=0) set_start_position_blue(n_dot-1,m_dot);
                    if (sch2>0 && n_dot+1<10) set_start_position_blue(n_dot+1,m_dot);
                    if (sch2>0 && m_dot+1<10) set_start_position_blue(n_dot,m_dot+1);
                    if (sch2>0 && m_dot-1>=0) set_start_position_blue(n_dot,m_dot-1);
                }
    else
        if (sch2>0) set_start_position_blue(rand()%10,rand()%10);
    return;
}

void Game::random_map()
{
   int m_lenth = 11;
   int n_lenth = 11;
   maps = (char**)malloc(m_lenth * sizeof(char*));
   for (int i = 0;i < m_lenth;i++)
       {
           *(maps + i) = (char*)malloc(n_lenth * sizeof(char));
           for (int j = 0;j < n_lenth;j++)
                 *(*(maps + i) + j) = 'w';
       }
    int m_dot = m_lenth/2;
    int n_dot = n_lenth/2;
    int sch=0;
    *(*(maps + m_dot) + n_dot) = 's';
    int m_up = rand() % (m_dot)+1;
    int m_dwn = rand() % (m_lenth - m_dot-1)+1;
    int n_lft = rand() % (n_dot)+1;
    int n_rght = rand()%(n_lenth-n_dot-1)+1;
       for (int i = m_dot - m_up;i <= m_dot + m_dwn;i++)
           for(int j=n_dot-(rand()% (n_lft));j<=n_dot+(rand()% (n_rght));j++)
                {
                   if (*(*(maps+i)+j)!='s')
                    {
                       *(*(maps+i)+j)= 's';
                       sch++;
                       lands++;
                    }
                }
       for (int j = n_dot - n_lft;j <= n_dot + n_rght;j++)
           for (int i=m_dot-rand()%(m_up);i<=m_dot+rand()%(m_dwn);i++)
                {
                    if(*(*(maps+i)+j)!='s')
                        {
                            *(*(maps+i)+j)= 's';
                            sch++;
                            lands++;
                        }
                }
     if (sch<((m_lenth*n_lenth)/2))
                random_map();
     else
         {
              lands=sch;
              for (int i=0;i<10;i++)
                  for(int j=0;j<10;j++)
                     if (maps[i][j]=='s')
                     {
                            RandomMap * map=new RandomMap();
                            map->setPos(i*100+5,j*100+5);
                            scene->addItem(map);
                     }
          }
}
