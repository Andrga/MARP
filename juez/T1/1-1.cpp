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
//
//using namespace std;
//
//#include "bintree.h"
//
///*@ <answer>
//	
//	la funcion comprueba si un arbol dado cumple las condiciones para ser un arbol avl
//	si el desnivel de las ramas del arbol y subarboles es igual o menor que 1, 
//	y si elementos de arbol y subarbol cumplen que: izquierdos < root < derechos.
//	la funcion devuelve la altura del arbol o -1 si incumple alguna de las caracteristicas de los arboles avl.
//	la complejidad es lineal o(n) ya que recorre el arbol entero pasando por cada uno de sus elementos una vez
//
// @ </answer> */
//
//template <typename t>
//int resolver(const BinTree<t>& tree, t& minval, t& maxval) {
//	// casos base
//	// el arbol esta vacio el nivel es 0 y es avl
//	if (tree.empty()) return 0;
//
//	// inicializacion de variables locales
//	t root = tree.root();
//	minval = root;
//	maxval = root;
//
//	t minl, maxl, minr, maxr;
//	int llevel = 0, rlevel = 0;
//
//	if (!tree.left().empty()) {
//		// recorremos las ramsas del arbol
//		llevel = resolver(tree.left(), minl, maxl);
//		// si el elemento izquierdo es mayor que el root no es avl
//		if (llevel < 0 || maxl >= root) return -1;
//		minval = minl;
//	}
//	if (!tree.right().empty()) {
//		// recorremos las ramas del arbol
//		rlevel = resolver(tree.right(), minr, maxr);
//		// si el elemento derecho es menor que el root no es avl
//		if (rlevel < 0 || minr <= root) return -1;
//		maxval = maxr;
//	}
//
//	// el arbol es degenerado si hay un desnivel superior a 1
//	if (abs(llevel - rlevel) > 1) return -1;
//	return (llevel > rlevel ? llevel : rlevel) + 1;
//}
//
////@ <answer>
//
//bool resuelvecaso() {
//	// leer los datos de la entrada
//	char t;
//	cin >> t;
//
//	if (!std::cin)  // fin de la entrada
//		return false;
//
//	int sol = 0;
//	if (t == 'n') {
//		int min, max;
//		BinTree<int> tree = read_tree<int>(cin);
//		sol = resolver(tree, min, max);
//	}
//	else {
//		string min, max;
//		BinTree<string> tree = read_tree<string>(cin);
//		sol = resolver(tree, min, max);
//	}
//
//	cout << ((sol < 0) ? "no" : "si") << endl;
//
//	return true;
//}
//
////@ </answer>
////  lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef domjudge
//	std::ifstream in("casos.txt");
//	if (!in.is_open())
//		std::cout << "error: no se ha podido abrir el archivo de entrada." << std::endl;
//	auto cinbuf = std::cin.rdbuf(in.rdbuf());
//#endif
//
//	while (resuelvecaso());
//
//	// para dejar todo como estaba al principio
//#ifndef domjudge
//	std::cin.rdbuf(cinbuf);
//	std::cout << "pulsa intro para salir..." << std::flush;
//	std::cin.get();
//#endif
//	return 0;
//}
