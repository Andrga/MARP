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

class Archipielago
{
private:
    std::vector<Arista<int>> _ARM;
    int coste;

public:
    Archipielago(GrafoValorado<int> const &grafo) : coste(0)
    {
        PriorityQueue<Arista<int>> pq(grafo.aristas());
        ConjuntosDisjuntos cjtos(grafo.V());
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
                if (_ARM.size() == grafo.V() - 1)
                    break;
            }
        }
    }
    int costeARM() const { return coste; };
    int tamARM() const { return _ARM.size(); };
};

bool resuelveCaso()
{
    // leemos la entrada.
    int I, P;
    cin >> I >> P;
    if (!cin)
        return false;
    GrafoValorado<int> g(I);
    for (int i = 0; i < P; i++)
    {
        int uno, otro, coste;
        cin >> uno >> otro >> coste;
        g.ponArista({uno-1, otro-1, coste});
    }
    Archipielago archipielago(g);

    cout << (archipielago.tamARM() < I-1? "No hay puentes suficientes" : to_string(archipielago.costeARM())) << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos6.3.txt");
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