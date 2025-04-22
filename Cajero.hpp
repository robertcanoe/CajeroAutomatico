#ifndef CAJERO_HPP
#define CAJERO_HPP

#include "CuentaBancaria.hpp"

void mostrarMenu();
bool autenticar(CuentaBancaria& cuenta, int maxIntentos);

#endif // CAJERO_HPP