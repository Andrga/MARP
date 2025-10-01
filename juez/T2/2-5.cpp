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
//struct Comic {
//	int ns; // numero de serie.
//	int pla; // numero en la pila.
//
//	bool operator<(Comic const& other)const {
//		return other.ns < ns;
//	}
//};
//
//int resolver(vector<stack<Comic>>& pilas, priority_queue<Comic>& queue, int const menor) {
//
//	if (queue.top().ns == menor)
//		return 1;
//
//	Comic com = queue.top();
//	queue.pop();
//	// Si la pila ha sido vaciada no se anyade ningun comic nuevo a la cola.
//	if (!pilas[com.pla].empty()) {
//		// Cogemos el siguiente comic de la misma pila que ha sido cogido el anterior.
//		Comic auxCom = pilas[com.pla].top(); pilas[com.pla].pop();
//		queue.push(auxCom);
//	}
//
//	return resolver(pilas, queue, menor) + 1;
//}
//
////@ <answer>
//
//bool resuelvecaso() {
//	// Leer los datos de la entrada.
//	int n;
//	cin >> n;
//
//	if (!std::cin)  // Fin de la entrada.
//		return false;
//
//	vector<stack<Comic>> pilas;
//	priority_queue<Comic> tops;
//	int menor = -1;
//	// Lectura de pilas
//	for (size_t i = 0; i < n; i++)
//	{
//		stack<Comic> pila;
//		int k;
//		cin >> k;
//		for (size_t j = 0; j < k; j++)
//		{
//			int ns;
//			cin >> ns;
//
//			if (menor == -1 || menor > ns)
//				menor = ns;
//			Comic comic = { ns, i };
//
//			// Si es el primer elemento de la pila se anyade a la cola.
//			if (j == k - 1)
//				tops.push(comic);
//			else // Si no se anyade a su pila correspondiente.
//				pila.push(comic);
//		}
//		pilas.push_back(pila);
//	}
//	// Metodo para resolver de manera recursiva.
//	int sol = resolver(pilas, tops, menor);
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
//#ifndef DOMJUDGE
//	std::ifstream in("T2/casos2.5.txt");
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
