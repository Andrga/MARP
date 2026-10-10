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

class Amigos
{
private:
  std::vector<int> tam;

public:
  Amigos(const Grafo &g) : tam(g.V(), 0)
  {
    for (int i = 0; i < g.V(); i++)
    {
      if (tam[i] == 0)
        bfs(g, i);
    }
  }

  int noticia(int v) const { return tam[v]; }

private:
  void bfs(const Grafo &G, int s)
  {
    std::vector<int> miembros;
    std::queue<int> q;
    tam[s] = -1;
    q.push(s);
    while (!q.empty())
    {
      int v = q.front();
      q.pop();
      miembros.push_back(v);
      for (int w : G.ady(v))
      {
        if (tam[w] == 0)
        {
          tam[w] = -1;
          q.push(w);
        }
      }
    }

    for (int v : miembros) // todos comparten el mismo tamaño
      tam[v] = miembros.size();
  }
};

void resuelveCaso()
{

  // leer los datos de la entrada
  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> relaciones;
  for (int i = 0; i < M; i++)
  {
    int usuarios;
    cin >> usuarios;
    int ant = -1;
    for (int j = 0; j < usuarios; j++)
    {
      int sig;
      cin >> sig;
      sig--;
      if (ant != -1)
        relaciones.push_back({ant, sig});
      ant = sig;
    }
  }
  Grafo g(N);
  for (pair<int, int> p : relaciones)
    g.ponArista(p.first, p.second);

  Amigos a(g);
  for (int i = 0; i < N; i++)
  {
    cout << a.noticia(i) << " ";
  }
  cout << "\n";
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