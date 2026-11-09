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
class Red
{
private:
  const Valor INF = std::numeric_limits<Valor>::max();
  int origen;
  std::vector<Valor> dist;
  IndexPQ<int, Valor> pq;

public:
  Red(DigrafoValorado<Valor> const &g, int orig)
      : origen(orig), dist(g.V(), INF)
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
private:
  void relajar(AristaDirigida<Valor> a)
  {
    int v = a.desde(), w = a.hasta();
    if (dist[w] > dist[v] + a.valor())
    {
      dist[w] = dist[v] + a.valor();
      pq.update(w, dist[w]);
    }
  }
};

void resuelveCaso()
{

  // leer los datos de la entrada
  int N;
  std::cin >> N;
  vector<int> sitios(N);
  for (int i = 0; i < N; i++)
  {int e; cin >> e;
      sitios[i] = e;
  }

  DigrafoValorado<int> g(N);
  int M;
  cin >> M;
  for (int i = 0; i < M; i++)
  {
    int v, w, valor;
    cin >> v >> w >> valor;
    g.ponArista({v - 1, w - 1, valor + sitios[w - 1]});
  }
  Red<int> r(g, 0);
  cout << (r.hayCamino(N-1) ? to_string(r.distancia(N-1) + sitios[0]) : "IMPOSIBLE") << "\n";
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