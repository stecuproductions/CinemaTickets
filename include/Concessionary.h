//
// Created by stecu on 29.12.2024.
//

#ifndef QTAPP_CONCESSIONARY_H
#define QTAPP_CONCESSIONARY_H
#include "Ticket.h"
class Concessionary:public Ticket{
public:
    double getPrice();
    ~Concessionary();
};
#endif //QTAPP_CONCESSIONARY_H
