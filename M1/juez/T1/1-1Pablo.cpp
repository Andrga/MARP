//
///*@ <authors>
// *
// * Andres, Garcia, Navarro, MARP19
// *
// *@ </authors> */
//
//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//#include "bintree.h"
//
///*@ <answer>
//
//	La función comprueba si un arbol dado cumple las condiciones para ser un arbol AVL
//	Si el desnivel de las ramas del arbol y subarboles es igual o menor que 1,
//	y si elementos de arbol y subarbol cumplen que: izquierdos < root < derechos.
//	La funcion devuelve la altura del arbol o -1 si incumple alguna de las caracteristicas de los arboles AVL.
//	La complejidad es lineal O(n) ya que recorre el arbol entero pasando por cada uno de sus elementos una vez
//
// @ </answer> */
//
//template <class T>
//int ALV(BinTree<T> arbol, std::pair<T, T>& minMax)
//{
//	// CASOS BASE:
//	// Caso vacio;
//	if (arbol.empty())
//	{
//		return 0;
//	}
//	// Caso hoja;
//	if (arbol.left().empty() && arbol.right().empty())
//	{
//		minMax.first = arbol.root();
//		minMax.second = arbol.root();
//		return 1;
//	}
//
//	// CASOS IZQUIERDO Y DERECHO:
//	std::pair<T, T> minMaxIzq;
//	std::pair<T, T> minMaxDer;
//	int izq = ALV(arbol.left(), minMaxIzq);
//	int der = ALV(arbol.right(), minMaxDer);
//	if (!arbol.left().empty()) {
//		// Si el minimo de la izquierda es menor que el minimo general
//		if (minMaxIzq.first < minMax.first)
//		{
//			minMax.first = minMaxIzq.first // se guarda como nuevo minimo general
//		}
//		else return -1; // si no no es un arbol AVL
//	}
//	if (!arbol.right().empty()) {
//		// Si el maximo de la derecha es mayor que el maximo general
//		if (minMaxDer.second > minMax.second)
//		{
//			minMax.first = minMaxIzq.first // se guarda como nuevo maximo general
//		}
//		else return -1 // si no no es un arbol AVL
//	}
//
//	if (minMax.second < minMaxDer.second)
//	{
//		minMax.second = minMaxIzq.second;
//	}
//
//	int nivelHijos = izq >= der ? izq : der;
//	nivelHijos = izq == -1 ? der : izq;
//
//	if (abs(izq - der) > 1)
//	{
//		nivelHijos = -1;
//	}
//	else
//	{
//		nivelHijos++;
//	}
//
//	if (/*!arbol.left().empty() && !arbol.right().empty() && arbol.left().root() > arbol.right().root() ||*/
//		!arbol.left().empty() && arbol.root() < minMax.first ||
//		!arbol.right().empty() && arbol.root() > minMax.second)
//	{
//		nivelHijos = -1;
//	}
//
//	return nivelHijos;
//}
//
////@ <answer>
//
//bool resuelveCaso() {
//	// leer los datos de la entrada
//	char t;
//	cin >> t;
//
//	if (!std::cin)  // fin de la entrada
//		return false;
//
//	int sol = 0;
//	if (t == 'N') {
//		pair<int, int> minMax;
//		BinTree<int> tree = read_tree<int>(cin);
//		sol = ALV(tree, minMax);
//	}
//	else {
//		pair<string, string> minMax;
//		BinTree<string> tree = read_tree<string>(cin);
//		sol = ALV(tree, minMax);
//	}
//
//	cout << ((sol < 0) ? "NO" : "SI") << endl;
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
//	std::ifstream in("casos.txt");
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
