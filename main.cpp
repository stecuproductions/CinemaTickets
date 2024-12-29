#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QGridLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Główne okno
    QWidget window;
    window.setWindowTitle("System rezerwacji kina");

    // Layout główny
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // Etykieta wyboru filmu
    QLabel *movieLabel = new QLabel("Wybierz film:");
    mainLayout->addWidget(movieLabel);

    // Lista rozwijana z filmami
    QComboBox *movieList = new QComboBox;
    movieList->addItem("Film 1: Gwiezdne Wojny");
    movieList->addItem("Film 2: Władca Pierścieni");
    movieList->addItem("Film 3: Avatar");
    mainLayout->addWidget(movieList);

    // Etykieta wyboru miejsca
    QLabel *seatLabel = new QLabel("Wybierz miejsce:");
    mainLayout->addWidget(seatLabel);

    // Siatka z miejscami
    QGridLayout *seatLayout = new QGridLayout;
    QPushButton *seats[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            seats[i][j] = new QPushButton(QString::number(i * 3 + j + 1));
            seats[i][j]->setCheckable(true);
            seatLayout->addWidget(seats[i][j], i, j);
        }
    }
    mainLayout->addLayout(seatLayout);

    // Przycisk potwierdzający rezerwację
    QPushButton *confirmButton = new QPushButton("Zarezerwuj");
    mainLayout->addWidget(confirmButton);

    // Obsługa kliknięcia przycisku rezerwacji
    QObject::connect(confirmButton, &QPushButton::clicked, [&]() {
        QString selectedMovie = movieList->currentText();
        QString selectedSeat;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (seats[i][j]->isChecked()) {
                    selectedSeat = seats[i][j]->text();
                }
            }
        }
        if (!selectedSeat.isEmpty()) {
            QMessageBox::information(
                    &window,
                    "Rezerwacja zakończona",
                    "Zarezerwowano:\nFilm: " + selectedMovie + "\nMiejsce: " + selectedSeat
            );
        } else {
            QMessageBox::warning(&window, "Błąd", "Proszę wybrać miejsce!");
        }
    });

    // Ustawienie layoutu dla okna
    window.setLayout(mainLayout);

    // Wyświetlenie okna
    window.show();

    return app.exec();
}
