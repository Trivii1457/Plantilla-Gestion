#include "Producto.h"
#include <stdexcept>

Producto::Producto(int idProducto, const std::string& nombre, int cantidad, double precioVenta, const std::string& fechaVencimiento)
    : idProducto(idProducto), nombre(nombre), cantidad(cantidad), precioVenta(precioVenta), fechaVencimiento(fechaVencimiento) {
    if (idProducto <= 0) {
        throw std::invalid_argument("El ID del producto debe ser un número positivo.");
    }
    if (nombre.empty()) {
        throw std::invalid_argument("El nombre no puede estar vacío.");
    }
    if (cantidad < 0) {
        throw std::invalid_argument("La cantidad no puede ser negativa.");
    }
    if (precioVenta < 0) {
        throw std::invalid_argument("El precio de venta no puede ser negativo.");
    }
    if (fechaVencimiento.empty()) {
        throw std::invalid_argument("La fecha de vencimiento no puede estar vacía.");
    }
}

int Producto::getIdProducto() const { return idProducto; }
std::string Producto::getNombre() const { return nombre; }
int Producto::getCantidad() const { return cantidad; }
double Producto::getPrecioVenta() const { return precioVenta; }
std::string Producto::getFechaVencimiento() const { return fechaVencimiento; }

void Producto::setNombre(const std::string& nombre) { this->nombre = nombre; }
void Producto::setCantidad(int cantidad) { this->cantidad = cantidad; }
void Producto::setPrecioVenta(double precioVenta) { this->precioVenta = precioVenta; }
void Producto::setFechaVencimiento(const std::string& fechaVencimiento) { this->fechaVencimiento = fechaVencimiento; }