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

class Bacon
{
private:
  int INF = numeric_limits<int>::max();
  std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
  std::vector<int> dist;   // dist[v] = distancia de s a v
  int s;                   // id de bacon

public:
  Bacon(const Grafo &g, int s) : visit(g.V(), false), dist(g.V(), INF), s(s)
  {
    bfs(g);
  }

  bool conectado(int w) const { return visit[w]; }
  int distancia(int w) const { return dist[w]; }

private:
  void bfs(Grafo const &g)
  {
    std::queue<int> q;
    dist[s] = 0;
    visit[s] = true;
    q.push(s);
    while (!q.empty())
    {
      int v = q.front();
      q.pop();
      for (int w : g.ady(v))
      {
        if (!visit[w])
        {
          dist[w] = dist[v] + 1;
          visit[w] = true;
          q.push(w);
        }
        else if (dist[v] + 1 < dist[w])
          dist[w] = dist[v] + 1;
      }
    }
  }
};

void resuelveCaso()
{

  // leer los datos de la entrada
  int P;
  cin >> P;
  unordered_map<string, int> ids;          // relacion actor/peli - id
  vector<pair<string, string>> relaciones; // relaciones peli - actor

  for (int i = 0; i < P; i++)
  {
    string peli;
    cin >> peli;
    int actores;
    cin >> actores;
    if (!ids.count(peli))
      ids[peli] = ids.size();
    for (int i = 0; i < actores; i++)
    {
      string actor;
      cin >> actor;
      if (!ids.count(actor))
        ids[actor] = ids.size();
      relaciones.push_back({peli, actor});
    }
  }

  Grafo g(ids.size());
  for (pair<string, string> p : relaciones)
  {
    int v = ids[p.first],
        w = ids[p.second];
    g.ponArista(v, w);
  }
  
  bool estaKevin = ids.find("KevinBacon") != ids.end();
  
  int N;
  cin >> N;
  if(estaKevin){
    Bacon b(g, ids["KevinBacon"]);
    for (int i = 0; i < N; i++)
    {
      string a;
      cin >> a;
      cout << a << " " << (b.conectado(ids[a]) ? to_string(b.distancia(ids[a]) / 2) : "INF") << "\n";
    }
  }
  else{
    for (int i = 0; i < N; i++)
    {
      string a;
      cin >> a;
      cout << a << " INF\n";
    }
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