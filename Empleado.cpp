#include "Empleado.h"
#include <stdexcept>

Empleado::Empleado(int idEmpleado, const std::string& nombre, const std::string& puesto, double salario)
    : idEmpleado(idEmpleado), nombre(nombre), puesto(puesto), salario(salario) {
    if (idEmpleado <= 0) {
        throw std::invalid_argument("El ID del empleado debe ser un número positivo.");
    }
    if (nombre.empty()) {
        throw std::invalid_argument("El nombre no puede estar vacío.");
    }
    if (puesto.empty()) {
        throw std::invalid_argument("El puesto no puede estar vacío.");
    }
    if (salario < 0) {
        throw std::invalid_argument("El salario no puede ser negativo.");
    }
}

int Empleado::getIdEmpleado() const { return idEmpleado; }
std::string Empleado::getNombre() const { return nombre; }
std::string Empleado::getPuesto() const { return puesto; }
double Empleado::getSalario() const { return salario; }

void Empleado::setNombre(const std::string& nombre) { this->nombre = nombre; }
void Empleado::setPuesto(const std::string& puesto) { this->puesto = puesto; }
void Empleado::setSalario(double salario) { this->salario = salario; }
