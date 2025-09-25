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
//struct usuario
//{
//	int identificador;
//	int periodo;
//	long long instante;
//
//	// Sobrecarga del operador con valor invertido para que sea una cola de minimos
//	bool operator>(usuario const& other)const {
//		if (instante == other.instante)
//			return identificador > other.identificador;
//		return instante > other.instante;
//	}
//};
//
//void kPrimerosEnvios(priority_queue<usuario, vector<usuario>, greater<usuario>> & queue, int k) {
//	if (queue.size() == 0 || k == 0) return;
//
//	usuario usr = queue.top();
//	queue.pop();
//	queue.push({ usr.identificador, usr.periodo, usr.instante + usr.periodo });
//
//	cout << usr.identificador <<"\n";
//	kPrimerosEnvios(queue, k - 1);
//}
////@ <answer>
//
//bool resuelveCaso() {
//	// leer los datos de la entrada
//	int n, k;
//	cin >> n;
//
//	if (n == 0)  // fin de la entrada
//		return false;
//
//	priority_queue <usuario, vector<usuario>, greater<usuario>> queue;
//	for (size_t i = 0; i < n; i++) {
//		usuario usr;
//		cin >> usr.identificador >> usr.periodo;
//		usr.instante = usr.periodo;
//		queue.push(usr);
//	}
//	cin >> k;
//	kPrimerosEnvios(queue, k);
//	cout << "---\n";
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
//	std::ifstream in("casos2.2.txt");
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
