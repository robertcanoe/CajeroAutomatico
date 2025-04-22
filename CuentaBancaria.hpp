#ifndef CUENTA_BANCARIA_HPP
#define CUENTA_BANCARIA_HPP

#include <string>
#include "Dinero.hpp"

class CuentaBancaria {
private:
    std::string titular;
    int pin;
    Dinero saldo;

    void validarPIN(int nuevoPIN);

public:
    CuentaBancaria(std::string nombre, int pinInicial, double saldoInicial);
    bool verificarPIN(int intento) const;
    double consultarSaldo() const;
    void ingresar(double cantidad);
    bool retirar(double cantidad);
    void cambiarPIN(int nuevoPIN);
    std::string getTitular() const;
};

#endif // CUENTA_BANCARIA_HPP
