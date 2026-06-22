/*@ <authors>
 *
 * Andres Garcia Navarro, MARP19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <queue>
#include <string>
#include "PriorityQueue.h"

using namespace std;

/*@ <answer>

 @ </answer> */

//@ <answer>
bool resuelveCaso()
{
    // leemos la entrada.
    int N;
    cin >> N;
    if (N == 0)
        return false;
    PriorityQueue<long long> seguidores;
    for (size_t i = 0; i < N; i++)
    {
        long long s; cin >> s;
        seguidores.push(s);
    }
    long long minGorras = 0;
    for (size_t i = 0; i < N-1; i++){
        long long u,v;
        u = seguidores.top(); seguidores.pop();
        v = seguidores.top(); seguidores.pop();
        seguidores.push(u+v);
        minGorras += u+v;
    }
    cout << minGorras << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosR.10.txt");
    if (!in.is_open())
        cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso())
        ;

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}