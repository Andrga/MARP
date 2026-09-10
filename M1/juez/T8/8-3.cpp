///*@ <authors>
// *
// * Andres Garcia Navarro, MARP19
// *
// *@ </authors> */
//
//#include <iostream>
//#include <fstream>
//#include <algorithm>
//#include <limits>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//
//
///*@ <answer>
//* El coste en tiempo de este algortmo es O(N*log(N) + M*log(M)) donde N es el numero de jugadores y M el numero de equipaciones disponibles.
//* Hace falta ordenar los vectores de jugadores y equipaciones, usando el metodo sort tenemos un coste (N*logN)
//* El metodo realiza un bucle con coste O(N + M) por ello el coste total viene dado por la ordenacion.
// @ </answer> */
//
//
// //@ <answer>
//int temporada(vector<int> const& jugadores, vector<int> const& equipaciones) {
//	// Primer agujero tiene un parche.
//	int validas = 0;
//	int i = 0, j = 0;
//	while (i < jugadores.size() && j < equipaciones.size())
//	{
//		// si la talla del jugador es menor o igual que la equipacion, y la equipacion no supera en 1 a la talla, es una equipacion valida.
//		if (equipaciones[j] >= jugadores[i] && equipaciones[j] <= jugadores[i]+1) {
//			i++; j++;
//			validas++;
//		}
//		else {
//			// Si la equipacion es demasiado grande, probamos con el siguiente jugador.
//			if (equipaciones[j] > jugadores[i])
//				i++;
//			// Si no probamos con la siguiente equipacion.
//			else
//				j++;
//		}
//	}
//	return validas;
//}
//
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int N, M;
//	cin >> N >> M;
//	if (!cin) return false;
//
//	vector<int> jugadores(N, 0);
//	vector<int> equipaciones(M, 0);
//
//	for (int i = 0; i < N; i++)
//		cin >> jugadores[i];
//	for (int i = 0; i < M; i++)
//		cin >> equipaciones[i];
//
//	sort(jugadores.begin(), jugadores.end());
//	sort(equipaciones.begin(), equipaciones.end());
//
//	int validas = temporada(jugadores, equipaciones);
//
//	cout << N - validas << "\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("T8/casos8.3.txt");
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
