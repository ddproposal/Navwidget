#include "widget.h"

#include <iostream>

#include "m_elawindow.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowIcon(QIcon(":/FontistoMysql.svg"));
    setWindowTitle("QStackedWidget");
    resize(1000,500);

    Init();
    InitNav();
    InitStackWidget();


}

Widget::~Widget() {}

void Widget::InitNav()
{
    QStringList NavNames = {
        "导入模型",
        "设置避障参数",
        "设置工艺参数",
        "设置运动参数",
        "其它设置"
    };

    QStringList Icons = {
        ":/FluentDataTrending32Filled.svg",
        ":/FontistoRedux.svg",
        ":/GameIconsHistogram.svg",
        ":/StreamlineDatabaseLockSolid.svg",
        ":/StreamlineDatabaseServer2Solid.svg"
    };


    buttongroup = new QButtonGroup(this);

    for(int i = 0 ; i < NavNames.size() ; i++)
    {
        QToolButton* btn = new QToolButton(this);
        btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btn->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

        btn->setIcon(QIcon(Icons.at(i)));
        btn->setIconSize(QSize(32,32));
        btn->setText(NavNames.at(i));

        btn->setStyleSheet(R"(
            QToolButton{
                border-style:none;
                border: 1px solid #C0DCF2;
                padding: 5px;
                font:15px "Microsoft YaHei";
                border-radius:5px;
                background: #DEF0FE;
            }
            QToolButton:hover{
                background:#C0DEF9;
            }
            QToolButton:checked{
                background:#C0DEF9;
            }

        )");


        btn->setCheckable(true);

        connect(btn,&QToolButton::clicked,this,&Widget::buttonclicked);

        buttongroup->addButton(btn,i);

        QGridLayout* leftLayout = (QGridLayout*)leftwidget->layout();
        leftLayout->addWidget(btn,i,0);


    }
    QGridLayout* leftLayout1 = (QGridLayout*)leftwidget->layout();
    leftLayout1->setRowStretch(NavNames.size(),10);




}

void Widget::Init()
{

    //总体布局
    QHBoxLayout* mainlayout = new QHBoxLayout(this);
    mainlayout->setSpacing(0);
    mainlayout->setContentsMargins(0,0,0,0);

    //左侧导航栏布局
    leftwidget = new QWidget(this);
    leftwidget->setObjectName("leftwidget");
    leftwidget->setStyleSheet("#leftwidget{background-color:rgb(220,240,255);}");
    //leftwidget->setMinimumWidth(300);

    QGridLayout* gridlayout = new QGridLayout(leftwidget);
    gridlayout->setSpacing(10);

    mainlayout->addWidget(leftwidget);

    //右侧布局
    rightwidget = new QWidget(this);
    rightwidget->setObjectName("rightwidget");
    rightwidget->setStyleSheet("#rightwidget{background-color:rgb(250,250,250);}");
    rightwidget->setMinimumSize(QSize(500,500));

    QVBoxLayout* Vlayout = new QVBoxLayout(rightwidget);
    Vlayout->setSpacing(0);

    stackwidget = new QStackedWidget(rightwidget);
    Vlayout->addWidget(stackwidget);

    mainlayout->addWidget(rightwidget);


}

void Widget::InitStackWidget()
{
    QWidget* widget1 = new QWidget(this);
    widget1->setWindowTitle("视图1");
    widget1->setStyleSheet("background-color:green");
    QWidget* widget2 = new QWidget(this);
    widget2->setWindowTitle("视图2");
    widget2->setStyleSheet("background-color:blue");

    M_Elawindow* Elawindow = new M_Elawindow(this);
    Elawindow->Init();



    stackwidget->addWidget(widget1);
    stackwidget->addWidget(widget2);
    stackwidget->addWidget(Elawindow);

}

void Widget::buttonclicked()
{
    std::cout<<buttongroup->checkedId()<<std::endl;
    stackwidget->setCurrentIndex(buttongroup->checkedId());
}


