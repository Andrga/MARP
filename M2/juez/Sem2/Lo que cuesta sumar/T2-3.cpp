/*@ <authors>
 *
 * MARP30 Nombre Apellidos
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <string>

// propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"

/*@ <answer>



 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

// Funcion recursiva comprueba si el arbol dado es AVL

bool resuelveCaso()
{

    // leer los datos de la entrada
    int N;
    std::cin >> N;
    if (N == 0) // fin de la entrada
        return false;
    PriorityQueue<int> pq;

    for (int i = 0; i < N; i++)
    {
        int e; std::cin >> e;
        pq.push(e);
    }
    
   while (!pq.empty())
   {
    /* code */
   }
   
    

    std::cout << "---\n";

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
