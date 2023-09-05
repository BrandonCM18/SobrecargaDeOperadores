#include <iostream>
#include <string>

class Empleado {
private:
    int clave;
    std::string nombre;
    std::string domicilio;
    double sueldo;
    std::string jefe;

public:
    Empleado(int _clave, std::string _nombre, std::string _domicilio, double _sueldo, std::string _jefe)
        : clave(_clave), nombre(_nombre), domicilio(_domicilio), sueldo(_sueldo), jefe(_jefe) {}

    void CambiarDomicilio(const std::string& nuevoDomicilio) {
        domicilio = nuevoDomicilio;
    }

    void ActualizarSueldo(double porcentajeIncremento) {
        sueldo += sueldo * (porcentajeIncremento / 100.0);
    }

    void CambiarJefe(const std::string& nuevoJefe) {
        jefe = nuevoJefe;
    }

    void ImprimirDatos() const {
        std::cout << "Clave de empleado: " << clave << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Domicilio: " << domicilio << std::endl;
        std::cout << "Sueldo: " << sueldo << std::endl;
        std::cout << "Persona a quien reporta: " << jefe << std::endl;
    }


    friend std::ostream& operator<<(std::ostream& os, const Empleado& empleado) {
        os << "Clave de empleado: " << empleado.clave << std::endl;
        os << "Nombre: " << empleado.nombre << std::endl;
        os << "Domicilio: " << empleado.domicilio << std::endl;
        os << "Sueldo: " << empleado.sueldo << std::endl;
        os << "Persona a quien reporta: " << empleado.jefe << std::endl;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Empleado& empleado) {
        std::cout << "Ingrese la clave del empleado: ";
        is >> empleado.clave;
        std::cout << "Ingrese el nombre del empleado: ";
        is.ignore();
        std::getline(is, empleado.nombre);
        std::cout << "Ingrese el domicilio del empleado: ";
        std::getline(is, empleado.domicilio);
        std::cout << "Ingrese el sueldo del empleado: ";
        is >> empleado.sueldo;
        std::cout << "Ingrese el jefe del empleado: ";
        is.ignore();
        std::getline(is, empleado.jefe);
        return is;
    }
};

int main() {
    Empleado empleado1(1, "Brandon Chavez", "Isla Gomera", 15000.0 , "Jefe primero");
    Empleado empleado2(2, "Maria Medrano", "Rafael Lozada", 10000.0 , "Jefe segundo");

    int opcion;
    do {
        std::cout << "\nMenu de opciones: (Las claves de los empleados son 1 y 2 respectivamente)" << std::endl;
        std::cout << "1. Cambiar domicilio de un empleado." << std::endl;
        std::cout << "2. Actualizar sueldo de un empleado." << std::endl;
        std::cout << "3. Imprimir datos de un empleado." << std::endl;
        std::cout << "4. Cambiar jefe de un empleado." << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int clave;
                std::string nuevoDomicilio;
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                std::cout << "Ingrese el nuevo domicilio: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoDomicilio);
                if (clave == 1) {
                    empleado1.CambiarDomicilio(nuevoDomicilio);
                } else if (clave == 2) {
                    empleado2.CambiarDomicilio(nuevoDomicilio);
                } else {
                    std::cout << "Clave de empleado no valida." << std::endl;
                }
                break;
            }
            case 2: {
                int clave;
                double porcentajeIncremento;
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                std::cout << "Ingrese el porcentaje de incremento: ";
                std::cin >> porcentajeIncremento;
                if (clave == 1) {
                    empleado1.ActualizarSueldo(porcentajeIncremento);
                } else if (clave == 2) {
                    empleado2.ActualizarSueldo(porcentajeIncremento);
                } else {
                    std::cout << "Clave de empleado no vslida." << std::endl;
                }
                break;
            }
            case 3: {
                int clave;
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                if (clave == 1) {
                    std::cout << empleado1;
                } else if (clave == 2) {
                    std::cout << empleado2;
                } else {
                    std::cout << "Clave de empleado no valida." << std::endl;
                }
                break;
            }
            case 4: {
                int clave;
                std::string nuevoJefe;
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                std::cout << "Ingrese el nuevo jefe: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoJefe);
                if (clave == 1) {
                    empleado1.CambiarJefe(nuevoJefe);
                } else if (clave == 2) {
                    empleado2.CambiarJefe(nuevoJefe);
                } else {
                    std::cout << "Clave de empleado no valida." << std::endl;
                }
                break;
            }
            case 5:
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}
