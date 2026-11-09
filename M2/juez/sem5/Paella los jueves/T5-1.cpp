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

using namespace std;

// propios o los de las estructuras de datos de clase
#include "Digrafo.h"

/*@ <answer>

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Ciudad
{
private:
  int restaurantes;

public:
  Ciudad(const Digrafo &g, const Digrafo &ginv, int s, int e) : restaurantes(0)
  {
    vector<bool> visitIni(g.V(), false);
    vector<bool> visitFin(g.V(), false);
    dfs(g, s, visitIni);    // Marcamos los nodos a los que se puede llegar desde ini.
    dfs(ginv, e, visitFin); // Marcamos los nodos que se pueden llegar a fin.

    if (!visitIni[e])
    {
      restaurantes = -1;
      return;
    }
    for (int i = 0; i < g.V(); i++)
    {
      // Si ha sido visitado por los dos y no es ni ini ni fin, es un restaurante posible.
      if (i != s && i != e && visitIni[i] && visitFin[i])
        restaurantes++;
    }
  }
  // devuelve la distancia sin contar con la final
  int getRestaurantes() const { return restaurantes; }

private:
  void dfs(Digrafo const &g, int v, vector<bool> &visit)
  {
    visit[v] = true;
    for (int w : g.ady(v))
      if (!visit[w])
      {
        dfs(g, w, visit);
      }
  }
};

void resuelveCaso()
{

  // leer los datos de la entrada
  int NV, NA;
  std::cin >> NV >> NA;
  Digrafo g(NV);

  for (int i = 0; i < NA; i++)
  {
    int v, w;
    cin >> v >> w;
    g.ponArista(v - 1, w - 1);
  }
  Digrafo ginv = g.inverso();

  int casos;
  cin >> casos;
  for (int i = 0; i < casos; i++)
  {
    int v, w;
    cin >> v >> w;
    Ciudad c(g, ginv, v - 1, w - 1);
    int dist = c.getRestaurantes();
    cout << (dist >= 0 ? to_string(dist) : "IMPOSIBLE") << "\n";
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