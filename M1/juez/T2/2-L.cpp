///*@ <authors>
// *
// * MARP19 Andres Garcia Navarro
// *
// *@ </authors> */
//
//#include <iostream>
//#include <fstream>
//#include <algorithm>
//#include <limits>
//#include <queue>
//using namespace std;
//
//
///*@ <answer>
//
// El metodo assignaAtril() utiliza assignaAtrilRec() que lo que hace es asignar partituras a los diferentes instrumentos.
//	assignaAtrilRec() recalcula la prioridad en caso de anyadir un nuevo atril al instrumento.
// La prioridad de la cola viene dada por el numero cuyo subgrupo (musicos/partituras asignadas) sea mayor.
//
// La complejidad en tiempo del algoritmo es O(Plog(N)) donde N es el numero de instrumentos en la orquesta, y P el numero de partituras a repartir.
// La complejidad en espacio es O(N) siendo N los elementos de la cola;
//
// @ </answer> */
//
//
// // ================================================================
//struct Instrumento {
//	int cant; // Cantidad de musicos de el instrumento
//	int nAtril; // Numero de atriles asignados
//	int priority; // Cant/nAtril
//
//	bool operator<(Instrumento const& other)const {
//		return priority < other.priority;
//	}
//};
//
//void assignaAtrilRec(priority_queue<Instrumento>& pq, int p) {
//	if (p == 0) return;
//	Instrumento i = pq.top();
//	if (i.priority == 1) return;
//	pq.pop();
//	i.nAtril += 1;
//	i.priority = i.cant / i.nAtril;
//	if (i.cant % i.nAtril != 0) // Para casos en los que la division no de exacta
//		i.priority++;
//	pq.push(i);
//	assignaAtrilRec(pq, p - 1);
//}
//
//int assignaAtril(priority_queue<Instrumento>& pq, int p, int n) {
//	// Asignamos el numero de partituras a cada instrumento priorizando el numero de musicos.
//	assignaAtrilRec(pq, p);
//	Instrumento ins = pq.top();
//	return ins.priority;
//}
//
////@ <answer>
//
//
//
//bool resuelveCaso() {
//
//	// leemos la entrada
//	int P, N;
//	cin >> P >> N;
//
//	if (!cin)
//		return false;
//
//	// leer el resto del caso y resolverlo
//	priority_queue<Instrumento> queue;
//	for (size_t i = 0; i < N; i++)
//	{
//		Instrumento ins;
//		cin >> ins.cant;
//		ins.nAtril = 1;
//		ins.priority = ins.cant;
//		queue.push(ins);
//	}
//
//	P -= N;
//	cout << assignaAtril(queue, P, N) << "\n";
//
//
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba debajo de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("T2/casos2.L.txt");
//	if (!in.is_open())
//		cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
//	auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
//
//	// Resolvemos
//	while (resuelveCaso());
//
//	// para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//	cin.rdbuf(cinbuf);
//#endif
//	return 0;
//}
