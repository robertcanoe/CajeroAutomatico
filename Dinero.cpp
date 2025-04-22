#include "Dinero.hpp"

Dinero::Dinero(double euros) : centavos(static_cast<long long>(euros * 100)) {}

double Dinero::toEuros() const {
    return centavos / 100.0;
}

Dinero Dinero::operator+(const Dinero& other) const {
    return Dinero(centavos + other.centavos);
}

Dinero Dinero::operator-(const Dinero& other) const {
    return Dinero(centavos - other.centavos);
}

bool Dinero::operator>=(const Dinero& other) const {
    return centavos >= other.centavos;
}

Dinero::operator double() const {
    return toEuros();
}
