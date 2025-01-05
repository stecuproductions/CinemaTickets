//
// Created by stecu on 29.12.2024.
//

#ifndef QTAPP_TICKET_H
#define QTAPP_TICKET_H
#include "Screening.h"
using namespace std;
class Seat;
class Customer;
class Ticket{
private:
    Customer* owner;
    bool available;
    Screening screening;
public:
    void setAvaiablity();
    double virtual getPrice()=0;
    virtual ~Ticket();
    Ticket(Screening screening, int seatNumber);
    bool showAvailability();
    string displayTicketInfo();
    void setOwner(Customer* newOwner);
};
#endif
