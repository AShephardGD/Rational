#include <iostream>

/**
 * ִנמבü, x/y
 */
class Rational {
public:

    Rational();
    Rational(int, int);
    Rational(int);

    Rational reduce();

    Rational neg();
    Rational inv();

    Rational sum(const Rational);
    Rational sub(const Rational);
    Rational mul(const Rational);
    Rational div(const Rational);

    // ==
    bool eq(const Rational);//
    // !=
    bool neq(const Rational);//
    // less than
    // <
    bool l(const Rational);
    // less or equal than
    // <=
    bool leq(const Rational);
    // greater than
    // >
    bool g(const Rational);
    // greater or equal than
    // >=
    bool geq(const Rational);

    void print(std::ostream& stream = std::cout) const;
    void scan(std::istream& in = std::cin, std::ostream& out = std::cout);

    Rational operator+(const Rational);
    Rational operator-(const Rational);
    Rational operator*(const Rational);
    Rational operator/(const Rational);

    void operator=(const Rational);
    void operator+=(const Rational);
    void operator-=(const Rational);
    void operator*=(const Rational);
    void operator/=(const Rational);

    bool operator==(const Rational);
    bool operator<(const Rational);
    bool operator<=(const Rational);
    bool operator>(const Rational);
    bool operator>=(const Rational);

    friend std::ostream& operator<<(std::ostream& stream, const Rational& rational);
    friend std::istream& operator>>(std::istream& stream, const Rational& rational);

private:
    bool nan;
    int numerator;
    int denumerator;
};
