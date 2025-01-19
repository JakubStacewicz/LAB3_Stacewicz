// LAB3_Stacewicz.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
/*
#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159
#endif // !M_PI


class RobotStary {
public:
    virtual void idzDo(double x, double y) {
        std::cout << "Stary robot idzie do punktu (" << x << ", " << y << ")" << std::endl;
    }
};

class RobotNowy {
public:
    void idzDo(double kat, double odleglosc) {
        std::cout << "Nowy robot idzie pod katem " << kat << "° na odległosc " << odleglosc << std::endl;
    }
};

class AdapterRobota : public RobotStary {
private:
    RobotNowy* robotNowy;
public:
    AdapterRobota(RobotNowy* r) : robotNowy(r) {}

    void idzDo(double x, double y) override {
        double kat = atan2(y, x) * 180 / M_PI; // Konwersja kata na stopnie
        double odleglosc = sqrt(x * x + y * y); // Dystans
        robotNowy->idzDo(kat, odleglosc);
    }
};

int main() {
    RobotNowy nowyRobot;
    AdapterRobota adapter(&nowyRobot);

    // Testowanie adaptera
    adapter.idzDo(3, 4); // Powinno wypisać (53.13°, 5)

    return 0;
}
*/

#include <iostream>
#include <string>

// Klasa bazowa
class Robot {
public:
    virtual std::string operacja() = 0; // Wirtualna metoda
    virtual ~Robot() = default;        // Wirtualny destruktor
};

// Klasa podstawowa robota
class RobotPodstawowy : public Robot {
public:
    std::string operacja() override {
        return "Robot podstawowy porusza sie.";
    }
};

// Abstrakcyjny dekorator
class RobotDekorator : public Robot {
protected:
    Robot* robot; // Wskaźnik na obiekt dekorowany
public:
    RobotDekorator(Robot* r) : robot(r) {}
    virtual ~RobotDekorator() {
        delete robot; // Usuwanie obiektu bazowego
    }
};

// Konkretne dekoratory
class RobotZKamera : public RobotDekorator {
public:
    RobotZKamera(Robot* r) : RobotDekorator(r) {}
    std::string operacja() override {
        return robot->operacja() + "\nRobot teraz ma kamere, moze nagrywac.";
    }
};

class RobotZCzujnikiemTemperatury : public RobotDekorator {
public:
    RobotZCzujnikiemTemperatury(Robot* r) : RobotDekorator(r) {}
    std::string operacja() override {
        return robot->operacja() + "\nRobot teraz ma czujnik temperatury.";
    }
};

class RobotZDzwiekiem : public RobotDekorator {
public:
    RobotZDzwiekiem(Robot* r) : RobotDekorator(r) {}
    std::string operacja() override {
        return robot->operacja() + "\nRobot teraz ma system dzwiekowy.";
    }
};

int main() {
    // Tworzenie podstawowego robota
    Robot* robot = new RobotPodstawowy();
    std::cout << robot->operacja() << std::endl;

    std::cout << "\nDodajemy kamere do robota:" << std::endl;
    robot = new RobotZKamera(robot);
    std::cout << robot->operacja() << std::endl;

    std::cout << "\nDodajemy czujnik temperatury:" << std::endl;
    robot = new RobotZCzujnikiemTemperatury(robot);
    std::cout << robot->operacja() << std::endl;

    std::cout << "\nDodajemy system dzwiekowy:" << std::endl;
    robot = new RobotZDzwiekiem(robot);
    std::cout << robot->operacja() << std::endl;

    // Zwolnienie pamieci
    delete robot;

    return 0;
}