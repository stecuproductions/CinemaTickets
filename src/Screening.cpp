//
// Created by stecu on 29.12.2024.
//

#include "Screening.h"
#include "Seat.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
Screening::Screening(string filmTitle, string date, string hour, int auditoriumId) : filmTitle(filmTitle), date(date), hour(hour) {
    if (auditoriumId == 1) {
        for (int i = 0; i < 50; i++) {
            Seat* seat = new Seat(i);
            seats.push_back(seat);
        }
    } else if (auditoriumId == 2) {
        for (int i = 0; i < 80; i++) {
            Seat* seat = new Seat(i);
            seats.push_back(seat);
        }
    }

    ofstream file("../txtFiles/screenings.txt", ios::app);
    if (file.is_open()) {
        file << filmTitle << ","
             << date << ","
             << hour << ","
             << auditoriumId << ",";

        for (size_t i = 0; i < seats.size(); i++) {
            file << (i) << "F";
            if (i != seats.size() - 1) {
                file << " ";
            }
        }
        file << "\n"; // Zakończ wiersz

        file.close();
        cout << "Dane zapisano do pliku screenings.txt" << endl;
    } else {
        cerr << "Nie można otworzyć pliku screenings.txt" << endl;
    }
}

Screening::~Screening() {
    for (Seat* seat:seats){
        delete seat;
    }
}

bool Screening::assignSeat(int seatNo) {
    if (!seats[seatNo]->getAvailability()){
        return false;
    }
    else{
        seats[seatNo]->changeSeatAvailability();
    }
}

string Screening::getScreeningTitle() {return filmTitle;}

string Screening::getScreeningDate() {return date;}

string Screening::getScreeningHour() {return hour;}
