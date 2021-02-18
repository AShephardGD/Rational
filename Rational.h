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

    Rational sum(Rational);
    Rational sub(Rational);
    Rational mul(Rational);
    Rational div(Rational);

    // ==
    bool eq(Rational);//
    // !=
    bool neq(Rational);//
    // less than
    // <
    bool l(Rational);
    // less or equal than
    // <=
    bool leq(Rational);
    // greater than
    // >
    bool g(Rational);
    // greater or equal than
    // >=
    bool geq(Rational);

    void print();
    void scan();

private:
    bool nan;
    int numerator;
    int denumerator;
};
