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

class Red
{
private:
	vector<bool> visit;
    std::vector<int> amg;    // ant[v] = numero de amigos
public:
    Red(Grafo const& g): visit(g.V(), false),amg(g.V(), 0)
    {
        for (int i = 0; i < g.V(); i++)
        {
			if (visit[i]) continue;
			vector<int> comp;
			int tam = dfs(g, i, comp);
			for (int v : comp) amg[v] = tam;
        }
    }
    int getAmigos(int i)const {return amg[i];}
private:
	int dfs(Grafo const& g, int v, vector<int> & comp) {
		visit[v] = true;
		int tam = 1;
		comp.push_back(v);
		for (int w : g.ady(v))
		{
			if (visit[w]) continue;
			tam += dfs(g, w, comp);
		}
		return tam;
	}
    // void bfs(Grafo const &g, int s)
    // {
    //     std::vector<bool> visit(g.V(), false);
    //     std::queue<int> q;
    //     visit[s] = true;
    //     q.push(s);
    //     while (!q.empty())
    //     {
    //         int v = q.front();
    //         q.pop();
    //         for (int w : g.ady(v))
    //         {
    //             if (!visit[w])
    //             {
    //                 amg[s] ++;
    //                 visit[w] = true;
    //                 q.push(w);
    //             }
    //         }
    //     }
    // }
};

bool resuelveCaso()
{
    int N, M; cin >> N >> M;
    if (!cin) return false;

    Grafo grafo(N);
    for (int g = 0; g < M; g++)
    {
        int np; cin >> np;
        if(np==0) continue;
        int uno; cin >> uno;
        for (int i = 0; i < np-1; i++)
        {
            int otro; cin >> otro;
            grafo.ponArista(uno-1, otro-1);
            uno = otro;
        }
    }

    Red red(grafo);

    for (int i = 0; i < N; i++)
        cout << red.getAmigos(i) <<" ";
    cout << "\n";

    return true;
};

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos4.6.txt");
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
