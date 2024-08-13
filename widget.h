#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QStringList>
#include <QIcon>
#include <QToolButton>
#include <QDockWidget>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QString name;

private:
    QWidget* leftwidget;
    QWidget* rightwidget;
    QDockWidget* log;

    QButtonGroup* buttongroup;
    QStackedWidget* stackwidget;

    void InitNav();
    void Init();
    void InitStackWidget();

private slots:
    void buttonclicked();

};
#endif // WIDGET_H
