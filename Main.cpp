#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Cliente.cpp"
#include "Producto.cpp"
#include "Empleado.cpp"

// Funciones CRUD para Cliente
void crearCliente(std::vector<Cliente>& clientes);
void leerClientes(const std::vector<Cliente>& clientes);
void actualizarCliente(std::vector<Cliente>& clientes);
void eliminarCliente(std::vector<Cliente>& clientes);

// Funciones CRUD para Producto
void crearProducto(std::vector<Producto>& productos);
void leerProductos(const std::vector<Producto>& productos);
void actualizarProducto(std::vector<Producto>& productos);
void eliminarProducto(std::vector<Producto>& productos);

// Funciones CRUD para Empleado
void crearEmpleado(std::vector<Empleado>& empleados);
void leerEmpleados(const std::vector<Empleado>& empleados);
void actualizarEmpleado(std::vector<Empleado>& empleados);
void eliminarEmpleado(std::vector<Empleado>& empleados);

// Menús
void menuClientes(std::vector<Cliente>& clientes);
void menuProductos(std::vector<Producto>& productos);
void menuEmpleados(std::vector<Empleado>& empleados);
void menuPrincipal();

int main() {
    menuPrincipal();
    return 0;
}

void menuPrincipal() {
    std::vector<Cliente> clientes;
    std::vector<Producto> productos;
    std::vector<Empleado> empleados;

    int eleccion;
    do {
        std::cout << "\n--- Menu Principal ---\n";
        std::cout << "1. Clientes\n";
        std::cout << "2. Productos\n";
        std::cout << "3. Empleados\n";
        std::cout << "4. Salir\n";
        std::cin >> eleccion;
        switch (eleccion) {
            case 1:
                menuClientes(clientes);
                break;
            case 2:
                menuProductos(productos);
                break;
            case 3:
                menuEmpleados(empleados);
                break;
            case 4:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no valida. Intente nuevamente.\n";
                break;
        }
    } while (eleccion != 4);
}

void menuClientes(std::vector<Cliente>& clientes) {
    int opcion;
    do {
        std::cout << "\n--- Menu Clientes ---\n";
        std::cout << "1. Crear Cliente\n";
        std::cout << "2. Leer Clientes\n";
        std::cout << "3. Actualizar Cliente\n";
        std::cout << "4. Eliminar Cliente\n";
        std::cout << "5. Volver al Menu Principal\n";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
            case 1:
                crearCliente(clientes);
                break;
            case 2:
                leerClientes(clientes);
                break;
            case 3:
                actualizarCliente(clientes);
                break;
            case 4:
                eliminarCliente(clientes);
                break;
            case 5:
                std::cout << "Volviendo al Menu Principal...\n";
                break;
            default:
                std::cout << "Opción no valida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 5);
}

void crearCliente(std::vector<Cliente>& clientes) {
    int id;
    std::string nombre, fechaNacimiento;
    std::cout << "Ingrese ID del cliente: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Ingrese nombre del cliente: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese fecha de nacimiento del cliente: ";
    std::getline(std::cin, fechaNacimiento);

    try {
        Cliente nuevoCliente(id, nombre, fechaNacimiento);
        clientes.push_back(nuevoCliente);
        std::cout << "Cliente creado exitosamente.\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

void leerClientes(const std::vector<Cliente>& clientes) {
    for (const auto& cliente : clientes) {
        std::cout << "ID: " << cliente.getIdCliente() << ", Nombre: " << cliente.getNombre() << ", Fecha de Nacimiento: " << cliente.getFechaNacimiento() << '\n';
    }
}

void actualizarCliente(std::vector<Cliente>& clientes) {
    int id;
    std::cout << "Ingrese ID del cliente a actualizar: ";
    std::cin >> id;
    std::cin.ignore();

    for (auto& cliente : clientes) {
        if (cliente.getIdCliente() == id) {
            std::string nombre, fechaNacimiento;
            std::cout << "Ingrese nuevo nombre del cliente: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese nueva fecha de nacimiento del cliente: ";
            std::getline(std::cin, fechaNacimiento);

            cliente.setNombre(nombre);
            cliente.setFechaNacimiento(fechaNacimiento);
            std::cout << "Cliente actualizado exitosamente.\n";
            return;
        }
    }
    std::cout << "Cliente no encontrado.\n";
}

void eliminarCliente(std::vector<Cliente>& clientes) {
    int id;
    std::cout << "Ingrese ID del cliente a eliminar: ";
    std::cin >> id;
    std::cin.ignore();

    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->getIdCliente() == id) {
            clientes.erase(it);
            std::cout << "Cliente eliminado exitosamente.\n";
            return;
        }
    }
    std::cout << "Cliente no encontrado.\n";
}

void menuProductos(std::vector<Producto>& productos) {
    int opcion;
    do {
        std::cout << "\n--- Menú Productos ---\n";
        std::cout << "1. Crear Producto\n";
        std::cout << "2. Leer Productos\n";
        std::cout << "3. Actualizar Producto\n";
        std::cout << "4. Eliminar Producto\n";
        std::cout << "5. Volver al Menú Principal\n";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
            case 1:
                crearProducto(productos);
                break;
            case 2:
                leerProductos(productos);
                break;
            case 3:
                actualizarProducto(productos);
                break;
            case 4:
                eliminarProducto(productos);
                break;
            case 5:
                std::cout << "Volviendo al Menú Principal...\n";
                break;
            default:
                std::cout << "Opción no válida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 5);
}

void crearProducto(std::vector<Producto>& productos) {
    int id, cantidad;
    double precioVenta;
    std::string nombre, fechaVencimiento;

    std::cout << "Ingrese ID del producto: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Ingrese nombre del producto: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese cantidad del producto: ";
    std::cin >> cantidad;
    std::cin.ignore();
    std::cout << "Ingrese precio de venta del producto: ";
    std::cin >> precioVenta;
    std::cin.ignore();
    std::cout << "Ingrese fecha de vencimiento del producto: ";
    std::getline(std::cin, fechaVencimiento);

    try {
        Producto nuevoProducto(id, nombre, cantidad, precioVenta, fechaVencimiento);
        productos.push_back(nuevoProducto);
        std::cout << "Producto creado exitosamente.\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

void leerProductos(const std::vector<Producto>& productos) {
    for (const auto& producto : productos) {
        std::cout << "ID: " << producto.getIdProducto() << ", Nombre: " << producto.getNombre() << ", Cantidad: " << producto.getCantidad() << ", Precio de Venta: " << producto.getPrecioVenta() << ", Fecha de Vencimiento: " << producto.getFechaVencimiento() << '\n';
    }
}

void actualizarProducto(std::vector<Producto>& productos) {
    int id;
    std::cout << "Ingrese ID del producto a actualizar: ";
    std::cin >> id;
    std::cin.ignore();

    for (auto& producto : productos) {
        if (producto.getIdProducto() == id) {
            std::string nombre, fechaVencimiento;
            int cantidad;
            double precioVenta;

            std::cout << "Ingrese nuevo nombre del producto: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese nueva cantidad del producto: ";
            std::cin >> cantidad;
            std::cin.ignore();
            std::cout << "Ingrese nuevo precio de venta del producto: ";
            std::cin >> precioVenta;
            std::cin.ignore();
            std::cout << "Ingrese nueva fecha de vencimiento del producto: ";
            std::getline(std::cin, fechaVencimiento);

            producto.setNombre(nombre);
            producto.setCantidad(cantidad);
            producto.setPrecioVenta(precioVenta);
            producto.setFechaVencimiento(fechaVencimiento);
            std::cout << "Producto actualizado exitosamente.\n";
            return;
        }
    }
    std::cout << "Producto no encontrado.\n";
}

void eliminarProducto(std::vector<Producto>& productos) {
    int id;
    std::cout << "Ingrese ID del producto a eliminar: ";
    std::cin >> id;
    std::cin.ignore();

    for (auto it = productos.begin(); it != productos.end(); ++it) {
        if (it->getIdProducto() == id) {
            productos.erase(it);
            std::cout << "Producto eliminado exitosamente.\n";
            return;
        }
    }
    std::cout << "Producto no encontrado.\n";
}

void menuEmpleados(std::vector<Empleado>& empleados) {
    int opcion;
    do {
        std::cout << "\n--- Menú Empleados ---\n";
        std::cout << "1. Crear Empleado\n";
        std::cout << "2. Leer Empleados\n";
        std::cout << "3. Actualizar Empleado\n";
        std::cout << "4. Eliminar Empleado\n";
        std::cout << "5. Volver al Menú Principal\n";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
            case 1:
                crearEmpleado(empleados);
                break;
            case 2:
                leerEmpleados(empleados);
                break;
            case 3:
                actualizarEmpleado(empleados);
                break;
            case 4:
                eliminarEmpleado(empleados);
                break;
            case 5:
                std::cout << "Volviendo al Menú Principal...\n";
                break;
            default:
                std::cout << "Opción no válida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 5);
}

void crearEmpleado(std::vector<Empleado>& empleados) {
    int id;
    double salario;
    std::string nombre, puesto;

    std::cout << "Ingrese ID del empleado: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Ingrese nombre del empleado: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese puesto del empleado: ";
    std::getline(std::cin, puesto);
    std::cout << "Ingrese salario del empleado: ";
    std::cin >> salario;
    std::cin.ignore();

    try {
        Empleado nuevoEmpleado(id, nombre, puesto, salario);
        empleados.push_back(nuevoEmpleado);
        std::cout << "Empleado creado exitosamente.\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

void leerEmpleados(const std::vector<Empleado>& empleados) {
    for (const auto& empleado : empleados) {
        std::cout << "ID: " << empleado.getIdEmpleado() << ", Nombre: " << empleado.getNombre() << ", Puesto: " << empleado.getPuesto() << ", Salario: " << empleado.getSalario() << '\n';
    }
}

void actualizarEmpleado(std::vector<Empleado>& empleados) {
    int id;
    std::cout << "Ingrese ID del empleado a actualizar: ";
    std::cin >> id;
    std::cin.ignore();

    for (auto& empleado : empleados) {
        if (empleado.getIdEmpleado() == id) {
            std::string nombre, puesto;
            double salario;

            std::cout << "Ingrese nuevo nombre del empleado: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese nuevo puesto del empleado: ";
            std::getline(std::cin, puesto);
            std::cout << "Ingrese nuevo salario del empleado: ";
            std::cin >> salario;
            std::cin.ignore();

            empleado.setNombre(nombre);
            empleado.setPuesto(puesto);
            empleado.setSalario(salario);
            std::cout << "Empleado actualizado exitosamente.\n";
            return;
        }
    }
    std::cout << "Empleado no encontrado.\n";
}

void eliminarEmpleado(std::vector<Empleado>& empleados) {
    int id;
    std::cout << "Ingrese ID del empleado a eliminar: ";
    std::cin >> id;
    std::cin.ignore();

    for (auto it = empleados.begin(); it != empleados.end(); ++it) {
        if (it->getIdEmpleado() == id) {
            empleados.erase(it);
            std::cout << "Empleado eliminado exitosamente.\n";
            return;
        }
    }
    std::cout << "Empleado no encontrado.\n";
}
