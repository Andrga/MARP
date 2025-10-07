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
//#include <unordered_map>
//#include "IndexPQ.h"
//using namespace std;
//
//
///*@ <answer>
//
// He usado dos priority queues una en la que se almacenan los canales con sus audiencias
// y una segunda donde se ordenan los canales con su tiempo en primetime. 
//
// Cuando se termina de procesar una actualizacion, se mira el canal con mayor audiencia, 
// se resta la hora de la actualizacion actual menos el de la anterior y se asigna ese periodo
// de tiempo al canal ganador del primetime, eso se mete en la segunda IndexPQ (canal-tiempo).
//
// complejidad en tiempo: O(N*C*log(C)) siendo N el numero de actualizaciones y C el numero de canales
//
// @ </answer> */
//
//
// // ================================================================
// // Escribe el código completo de tu solución aquí debajo (después de la marca)
// //@ <answer>
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int D, C, N;
//	cin >> D >> C >> N;
//	if (!cin) return false;
//
//	// leer el resto del caso y resolverlo.
//	IndexPQ<int, int, greater<int>> canalesAudiencia;
//	IndexPQ<int, int, greater<int>> canalesTiempo;
//	// Lee el primer dato de cada canal.
//	for (size_t i = 0; i < C; i++)
//	{
//		int a;
//		cin >> a;
//		canalesAudiencia.push(i + 1, a);
//	}
//	int minsAnt = 0;
//	// Actualizaciones.
//	for (size_t i = 0; i < N; i++)
//	{
//		int mins, canal;
//		cin >> mins >> canal;
//
//		// Acumulamos los minutos del canal
//		int minsCAct = 0;
//		try {
//			minsCAct = canalesTiempo.priority(canalesAudiencia.top().elem);
//		}
//		catch (exception& e) {}
//		canalesTiempo.update(canalesAudiencia.top().elem, minsCAct + (mins - minsAnt));
//		minsAnt = mins;
//
//		// Leemos la actualizacion.
//		while (canal != -1)
//		{
//			int audiencia;
//			cin >> audiencia;
//			canalesAudiencia.update(canal, audiencia);
//			cin >> canal;
//		}
//		
//	}
//	int minsCAct = 0;
//	try {
//		minsCAct = canalesTiempo.priority(canalesAudiencia.top().elem);
//	}
//	catch (exception& e) {}
//	// Actualiza el tiempo, desde la ultima actualizacion hasta el final.
//	canalesTiempo.update(canalesAudiencia.top().elem, minsCAct + (D - minsAnt));
//	
//	// Impresion de canales y minutos ordenados.
//	while (!canalesTiempo.empty())
//	{
//		int canal, tiempo;
//		canal = canalesTiempo.top().elem;
//		tiempo = canalesTiempo.top().prioridad;
//		canalesTiempo.pop();
//		cout << canal << " " << tiempo << "\n";
//	}
//
//	cout << "---\n";
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
//	ifstream in("T3/casos3.L.txt");
//	if (!in.is_open())
//		cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
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
