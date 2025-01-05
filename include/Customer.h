//
// Created by stecu on 29.12.2024.
//

#ifndef QTAPP_CUSTOMER_H
#define QTAPP_CUSTOMER_H
#include <vector>
#include <string>
using namespace std;
class Ticket;
class Customer{
private:
    string name;
    string surname;
    int custId;
    int age;
    vector<Ticket*> customerTickets;
public:
    Customer(string name, string surname, int age);
    void buyTicket(int seatNo, string type );
    string getName();
    string getSurname();
    int getId();
    int getAge();
    string displayCustomerTickets();
};
#endif //QTAPP_CUSTOMER_H
