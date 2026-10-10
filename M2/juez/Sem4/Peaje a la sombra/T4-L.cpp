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

class Ciudad
{
private:
  std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
  std::vector<int> dist;   // dist[v] = distancia de s a v
  int s;

public:
  Ciudad(const Grafo &g, int s)
      : visit(g.V(), false), dist(g.V(), 0), s(s)
  {
    bfs(g);
  }

  int distancia(int w) const { return dist[w]; }

private:
  void bfs(Grafo const &g)
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
        else if (dist[v] + 1 < dist[w])
          dist[w] = dist[v] + 1;
      }
    }
  }
};

constexpr int INF = numeric_limits<int>::max();
void resuelveCaso()
{
  // leer los datos de la entrada
  int N, C, A, L, T;
  cin >> N >> C >> A >> L >> T;

  Grafo g(N);
  for (int i = 0; i < C; i++)
  {
    int v, w;
    cin >> v >> w;
    g.ponArista(v-1, w-1);
  }

  Ciudad cAlex(g, A-1);
  Ciudad cLucas(g, L-1);
  Ciudad cTrabajo(g, T-1);

  int minDist = INF;
  for (int i = 0; i < N; i++)
  {
    int d = cAlex.distancia(i) + cLucas.distancia(i) + cTrabajo.distancia(i);
    if (d < minDist)
      minDist = d;
  }

  cout << minDist << "\n";
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
