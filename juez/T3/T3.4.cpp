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
//#include "PriorityQueue.h"
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
//void resuelve(PriorityQueue<int, greater<int>>& pilasA, PriorityQueue<int, greater<int>>& pilasB, int N) {
//	// recorremos hasta que se hayan acabado todas las pilas
//	while (!pilasA.empty() && !pilasB.empty()) {
//		int horasVoladas = 0;
//
//		int drones = min(N, min(pilasA.size(), pilasB.size()));
//		vector<int> sobA(drones), sobB(drones);
//		// mientras que los indices aumenten a la vez, no se han acabado ninguna de las pilas
//		for (size_t i = 0; i < drones; i++)
//		{
//			int hA = pilasA.top(); pilasA.pop();
//			int hB = pilasB.top(); pilasB.pop();
//			// el numero de horas voladas es la cantidad menor capaz de volar de una de las pilas
//			int nhoras = min(hA, hB);
//			// restamos las horas restantes
//			horasVoladas += nhoras;
//			hA -= nhoras; if (hA > 0)
//				sobA[i] = hA;
//			hB -= nhoras; if (hB > 0)
//				sobB[i] = hB;
//		}
//
//		for (int c : sobA) if(c>0)pilasA.push(c);
//		for (int c : sobB) if(c>0)pilasB.push(c);
//
//		cout << horasVoladas << " ";
//	}
//}
//
//bool resuelvecaso() {
//	// Leer los datos de la entrada.
//	int N, A, B;
//	if (!(cin >> N >> A >> B))  // Fin de la entrada.
//		return false;
//
//	PriorityQueue<int, greater<int>> pilasA;
//	for (size_t i = 0; i < A; i++)
//	{
//		int carg;
//		cin >> carg;
//		pilasA.push(carg);
//	}
//	PriorityQueue<int, greater<int>> pilasB;
//	for (size_t i = 0; i < B; i++)
//	{
//		int carg;
//		cin >> carg;
//		pilasB.push(carg);
//	}
//
//	resuelve(pilasA, pilasB, N);
//	cout << "\n";
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
//	std::ifstream in("T3/casos3.4.txt");
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
