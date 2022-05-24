/********************************************************************************
** Form generated from reading UI file 'gamewindowTtXnMy.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef GAMEWINDOWTTXNMY_H
#define GAMEWINDOWTTXNMY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QHBoxLayout *horizontalLayout;
    QGraphicsView *view;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *next;
    QGraphicsView *nextview;
    QLabel *score_label;
    QLabel *score;
    QSpacerItem *verticalSpacer_4;
    QLabel *explain;
    QSpacerItem *verticalSpacer_3;
    QPushButton *newgame;
    QPushButton *pause;
    QPushButton *setting;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(620, 800);
        Form->setMinimumSize(QSize(620, 800));
        Form->setMaximumSize(QSize(620, 800));
        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        view = new QGraphicsView(Form);
        view->setObjectName(QString::fromUtf8("view"));
        view->setMinimumSize(QSize(400, 800));
        view->setMaximumSize(QSize(400, 800));
        view->setFocusPolicy(Qt::NoFocus);
        view->setFrameShape(QFrame::NoFrame);
        view->setFrameShadow(QFrame::Plain);

        horizontalLayout->addWidget(view);

        frame = new QFrame(Form);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        next = new QLabel(frame);
        next->setObjectName(QString::fromUtf8("next"));
        QFont font;
        font.setPointSize(12);
        next->setFont(font);

        verticalLayout->addWidget(next);

        nextview = new QGraphicsView(frame);
        nextview->setObjectName(QString::fromUtf8("nextview"));
        nextview->setMinimumSize(QSize(160, 160));
        nextview->setMaximumSize(QSize(160, 160));
        nextview->setFocusPolicy(Qt::NoFocus);
        nextview->setFrameShape(QFrame::NoFrame);
        nextview->setFrameShadow(QFrame::Plain);
        nextview->setLineWidth(0);

        verticalLayout->addWidget(nextview);

        score_label = new QLabel(frame);
        score_label->setObjectName(QString::fromUtf8("score_label"));
        score_label->setFont(font);

        verticalLayout->addWidget(score_label);

        score = new QLabel(frame);
        score->setObjectName(QString::fromUtf8("score"));
        QFont font1;
        font1.setPointSize(18);
        font1.setItalic(true);
        score->setFont(font1);

        verticalLayout->addWidget(score);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        explain = new QLabel(frame);
        explain->setObjectName(QString::fromUtf8("explain"));
        explain->setFont(font);
        explain->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(explain);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        newgame = new QPushButton(frame);
        newgame->setObjectName(QString::fromUtf8("newgame"));
        newgame->setFont(font);
        newgame->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(newgame);

        pause = new QPushButton(frame);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setFont(font);
        pause->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pause);

        setting = new QPushButton(frame);
        setting->setObjectName(QString::fromUtf8("setting"));
        setting->setFont(font);
        setting->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(setting);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(frame);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "\344\277\204\347\275\227\346\226\257\346\226\271\345\235\227", nullptr));
        next->setText(QCoreApplication::translate("Form", "\344\270\213\344\270\200\344\270\252", nullptr));
        score_label->setText(QCoreApplication::translate("Form", "\345\275\223\345\211\215\345\210\206\346\225\260", nullptr));
        score->setText(QCoreApplication::translate("Form", "0", nullptr));
        explain->setText(QCoreApplication::translate("Form", "\346\223\215\344\275\234\350\257\264\346\230\216\357\274\232\n"
"\n"
"\344\270\212\357\274\232\346\227\213\350\275\254\n"
"\n"
"\344\270\213\357\274\232\345\212\240\351\200\237\344\270\213\350\220\275\n"
"\n"
"\347\251\272\346\240\274\357\274\232\344\270\200\346\255\245\345\210\260\345\272\225", nullptr));
        newgame->setText(QCoreApplication::translate("Form", "\346\226\260\346\270\270\346\210\217", nullptr));
        pause->setText(QCoreApplication::translate("Form", "\346\232\202\345\201\234", nullptr));
        setting->setText(QCoreApplication::translate("Form", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // GAMEWINDOWTTXNMY_H
