//
// Created by stecu on 29.12.2024.
//
#ifndef QTAPP_SCREENING_H
#define QTAPP_SCREENING_H
#include "Seat.h"
#include <string>
#include <vector>
using namespace std;
class Screening{
private:
    string filmTitle;
    string date;
    string hour;
    vector<Seat*> seats;
public:
    Screening(string filmTitle, string date, string hour, int auditoriumId);
    ~Screening();
    bool assignSeat(int seatNo);
    string getScreeningTitle();
    string getScreeningDate();
    string getScreeningHour();
    string displaySeats();
};
#endif //QTAPP_SCREENING_H
