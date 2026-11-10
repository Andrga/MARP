/*@ <authors>
 *
 * MARP30 Andrés García Navarro
 *
 *@ </authors> */

#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// propios o los de las estructuras de datos de clase

/*@ <answer>

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

const int MAX = 10000;
const int INF = 1000000000;

int adyacente(int v, int i) {
  switch (i) {
  case 0:
    return (v + 1) % MAX;
  case 1:
    return (v * 2) % MAX;
  default:
    return v / 3;
  }
};

int bfs(int ini, int fin) {
  vector<int> distancia(MAX, INF);
  distancia[ini] = 0;
  queue<int> cola;
  cola.push(ini);
  while (!cola.empty()) {
    int v = cola.front();
    cola.pop();
    for (int i = 0; i < 3; i++) {
      int w = adyacente(v, i);
      if (distancia[w] == INF) { // no ha sido visitado
        distancia[w] = distancia[v] + 1;
        if (w == fin)
          return distancia[w];
        cola.push(w);
      }
    }
  }
  return distancia[fin];
}

void resuelveCaso() {

  // leer los datos de la entrada
  int INI, FIN; cin >> INI >> FIN;
  cout << to_string(bfs(INI, FIN)) << "\n";
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