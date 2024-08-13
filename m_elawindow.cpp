#include "m_elawindow.h"

M_Elawindow::M_Elawindow(QWidget *parent)
    : ElaWindow(parent)
{


}

void M_Elawindow::Init()
{
    setUserInfoCardVisible(false);
    setVisible(false);

    QWidget* widget3 = new QWidget(this);
    widget3->setStyleSheet("background-color:red");

    QString key1,key2;
    addExpanderNode("转换试图",key1,ElaIconType::CalendarUsers);
    addExpanderNode("旋转试图",key1,ElaIconType::CalendarArrowUp);
    addExpanderNode("试图",key2,key1,ElaIconType::CalendarArrowDown);
    addPageNode("设置试图",widget3,key2,ElaIconType::ArrowDownLeft);
}
