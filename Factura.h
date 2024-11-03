#include <string>
#include <vector>

struct ProductoVendido {
    int idProducto;
    int cantidad;
    double precioVenta;
};

class Factura {
private:
    int idFactura;
    int idCliente;
    std::string fechaFactura;
    double totalFactura;
    std::vector<ProductoVendido> productosVendidos;

public:
    Factura(int idFactura, int idCliente, const std::string& fechaFactura, double totalFactura, const std::vector<ProductoVendido>& productosVendidos);

    int getIdFactura() const;
    int getIdCliente() const;
    std::string getFechaFactura() const;
    double getTotalFactura() const;
    std::vector<ProductoVendido> getProductosVendidos() const;

    void setIdCliente(int idCliente);
    void setFechaFactura(const std::string& fechaFactura);
    void setTotalFactura(double totalFactura);
    void setProductosVendidos(const std::vector<ProductoVendido>& productosVendidos);
};