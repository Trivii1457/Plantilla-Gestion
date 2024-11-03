#include <string>

class Empleado {
private:
    int idEmpleado;
    std::string nombre;
    std::string puesto;
    double salario;

public:
    Empleado(int idEmpleado, const std::string& nombre, const std::string& puesto, double salario);

    int getIdEmpleado() const;
    std::string getNombre() const;
    std::string getPuesto() const;
    double getSalario() const;

    void setNombre(const std::string& nombre);
    void setPuesto(const std::string& puesto);
    void setSalario(double salario);
};