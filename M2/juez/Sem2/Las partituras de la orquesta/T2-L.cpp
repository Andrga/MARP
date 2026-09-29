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

struct Atril{
    int partituras;
    int musicos;
    int prioridad;

    bool operator<(const Atril& other) const {
        return  prioridad > other.prioridad;
    }
};

void resuelveCaso()
{

    // leer los datos de la entrada
    int P, N;
    std::cin >> P >> N;
    
    PriorityQueue<Atril> pq;

    for (int i = 0; i < N; i++)
    {
        int m; cin >> m;
        pq.push({1, m, m/1});
    }
    for (int i = 0; i < P-N; i++)
    {
        Atril a = pq.top(); pq.pop();
        a.partituras += 1;
        a.prioridad = (a.musicos % a.partituras) != 0? 1:0;
        a.prioridad += a.musicos / a.partituras;
        pq.push(a);
    }
    
    std::cout << pq.top().prioridad << "\n";
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
    int N; cin >> N;
    for (int i = 0; i < N; i++)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}
