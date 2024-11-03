#include <string>

class Producto {
private:
    int idProducto;
    std::string nombre;
    int cantidad;
    double precioVenta;
    std::string fechaVencimiento;

public:
    Producto(int idProducto, const std::string& nombre, int cantidad, double precioVenta, const std::string& fechaVencimiento);

    int getIdProducto() const;
    std::string getNombre() const;
    int getCantidad() const;
    double getPrecioVenta() const;
    std::string getFechaVencimiento() const;

    void setNombre(const std::string& nombre);
    void setCantidad(int cantidad);
    void setPrecioVenta(double precioVenta);
    void setFechaVencimiento(const std::string& fechaVencimiento);
};