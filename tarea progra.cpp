#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <limits>

// Clase Pregunta
class Pregunta {
private:
    int id;
    std::string enunciado;
    std::string tipo;
    std::string respuesta;
    std::string nivel;
    int year; 
    int tiempo;

public:
    Pregunta(int _id, const std::string& _enunciado, const std::string& _tipo, const std::string& _respuesta, const std::string& _nivel, int _year, int _tiempo)
        : id(_id), enunciado(_enunciado), tipo(_tipo), respuesta(_respuesta), nivel(_nivel), year(_year), tiempo(_tiempo) {}

    int getId() const { return id; }
    std::string getNivel() const { return nivel; }
    int getTiempo() const { return tiempo; }
    int getYear() const { return year; } 

    void setYear(int _year) { year = _year; } 

    void actualizar(const std::string& _enunciado, const std::string& _tipo, const std::string& _respuesta, const std::string& _nivel, int _year, int _tiempo) {
        enunciado = _enunciado;
        tipo = _tipo;
        respuesta = _respuesta;
        nivel = _nivel;
        year = _year;
        tiempo = _tiempo;
    }

    void mostrar() const {
        std::cout << "\nID: " << id
                  << "\nEnunciado: " << enunciado
                  << "\nTipo: " << tipo
                  << "\nRespuesta esperada: " << respuesta
                  << "\nNivel taxonómico: " << nivel
                  << "\nAño: " << year // Mostrar el año
                  << "\nTiempo estimado: " << tiempo << " minutos\n";
    }
};

// Clase BancoPreguntas
class BancoPreguntas {
private:
    std::vector<Pregunta> preguntas;

public:
    void agregarPregunta(const Pregunta& p) {
        preguntas.push_back(p);
    }

    bool eliminarPregunta(int id) {
        auto it = std::remove_if(preguntas.begin(), preguntas.end(),
            [id](const Pregunta& p) { return p.getId() == id; });
        if (it != preguntas.end()) {
            preguntas.erase(it, preguntas.end());
            return true;
        }
        return false;
    }

    Pregunta* buscarPorId(int id) {
        for (auto& p : preguntas) {
            if (p.getId() == id) return &p;
        }
        return nullptr;
    }

    void mostrarPorNivel(const std::string& nivel) const {
        for (const auto& p : preguntas) {
            if (p.getNivel() == nivel) {
                p.mostrar();
            }
        }
    }

    void mostrarTodas() const {
        for (const auto& p : preguntas) {
            p.mostrar();
        }
    }

    std::vector<Pregunta> obtenerPreguntasNivel(const std::string& nivel, int cantidad) const {
        std::vector<Pregunta> seleccionadas;
        for (const auto& p : preguntas) {
            if (p.getNivel() == nivel) {
                seleccionadas.push_back(p);
                if (seleccionadas.size() == cantidad) break;
            }
        }
        return seleccionadas;
    }
};

// Clase Evaluacion
class Evaluacion {
private:
    std::vector<Pregunta> preguntas;

public:
    void agregarPregunta(const Pregunta& p) {
        preguntas.push_back(p);
    }

    int calcularTiempoTotal() const {
        int total = 0;
        for (const auto& p : preguntas) {
            total += p.getTiempo();
        }
        return total;
    }

    void mostrarEvaluacion() const {
        std::cout << "\n--- Evaluación Generada ---\n";
        for (const auto& p : preguntas) {
            p.mostrar();
        }
        std::cout << "\nTiempo total estimado: " << calcularTiempoTotal() << " minutos\n";
    }
};


int leerEntero(const std::string& mensaje) {
    int valor;
    while (true) {
        std::cout << mensaje;
        std::cin >> valor;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Intente de nuevo.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }
    }
}

// Función para manejar la entrada de una cadena
std::string leerCadena(const std::string& mensaje) {
    std::string valor;
    std::cout << mensaje;
    std::getline(std::cin, valor);
    return valor;
}

// Función principal
int main() {
    BancoPreguntas banco;
    int opcion;

    do {
        std::cout << "\n===== MENÚ =====\n";
        std::cout << "1. Crear pregunta\n";
        std::cout << "2. Actualizar pregunta\n";
        std::cout << "3. Borrar pregunta\n";
        std::cout << "4. Consultar pregunta\n";
        std::cout << "5. Buscar por nivel\n";
        std::cout << "6. Generar evaluación\n";
        std::cout << "7. Mostrar todas\n";
        std::cout << "0. Salir\nOpción: ";
        opcion = leerEntero("");

        switch (opcion) {
            case 1: {
                int id = leerEntero("ID: ");
                std::string enunciado = leerCadena("Enunciado: ");
                std::string tipo = leerCadena("Tipo (VF/OM): ");
                std::string respuesta = leerCadena("Respuesta esperada: ");
                std::string nivel = leerCadena("Nivel taxonómico: ");
                int year = leerEntero("Año: "); // Solicitar el año
                int tiempo = leerEntero("Tiempo estimado (min): ");
                banco.agregarPregunta(Pregunta(id, enunciado, tipo, respuesta, nivel, year, tiempo));
                break;
            }
            case 2: {
                int id = leerEntero("ID de pregunta a actualizar: ");
                Pregunta* p = banco.buscarPorId(id);
                if (p) {
                    std::string enunciado = leerCadena("Nuevo enunciado: ");
                    std::string tipo = leerCadena("Nuevo tipo: ");
                    std::string respuesta = leerCadena("Nueva respuesta: ");
                    std::string nivel = leerCadena("Nuevo nivel: ");
                    int year = leerEntero("Nuevo año: "); // Solicitar el nuevo año
                    int tiempo = leerEntero("Nuevo tiempo: ");
                    p->actualizar(enunciado, tipo, respuesta, nivel, year, tiempo);
                } else {
                    std::cout << "Pregunta no encontrada.\n";
                }
                break;
            }
            case 3: {
                int id = leerEntero("ID a borrar: ");
                if (banco.eliminarPregunta(id)) {
                    std::cout << "Pregunta eliminada.\n";
                } else {
                    std::cout << "Pregunta no encontrada.\n";
                }
                break;
            }
            case 4: {
                int id = leerEntero("ID a consultar: ");
                Pregunta* p = banco.buscarPorId(id);
                if (p) {
                    p->mostrar();
                } else {
                    std::cout << "Pregunta no encontrada.\n";
                }
                break;
            }
            case 5: {
                std::string nivel = leerCadena("Nivel taxonómico a buscar: ");
                banco.mostrarPorNivel(nivel);
                break;
            }
            case 6: {
                std::string nivel = leerCadena("Nivel a incluir en evaluación: ");
                int cantidad = leerEntero("Cantidad de preguntas: ");
                Evaluacion eval;
                auto seleccionadas = banco.obtenerPreguntasNivel(nivel, cantidad);
                if (seleccionadas.size() < cantidad) {
                    std::cout << "No hay suficientes preguntas disponibles en este nivel.\n";
                }
                for (const auto& p : seleccionadas) {
                    eval.agregarPregunta(p);
                }
                eval.mostrarEvaluacion();
                break;
            }
            case 7:
                banco.mostrarTodas();
                break;
            case 0:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
        }
    } while (opcion != 0);

    return 0;
}





