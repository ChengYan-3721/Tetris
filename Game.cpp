#include "Game.h"
#include <QTimer>
#include <QRandomGenerator>
#include <QKeyEvent>
#include <QMessageBox>

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form),
    scene(new QGraphicsScene(this)),
    timer(new QTimer(this))
{
    ui->setupUi(this);
    setWindowOpacity(0.8);
    //设置场景大小
    scene->setSceneRect(0, 0, 400, 1000);
    scene->setBackgroundBrush(Qt::black);   //设置背景为黑色

    ui->view->setScene(scene);
    ui->view->setSceneRect(0, 200, 400, 800);
    ui->view->setStyleSheet("border:0px");      //设置视图边框为0
    ui->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //隐藏水平滚动条
    ui->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   //隐藏垂直滚动条
//    ui->view->setParent(this);      //设置父类（要在哪个窗口上显示）

    ui->nextview->setScene(scene);
    ui->nextview->setSceneRect(0, 0, 160, 160);
    ui->nextview->setStyleSheet("border:0px");      //设置视图边框为0
    ui->nextview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //隐藏水平滚动条
    ui->nextview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   //隐藏垂直滚动条
//    ui->nextview->setParent(this);      //设置父类（要在哪个窗口上显示）

    init();
    nextblock();
    newblock();

    timer->start(800);
    connect(timer, &QTimer::timeout, this, &Game::timeOut);
    connect(ui->pause, &QPushButton::clicked, this, &Game::game_pause);
    connect(ui->newgame, &QPushButton::clicked, this, &Game::restart);
}

void Game::init() {
    scene->addLine(0, 1005, 400, 1005);
    scene->addLine(-5, 0, -5, 1000);
    scene->addLine(-45, 0, -45, 1000);
    scene->addLine(405, 0, 405, 1000);
    score = 0;
    ui->score->setNum(0);
    ui->pause->setText("暂停");
    pause = false;
    over = false;
}

void Game::nextblock() {
    nblock = new BoxGroup();
    nblock->setgroup(QRandomGenerator::global()->bounded(7));
    scene->addItem(nblock);
    nblock->setPos(0, 40);
}

void Game::newblock() {
    block = nblock;
    nblock = nullptr;
    block->setPos(120, 200);
    //设置为焦点，可以接受键盘输入信号
    block->setFlags(QGraphicsItem::ItemIsFocusable);
    block->setFocus();
    nextblock();
    check_coll();
}

void Game::keyPressEvent(QKeyEvent *event) {
    if(over || pause) return;
    switch (event->key()) {
        case Qt::Key_Up:
            block->spin();
            break;
        case Qt::Key_Down:
            block->movedown();
            break;
        case Qt::Key_Left:
            block->moveleft();
            break;
        case Qt::Key_Right:
            block->moveright();
            break;
        case Qt::Key_Space:
            block->moveend();
            break;
    }
    unpick();
}

void Game::unpick() {
    if(block->end){
        //取消组合
        scene->destroyItemGroup(block);
        block = nullptr;
        checkfull();
        newblock();
    }
}

void Game::checkfull() {
    for (int i = 960; i > 199; i -= 40) {
        boxs = scene->items(QRectF(0, i, 400, 20));
        if(boxs.length() > 9){
            for (const auto &box: boxs) {
                scene->removeItem(box);
                delete box;
            }
            score += 10;
            ui->score->setNum(score);
            boxs = scene->items(QRectF(0, 200, 400, i - 200));
            for (const auto &box: boxs) {
                box->moveBy(0, 40);
            }
        }
    }

}

void Game::timeOut() {
    block->movedown();
    unpick();
}

void Game::check_coll() {
    if(block->collidingItems().count() > 4 && block->y() < 201) {
        over = true;
        timer->stop();
        QMessageBox::about(this, "提示", QString(" Game Over ! \n     得分 %1").arg(score));
    }
}

void Game::game_pause() {
    if(pause){
        ui->pause->setText("暂停");
        pause = false;
        timer->start();
    } else {
        ui->pause->setText("继续");
        pause = true;
        timer->stop();
    }
}

void Game::restart() {
    timer->stop();
    boxs = scene->items();
    for (const auto &box: boxs){
        scene->removeItem(box);
        delete box;
    }
    init();
    nextblock();
    newblock();
    timer->start(800);
}

Game::~Game() {
    delete ui;
    delete scene;
    delete nblock;
    delete block;
    delete timer;
    qDeleteAll(boxs);
    boxs.clear();
}
