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
//
//using namespace std;
//
///*@ <answer>
//
//	La funcion recorre los elementos de la cola de prioridad encontrando el que tiene el menor numero de serie
//	y contando las posiciones necesarias para llegar a este.
//	La cola se organiza por posicion en las diferentes pilas, si se encuentran en la misma posicion se prioriza
//	el que tenga menor numero de serie.
//	Coste en tiempo: O(Nlog(M)), siendo N el numero de eventos y M el numero de pacientes.
//	Coste en espacio: O(M), siendo M el numero de pacientes.
//
// @ </answer> */
//
//struct Comic {
//	int ns; // numero de serie
//	int pla; // numero en la pila
//
//	bool operator<(Comic const& other)const {
//		if (pla == other.pla)
//			return other.ns < ns;
//		return other.pla < pla;
//	}
//};
//
//void resolver(vector<priority_queue<Comic>>& pilas, int const menor, int& m) {
//}
//
////@ <answer>
//
//bool resuelvecaso() {
//	// leer los datos de la entrada
//	int n;
//	cin >> n;
//
//	if (!std::cin)  // fin de la entrada
//		return false;
//
//	vector<priority_queue<Comic>> pilas(n);
//	int menor = -1;
//	for (size_t i = 0; i < n; i++)
//	{
//		int k;
//		cin >> k;
//		priority_queue<Comic> queue;
//		for (size_t j = 0; j < k; j++)
//		{
//			int ns;
//			cin >> ns;
//
//			if (menor == -1 || menor > ns)
//				menor = ns;
//			Comic comic = { ns, j };
//			queue.push(comic);
//		}
//		pilas.push_back(queue)
//	}
//	int sol = 0;
//	resolver(queue, menor, sol);
//	cout << sol << "\n";
//
//	return true;
//}
//
////@ </answer>
////  lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef domjudge
//	std::ifstream in("T2/casos2.5.txt");
//	if (!in.is_open())
//		std::cout << "error: no se ha podido abrir el archivo de entrada." << std::endl;
//	auto cinbuf = std::cin.rdbuf(in.rdbuf());
//#endif
//
//	while (resuelvecaso());
//
//	// para dejar todo como estaba al principio
//#ifndef domjudge
//	std::cin.rdbuf(cinbuf);
//	std::cout << "pulsa intro para salir..." << std::flush;
//	std::cin.get();
//#endif
//	return 0;
//}
