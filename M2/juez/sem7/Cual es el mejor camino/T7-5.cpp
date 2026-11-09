/*@ <authors>
 *
 * MARP30 Andrés García Navarro
 *
 *@ </authors> */

#include <cstdio>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <limits>

using namespace std;

// propios o los de las estructuras de datos de clase
#include "DigrafoValorado.h"
#include "IndexPQ.h"

/*@ <answer>

 @ </answer> */

// ================================================================
// Escribe el código Dcompleto de tu solución aquí debajo
// ================================================================
//@ <answer>

template <typename Valor>
class Ciudad
{
private:
  const Valor INF = std::numeric_limits<Valor>::max();
  int origen;
  vector<int> callesDjk;
  vector<int> callesBFS;
  vector<bool> visit; // visit[v] = ¿hay camino de s a v?
  std::vector<Valor> dist;
  IndexPQ<int, Valor> pq;

public:
  Ciudad(DigrafoValorado<Valor> const &g, int orig)
      : origen(orig), callesDjk(g.V(), 0),  callesBFS(g.V(), 0), visit(g.V(), false), dist(g.V(), INF)
  {
    dist[origen] = 0;
    pq.push(origen, 0);
    while (!pq.empty())
    {
      int v = pq.top().elem;
      pq.pop();
      for (auto a : g.ady(v))
        relajar(a);
    }
    bfs(g, orig);
  }

  bool hayCamino(int v)   const {return dist[v] != INF;}
  int getCallesBFS(int v) const { return callesBFS[v]; }
  int getCallesDjk(int v) const { return callesDjk[v]; }
  int getDistancia(int v) const { return dist[v]; }

private:
  void relajar(AristaDirigida<Valor> a)
  {
    int v = a.desde(), w = a.hasta();
    if (dist[w] == dist[v] + a.valor() && callesDjk[v] + 1 < callesDjk[w])
    {
      callesDjk[w] = callesDjk[v] + 1;
    }
    else if (dist[w] > dist[v] + a.valor())
    {
      dist[w] = dist[v] + a.valor();
      callesDjk[w] = callesDjk[v] + 1;
      pq.update(w, dist[w]);
    }
  }
  void bfs(DigrafoValorado<Valor> const &g, int s)
  {
    queue<int> q;
    visit[s] = true;
    q.push(s);
    while (!q.empty())
    {
      int v = q.front();
      q.pop();
      for (AristaDirigida<Valor> arista : g.ady(v))
      {
        int w = arista.hasta();
        if (!visit[w])
        {
          callesBFS[w] = callesBFS[v] + 1;
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
  std::cin >> N >> C;
  DigrafoValorado<int> g(N);
  for (int i = 0; i < C; i++)
  {
    int v, w, valor;
    cin >> v >> w >> valor;
    g.ponArista({v - 1, w - 1, valor});
    g.ponArista({w - 1, v - 1, valor});
  }

  int k;
  cin >> k;
  for (int i = 0; i < k; i++)
  {
    int org, dest;
    cin >> org >> dest;
    org--;dest--;
    Ciudad c(g, org);
    if (!c.hayCamino(dest)){
      cout << "SIN CAMINO\n";
      continue;
    }
      cout<< c.getDistancia(dest) << (c.getCallesBFS(dest) != c.getCallesDjk(dest)? " NO": " SI") << "\n";
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