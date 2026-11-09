/*@ <authors>
 *
 * MARP30 Andrés García Navarro
 *
 *@ </authors> */

#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
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

class Abudajh
{
private:
  std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
  vector<bool> ocupada;    // ocupada[v] = si ya hay un guardia
  bool posible;
  int guardias;
  int conGuardia, sinGuardia; // cuentas de la componente actual

public:
  Abudajh(const Grafo &g) : visit(g.V(), false), ocupada(g.V(), true), posible(true), guardias(0)
  {
    for (int i = 0; i < g.V(); i++)
    {
        conGuardia = 0;
        sinGuardia = 0;
      if (!visit[i])
        dfs(g, i);
        guardias += min(conGuardia, sinGuardia); // el color más barato
    }
  }

  bool getPosible() const { return posible; }
  int getGuardias() const { return guardias; }

private:
  void dfs(Grafo const &G, int v)
  {
    visit[v] = true;
    if (G.ady(v).size() == 0) return; 
    if (ocupada[v]) conGuardia++;
    else            sinGuardia++;
    for (int w : G.ady(v))
    {
      if (!visit[w])
      {
        ocupada[w] = !ocupada[v];
        dfs(G, w);
      }
      else if (ocupada[w] == ocupada[v])
      {
        posible = false;
      }
    }
  }
};

void resuelveCaso()
{

  // leer los datos de la entrada
  int N, C;
  std::cin >> N >> C;
  Grafo g(N);

  for (int i = 0; i < C; i++)
  {
    int v, w;
    cin >> v >> w;
    g.ponArista(v - 1, w - 1);
  }

  Abudajh a(g);
  cout << (a.getPosible() ? to_string(a.getGuardias()) : "IMPOSIBLE") << "\n";
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