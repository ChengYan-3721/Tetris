#include "mybox.h"

#include <QPen>
#include <QBrush>
#include <iostream>

Box::Box(int x, int y, QColor color) {
    setRect(x + 1, y + 1, 38, 38);
    setPen(QPen(Qt::white));
    setBrush(QBrush(color));
}

Box::~Box() {}


BoxGroup::BoxGroup() {}


void BoxGroup::setgroup(int num) {
    switch (num) {
        case IShape:
            addToGroup(new Box(0, 0, QColor(248, 85, 85)));
            addToGroup(new Box(40, 0, QColor(248, 85, 85)));
            addToGroup(new Box(80, 0, QColor(248, 85, 85)));
            addToGroup(new Box(120, 0, QColor(248, 85, 85)));
            setTransformOriginPoint(40, 40);
            setData(0,90);
            break;
        case JShape:
            addToGroup(new Box(40, 0, QColor(210, 120, 209)));
            addToGroup(new Box(40, 40, QColor(210, 120, 209)));
            addToGroup(new Box(40, 80, QColor(210, 120, 209)));
            addToGroup(new Box(0, 80, QColor(210, 120, 209)));
            setTransformOriginPoint(40, 80);
            setData(0,360);
            break;
        case LShape:
            addToGroup(new Box(0, 0, QColor(96, 99, 227)));
            addToGroup(new Box(0, 40, QColor(96, 99, 227)));
            addToGroup(new Box(0, 80, QColor(96, 99, 227)));
            addToGroup(new Box(40, 80, QColor(96, 99, 227)));
            setTransformOriginPoint(40, 80);
            setData(0,360);
            break;
        case OShape:
            addToGroup(new Box(0, 0, QColor(96, 213, 227)));
            addToGroup(new Box(40, 0, QColor(96, 213, 227)));
            addToGroup(new Box(0, 40, QColor(96, 213, 227)));
            addToGroup(new Box(40, 40, QColor(96, 213, 227)));
            setTransformOriginPoint(40, 40);
            setData(0,0);
            break;
        case SShape:
            addToGroup(new Box(0, 40, QColor(96, 227, 133)));
            addToGroup(new Box(40, 40, QColor(96, 227, 133)));
            addToGroup(new Box(40, 0, QColor(96, 227, 133)));
            addToGroup(new Box(80, 0, QColor(96, 227, 133)));
            setTransformOriginPoint(40, 40);
            setData(0,90);
            break;
        case TShape:
            addToGroup(new Box(0, 40, QColor(182, 227, 96)));
            addToGroup(new Box(40, 40, QColor(182, 227, 96)));
            addToGroup(new Box(40, 0, QColor(182, 227, 96)));
            addToGroup(new Box(80, 40, QColor(182, 227, 96)));
            setTransformOriginPoint(80, 40);
            setData(0,360);
            break;
        case ZShape:
            addToGroup(new Box(0, 0, QColor(202, 168, 75)));
            addToGroup(new Box(40, 0, QColor(202, 168, 75)));
            addToGroup(new Box(40, 40, QColor(202, 168, 75)));
            addToGroup(new Box(80, 40, QColor(202, 168, 75)));
            setTransformOriginPoint(40, 40);
            setData(0,90);
            break;
    }
    angle = 90;
    end = false;
}

bool BoxGroup::iscollid() {
    QList <QGraphicsItem*> boxs = childItems();
    for (auto box : boxs) {
        if(box->collidingItems().count() > 1) {
            std::cout << "x？  " << x() << std::endl;
            std::cout << "y？  " << y() << std::endl;
            return true;
        }
    }
    return false;
}

void BoxGroup::spin() {
    if(end) return;
    if(data(0) == 360) {
        setRotation(angle);
        if(y() < 200) movedown();
        if(iscollid()){
            setRotation(angle -= 90);
        }
        angle += 90;
        if(angle == 360) angle = 0;
    }else if(data(0) == 90){
        setRotation(angle);
        if(y() < 200) movedown();
        if(iscollid()){
            if(x() < 0){
                moveright();
            }else{
                moveleft();
            }
        }
        angle = angle == 90 ? 0 : 90;
    }else return;
}

void BoxGroup::movedown() {
    if(end) return;
    moveBy(0, 40);
    if(iscollid()) {
        moveBy(0, -40);
        end = true;
    }
}

void BoxGroup::moveleft() {
    if(end) return;
    moveBy(-40, 0);
    if(iscollid()) moveBy(40, 0);
}

void BoxGroup::moveright() {
    if(end) return;
    moveBy(40, 0);
    if(iscollid()) moveBy(-40, 0);
}

void BoxGroup::moveend() {
    while (!end){
        movedown();
    }
}

//QPainterPath BoxGroup::shape() const {
//    QPainterPath path;
//    path.addRect(0, 0, 160, 160);
//    return path;
//}
