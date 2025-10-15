///*@ <authors>
// *
// * Andres, Garcia, Navarro, MARP19
// *
// *@ </authors> */
//
//#include <iostream>
//#include <fstream>
//#include <algorithm>
//#include <limits>
//#include <queue>
//#include <string>
//#include <unordered_map>
//#include "Grafo.h"
//
//using namespace std;
//
//
//
///*@ <answer>
//
//	Coste en tiempo = O(V + A),
//	siendo V el numero de vertices y A el numero de aristas totales.
//	En el caso peor se recorren todos los vertices y las aristas que los unen.
//
// @ </answer> */
//
//
// //@ <answer>
//
//class GruposAmigos
//{
//private:
//	vector<bool> visit;	// visit[v] = hay camino de s a v.
//	vector<int> alcances; // alcances[v] = el alcance que tiene la persona v.
//	int _s;				// vertice origen.
//public:
//	GruposAmigos(Grafo const& g, int user) : _s(user), visit(g.V(), false), alcances(g.V())
//	{
//		user
//	}
//
//	// Distancia / 2 porque recorres la pelicula y luego el actor, eso son 2 aristas pero deberia ser distancia 1.
//	int getNBacon(int actor) { return dist[actor]; }
//
//private:
//	int dfs(Grafo const& g, int v) {
//		visit[v] = true;
//		int tam = 1;
//		for (int w : g.ady(v))
//		{
//			if (!visit[w])
//			{
//				tam += dfs(g, w);
//			}
//		}
//		return tam;
//	}
//
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int nUsr, nGrp;
//	cin >> nUsr >> nGrp;
//	if (!cin) return false;
//
//	unordered_map<int, int> idNodo; // Mapa que asigna un nombre de peli o actor a un nodo.
//	vector<int> users;
//	Grafo g(nUsr + nGrp);
//
//	for (size_t i = 0; i < nGrp; i++) // i representa al grupo
//	{
//		idNodo[i] = idNodo.size();
//		int uInGrp;
//		cin >> uInGrp;
//		for (size_t j = 0; j < uInGrp; j++)
//		{
//			int usr;
//			cin >> usr;
//			if (!idNodo.count(usr)) {
//				idNodo[usr] = idNodo.size();
//				users.push_back(usr);
//			}
//			g.ponArista(idNodo[i], idNodo[usr]); // Guarda la relacion.
//		}
//	}
//
//
//
//
//	Bacon bacon(grafo, nombNodo["KevinBacon"]);
//
//	int n;
//	cin >> n;
//	for (size_t i = 0; i < n; i++)
//	{
//		string actor;
//		cin >> actor;
//		int nBacon = bacon.getNBacon(nombNodo[actor]);
//		cout << actor << " " << (nBacon == -1 ? "INF" : to_string(nBacon / 2)) << "\n";
//	}
//	cout << "---\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("T4/casos4.5.txt");
//	if (!in.is_open())
//		cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
//	auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
//
//	// Resolvemos
//	while (resuelveCaso());
//
//	// para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//	cin.rdbuf(cinbuf);
//#endif
//	return 0;
//}
