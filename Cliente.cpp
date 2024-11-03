#include "Cliente.h"
#include <stdexcept>

Cliente::Cliente(int idCliente, const std::string& nombre, const std::string& fechaNacimiento)
    : idCliente(idCliente), nombre(nombre), fechaNacimiento(fechaNacimiento)
{
    if (idCliente <= 0)
    {
        throw std::invalid_argument("El ID del cliente debe ser un número positivo.");
    }

    if (nombre.empty())
    {
        throw std::invalid_argument("El nombre no puede estar vacío.");
    }

    if (fechaNacimiento.empty())
    {
        throw std::invalid_argument("La fecha de nacimiento no puede estar vacía.");
    }
}

int Cliente::getIdCliente() const { return idCliente; }
std::string Cliente::getNombre() const { return nombre; }
std::string Cliente::getFechaNacimiento() const { return fechaNacimiento; }

void Cliente::setNombre(const std::string& nombre) { this->nombre = nombre; }
void Cliente::setFechaNacimiento(const std::string& fechaNacimiento) { this->fechaNacimiento = fechaNacimiento; }