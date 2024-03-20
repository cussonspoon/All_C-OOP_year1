#include <iostream>

class Fraction
{
private:
    int numerator, denominator;
    static int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    void simplify()
    {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
        if (denominator < 0){
            denominator *= -1;
            numerator *= -1;
        }
    }
    Fraction(int numerator = 0, int denominator = 1) : numerator(numerator), denominator(denominator) {}
    Fraction operator+(const Fraction &other) const
    {
        int new_deno = denominator * other.denominator;
        int new_num1 = numerator * other.denominator;
        int new_num2 = other.numerator * denominator;
        int new_sum = new_num1 + new_num2;
        return Fraction(new_sum, new_deno);
    }
    Fraction operator-(const Fraction &other) const
    {
        int new_deno = denominator * other.denominator;
        int new_num1 = numerator * other.denominator;
        int new_num2 = other.numerator * denominator;
        int new_diff = new_num1 - new_num2;
        return Fraction(new_diff, new_deno);
    }
    Fraction operator*(const Fraction &other) const
    {
        int new_deno = denominator * other.denominator;
        int new_prod = numerator * other.numerator;
        return Fraction(new_prod, new_deno);
    }
    Fraction operator/(const Fraction &other) const
    {
        int new_deno = denominator * other.numerator;
        int new_prod = numerator * other.denominator;
        return Fraction(new_prod, new_deno);
    }
    bool operator==(const Fraction &other) const
    {
        return numerator * other.denominator == other.numerator * denominator;
    }
    bool operator<(const Fraction &other) const
    {
        return numerator * other.denominator < other.numerator * denominator;
    }
    bool operator>(const Fraction &other) const
    {
        return numerator * other.denominator > other.numerator * denominator;
        ;
    }
    friend std::ostream &operator<<(std::ostream &os, const Fraction &c)
    {
        os << c.numerator << "/" << c.denominator;
        return os;
    }
friend std::istream &operator>>(std::istream &is, Fraction &c)
{
    char slash;
    is >> c.numerator >> slash >> c.denominator;

    while (c.denominator == 0) {
        std::cout << "Error: Denominator cannot be 0. Please enter a valid fraction (format a/b): ";
        is >> c.numerator >> slash >> c.denominator;
    }

    return is;
}
};

int main()
{
    Fraction f1, f2;
    std::cout << "Enter the first fraction (format a/b): ";
    std::cin >> f1;
    std::cout << "Enter the second fraction (format a/b): ";
    std::cin >> f2;

    Fraction sum = f1 + f2;
    sum.simplify();
    std::cout << "f1 + f2 = " << sum << "\n";

    Fraction diff = f1 - f2;
    diff.simplify();
    std::cout << "f1 - f2 = " << diff << "\n";

    Fraction prod = f1 * f2;
    prod.simplify();
    std::cout << "f1 * f2 = " << prod << "\n";

    Fraction quotient = f1 / f2;
    quotient.simplify();
    std::cout << "f1 / f2 = " << quotient << "\n";

    if (f1 == f2)
        std::cout << "f1 is equal to f2"
                  << "\n";
    if (f1 > f2)
        std::cout << "f1 is greater than f2"
                  << "\n";
    if (f1 < f2)
        std::cout << "f1 is less than f2"
                  << "\n";

    return 0;
}