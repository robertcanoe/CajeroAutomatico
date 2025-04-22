#include "CuentaBancaria.hpp"
#include <iostream>
#include <iomanip>

CuentaBancaria::CuentaBancaria(std::string nombre, int pinInicial, double saldoInicial)
    : titular(nombre), pin(pinInicial), saldo(saldoInicial) {
    validarPIN(pinInicial);
}

void CuentaBancaria::validarPIN(int nuevoPIN) {
    if (nuevoPIN < 1000 || nuevoPIN > 9999) {
        throw std::invalid_argument("El PIN debe ser un número de 4 dígitos.");
    }
}

bool CuentaBancaria::verificarPIN(int intento) const {
    return intento == pin;
}

double CuentaBancaria::consultarSaldo() const {
    return saldo.toEuros();
}

void CuentaBancaria::ingresar(double cantidad) {
    if (cantidad <= 0) {
        std::cout << "Error: La cantidad a ingresar debe ser positiva.\n";
        return;
    }
    saldo = saldo + Dinero(cantidad);
    std::cout << "Ingreso de " << std::fixed << std::setprecision(2) << cantidad
              << " € realizado correctamente.\n";
}

bool CuentaBancaria::retirar(double cantidad) {
    if (cantidad <=	0) {
        std::cout << "Error: La cantidad a retirar debe ser positiva.\n";
        return false;
    }
    Dinero monto(cantidad);
    if (monto >= saldo) {
        std::cout << "Error: Saldo insuficiente.\n";
        return false;
    }
    saldo = saldo - monto;
    std::cout << "Retiro de " << std::fixed << std::setprecision(2) << cantidad
              << " € realizado correctamente.\n";
    return true;
}

void CuentaBancaria::cambiarPIN(int nuevoPIN) {
    try {
        validarPIN(nuevoPIN);
        pin = nuevoPIN;
        std::cout << "PIN cambiado correctamente.\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

std::string CuentaBancaria::getTitular() const {
    return titular;
}