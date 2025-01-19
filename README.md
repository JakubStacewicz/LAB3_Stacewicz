 README

 Opis projektu

 Ten projekt zawiera implementację dwóch wzorców projektowych:
 **Adapter** oraz **Dekorator** w C++. Celem projektu jest pokazanie, jak
 te wzorce mogą zostać zastosowane do rozszerzenia funkcjonalności robota.

 Struktura projektu:

 Projekt składa się z dwóch części:
 1. **Adapter** – umożliwia dostosowanie interfejsu starego robota do nowego systemu.
 2. **Dekorator** – pozwala na dynamiczne dodawanie nowych funkcji do robota
    bez zmiany jego kodu źródłowego.

 Adapter (część zakomentowana):

 W tej części kodu implementujemy adapter, który dostosowuje stary interfejs robota
 do nowego. Stary robot wymaga dwóch współrzędnych (x, y), podczas gdy nowy robot
 wymaga kąta i odległości. Adapter konwertuje współrzędne na kąt i odległość, a
 następnie przekazuje te dane do nowego robota.

 Klasy:
 - `RobotStary`: Klasa reprezentująca starego robota, który używa współrzędnych (x, y).
 - `RobotNowy`: Klasa reprezentująca nowego robota, który używa kąta i odległości.
 - `AdapterRobota`: Klasa adaptera, która konwertuje współrzędne (x, y) na kąt i odległość.

 Przykład użycia:

 RobotNowy nowyRobot;
 AdapterRobota adapter(&nowyRobot);
 adapter.idzDo(3, 4);  // Powinno wypisać (53.13°, 5)

 Dekorator:

 W tej części kodu demonstrujemy wzorzec **Dekorator**, który umożliwia dodawanie
 nowych funkcji do robota bez zmiany jego podstawowego kodu. Używamy abstrakcyjnego
 dekoratora, który pozwala na "opakowanie" obiektu robota w różne dekoratory,
 dodając mu funkcjonalności takie jak kamera, czujnik temperatury czy system dźwiękowy.

 Klasy:
 - `Robot`: Klasa bazowa, która posiada metodę `operacja()`, która zwraca
   tekstową reprezentację operacji robota.
 - `RobotPodstawowy`: Klasa implementująca podstawową operację robota.
 - `RobotDekorator`: Abstrakcyjna klasa dekoratora, która przyjmuje obiekt `Robot`
   i rozszerza jego funkcjonalność.
 - `RobotZKamera`: Konkretna klasa dekoratora, która dodaje kamerę do robota.
 - `RobotZCzujnikiemTemperatury`: Konkretna klasa dekoratora, która dodaje czujnik
   temperatury do robota.
 - `RobotZDzwiekiem`: Konkretna klasa dekoratora, która dodaje system dźwiękowy do robota.

 Przykład użycia:

 Robot* robot = new RobotPodstawowy();
 printf("%s\n", robot->operacja());

 robot = new RobotZKamera(robot);
 printf("%s\n", robot->operacja());

 robot = new RobotZCzujnikiemTemperatury(robot);
 printf("%s\n", robot->operacja());

 robot = new RobotZDzwiekiem(robot);
 printf("%s\n", robot->operacja());

 delete robot;  // Zwolnienie pamięci

 Jak uruchomić?

 1. Aby uruchomić zadanie 1. należy odkomentować zakomentowaną część programu oraz zakomentować drugą część programu
 2. Zadanie drugie jest odkomentowane w
 3. 
