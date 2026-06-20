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
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

/*@ <answer>


 @ </answer> */

//@ <answer>

class Autonomia
{
private:
    vector<Arista<int>> _ARM;
    int _coste;
    bool _conexo;

public:
    Autonomia(GrafoValorado<int> const &g) : _coste(0), _conexo(false)
    {
        PriorityQueue<Arista<int>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty())
        {
            auto a = pq.top();
            pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w))
            {
                cjtos.unir(v, w);
                _ARM.push_back(a);
                _coste = max(_coste, a.valor());
                if (_ARM.size() == g.V() - 1)
                    break;
            }
        }

        _conexo = _ARM.size() >= g.V() - 1;
    }
    int costeARM() const { return _coste; }
    bool conexo() const { return _conexo; }
};

bool resuelveCaso()
{
    // leemos la entrada.
    int N, M;
    cin >> N >> M;
    if (!cin)
        return false;
    GrafoValorado<int> grafo(N);

    for (size_t i = 0; i < M; i++)
    {
        int uno, otro, valor;
        cin >> uno >> otro >> valor;
        grafo.ponArista({uno-1, otro-1, valor});
    }
    Autonomia autonomia(grafo);
    cout << (autonomia.conexo() ? to_string(autonomia.costeARM()) : "Imposible") << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos6.4.txt");
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