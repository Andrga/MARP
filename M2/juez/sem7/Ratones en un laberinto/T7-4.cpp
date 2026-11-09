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
class Comarca
{
private:
  const Valor INF = std::numeric_limits<Valor>::max();
  int origen;
  std::vector<Valor> dist;
  IndexPQ<int, Valor> pq;

public:
  Comarca(DigrafoValorado<Valor> const &g, int orig)
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
  int getDistancia(int v) const { return dist[v]; }

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
  int N, C;
  std::cin >> N >> C;
  DigrafoValorado<int> g(N);
  for (int i = 0; i < C; i++)
  {
    int v, w, valor;
    cin >> v >> w >> valor;
    g.ponArista({v - 1, w - 1, valor});
  }

  int O, P;
  cin >> O >> P;
  O--;
  Comarca c(g, O);
  Comarca cInv(g.inverso(), O);

  long coste = 0;
  bool posible = true;
  for (int i = 0; i < P; i++)
  {
    int dest;
    cin >> dest;
    dest--;
    if(!c.hayCamino(dest) || ! cInv.hayCamino(dest))
      posible = false;
    coste += c.getDistancia(dest);
    coste += cInv.getDistancia(dest);
  }
  cout << (posible? to_string(coste) : "Imposible")<< "\n";
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