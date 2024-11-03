#include "Factura.h"
#include <stdexcept>

Factura::Factura(int idFactura, int idCliente, const std::string& fechaFactura, double totalFactura, const std::vector<ProductoVendido>& productosVendidos)
    : idFactura(idFactura), idCliente(idCliente), fechaFactura(fechaFactura), totalFactura(totalFactura), productosVendidos(productosVendidos) {
    if (idFactura <= 0) {
        throw std::invalid_argument("El ID de la factura debe ser un número positivo.");
    }
    if (idCliente <= 0) {
        throw std::invalid_argument("El ID del cliente debe ser un número positivo.");
    }
    if (fechaFactura.empty()) {
        throw std::invalid_argument("La fecha de la factura no puede estar vacía.");
    }
    if (totalFactura < 0) {
        throw std::invalid_argument("El total de la factura no puede ser negativo.");
    }
    if (productosVendidos.empty()) {
        throw std::invalid_argument("La lista de productos vendidos no puede estar vacía.");
    }
}

int Factura::getIdFactura() const { return idFactura; }
int Factura::getIdCliente() const { return idCliente; }
std::string Factura::getFechaFactura() const { return fechaFactura; }
double Factura::getTotalFactura() const { return totalFactura; }
std::vector<ProductoVendido> Factura::getProductosVendidos() const { return productosVendidos; }

void Factura::setIdCliente(int idCliente) { this->idCliente = idCliente; }
void Factura::setFechaFactura(const std::string& fechaFactura) { this->fechaFactura = fechaFactura; }
void Factura::setTotalFactura(double totalFactura) { this->totalFactura = totalFactura; }
void Factura::setProductosVendidos(const std::vector<ProductoVendido>& productosVendidos) { this->productosVendidos = productosVendidos; }