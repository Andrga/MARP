/*@ <authors>
 *
 * MARP30 Nombre Apellidos
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"
using ll = long long;

/*@ <answer>



 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Caja{
    int id;
    ll tiempo;

    bool operator<(const Caja& other) const {
        return tiempo == other.tiempo ? id < other.id : tiempo < other.tiempo;
    }
};

bool resuelveCaso()
{

    // leer los datos de la entrada
    int N, C;
    std::cin >> N >> C;
    if (N == 0 && C == 0) // fin de la entrada
        return false;
    PriorityQueue<Caja> pq;
    for (int i = 0; i < N; i++)
        pq.push({i+1, 0});

    for (int i = 0; i < C; i++)
    {
        int t; std::cin >> t;
        Caja c = pq.top(); pq.pop();
        c.tiempo += t;
        pq.push(c);
    }
    
    std::cout << pq.top().id << "\n";

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
