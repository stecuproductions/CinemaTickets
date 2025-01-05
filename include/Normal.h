//
// Created by stecu on 29.12.2024.
//

#ifndef QTAPP_NORMAL_H
#define QTAPP_NORMAL_H
#include "Ticket.h"
class Normal:public Ticket{
public:
    double getPrice();
    ~Normal();
};
#endif //QTAPP_NORMAL_H
