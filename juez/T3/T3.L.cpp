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
//#include "IndexPQ.h"
//
//using namespace std;
//
///*@ <answer>
//
//	Coste en tiempo: O((N + N * C) * log(C))
//	Coste en espacio: O(C)
//
// @ </answer> */
//
// //@ <answer>
//struct Canal {
//	int audiencia = 0;
//	int tPrime = 0;
//	int id = 0;
//	bool operator<(Canal const& other) const{
//		// invertido porque queremos el mayor
//		return audiencia > other.audiencia;
//	}
//};
//
//struct comp_canal {
//	bool operator()(Canal const& a, Canal const& b) const {
//		return b.tPrime < a.tPrime ||
//			(a.tPrime == b.tPrime && b.id > a.id);
//	}
//};
//
//bool resuelvecaso() {
//	// Leer los datos de la entrada.
//	int D, C, N;
//	if (!(cin >> D >> C >> N))  // Fin de la entrada.
//		return false;
//
//	int min = 0;
//	IndexPQ<int, Canal> canales;
//	for (int i = 0; i < C; i++)
//	{
//		int aud;
//		cin >> aud;
//		canales.push(i +1, {aud, min, i +1});
//	}
//
//	// regista las actualizaciones
//	for (int i = 0; i < N; i++)
//	{
//		int auxmin;
//		cin >> auxmin;
//		Canal cinf = canales.top().prioridad;
//		cinf.tPrime += auxmin - min;
//		min = auxmin;
//		canales.update(cinf.id, cinf);
//
//		int c, aud;
//		// actualiza la cola
//		while (cin>>c, c!= -1){
//			cin >> aud;
//			cinf = canales.priority(c);
//			cinf.audiencia = aud;
//			canales.update(c, cinf);
//		}
//	}
//	// sumamos lo que falta para llegar al final de primetime
//	Canal cinf = canales.top().prioridad;
//	cinf.tPrime += D - min;
//	canales.update(cinf.id, cinf);
//
//	//ordenamos segun el primetime
//	PriorityQueue<Canal, comp_canal> cola;
//
//	for (int i = 0; i < C; ++i) {
//		cola.push(canales.top().prioridad); canales.pop();
//	}
//
//	// Salida
//	while (!cola.empty())
//	{
//		Canal c = cola.top(); cola.pop();
//		if (c.tPrime == 0) continue;
//		cout << c.id << " "  << c.tPrime << "\n";
//	}
//	cout << "---\n";
//	return true;
//}
//
////@ </answer>
////  lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	std::ifstream in("T3/casos3.L.txt");
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
