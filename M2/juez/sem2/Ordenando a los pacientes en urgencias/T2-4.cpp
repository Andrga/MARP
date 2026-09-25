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

struct Paciente
{
    string name;
    int gravedad;
    ll tiempo;

    bool operator<(const Paciente &other) const
    {
        return gravedad == other.gravedad ? tiempo < other.tiempo : gravedad > other.gravedad;
    }
};

bool resuelveCaso()
{

    // leer los datos de la entrada
    int N;
    std::cin >> N;
    if (N == 0) // fin de la entrada
        return false;
    PriorityQueue<Paciente> pq;

    for (int i = 0; i < N; i++)
    {
        char ev; std::cin >> ev;
        if(ev == 'I'){
            string n; int g;
            cin >> n >> g;
            // i es el tiempo del evento, i1 < i2 => i1 lleva mas tiempo esperando
            pq.push({n, g, i});
        }
        else if(ev == 'A'){
            Paciente p = pq.top(); pq.pop();
            cout << p.name << "\n";
        }

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
