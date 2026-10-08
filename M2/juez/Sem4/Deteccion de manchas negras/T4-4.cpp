/*@ <authors>
 *
 * MARP30 Andrés García Navarro
 *
 *@ </authors> */

#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// propios o los de las estructuras de datos de clase
#include "Grafo.h"

/*@ <answer>

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Manchas
{
private:
  std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
  int manchas;
  int mayor;
  int F, C;
  const vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
  Manchas(const vector<string> &g, int f, int c)
      : F(f), C(c), visit(f * c, false), manchas(0), mayor(0)
  {
    for (int v = 0; v < F * C; v++)
    {
      int i = v / C, j = v % C;
      if (g[i][j] == '#' && !visit[v])
      {
        manchas++;
        int a = dfs(g, v);
        mayor = a > mayor ? a : mayor;
      }
    }
  }

  int nroManchas() const { return manchas; }
  int manchaMayor() const { return mayor; }

private:
  bool enRango(int i, int j) const
  {
    return 0 <= i && i < F && 0 <= j && j < C;
  }

  int dfs(const vector<string> &G, int v)
  {
    visit[v] = true;
    int a = 1;
    int i = v / C, j = v % C; // dividir entre columnas
    for (auto d : dirs)
    {
      int ni = i + d.first, nj = j + d.second;
      int w = ni * C + nj; // multiplicar por columnas
      if (enRango(ni, nj) && G[ni][nj] == '#' && !visit[w])
        a += dfs(G, w);
    }
    return a;
  }
};

void resuelveCaso()
{

  // leer los datos de la entrada
  int F, C;
  std::cin >> F >> C;

  vector<string> bitmap(F);
  for (string &fila : bitmap)
    std::cin >> fila;

  Manchas m(bitmap, F, C);
  cout << m.nroManchas() << " " << m.manchaMayor() << "\n";
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