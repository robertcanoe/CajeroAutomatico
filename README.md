# Cajero Automático

Simulador de cajero automático implementado en C++ que permite realizar operaciones bancarias básicas.

## Características

- Consulta de saldo
- Depósitos en efectivo
- Retiros de efectivo
- Cambio de PIN
- Autenticación segura con PIN (con máximo de intentos)
- Manejo preciso de dinero con céntimos

## Estructura del Proyecto

- `main.cpp` - Punto de entrada del programa
- `CuentaBancaria.hpp/cpp` - Implementación de la clase cuenta bancaria
- `Cajero.hpp/cpp` - Interfaz del cajero y autenticación
- `Dinero.hpp/cpp` - Clase para manejo de dinero
- `Utils.hpp/cpp` - Funciones auxiliares para manejo de entrada

## Compilación del Proyecto

### Requisitos Previos

- Compilador C++ (g++)
- Make (opcional)

### Instrucciones de Compilación

Usando g++ directamente:

```bash
g++ main.cpp Dinero.cpp CuentaBancaria.cpp Utils.cpp Cajero.cpp -o cajero
```

O usando VS Code:
1. Abrir el proyecto en VS Code
2. Presionar Ctrl+Shift+B para compilar usando la tarea configurada

## Uso

1. Ejecutar el programa compilado:
```bash
./cajero
```

2. Cuenta de prueba por defecto:
   - Titular: Robert
   - PIN: 1234
   - Saldo inicial: 1000.00 €

3. Sigue el menú en pantalla para:
   - Consultar saldo
   - Depositar dinero
   - Retirar dinero
   - Cambiar PIN
   - Salir

## Características de Seguridad

- El PIN debe ser de 4 dígitos
- Tres intentos fallidos de PIN bloquearán la cuenta
- Validación de entrada para todas las operaciones
- Manejo seguro de dinero con precisión de céntimos

## Autor

Robert Cano

## Licencia

Este proyecto es de código abierto y está disponible bajo la Licencia MIT.