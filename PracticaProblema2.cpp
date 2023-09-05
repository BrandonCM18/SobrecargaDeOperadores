#include <iostream>
#include <string>

class Materia {
private:
    std::string clave;
    std::string nombre;
    std::string profesortit;
    std::string libroTexto;

public:
    // Constructor
    Materia(const std::string& clave, const std::string& nombre, const std::string& profesortit, const std::string& libroTexto)
        : clave(clave), nombre(nombre), profesortit(profesortit), libroTexto(libroTexto) {}

    // Sobrecarga del operador de igualdad (==)
    bool operator==(const Materia& other) const {
        return clave == other.clave;
    }

    // Sobrecarga del operador de desigualdad (!=)
    bool operator!=(const Materia& other) const {
        return clave != other.clave;
    }

    // Sobrecarga del operador de entrada (>>)
    friend std::istream& operator>>(std::istream& input, Materia& materia) {
        std::cout << "Ingrese clave: ";
        input >> materia.clave;
        std::cout << "Ingrese nombre: ";
        input >> materia.nombre;
        std::cout << "Ingrese maestro: ";
        input >> materia.profesortit;
        std::cout << "Ingrese libro de texto: ";
        input >> materia.libroTexto;
        return input;
    }

    // Sobrecarga del operador de salida (<<)
    friend std::ostream& operator<<(std::ostream& output, const Materia& materia) {
        output << "Clave: " << materia.clave << "\n";
        output << "Nombre: " << materia.nombre << "\n";
        output << "Maestro: " << materia.profesortit << "\n";
        output << "Libro de texto: " << materia.libroTexto << "\n";
        return output;
    }

    // Sobrecarga del operador de suma (+)
    Materia operator+(const Materia& other) const {
        return Materia(clave + other.clave, nombre, profesortit, libroTexto + ", " + other.libroTexto);
    }

    // Sobrecarga del operador menor que (<)
    bool operator<(const Materia& other) const {
        return clave < other.clave;
    }

    // Sobrecarga del operador mayor que (>)
    bool operator>(const Materia& other) const {
        return clave > other.clave;
    }

    // Getter para el nombre del libro de texto
    std::string getLibroTexto() const {
        return libroTexto;
    }

    // Setter para cambiar la clave de la materia
    void cambiarClave(const std::string& nuevaClave) {
        clave = nuevaClave;
    }

    // Setter para cambiar el nombre del maestro
    void cambiarMaestro(const std::string& nuevoMaestro) {
        profesortit = nuevoMaestro;
    }
};

int main() {
    Materia Programacion("PRO2023", "Programacion I", "Jairo Cain", "Fundamentos de la programacion");
    Materia BasesDatos("BD2023", "Bases de Datos I", "Oscar Didier", "Bases de datos");

    int opcion;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Cambiar clave de Programacion\n";
        std::cout << "2. Cambiar nombre del maestro de Bases de Datos\n";
        std::cout << "3. Imprimir datos de Bases de Datos\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese la nueva clave para Programacion: \n";
                std::cin >> Programacion;
                break;
            case 2:
                std::cout << "Ingrese el nuevo nombre del maestro de Bases de Datos: \n";
                std::cin >> BasesDatos;
                break;
            case 3:
                std::cout << "Datos de Bases de Datos:\n" << BasesDatos;
                std::cout << "Libro de texto: \n" << BasesDatos.getLibroTexto() << "\n";
                break;
            case 4:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 4);

    return 0;
}
