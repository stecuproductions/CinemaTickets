#include <QApplication>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QHeaderView>
#include "CinemaManager.h"

void loadScreeningsFromFile(QTableWidget *table, const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Błąd", "Nie można otworzyć pliku: " + filePath);
        return;
    }

    QTextStream in(&file);
    int row = 0;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(',');

        if (parts.size() < 5) {
            QMessageBox::warning(nullptr, "Błąd", "Nieprawidłowy format danych w pliku.");
            continue;
        }

        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(parts[0]));
        table->setItem(row, 1, new QTableWidgetItem(parts[1]));
        table->setItem(row, 2, new QTableWidgetItem(parts[2]));
        table->setItem(row, 3, new QTableWidgetItem(parts[3]));
        ++row;
    }

    file.close();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    CinemaManager myCinemaManager;
    myCinemaManager.addScreening("Interstellar", "11/12/2003", "16:00", 1);

    QWidget window;
    window.setWindowTitle("Screenings Viewer");

    QTableWidget *table = new QTableWidget();
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels({"Tytuł", "Data", "Godzina", "Sala"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QString filePath = "../txtFiles/screenings.txt";
    loadScreeningsFromFile(table, filePath);

    // Tworzenie przycisku
    QPushButton *adminButton = new QPushButton("Otwórz Panel Administratora");


    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(table);
    layout->addWidget(adminButton); // Dodanie przycisku do układu

    window.setLayout(layout);
    window.resize(600, 400);
    window.show();

    return app.exec();
}
