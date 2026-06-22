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
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

/*@ <answer>

 @ </answer> */

//@ <answer>
class Barrocity
{
private:
    
    int coste;
    bool puede;

public:
    Barrocity(GrafoValorado<int> const &g) : coste(0), puede(false)
    {
        PriorityQueue<Arista<int>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        vector<Arista<int>> _ARM;
        while (!pq.empty())
        {
            auto a = pq.top();
            pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w))
            {
                cjtos.unir(v, w);
                _ARM.push_back(a);
                coste += a.valor();
                if (_ARM.size() == g.V() - 1)
                    break;
            }
        }
        puede = _ARM.size() == g.V()-1;
    }
    int costeARM() const { return coste; }
    bool posible() const { return puede; }
};

bool resuelveCaso()
{
    // leemos la entrada.
    int N, C;
    cin >> N >> C;
    if (!cin)
        return false;
    GrafoValorado<int> grafo(N);
    for (size_t i = 0; i < C; i++)
    {
        int u, v, valor;
        cin >> u >> v >> valor;
        grafo.ponArista({--u, --v, valor});
    }
    Barrocity barrocity(grafo);

    if(!barrocity.posible()) cout << "Imposible\n";
    else cout << barrocity.costeARM() << "\n";
    
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosR09.txt");
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