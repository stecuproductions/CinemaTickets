//
// Created by stecu on 29.12.2024.
//

#ifndef QTAPP_REGISTER_H
#define QTAPP_REGISTER_H
#include <vector>
#include <string>
using namespace std;
class Ticket;
class Register{
private:
    vector<Ticket*> tickets;
public:
    ~Register();
    double getDailyEarnings(string date);
    string displayTickets();
    void addTicket(Ticket* ticket);
};
#endif //QTAPP_REGISTER_H
