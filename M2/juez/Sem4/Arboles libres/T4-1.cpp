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

class ArbolLibre {
private:
  std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
  vector<int> ant;	// ant[v] = nodo anterior a v.
  int vertices; // numero de vertices conectados
  bool ciclo;

public:
  ArbolLibre(const Grafo &g) : visit(g.V(), false), ant(g.V(), -1), vertices(0), ciclo(false) {
    std::queue<int> q;
    visit[0] = true;
    q.push(0);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int w : g.ady(v)) {
        if (!visit[w]) {
          visit[w] = true;
          ant[w] = v;
          vertices ++;
          q.push(w);
        }
        else if (w != ant[v]) {
          ciclo = true;    // w ya visitado y no es por donde vinimos
        }
      }
    }
  }
  bool libre() const { return vertices == (int)visit.size() - 1 && !ciclo; }
};

void resuelveCaso() {

  // leer los datos de la entrada
  int V, A;
  std::cin >> V >> A;
  Grafo g(V);

  for (int i = 0; i < A; i++) {
    int v, w;
    cin >> v >> w;
    g.ponArista(v, w);
  }
  ArbolLibre a(g);
  cout << (a.libre() ? "SI" : "NO") << "\n";
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
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