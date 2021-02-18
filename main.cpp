#include "Rational.h"
#include <iostream>

int gcd(int a, int b) {
    return b? gcd(b, a%b) : a;
}

Rational::Rational() {
    numerator = 1;
    denumerator = 1;
    nan = false;
}

Rational::Rational(int x, int y) {
    numerator = x;
    denumerator = y;
    nan = (y == 0);
}

Rational::Rational(int x) {
    numerator = x;
    denumerator = 1;
    nan = false;
}



Rational Rational::reduce() {
    int g = gcd(denumerator, numerator);
    return Rational(numerator / g, denumerator / g);
}



Rational Rational::neg() {
    return Rational(-1 * numerator, denumerator);
}

Rational Rational::inv() {
    return Rational(denumerator, numerator);
}



Rational Rational::sum(Rational other) {
    int newNumerator = (numerator * other.denumerator) + (other.numerator * denumerator),
        newDenumerator = denumerator * other.denumerator;
    return Rational(newNumerator, newDenumerator).reduce();
}

Rational Rational::sub(Rational other) {
    int newNumerator = (numerator * other.denumerator) - (other.numerator * denumerator),
        newDenumerator = denumerator * other.denumerator;
    return Rational(newNumerator, newDenumerator).reduce();
}

Rational Rational::mul(Rational other) {
    int newNumerator = numerator * other.numerator,
        newDenumerator = denumerator * other.denumerator;
    return Rational(newNumerator, newDenumerator).reduce();
}

Rational Rational::div(Rational other) {
    int newNumerator = numerator * other.denumerator,
        newDenumerator = denumerator * other.numerator;
    return Rational(newNumerator, newDenumerator).reduce();
}



bool Rational::eq(Rational other) {
    return (numerator * other.denumerator == other.numerator * denumerator) && nan && other.nan;
}

bool Rational::neq(Rational r) {
    return !eq(r);
}

bool Rational::l(Rational other) {
    return (numerator * other.denumerator < other.numerator * denumerator);
}

bool Rational::leq(Rational other) {
    return (numerator * other.denumerator <= other.numerator * denumerator);
}

bool Rational::g(Rational other) {
    return (numerator * other.denumerator > other.numerator * denumerator);
}

bool Rational::geq(Rational other) {
    return (numerator * other.denumerator >= other.numerator * denumerator);
}



void Rational::print() {
    if(nan) {
        std::cout << "<NAN>" << std::endl;
    }
    else {
        std::cout << numerator << "/" << denumerator << std::endl;
    }
}

void Rational::scan() {
    std::cout << "¬ведите числитель: ";
    std::cin >> numerator;
    std::cout << "¬ведите знаменатель: ";
    std::cin >> denumerator;
}


int main() {
    setlocale(LC_ALL, "Russian");
    Rational x;        // 1/1
    Rational y(10, 7); // 10/7
    Rational z(7, 4);  // 7/4
    Rational n(10, 0); // NaN

    std::cout << "x = ";
    x.print();
    std::cout << "y = ";
    y.print();
    std::cout << "z = ";
    z.print();
    std::cout << "n = ";
    n.print();

    std::cout << std::endl;

    x.scan();
    std::cout << std::endl;
    std::cout << "new x = ";
    x.print();

    std::cout << std::endl;

    std::cout << "z.neg(): ";
    z.neg().print();
    std::cout << "y.inv(): ";
    y.inv().reduce().print();

    std::cout << std::endl;

    std::cout << "x == y: ";
    std::cout << x.eq(y) << std::endl;
    std::cout << "y != z: ";
    std::cout << y.neq(z) << std::endl;
    std::cout << "x < y: ";
    std::cout << x.l(y) << std::endl;
    std::cout << "y <= z: ";
    std::cout << y.leq(z) << std::endl;
    std::cout << "x > y: ";
    std::cout << x.g(y) << std::endl;
    std::cout << "y >= z: ";
    std::cout << y.geq(z) << std::endl;

    std::cout << std::endl;

    std::cout << "x + y: ";
    x.sum(y).print();
    std::cout << "y + z: ";
    y.sum(z).print();
    std::cout << "x - y: ";
    x.sub(y).print();
    std::cout << "y - z: ";
    y.sub(z).print();
    std::cout << "n * 1/1: ";
    n.mul(Rational(1)).print();
    std::cout << "y * z: ";
    y.mul(z).print();
    std::cout << "x / y: ";
    x.div(y).print();
    std::cout << "y / z: ";
    y.div(z).print();
}
