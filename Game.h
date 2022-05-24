#pragma once

#include "ui_gamewindow.h"
#include "mybox.h"


class Game : public QWidget {
Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    ~Game() override;
private:
    Ui::Form *ui;
    QGraphicsScene *scene;
    QTimer* timer;
    BoxGroup* block;
    BoxGroup* nblock;
    QList<QGraphicsItem*> boxs;
    int score;
    bool pause;
    bool over;

    void keyPressEvent(QKeyEvent *event) override;
public:
    void init();
    void timeOut();
    void nextblock();
    void newblock();
    void unpick();
    void checkfull();
    void check_coll();
    void game_pause();
    void restart();

};

