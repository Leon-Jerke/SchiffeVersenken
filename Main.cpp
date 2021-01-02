#include <iostream> 
#include <vector>
#include <memory>
#include <array>
#include <string>
#include <time.h>

std::array<std::array<std::string, 10>, 10> field;
void drawField();

enum class enum_Ships {
    Schlachtschiff,
    Kreuzer,
    Zerstoerer,
    U_Boot
};

typedef struct struct_Points {
    int x;
    int y;
    struct_Points(int a, int b) : x(a), y(b) {}
    struct_Points();

    ~struct_Points() {
        std::cout << "A Point was deleted at" << x << y << std::endl;
    }
}struct_Point;

typedef struct struct_Ship {
    enum_Ships type;
    bool vertical;
    std::shared_ptr<struct_Point> upperLeftCoordinates;
    struct_Ship(enum_Ships givenType, bool vert, std::shared_ptr<struct_Point> coordinates) : type(givenType), vertical(vert), upperLeftCoordinates(coordinates) {}

    ~struct_Ship() {
        std::cout << "A ship was deleted at " << upperLeftCoordinates->x << upperLeftCoordinates->y << std::endl;
    }
}struct_ship;

std::vector<std::shared_ptr<struct_ship>> shipVector;

void setEmptyField() {
    for (int i = 0; i < 10; ++i) {
        for (int k = 0; k < 10; ++k) {
            field[i][k] = "*";
        }
    }
    drawField();
}

void updateField() {
    int size;
    for (std::shared_ptr<struct_ship> tmp : shipVector) {
        switch (tmp->type) {
        case enum_Ships::Schlachtschiff:
            size = 5;
            break;
        case enum_Ships::Kreuzer:
            size = 4;
            break;
        case enum_Ships::Zerstoerer:
            size = 3;
            break;
        case enum_Ships::U_Boot:
            size = 2;
            break;
        }
        if (tmp->vertical) {
            for (int i = 0; i < size; ++i) {
                field[tmp->upperLeftCoordinates->x][tmp->upperLeftCoordinates->y + i] = "S";
            }
        }
        else {
            for (int i = 0; i < size; ++i) {
                field[tmp->upperLeftCoordinates->x + i][tmp->upperLeftCoordinates->y] = "S";
            }
        }
    }
    drawField();
}

void drawField() {
    char t = 'A';
    std::cout << "   |";
    for (int i = 0; i < 10; ++i) {
        std::cout << " " << t << " |";
        t++;
    }
    std::cout << std::endl;
    for (int i = 0; i < 11; ++i) {
        std::cout << "___|";
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << " " << i << " |";
        for (int k = 0; k < 10; ++k) {
            std::cout << " " << field[k][i] << " |";
        }
        std::cout << std::endl;
        for (int z = 0; z < 11; ++z) {
            std::cout << "___|";
        }
        std::cout << std::endl;
    }
}

bool checkShipPos(std::shared_ptr<struct_Point> coordinates, int size, bool& vert) {
    if (vert) {
        for (int i = 0; i < size; ++i) {
            if (field[coordinates->x][coordinates->y + i] == "S") {
                std::cout << "Das Schiff kollidiert mit einem Anderen, bitte setzen Sie es erneut." << std::endl;
                return false;
            }
        }
        if (coordinates->y + size > 10) {
            std::cout << "Das Schiff kann hier nicht platziert werden, bitte beachten Sie die Größe des Schiffes: " << size << std::endl;
            return false;
        }
    }
    else {
        for (int i = 0; i < size; ++i) {
            if (field[coordinates->x + i][coordinates->y] == "S") {
                std::cout << "Das Schiff kollidiert mit einem Anderen, bitte setzen Sie es erneut." << std::endl;
                return false;
            }
        }
        if (coordinates->x + size > 10) {
            std::cout << "Das Schiff kann hier nicht platziert werden, bitte beachten Sie die Größe des Schiffes: " << size << std::endl;
            return false;
        }
    }
    return true;
}

int charToInt(char& input) {
    switch (input) {
    case 'a':
    case 'A':
    case '0':
        return 0;
    case 'b':
    case 'B':
    case '1':
        return 1;
    case 'c':
    case 'C':
    case '2':
        return 2;
    case 'd':
    case 'D':
    case '3':
        return 3;
    case 'e':
    case 'E':
    case '4':
        return 4;
    case 'f':
    case 'F':
    case '5':
        return 5;
    case 'g':
    case 'G':
    case '6':
        return 6;
    case 'h':
    case 'H':
    case '7':
        return 7;
    case 'i':
    case 'I':
    case '8':
        return 8;
    case 'j':
    case 'J':
    case '9':
        return 9;
    default:
        return 0;
    }
}

bool setHorizontalVertical() {
    char input;
    std::cout << "Geben Sie \"H\" für Horizontal und \"V\" für Vertikal ein" << std::endl;
    std::cin >> input;
    switch (input) {
    case 'h':
    case 'H':
        return false;
    case 'v':
    case 'V':
        return true;
    default: std::cout << "Die Eingabe wurde leider nicht erkannt, versuchen Sie es bitte erneut";
    }
}

void setBattleships() {
    bool check = true;
    char input;
    int tmpX;
    int tmpY;
    bool tmpDirection;
    while (check) {
        std::cout << "Um das erste Schlachtschiff zu setzen, muessen Sie festlegen ob dieses Horizontal oder Vertikal gesetzt werden soll." << std::endl;
        tmpDirection = setHorizontalVertical();
        std::cout << "Nun benötige ich " << (tmpDirection ? " die oberste " : " die linkeste ") << "Koordinate des Schiffes" << std::endl;
        std::cout << "Bitte beachten Sie die jeweilige Größe des Schiffes von 5 Feldern" << std::endl;
        std::cout << "X: ";
        std::cin >> input;
        tmpX = charToInt(input);
        std::cout << std::endl << "Y: ";
        std::cin >> input;
        tmpY = input - '0';
        auto point = std::make_shared<struct_Point>(tmpX, tmpY);
        if (checkShipPos(point, 5, tmpDirection)) {
            auto newShip = std::make_shared<struct_ship>(struct_ship(enum_Ships::Schlachtschiff, tmpDirection, point));
            shipVector.push_back(newShip);
            check = false;
            updateField();
        }
    }
}

void setCruisers() {
    char input;
    int tmpX;
    int tmpY;
    bool tmpDirection;
    for (int i = 1; i < 3; ++i) {
        std::cout << "Um Kreuzer " << i << " zu setzen, muessen Sie festlegen ob dieser Horizontal oder Vertikal gesetzt werden soll." << std::endl;
        tmpDirection = setHorizontalVertical();
        std::cout << "Nun benötige ich " << (tmpDirection ? " die oberste " : " die linkeste ") << "Koordinate des Schiffes" << std::endl;
        std::cout << "Bitte beachten Sie die jeweilige Größe des Schiffes von 4 Feldern" << std::endl;
        std::cout << "X: ";
        std::cin >> input;
        tmpX = charToInt(input);
        std::cout << std::endl << "Y: ";
        std::cin >> input;
        tmpY = input - '0';
        auto point = std::make_shared<struct_Point>(tmpX, tmpY);
        if (checkShipPos(point, 4, tmpDirection)) {
            auto newShip = std::make_shared<struct_ship>(struct_ship(enum_Ships::Kreuzer, tmpDirection, point));
            shipVector.push_back(newShip);
            updateField();
        }
        else {
            i--;
        }
    }
}

void setDestroyers() {
    char input;
    int tmpX;
    int tmpY;
    bool tmpDirection;
    for (int i = 1; i < 4; ++i) {
        std::cout << "Um Zerstörer " << i << " zu setzen, muessen Sie festlegen ob dieser Horizontal oder Vertikal gesetzt werden soll." << std::endl;
        tmpDirection = setHorizontalVertical();
        std::cout << "Nun benötige ich " << (tmpDirection ? " die oberste " : " die linkeste ") << "Koordinate des Schiffes" << std::endl;
        std::cout << "Bitte beachten Sie die jeweilige Größe des Schiffes von 3 Feldern" << std::endl;
        std::cout << "X: ";
        std::cin >> input;
        tmpX = charToInt(input);
        std::cout << std::endl << "Y: ";
        std::cin >> input;
        tmpY = input - '0';
        auto point = std::make_shared<struct_Point>(tmpX, tmpY);
        if (checkShipPos(point, 3, tmpDirection)) {
            auto newShip = std::make_shared<struct_ship>(struct_ship(enum_Ships::Zerstoerer, tmpDirection, point));
            shipVector.push_back(newShip);
            updateField();
        }
        else {
            i--;
        }
    }
}

void setUBoats() {
    char input;
    int tmpX;
    int tmpY;
    bool tmpDirection;
    for (int i = 1; i < 5; ++i) {
        std::cout << "Um U-Boot " << i << " zu setzen, muessen Sie festlegen ob dieses Horizontal oder Vertikal gesetzt werden soll." << std::endl;
        tmpDirection = setHorizontalVertical();
        std::cout << "Nun benötige ich " << (tmpDirection ? " die oberste " : " die linkeste ") << "Koordinate des Schiffes" << std::endl;
        std::cout << "Bitte beachten Sie die Größe des Schiffes von 2 Feldern" << std::endl;
        std::cout << "X: ";
        std::cin >> input;
        tmpX = charToInt(input);
        std::cout << std::endl << "Y: ";
        std::cin >> input;
        tmpY = input - '0';
        auto point = std::make_shared<struct_Point>(tmpX, tmpY);
        if (checkShipPos(point, 2, tmpDirection)) {
            auto newShip = std::make_shared<struct_ship>(struct_ship(enum_Ships::U_Boot, tmpDirection, point));
            shipVector.push_back(newShip);
            updateField();
        }
        else {
            i--;
        }
    }
}

int main() {
    setEmptyField();
    setBattleships();
    setCruisers();
    setDestroyers();
    setUBoats();
    return 0;
}