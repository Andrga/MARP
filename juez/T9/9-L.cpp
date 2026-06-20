/*@ <authors>
 *
 * Andres Garcia Navarro, MARP19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include "DigrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

/*@ <answer>
*
 @ </answer> */

//@ <answer>
class Secaniza
{
private:
    const long long INF = numeric_limits<long long>::max();
    vector<long long> dist;
    IndexPQ<int, long long> pq;

    void relajar(AristaDirigida<long long> a)
    {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor())
        {
            dist[w] = dist[v] + a.valor();
            pq.update(w, dist[w]); // O(log(N))
        }
    }

public:
    Secaniza(DigrafoValorado<long long> const &g, int s) : dist(g.V(), INF)
    {
        dist[s] = 0;
        pq.push(s, 0);
        while (!pq.empty()) // O(N*log(N))
        {
            auto v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    long long distancia(int w) const { return dist[w]; }
};

bool resuelveCaso()
{
    // leemos la entrada.
    int N, M;
    cin >> N >> M;
    if (!cin)
        return false;
    // construccion de la ciudad
    DigrafoValorado<long long> grafo(N);
    for (int i = 0; i < M; i++) // O(M)
    {
        int u, v, valor;
        cin >> u >> v >> valor;
        grafo.ponArista({u - 1, v - 1, valor}); // O(1)
        grafo.ponArista({v - 1, u - 1, valor}); // O(1)
    }

    Secaniza norte(grafo, 0);   // planta norte
    Secaniza sur(grafo, N - 1); // planta sur

    vector<long long> deltas(N-2);
    long long costeTotal = 0;
    for (int i = 1; i < N-1; i++){
        costeTotal += norte.distancia(i);
		deltas[i - 1] = sur.distancia(i) - norte.distancia(i);
    }
    
    sort(deltas.begin() , deltas.end());

    int mitad = (N - 2) / 2;
    for (size_t i = 0; i < mitad; i++)
        costeTotal += deltas[i];

    cout << costeTotal * 2 << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos9.L.txt");
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
