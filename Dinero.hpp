#ifndef DINERO_HPP
#define DINERO_HPP

class Dinero {
private:
    long long centavos;
    Dinero(long long c) : centavos(c) {}

public:
    Dinero(double euros);
    double toEuros() const;
    Dinero operator+(const Dinero& other) const;
    Dinero operator-(const Dinero& other) const;
    bool operator>=(const Dinero& other) const;
    explicit operator double() const;
};

#endif // DINERO_HPP
