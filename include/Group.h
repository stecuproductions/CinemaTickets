//
// Created by stecu on 29.12.2024.
//

#ifndef QTAPP_GROUP_H
#define QTAPP_GROUP_H
#include "Ticket.h"
#include "Customer.h"
#include "Screening.h"
class Group:public Ticket{
private:
    int groupSize;
public:
    Group(Customer customer, Screening  screening, int groupSize);
    double getPrice();
    ~Group();
    double getGroupSize();
};
#endif //QTAPP_GROUP_H
