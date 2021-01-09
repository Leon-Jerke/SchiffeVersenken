#pragma once
#ifndef Structs_h
#define Structs_h
#include <iostream>
#include <string>

typedef struct struct_Points {
    unsigned x;
    unsigned y;
    struct_Points(int& a, int& b) : x(a), y(b) {}
    struct_Points(std::string& s) 
    {
        std::string input = s;
        if (input.size() == 2) {
            x = toupper(input[0]) - 'A';
            y = input[1] - '0';
        }
        else {
            std::cout << "Es ist ein graunhafter Fehler aufgetreten, bitte Starten Sie das Spiel neu!" << std::endl;
        }
    }
    ~struct_Points() {
        //std::cout << "A Point was deleted at" << x << y << std::endl;
    }
}struct_Point;
#endif