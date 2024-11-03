#include <string>

class Cliente
{
private:
    int idCliente;
    std::string nombre;
    std::string fechaNacimiento;

public:
    Cliente(int idCliente, const std::string& nombre, const std::string& fechaNacimiento);

    int getIdCliente() const;
    std::string getNombre() const;
    std::string getFechaNacimiento() const;

    void setNombre(const std::string& nombre);
    void setFechaNacimiento(const std::string& fechaNacimiento);
};