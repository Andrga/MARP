/*@ <authors>
 *
 * Andres Garcia Navarro, MARP19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
#include <string>
#include <unordered_map>
#include "Digrafo.h"

using namespace std;

/*@ <answer>

 @ </answer> */

//@ <answer>

int bfs(vector<pair<int, int>> sums, int s, int t, int mod)
{
    if (s == t) return 0;

    std::queue<int> q;
    vector<int> dist (mod, -1); dist [s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (pair<int, int> sum : sums)
        {
            int w = (sum.first * v + sum.second) % mod;
            if (dist[w] == -1)
            {
                dist[w] = dist[v] + 1;
                if( w == t)
                    return dist[v] +1;
                q.push(w);
            }
        }
    }
    return -1;
}

bool resuelveCaso()
{

    // leemos la entrada.
    int M, S, T, N;
    if (!(cin >> M >> S >> T >> N))
        return false;

    vector<pair<int, int>> sumandos(N);

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        sumandos[i] = {a, b};
    }

    cout << bfs(sumandos, S, T, M)<< "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos5.5.txt");
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
