//
///*@ <authors>
// *
// * andres, garcia, navarro, marp19
// *
// *@ </authors> */
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <queue>
//#include <stack>
//#include "IndexPQ.h"
//
//using namespace std;
//
///*@ <answer>
//
//	Coste en tiempo:
//	Coste en espacio:
//
// @ </answer> */
//
// //@ <answer>
//
//struct Pais {
//	string nom;
//	int points;
//
//	bool operator<(Pais const& other)const {
//		return other.points < points || (other.points == points && nom < other.nom);
//	}
//};
//
//bool resuelvecaso() {
//	// Leer los datos de la entrada.
//	int n;
//	cin >> n;
//
//	if (!cin)  // Fin de la entrada.
//		return false;
//
//	IndexPQ<string, Pais> paises; // Usar la nueva ampliada, con un tipo generico de dato
//	for (size_t i = 0; i < n; i++)
//	{
//		string nom; int pts;
//		cin >> nom;
//		if (nom == "?")
//		{
//			cout << paises.top().elem << " " << paises.top().prioridad.points << "\n";
//		}
//		else
//		{
//			cin >> pts;
//			int ptsAnt = 0;
//			try {
//				ptsAnt = paises.priority(nom).points;
//			}
//			catch (exception& e) {}
//
//			paises.update(nom, { nom, pts + ptsAnt });
//		}
//	}
//
//	cout << "---\n";
//
//	return true;
//}
//
////@ </answer>
////  lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	std::ifstream in("T3/casos3.2.txt");
//	if (!in.is_open())
//		std::cout << "error: no se ha podido abrir el archivo de entrada." << std::endl;
//	auto cinbuf = std::cin.rdbuf(in.rdbuf());
//#endif
//
//	while (resuelvecaso());
//
//	// para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//	std::cin.rdbuf(cinbuf);
//	std::cout << "pulsa intro para salir..." << std::flush;
//	std::cin.get();
//#endif
//	return 0;
//}
