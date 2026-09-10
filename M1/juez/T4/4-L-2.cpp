/*@ <authors>
 *
 * Andres Garcia Navarro, MARP19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"
#include <algorithm>
#include <queue>
using namespace std;

class Ciudad
{
private:
    vector<bool> visit;
    vector<int> dist; // dist[v] = distancia de v a s
    int _s;

public:
    Ciudad(Grafo const &g, int s) : visit(g.V(), false), dist(g.V(), 0), _s(s)
    {
        bfs(g);
    }
    int getDistancia(int i) const { return dist[i]; }

private:
    void bfs(Grafo const &g)
    {
        std::queue<int> q;
        visit[_s] = true;
        q.push(_s);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int w : g.ady(v))
            {
                if (!visit[w])
                {
                    dist[w] = dist[v] + 1;
                    visit[w] = true;
                    q.push(w);
                }
            }
        }
    }
};

bool resuelveCaso()
{
    int N, C, A, L, T;
    if (!(cin >> N >> C >> A >> L >> T))
        return false;

    Grafo grafo(N);
    for (int g = 0; g < C; g++)
    {
        int uno, otro;
        cin >> uno >> otro;
        grafo.ponArista(uno-1, otro-1);
    }

    Ciudad ciuAlex(grafo, A-1);
    Ciudad ciuLucas(grafo, L-1);
    Ciudad ciuTrabajo(grafo, T-1);

    int minDist = ciuAlex.getDistancia(0) + ciuLucas.getDistancia(0) + ciuTrabajo.getDistancia(0);
    for (int i = 1; i < N; i++)
    {
        int d = ciuAlex.getDistancia(i) + ciuLucas.getDistancia(i) + ciuTrabajo.getDistancia(i);
        minDist = min(minDist, d);
    }
    cout << minDist << "\n";

    return true;
};

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos4.L.txt");
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
