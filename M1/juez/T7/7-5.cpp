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

class CaminoMinimo
{
private:
    const int INF = std::numeric_limits<int>::max();
    int origen;
    vector<bool> visit;
    vector<int> distDj;
    vector<int> caminos;
    vector<int> distBFS;
    IndexPQ<int, int> pq;

    void relajar(AristaDirigida<int> a)
    {
        int v = a.desde(), w = a.hasta();
        if (distDj[w] > distDj[v] + a.valor())
        {
            distDj[w] = distDj[v] + a.valor();
            caminos[w] = caminos[v] + 1;
            pq.update(w, distDj[w]);
        }
        else if (distDj[w] == distDj[v]+ a.valor() && caminos[v] + 1 < caminos[w]) {
            caminos[w] = caminos[v] + 1;
        }
    }

    void dijkstra(DigrafoValorado<int> const &g, int s)
    {
        distDj[s] = 0;
        pq.push(s, 0);
        while (!pq.empty())
        {
            int v = pq.top().elem;
            pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }

    void bfs(DigrafoValorado<int> const &g, int s)
    {
        std::queue<int> q;
        distBFS[s] = 0;
        visit[s] = true;
        q.push(s);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto a : g.ady(v))
            {
                int w = a.hasta();
                if (!visit[w])
                {
                    distBFS[w] = distBFS[v] + 1;
                    visit[w] = true;
                    q.push(w);
                }
            }
        }
    }

public:
    CaminoMinimo(DigrafoValorado<int> const &g, int s):
        origen(0), visit(g.V(), false), distDj(g.V(), INF), distBFS(g.V(), 0), caminos(g.V(), 0)
    {
        dijkstra(g, s);
        bfs(g, s);
    }

    bool hayCamino(int w) const { return visit[w]; }
    bool coincidenCaminos(int w) const { return distBFS[w] == caminos[w]; }
    int caminoMinimo(int w) const { return distDj[w]; }
};

bool resuelveCaso()
{

    // leemos la entrada.
    int N, C, K;
    cin >> N >> C;
    if (!cin)
        return false;
    DigrafoValorado<int> grafo(N);
    for (size_t i = 0; i < C; i++)
    {
        int desde, hasta, valor;
        cin >> desde >> hasta >> valor;
        grafo.ponArista({desde-1, hasta-1, valor});
        grafo.ponArista({hasta-1, desde-1, valor});
    }
    cin >> K;

    for (size_t i = 0; i < K; i++)
    {
        int org, dest;
        cin >> org >> dest;
        CaminoMinimo cam(grafo, org-1);

        if (!cam.hayCamino(dest-1))
        {
            cout << "SIN CAMINO\n";
            continue;
        }
        cout << cam.caminoMinimo(dest-1) << (cam.coincidenCaminos(dest-1)? " SI":" NO") << "\n";
    }
    cout << "---\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos7.5.txt");
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