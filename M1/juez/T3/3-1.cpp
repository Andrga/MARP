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
//	La funcion Busca el menor elemento de dos pilas, quitando primeramente el menor del top de ambas
//	Para ello, utilizamos una cola de prioridad donde se almacenan el primer comic de cada pila.
//	Coste en tiempo: O(N log(M)), siendo N el numero de Comics y M el numero de pilas de comics.
//	Coste en espacio: O(N), siendo N el numero de comics.
//
// @ </answer> */
//
// //@ <answer>
//
//bool resuelvecaso() {
//	// Leer los datos de la entrada.
//	int primerPajaro, parejas;
//	cin >> primerPajaro >> parejas;
//
//	if (primerPajaro == 0 && parejas == 0)  // Fin de la entrada.
//		return false;
//
//	priority_queue<int> min;
//	priority_queue<int, vector<int>, greater<int>> max;
//	min.push(primerPajaro);
//
//	for (size_t i = 0; i < parejas * 2; i += 2)
//	{
//		for (size_t j = 0; j < 2; j++)
//		{
//			int paj;
//			cin >> paj;
//
//			if (paj < min.top())
//				min.push(paj);
//			else
//				max.push(paj);
//		}
//
//		while (min.size() != max.size() +1)
//		{
//			if (min.size() > max.size() + 1) {
//				max.push(min.top());
//				min.pop();
//			}
//			else {
//				min.push(max.top());
//				max.pop();
//			}
//		}
//		std::cout << min.top() << " ";
//	}
//
//	std::cout << "\n";
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
//	std::ifstream in("T3/casos3.1.txt");
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
