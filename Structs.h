#pragma once
#ifndef Structs_h
#define Structs_h
#include <iostream>

typedef struct struct_Points {
    int x;
    int y;
    struct_Points(int a, int b) : x(a), y(b) {}
    //struct_Points();

    ~struct_Points() {
        std::cout << "A Point was deleted at" << x << y << std::endl;
    }
}struct_Point;

#endif