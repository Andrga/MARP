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
#include "DigrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

/*@ <answer>

 @ </answer> */

//@ <answer>

class Laberinto
{
private:
    const int INF = std::numeric_limits<int>::max();
    int origen;
    std::vector<int> dist;
    IndexPQ<int, int> pq;

public:
    Laberinto(DigrafoValorado<int> const &g, int s) : origen(s), dist(g.V(), INF)
    {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty())
        {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    int numRatones(int t)
    {
        int ratones = 0;
        for (int d : dist)
        {
            if (d <= t && d != 0)
                ratones++;
        }
        return ratones;
    }
private:
    void relajar(AristaDirigida<int> a)
    {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor())
        {
            dist[w] = dist[v] + a.valor();
            pq.update(w, dist[w]);
        }
    }
};

bool resuelveCaso()
{

    // leemos la entrada.
    int N, S, T, P;
    cin >> N >> S >> T >> P;
    if (!cin)
        return false;
    DigrafoValorado<int> grafo(N);
    for (size_t i = 0; i < P; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;
        grafo.ponArista({a - 1, b - 1, s});
    }
    Laberinto lab(grafo.inverso(), S - 1);

    cout << lab.numRatones(T) << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos7.4.txt");
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