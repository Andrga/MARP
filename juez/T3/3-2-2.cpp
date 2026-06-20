///*@ <authors>
// *
// * Andres Garcia Navarro, MARP19
// *
// *@ </authors> */
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include "IndexPQ.h"
//using namespace std;
//
//struct Pais
//{
//	string nombre;
//	int puntos;
//
//	bool operator<(Pais const& other) const
//	{
//		if (puntos == other.puntos) return nombre < other.nombre;
//		return puntos > other.puntos;
//	}
//};
//
//bool resuelveCaso()
//{
//	int N;
//	cin >> N;
//	if (!cin) return false;
//
//	IndexPQ<string, Pais> pq;
//
//	for (int i = 0; i < N; ++i)
//	{
//		string n;
//		cin >> n;
//
//		if (n == "?")
//		{
//			// consulta del top
//			auto top = pq.top();
//			cout << top.prioridad.nombre << " " << top.prioridad.puntos << "\n";
//		}
//		else
//		{
//			int points;cin >> points;
//			Pais p;
//			try{
//				p = pq.priority(n);
//				p.puntos += points;
//			}
//			catch (exception)
//			{
//				p = {n,points };
//			}
//			pq.update(n, p);
//		}
//	}
//	cout << "---\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("T3/casos3.2.txt");
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
