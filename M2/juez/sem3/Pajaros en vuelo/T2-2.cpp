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

struct Usuario{
    ll id;
    ll periodo;
    ll tiempo;

    bool operator<(const Usuario& other) const {
        return tiempo == other.tiempo ? id < other.id : tiempo < other.tiempo;
    }
};

bool resuelveCaso()
{

    // leer los datos de la entrada
    int N;
    std::cin >> N;
    if (N == 0) // fin de la entrada
        return false;
    PriorityQueue<Usuario> pq;

    for (int i = 0; i < N; i++)
    {
        ll id, p;
        std::cin >> id >> p;
        pq.push({id, p, p});
    }

    int k; cin >> k;
    for (int i = 0; i < k; i++)
    {
        Usuario usr = pq.top(); pq.pop();
        std::cout << usr.id << "\n";
        usr.tiempo += usr.periodo;
        pq.push(usr);
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
