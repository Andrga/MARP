//
///*@ <authors>
// *
// * Andres, Garcia, Navarro, MARP19
// *
// *@ </authors> */
//
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
///*@ <answer>
//
//	La funcion devuelve el esfuerzo minimo de realizar una suma, 
//
//	kesimoRec tiene un coste O(Nlog(n)), siendo n el numero de elementos del arbol.
//
// @ </answer> */
//long long esfuerzoMinimo(priority_queue<long long, std::vector<long long>, std::greater<long long>>& queue) {
//	if (queue.size() <= 1) return 0;
//	long long a = queue.top();queue.pop();
//	long long b = queue.top(); queue.pop();
//	queue.push(a+b);
//
//	long long esfuerzo = a+b;
//
//	return esfuerzo + esfuerzoMinimo(queue);
//}
////@ <answer>
//
//bool resuelveCaso() {
//	// leer los datos de la entrada
//	int n;
//	cin >> n;
//
//	if (n == 0)  // fin de la entrada
//		return false;
//
//	std::priority_queue<long long, std::vector<long long>, std::greater<long long>> queue;
//	for (size_t i = 0; i < n; i++) {
//		long e;
//		cin >> e;
//		queue.push(e);
//	}
//	
//	cout << esfuerzoMinimo(queue) << endl;
//
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	std::ifstream in("casos2.1.txt");
//	if (!in.is_open())
//		std::cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
//	auto cinbuf = std::cin.rdbuf(in.rdbuf());
//#endif
//
//	while (resuelveCaso());
//
//	// para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//	std::cin.rdbuf(cinbuf);
//	std::cout << "Pulsa Intro para salir..." << std::flush;
//	std::cin.get();
//#endif
//	return 0;
//}
