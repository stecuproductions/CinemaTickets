//
// Created by stecu on 29.12.2024.
//
#include "Seat.h"

Seat::Seat(int seatNo): seatNo(seatNo) {};

void Seat::changeSeatAvailability() {isAvailable=!isAvailable;}

bool Seat::getAvailability() {return isAvailable;}

int Seat::getSeatNo() {return seatNo;}