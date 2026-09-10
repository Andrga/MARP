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
//struct Task {
//	int inicio;
//	int fin;
//	int periodo;
//
//	bool operator<(Task const& other)const {
//		return inicio < other.inicio;
//	}
//};
//
//bool resuelvecaso() {
//	// Leer los datos de la entrada.
//	int N, M, T;
//	cin >> N >> M >> T;
//
//	if (!cin)  // Fin de la entrada.
//		return false;
//	int id = 0;
//	IndexPQ<int, Task> tasks;
//	for (size_t i = 0; i < N; i++)
//	{
//		int ini, fin;
//		cin >> ini >> fin;
//		if (ini < T) {
//			tasks.push(id, { ini,fin, 0 });
//			id++;
//		}
//	}
//	for (size_t i = 0; i < M; i++)
//	{
//		int ini, fin, periodo;
//		cin >> ini >> fin >> periodo;
//		if (ini < T) {
//			tasks.push(id, { ini,fin, periodo });
//			id++;
//		}
//	}
//
//	int ultimoFin = -1;
//	bool colision = false;
//
//	while (!tasks.empty() && !colision)
//	{
//		Task tAux = tasks.top().prioridad;
//		int idAux = tasks.top().elem;
//		if (ultimoFin > tAux.inicio)
//			colision = true;
//		else ultimoFin = max(ultimoFin, tAux.fin);
//		if (tAux.periodo > 0) {
//			tAux.inicio += tAux.periodo;
//			tAux.fin += tAux.periodo;
//			tasks.update(idAux, tAux);
//		}
//	}
//
//	cout << (colision ? "SI" : "NO") << "\n";
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
//	std::ifstream in("T3/casos3.3.txt");
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
