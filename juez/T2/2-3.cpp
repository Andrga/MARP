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
//	La funcion imprime los k primeros usuarios que van a recibir informacion.
//	kPrimerosEnvios tiene un coste O(klog(n)), siendo n el numero de elementos de la cola y k el numero de envios.
//
// @ </answer> */
//
//struct Caja {
//	int id;
//	int t;
//
//	bool operator<(Caja const& other)const {
//		if (t == other.t)
//			return other.id < id;
//		return other.t < t;
//	}
//};
//
//int ncaja(priority_queue<Caja>& queue, vector<int>& clientes, int c, int i) {
//	if (i >= clientes.size())
//		return queue.top().id;
//
//	Caja caja = queue.top();
//	queue.pop();
//	caja.t += clientes[i];
//	queue.push(caja);
//
//	return ncaja(queue, clientes, c, i + 1);
//}
////@ <answer>
//
//bool resuelveCaso() {
//	// leer los datos de la entrada
//	int n, c;
//	cin >> n >> c;
//
//	if (n == 0 && c == 0)  // fin de la entrada
//		return false;
//
//	priority_queue<Caja> queue;
//	for (size_t i = 0; i < n; i++) {
//		Caja caj = { i+1,0 };
//		queue.push(caj);
//	}
//	vector<int> clientes;
//	for (size_t i = 0; i < c; i++)
//	{
//		int c;
//		cin >> c;
//		clientes.push_back(c);
//	}
//	int sol = ncaja(queue, clientes, c, 0);
//	cout << sol << "\n";
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
//	std::ifstream in("T2/casos2.3.txt");
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
