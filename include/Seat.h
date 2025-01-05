//
// Created by stecu on 29.12.2024.
//

#ifndef QTAPP_SEAT_H
#define QTAPP_SEAT_H
class Seat{
private:
    int seatNo;
    bool isAvailable=true;
public:
    Seat(int seatNo);
    void changeSeatAvailability();
    bool getAvailability();
    int getSeatNo();
};
#endif //QTAPP_SEAT_H
