#include "CuentaBancaria.hpp"
#include "Cajero.hpp"
#include "Utils.hpp"
#include <iostream>
#include <iomanip>

int main() {
    try {
        CuentaBancaria cuenta("Robert", 1234, 1000.0);
        const int maxIntentos = 3;

        std::cout << "Bienvenido al cajero automático\n";

        if (!autenticar(cuenta, maxIntentos)) {
            return 1;
        }

        int opcion;
        do {
            mostrarMenu();
            opcion = leerEntero("");
            clean_terminal();
            switch (opcion) {
            case 1:
                std::cout << "Saldo actual: " << std::fixed << std::setprecision(2)
                          << cuenta.consultarSaldo() << " €\n";
                break;
            case 2: {
                double ingreso = leerDouble("Cantidad a ingresar: ");
                cuenta.ingresar(ingreso);
                break;
            }
            case 3: {
                double retiro = leerDouble("Cantidad a retirar: ");
                cuenta.retirar(retiro);
                break;
            }
            case 4: {
                int nuevoPIN = leerEntero("Nuevo PIN: ");
                cuenta.cambiarPIN(nuevoPIN);
                break;
            }
            case 5:
                std::cout << "Gracias por usar el cajero. ¡Hasta pronto!\n";
                break;
            default:
                std::cout << "Opción inválida. Por favor, selecciona una opción válida.\n";
                break;
            }
        } while (opcion != 5);

    } catch (const std::exception& e) {
        std::cerr << "Error inesperado: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
