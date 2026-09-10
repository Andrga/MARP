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
#include "Digrafo.h"

using namespace std;

/*@ <answer>

 @ </answer> */

//@ <answer>

class Recuerdos
{
private:
    std::vector<bool> _visit;
    std::deque<int> _orden;     // ordenación topológica
    std::vector<bool> _apilado; // apilado[v] = ¿está el vértice v en la pila?
    bool _hayciclo;

    void dfs(Digrafo const &g, int v)
    {
        _apilado[v] = true;
        _visit[v] = true;
        for (int w : g.ady(v))
        {
            if (_hayciclo) // si hemos encontrado un ciclo terminamos
                return;
            if (!_visit[w])
                dfs(g, w);
            else if (_apilado[w]) // hemos detectado un ciclo
                _hayciclo = true;
        }
        _orden.push_front(v);
        _apilado[v] = false;
    }

public:
    Recuerdos(Digrafo const &g) : _visit(g.V(), false), _apilado(g.V(), false), _hayciclo(false)
    {
        for (int v = 0; v < g.V(); ++v)
            if (!_visit[v])
                dfs(g, v);
    }
    // devuelve la ordenación topológica
    deque<int> const &orden() const
    {
        return _orden;
    }
    bool hayCiclo() const { return _hayciclo; }
};

bool resuelveCaso()
{

    // leemos la entrada.
    int N, M;
    cin >> N >> M;
    if (N == 0 && M == 0)
        return false;
    Digrafo grafo(N);
    for (size_t i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        grafo.ponArista(a - 1, b - 1);
    }
    Recuerdos rec(grafo);
    deque<int> orden = rec.orden();

    if (!rec.hayCiclo())
    {
        cout << "SI ";
        for (int r : orden)
        {
            cout << r + 1 << " ";
        }
        cout << "\n";
    }
    else
        cout << "NO\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosEN.1.txt");
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