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



Rational Rational::sum(const Rational Other) {
    int newNumerator = (numerator * Other.denumerator) + (Other.numerator * denumerator),
        newDenumerator = denumerator * Other.denumerator;
    return Rational(newNumerator, newDenumerator).reduce();
}

Rational Rational::sub(const Rational Other) {
    int newNumerator = (numerator * Other.denumerator) - (Other.numerator * denumerator),
        newDenumerator = denumerator * Other.denumerator;
    return Rational(newNumerator, newDenumerator).reduce();
}

Rational Rational::mul(const Rational Other) {
    int newNumerator = numerator * Other.numerator,
        newDenumerator = denumerator * Other.denumerator;
    return Rational(newNumerator, newDenumerator).reduce();
}

Rational Rational::div(const Rational Other) {
    int newNumerator = numerator * Other.denumerator,
        newDenumerator = denumerator * Other.numerator;
    return Rational(newNumerator, newDenumerator).reduce();
}



bool Rational::eq(const Rational Other) {
    return (numerator * Other.denumerator == Other.numerator * denumerator) && !nan && !Other.nan;
}

bool Rational::neq(const Rational Other) {
    return !eq(Other);
}

bool Rational::l(const Rational Other) {
    return (numerator * Other.denumerator < Other.numerator * denumerator);
}

bool Rational::leq(const Rational Other) {
    return (numerator * Other.denumerator <= Other.numerator * denumerator);
}

bool Rational::g(const Rational Other) {
    return (numerator * Other.denumerator > Other.numerator * denumerator);
}

bool Rational::geq(const Rational Other) {
    return (numerator * Other.denumerator >= Other.numerator * denumerator);
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



Rational Rational::operator+(const Rational Other) {
    return sum(Other);
}

Rational Rational::operator-(const Rational Other) {
    return sub(Other);
}

Rational Rational::operator*(const Rational Other) {
    return mul(Other);
}

Rational Rational::operator/(const Rational Other) {
    return div(Other);
}

void Rational::operator=(const Rational Other) {
    numerator = Other.numerator;
    denumerator = Other.denumerator;
}

void Rational::operator+=(const Rational Other) {
    Rational temp = sum(Other);
    numerator = temp.numerator;
    denumerator = temp.denumerator;
}

void Rational::operator-=(const Rational Other) {
    Rational temp = sub(Other);
    numerator = temp.numerator;
    denumerator = temp.denumerator;
}

void Rational::operator*=(const Rational Other) {
    Rational temp = mul(Other);
    numerator = temp.numerator;
    denumerator = temp.denumerator;
}

void Rational::operator/=(const Rational Other) {
    Rational temp = div(Other);
    numerator = temp.numerator;
    denumerator = temp.denumerator;
}

bool Rational::operator==(const Rational Other) {
    return eq(Other);
}

bool Rational::operator<(const Rational Other) {
    return l(Other);
}

bool Rational::operator<=(const Rational Other) {
    return leq(Other);
}

bool Rational::operator>(const Rational Other) {
    return g(Other);
}

bool Rational::operator>=(const Rational Other) {
    return geq(Other);
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
    /*
    x.scan();
    std::cout << std::endl;
    std::cout << "new x = ";
    x.print();
    */
    std::cout << std::endl;

    std::cout << "z.neg(): ";
    z.neg().print();
    std::cout << "y.inv(): ";
    y.inv().reduce().print();

    std::cout << std::endl;

    std::cout << "x == y: " << x.eq(y) << std::endl;
    std::cout << "y != z: " << y.neq(z) << std::endl;
    std::cout << "x < y: " << x.l(y) << std::endl;
    std::cout << "y <= z: " << y.leq(z) << std::endl;
    std::cout << "x > y: " << x.g(y) << std::endl;
    std::cout << "y >= z: " << y.geq(z) << std::endl;

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

    std::cout << std::endl;

    std::cout << "x + y: ";
    (x + y).print();
    std::cout << "y - z: ";
    (y - z).print();
    std::cout << "x * y: ";
    (x * y).print();
    std::cout << "y / z: ";
    (y / z).print();

    std::cout << std::endl;

    std::cout << "x = y => new x = ";
    x = y;
    x.print();
    std::cout << "x += z => new x = ";
    x += z;
    x.print();
    std::cout << "x -= y => new x = ";
    x -= y;
    x.print();
    std::cout << "x *= y => new x = ";
    x *= y;
    x.print();
    std::cout << "x /= z => new x = ";
    x /= z;
    x.print();

    std::cout << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;
    std::cout << "x < z: " << (x < z) << std::endl;
    std::cout << "x <= y: " << (x <= y) << std::endl;
    std::cout << "x > z: " << (x > z) << std::endl;
    std::cout << "x >= y: " << (x >= y) << std::endl;
}
