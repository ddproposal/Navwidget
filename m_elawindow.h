#ifndef M_ELAWINDOW_H
#define M_ELAWINDOW_H

#include "ElaWindow.h"

class M_Elawindow : public ElaWindow
{
    Q_OBJECT

public:
    M_Elawindow(QWidget *parent = nullptr);

    void Init();
};

#endif // M_ELAWINDOW_H
