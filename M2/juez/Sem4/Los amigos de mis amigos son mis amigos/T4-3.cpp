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

class Amigos
{
private:
  std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
  int mayor;

public:
  Amigos(const Grafo &g) : visit(g.V(), false), mayor(0)
  {
    for (size_t i = 0; i < g.V(); i++)
      if (!visit[i])
      {
        int a = dfs(g, i);
        mayor = a > mayor ? a : mayor;
      }
  }

  int grupoMayor() const { return mayor; }

private:
  int dfs(const Grafo &G, int v)
  {
    visit[v] = true;
    int a = 1;
    for (int w : G.ady(v))
    {
      if (!visit[w])
      {
        a += dfs(G, w);
      }
    }
    return a;
  }
};

void resuelveCaso()
{

  // leer los datos de la entrada
  int N, M;
  std::cin >> N >> M;
  Grafo g(N);

  for (int i = 0; i < M; i++)
  {
    int v, w;
    cin >> v >> w;
    g.ponArista(v-1, w-1);
  }
  Amigos a(g);
  cout << a.grupoMayor() << "\n";
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