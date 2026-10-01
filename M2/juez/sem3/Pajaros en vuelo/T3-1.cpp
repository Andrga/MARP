/*@ <authors>
 *
 * MARP30 Andrés García Navarro
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"

/*@ <answer>



 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
bool resuelveCaso()
{

    // leer los datos de la entrada
    int E, P;
    std::cin >> E >> P;
    if (E == 0 || P == 0) // fin de la entrada
        return false;

    PriorityQueue<int, greater<int>> min;
    PriorityQueue<int> max;
    min.push(E);

    for (int i = 0; i < P; i += 1)
    {
        for (int j = 0; j < 2; j++)
        {
            int paj;
            cin >> paj;

            if (paj < min.top())
                min.push(paj);
            else
                max.push(paj);
        }

        while (min.size() != max.size() + 1)
        {
            if (min.size() > max.size() + 1)
            {
                max.push(min.top());
                min.pop();
            }
            else
            {
                min.push(max.top());
                max.pop();
            }
        }
        std::cout << min.top() << " ";
    }
    std::cout << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    if (!in.is_open())
        cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}