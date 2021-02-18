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

    void print();
    void scan();

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

private:
    bool nan;
    int numerator;
    int denumerator;
};
