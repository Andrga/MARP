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

class SerpientesEscaleras
{
private:
    vector<bool> visit;
    vector<int> dist;
    int s;

public:
    SerpientesEscaleras(Digrafo const &g, int _s) : visit(g.V(), false), dist(g.V(), 0), s(_s)
    {
        bfs(g);
    }

    int getMoves(int dest) const { return dist[dest]; }

private:
    void bfs(Digrafo const &g)
    {
        std::queue<int> q;
        dist[s] = 0;
        visit[s] = true;
        q.push(s);
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

    // leemos la entrada.
    int N, K, S, E;
    cin >> N >> K >> S >> E;
    if (N == 0 && K == 0 && S == 0 && E == 0)
        return false;

    vector<int> serpEsc(N * N, -1);
    for (int i = 0; i < S + E; i++)
    {
        int u, v;
        cin >> u >> v;
        serpEsc[u - 1] = v - 1;
    }
    Digrafo grafo(N * N);

    for (int i = 1; i <= N * N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            int dest = i + j;
            if (dest > N * N)
                continue;
            grafo.ponArista(i - 1, serpEsc[dest - 1] != -1? 
                                    serpEsc[dest - 1]: 
                                    dest -1);
        }
    }
    SerpientesEscaleras se(grafo, 0);
    cout << se.getMoves((N * N) - 1) << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos5.6.txt");
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
