#include "Utils.hpp"
#include <iostream>
#include <limits>
#include <string>

void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int leerEntero(const std::string& mensaje) {
    std::string entrada;
    int valor;

    while (true) {
        std::cout << mensaje;
        std::getline(std::cin, entrada);

        // Si la entrada está vacía (solo Enter), pedir de nuevo
        if (entrada.empty()) {
            std::cout << "Error: No se ingresó ningún valor. Por favor, introduce un número válido.\n";
            continue;
        }

        // Intentar convertir la entrada a un entero
        try {
            size_t pos;
            valor = std::stoi(entrada, &pos);

            // Verificar si toda la entrada fue un número (no hay caracteres sobrantes)
            if (pos != entrada.length()) {
                throw std::invalid_argument("Entrada inválida");
            }

            return valor;
        } catch (...) {
            std::cout << "Error: Por favor, introduce un número entero válido.\n";
        }
    }
}

double leerDouble(const std::string& mensaje) {
    std::string entrada;
    double valor;

    while (true) {
        std::cout << mensaje;
        std::getline(std::cin, entrada); // Leer toda la línea como string

        // Si la entrada está vacía (solo Enter), pedir de nuevo
        if (entrada.empty()) {
            std::cout << "Error: No se ingresó ningún valor. Por favor, introduce un número válido.\n";
            continue;
        }

        // Intentar convertir la entrada a un double
        try {
            size_t pos;
            valor = std::stod(entrada, &pos);

            // Verificar si toda la entrada fue un número (no hay caracteres sobrantes)
            if (pos != entrada.length()) {
                throw std::invalid_argument("Entrada inválida");
            }

            return valor;
        } catch (...) {
            std::cout << "Error: Por favor, introduce un número válido.\n";
        }
    }
}