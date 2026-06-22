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
#include "Matriz.h"

using namespace std;

/*@ <answer>

 @ </answer> */

//@ <answer>
constexpr int INF = 1000000000;

void Floyd(Matriz<int> const &G, Matriz<int> &C)
{
    int V = G.numfils(); // número de vértices de G
    // inicialización
    C = G;
    // actualizaciones de las matrices
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
}

bool resuelveCaso()
{
    // leemos la entrada.
    int N;
    cin >> N;
    if (!cin)
        return false;
    Matriz<int> M(N, N, INF);
    for (int i = 0; i < N; i++)
        M[i][i] = 0;
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            cin >> M[i][j];
    Matriz<int> C;
    Floyd(M, C);

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosR11.txt");
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