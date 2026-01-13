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
//*
//*	La complejidad de este algoritmo 
//*	En tiempo es O((N+M*T) * log(N+M)) 
//*	En espacio es O(N+M)
//*	donde N es el numero de tareas unicas, M las tareas periodicas y T el periodo de tiempo a comprobar
//* 
//*	En el caso peor se recorren el bucle N+M*t veces, multiplicamos M*T porque se puede repetir una tarea hasta T veces
//*	Las operaciones en el bucle de mayor coste en tiempo es push o pop O(log(M+N))
//* 
//*	En espacio solo se reservan N+M espacios en la queue
// @ </answer> */
//
//
// // ================================================================
// // Escribe el código completo de tu solución aquí debajo (después de la marca)
// //@ <answer>
//
//struct Tarea {
//	int com = -1;
//	int fin = -1;
//	int rep = -1;
//
//	bool operator<(Tarea const& other)const {
//		return com < other.com;
//	}
//};
//
//bool resuelve(IndexPQ<int, Tarea>& agenda, int const T) {
//	if (agenda.empty()) return false;
//	Tarea t = agenda.top().prioridad;
//	agenda.pop();
//	while (!agenda.empty() && agenda.top().prioridad.com < T ) {
//		int fin = t.fin;
//		// Si el inicio de la siguiente tarea es menor que el fin de esta es porque se esta solapando
//		if (agenda.top().prioridad.com < fin) return true;
//		// si se repite y la siguiente tarea va a entrar en el rango de t insertamos
//		if (t.rep != -1 && t.com + t.rep < T) {
//			t.com += t.rep;
//			t.fin += t.rep;
//			// actualizamos la tarea que se repite
//			agenda.update(t.com, t);
//			continue;
//		}
//		// sacamos el siguiente elemento
//		t = agenda.top().prioridad;
//		agenda.pop();
//	}
//	return false;
//}
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int N, M, T;
//	cin >> N >> M >> T;
//	if (!cin) return false;
//	IndexPQ<int, Tarea> agenda;
//
//	// tareas unicas
//	for (int i = 0; i < N; i++)
//	{
//		int com, fin;
//		cin >> com >> fin;
//		agenda.push(com, { com, fin, -1 });
//	}
//	// tareas periodicas
//	for (int i = 0; i < M; i++)
//	{
//		int com, fin, rep;
//		cin >> com >> fin >> rep;
//		agenda.push(com, { com, fin, rep });
//	}
//
//	cout << (resuelve(agenda, T) ? "SI" : "NO") << "\n";
//	return true;
//}
////@ </answer>
////  Lo que se escriba debajo de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("T3/casos3.3.txt");
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
///// CON PRIORITYQUEUE
//
/////*@ <authors>
//// *
//// * MARP19 Andres Garcia Navarro
//// *
//// *@ </authors> */
////
////#include <iostream>
////#include <fstream>
////#include <algorithm>
////#include <limits>
////#include <queue>
////#include <unordered_map>
////#include "PriorityQueue.h"
////using namespace std;
////
////
/////*@ <answer>
////*
////*	La complejidad de este algoritmo
////*	En tiempo es O((N+M*T) * log(N+M))
////*	En espacio es O(N+M)
////*	donde N es el numero de tareas unicas, M las tareas periodicas y T el periodo de tiempo a comprobar
////*
////*	En el caso peor se recorren el bucle N+M*t veces, multiplicamos M*T porque se puede repetir una tarea hasta T veces
////*	Las operaciones en el bucle de mayor coste en tiempo es push o pop O(log(M+N))
////*
////*	En espacio solo se reservan N+M espacios en la queue
//// @ </answer> */
////
////
//// // ================================================================
//// // Escribe el código completo de tu solución aquí debajo (después de la marca)
//// //@ <answer>
////
////struct Tarea {
////	int com = -1;
////	int fin = -1;
////	int rep = -1;
////
////	bool operator<(Tarea const& other)const {
////		return com < other.com;
////	}
////};
////
////bool resuelve(PriorityQueue<Tarea>& agenda, int const T) {
////	if (agenda.empty()) return false;
////	Tarea t = agenda.top();
////	agenda.pop();
////	while (!agenda.empty() && agenda.top().com < T) {
////		int fin = t.fin;
////		// Si el inicio de la siguiente tarea es menor que el fin de esta es porque se esta solapando
////		if (agenda.top().com < fin) return true;
////		// si se repite y la siguiente tarea va a entrar en el rango de t insertamos
////		if (t.rep != -1 && t.com + t.rep < T) {
////			t.com += t.rep;
////			t.fin += t.rep;
////			// volvemos a meter la tarea que se repite
////			agenda.push(t);
////		}
////		// sacamos el siguiente elemento
////		t = agenda.top();
////		agenda.pop();
////	}
////	return false;
////}
////
////bool resuelveCaso() {
////
////	// leemos la entrada.
////	int N, M, T;
////	cin >> N >> M >> T;
////	if (!cin) return false;
////	PriorityQueue<Tarea> agenda;
////
////	// tareas unicas
////	for (int i = 0; i < N; i++)
////	{
////		int com, fin;
////		cin >> com >> fin;
////		agenda.push({ com, fin, -1 });
////	}
////	// tareas periodicas
////	for (int i = 0; i < M; i++)
////	{
////		int com, fin, rep;
////		cin >> com >> fin >> rep;
////		agenda.push({ com, fin, rep });
////	}
////
////	cout << (resuelve(agenda, T) ? "SI" : "NO") << "\n";
////	return true;
////}
//////@ </answer>
//////  Lo que se escriba debajo de esta línea ya no forma parte de la solución.
////
////int main() {
////	// ajustes para que cin extraiga directamente de un fichero
////#ifndef DOMJUDGE
////	ifstream in("T3/casos3.3.txt");
////	if (!in.is_open())
////		cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
////	auto cinbuf = cin.rdbuf(in.rdbuf());
////#endif
////
////	// Resolvemos
////	while (resuelveCaso());
////
////	// para dejar todo como estaba al principio
////#ifndef DOMJUDGE
////	cin.rdbuf(cinbuf);
////#endif
////	return 0;
////}
