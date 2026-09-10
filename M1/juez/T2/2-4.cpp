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
//	La funcion recorre las N lineas del documento de input imprimiendo los pacientes atendido.
//	Recorre el documento de input detectando el tipo de evento, cuando atiende extrae el paciente con prioridad de la cola.
//	La prioridad se establece mirando la gravedad del paciente, en caso de tener la misma gravedad, mira el turno establecido,
//	siendo este creciente segun cuando ha sido anyadido a la cola
//	Coste en tiempo: O(Nlog(M)), siendo N el numero de eventos y M el numero de pacientes.
//	Coste en espacio: O(M), siendo M el numero de pacientes.
//
// @ </answer> */
//
//struct Paciente {
//	string n;
//	int g;
//	int t;
//
//	bool operator<(Paciente const& other)const {
//		if (g == other.g)
//			return other.t < t;
//		return g < other.g;
//	}
//};
//
//string atender(priority_queue<Paciente>& queue) {
//	if (queue.size() <= 0) return "";
//	Paciente pac = queue.top();
//	queue.pop();
//	return pac.n;
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
//	priority_queue<Paciente> queue;
//	for (size_t i = 0; i < n; i++) {
//		char e;
//		cin >> e;
//
//		if (e == 'I') {
//			string name;
//			int gravedad;
//			cin >> name >> gravedad;
//			Paciente ev = {name,gravedad, i};
//			queue.push(ev);
//		}
//		else if (e == 'A') {
//			cout << atender(queue) << "\n";
//		}
//	}
//	cout << "---\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	std::ifstream in("T2/casos2.4.txt");
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
