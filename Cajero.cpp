#include "Cajero.hpp"
#include "Utils.hpp"
#include <iostream>

void mostrarMenu() {
    std::cout << "\n===== CAJERO AUTOMÁTICO =====\n";
    std::cout << "1. Consultar saldo\n";
    std::cout << "2. Ingresar dinero\n";
    std::cout << "3. Retirar dinero\n";
    std::cout << "4. Cambiar PIN\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opción: ";
}

bool autenticar(CuentaBancaria& cuenta, int maxIntentos) {
    int intentos = 0;
    while (intentos < maxIntentos) {
        int pin = leerEntero("Introduce tu PIN: ");
        if (cuenta.verificarPIN(pin)) {
            std::cout << "\n¡Bienvenido, " << cuenta.getTitular() << "!\n";
            return true;
        }
        std::cout << "PIN incorrecto. Intentos restantes: " << (maxIntentos - intentos - 1) << "\n";
        intentos++;
    }
    std::cout << "Has superado el número máximo de intentos. Cuenta bloqueada.\n";
    return false;
}