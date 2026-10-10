/*@ <authors>
 *
 * MARP30 Andrés García Navarro
 *
 *@ </authors> */

#include <cstdio>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <limits>

using namespace std;

// propios o los de las estructuras de datos de clase
#include "Grafo.h"

/*@ <answer>

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Red
{
private:
  std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
  std::vector<int> dist;   // dist[v] = aristas en el camino s-v más corto
  int alcanzables;

public:
  Red(const Grafo &g, int s, int ttl)
      : visit(g.V(), false), dist(g.V(), 0), alcanzables(1)
  {
    bfs(g, s, ttl);
  }

  int inalcanzables() const { return visit.size() - alcanzables; }

private:
  void bfs(Grafo const &g, int s, int ttl)
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
        if (!visit[w] && dist[v] + 1 <= ttl)
        {
          alcanzables++;
          dist[w] = dist[v] + 1;
          visit[w] = true;
          q.push(w);
        }
      }
    }
  }
};

void resuelveCaso()
{
  // leer los datos de la entrada
  int N, C;
  cin >> N >> C;

  Grafo g(N);
  for (int i = 0; i < C; i++)
  {
    int v, w;
    cin >> v >> w;
    g.ponArista(v - 1, w - 1);
  }

  int K;
  cin >> K;
  for (int i = 0; i < K; i++)
  {
    int s, ttl;
    cin >> s >> ttl;
    Red r(g, s - 1, ttl);
    cout << r.inalcanzables() << "\n";
  }

  cout << "---\n";
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