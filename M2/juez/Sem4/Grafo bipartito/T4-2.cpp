/*@ <authors>
 *
 * MARP30 Andrés García Navarro
 *
 *@ </authors> */

#include <cstdio>
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

// propios o los de las estructuras de datos de clase
#include "Grafo.h"

/*@ <answer>

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Bipartito
{
private:
  std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
  vector<bool> color;      // ant[v] = nodo anterior a v.
  bool bipartito;

public:
  Bipartito(const Grafo &g) :
   visit(g.V(), false), color(g.V(), false), bipartito(true)
  {
    for (size_t i = 0; i < g.V(); i++)
      if (!visit[i])
        dfs(g, i);
  }

  bool esBipartito() const { return bipartito; }

private:
  void dfs(const Grafo &G, int v)
  {
    visit[v] = true;
    for (int w : G.ady(v))
    {
      if (!visit[w])
      {
        color[w] = !color[v];
        dfs(G, w);
      }
      else if (color[w] == color[v])
      {
        bipartito = false;
        return;
      }
    }
  }
};

void resuelveCaso()
{

  // leer los datos de la entrada
  int V, A;
  std::cin >> V >> A;
  Grafo g(V);

  for (int i = 0; i < A; i++)
  {
    int v, w;
    cin >> v >> w;
    g.ponArista(v, w);
  }
  Bipartito a(g);
  cout << (a.esBipartito() ? "SI" : "NO") << "\n";
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main()
{
  // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
  ifstream in("casos.txt");
  if (!in.is_open())
    cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
  auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    resuelveCaso();

  // para dejar todo como estaba al principio
#ifndef DOMJUDGE
  cin.rdbuf(cinbuf);
#endif
  return 0;
}