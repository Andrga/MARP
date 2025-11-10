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
//* El coste en tiempo de este algortmo es O(N*log(N)) donde N es el numero de ciudades invadidas y equipos.
//* Hace falta ordenar los vectores de equipos y enemigos, usando el metodo sort tenemos un coste (N*logN)
// @ </answer> */
//
//
// //@ <answer>
//int ciudades(vector<int> const& Eq, vector<int> const& En) {
//	// Primer agujero tiene un parche.
//	int exitos = 0;
//	int i = 0, j = 0;
//	while (i< Eq.size() && j < En.size())
//	{
//		// si el numero en el equipo es mayor que los enemigos, es una victoria.
//		if (Eq[i] >= En[j]) {
//			i++; j++;
//			exitos++;
//		}
//		// Si no probamos con el siguiente equipo
//		else {
//			i++;
//		}
//	}
//	return exitos;
//}
//
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int N;
//	cin >> N;
//	if (!cin) return false;
//
//	vector<int> enemigos(N, 0);
//	vector<int> equipos(N, 0);
//
//	for (int i = 0; i < N; i++)
//		cin >> enemigos[i];
//	for (int i = 0; i < N; i++)
//		cin >> equipos[i];
//
//	sort(equipos.begin(), equipos.end());
//	sort(enemigos.begin(), enemigos.end());
//
//	cout << ciudades(equipos, enemigos) << "\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("T8/casos8.2.txt");
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
