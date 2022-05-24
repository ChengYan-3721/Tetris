#pragma once

#include <QGraphicsRectItem>
#include <QGraphicsItemGroup>

class Box : public QGraphicsRectItem {
public:
    Box(int x, int y, QColor);

    ~Box() override;
};


class BoxGroup : public QGraphicsItemGroup {
public:
    Box* box;
    int angle;
    bool end;
    enum BoxShape{IShape, JShape, LShape, OShape, SShape, TShape, ZShape};
    BoxGroup();
    void setgroup(int num);
    bool iscollid();
    void spin();
    void movedown();
    void moveleft();
    void moveright();
    void moveend();
};