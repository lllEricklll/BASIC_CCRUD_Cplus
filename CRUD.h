#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Definir una estructura para representar un elemento
struct Elemento {
    int id;
    string nombre;
    // Puedes agregar más campos según tus necesidades
};

// Función para imprimir un elemento
void imprimirElemento(const Elemento& elemento) {
    cout << "ID: " << elemento.id << "\tNombre: " << elemento.nombre << endl;
}

// Función para crear un nuevo elemento
Elemento crearElemento() {
    Elemento nuevoElemento;
    cout << "Ingrese el ID: ";
    cin >> nuevoElemento.id;
    cin.ignore(); // Limpiar el buffer del teclado
    cout << "Ingrese el nombre: ";
    getline(cin, nuevoElemento.nombre);
    return nuevoElemento;
}

int main() {
    vector<Elemento> elementos; // Vector para almacenar los elementos

    char opcion;

    do {
        // Menú
        cout << "\nCRUD en C++ con Visual Studio\n";
        cout << "1. Crear\n";
        cout << "2. Leer\n";
        cout << "3. Actualizar\n";
        cout << "4. Eliminar\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case '1': // Crear
            elementos.push_back(crearElemento());
            cout << "Elemento creado exitosamente.\n";
            break;
        case '2': // Leer
            cout << "Lista de elementos:\n";
            for (const auto& elem : elementos) {
                imprimirElemento(elem);
            }
            break;
        case '3': // Actualizar
            bool encontrado = false;
            int idActualizar;
            cout << "Ingrese el ID del elemento a actualizar: ";
            cin >> idActualizar;
            for (auto& elem : elementos) {
                if (elem.id == idActualizar) {
                    cout << "Ingrese el nuevo nombre: ";
                    cin >> elem.nombre;
                    cout << "Elemento actualizado exitosamente.\n";
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
            {
                cout << "El id ingresado no existe, porfavor intentalo con uno valido.\n";
            }
            break;
        case '4': // Eliminar
            int idEliminar;
            cout << "Ingrese el ID del elemento a eliminar: ";
            cin >> idEliminar;
            elementos.erase(
                remove_if(
                    elementos.begin(), elementos.end(),
                    [idEliminar](const Elemento& elem) { return elem.id == idEliminar; }),
                elementos.end());
            cout << "Elemento eliminado exitosamente.\n";
            break;
        case '0': // Salir
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opción no válida. Intente de nuevo.\n";
            break;
        }

    } while (opcion != '0');

    return 0;
}
