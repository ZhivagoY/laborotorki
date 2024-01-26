﻿#include <iostream>
#include <cmath>

class Triangle {
private:
    float side1;
    float side2;
    float side3;
    bool isTriangle() const {
        return (side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1);
    }
public:
    Triangle(float s1, float s2, float s3) : side1(s1), side2(s2), side3(s3) {
        if (!isTriangle()) {
            std::cout << "Wrong sides" << std::endl;
        }
    }

    float getSide1() const { return side1; }
    float getSide2() const { return side2; }
    float getSide3() const { return side3; }

    float findPerimeter() const {
        return side1 + side2 + side3;
    }
    float findS() const {
        float p = findPerimeter() / 2; // полупериметр
        return std::sqrt(p * (p - side1) * (p - side2) * (p - side3)); //нашли площадь по формуле Герона
    }
};

int main() {
    // пример использования 
    Triangle treugolnik(12, 16, 20);
    std::cout << "Perimetr: " << treugolnik.findPerimeter() << std::endl;
    std::cout << "Ploshad: " << treugolnik.findS() << std::endl;
    return 0;
}