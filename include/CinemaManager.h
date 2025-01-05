//
// Created by stecu on 29.12.2024.
//

#ifndef QTAPP_CINEMAMANAGER_H
#define QTAPP_CINEMAMANAGER_H
#include "Screening.h"
#include "string"
using namespace std;
class CinemaManager{
public:
    void addScreening(string filmTitle, string date, string hour, int auditoriumId);

};
#endif //QTAPP_CINEMAMANAGER_H
