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
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

template <typename Valor>
class Ciudad
{
private:
  const Valor INF = std::numeric_limits<Valor>::max();
  int origen;
  std::vector<Valor> dist;
  std::vector<AristaDirigida<Valor>> ulti;
  IndexPQ<int, Valor> pq;

public:
  Ciudad(DigrafoValorado<Valor> const &g, int orig)
      : origen(orig), dist(g.V(), INF), ulti(g.V())
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
  }

  bool hayCamino(int v) const { return dist[v] != INF; }
  Valor distancia(int v) const { return dist[v]; }
  deque<int> camino(int v) const
  {
    deque<int> cam;
    while (v != origen)
    {
      cam.push_front(v);
      v = ulti[v].desde();
    }
    cam.push_front(origen);
    return cam;
  }

private:
  void relajar(AristaDirigida<Valor> a)
  {
    int v = a.desde(), w = a.hasta();
    if (dist[w] > dist[v] + a.valor())
    {
      dist[w] = dist[v] + a.valor();
      ulti[w] = a;
      pq.update(w, dist[w]);
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
    int o, f;
    cin >> o >> f;
    f--;o--;
    Ciudad<int> c(g, o);
    if (!c.hayCamino(f))
    {
      cout << "NO LLEGA\n";
      continue;
    }
    cout << c.distancia(f) << ":";
    bool primero = true;
    for (int v : c.camino(f))
    {
      cout << (primero ? " " : " -> ") << v + 1;
      primero = false;
    }
    cout << "\n";
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