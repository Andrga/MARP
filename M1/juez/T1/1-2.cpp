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
//
//using namespace std;
//
//#include "TreeSet_AVL.h"
//
///*@ <answer>
//
//	La funcion devuelve el valor numero k del arbol utilizando el contador de hijos en cada nodo del Set.
//	Se suma 1 cada vez que se anyade un hijo por la izquierda a un nodo y se actualiza los contadores necesarios si se ha hecho una rotacion
//	Este contador tiene un coste constante O(1)
//
//	kesimoRec tiene un coste O(log(n)), siendo n el numero de elementos del arbol.
//
// @ </answer> */
//template <typename T>
//class ExtendedSet : public Set<T> {
//public:
//	T const& kesimo(int k) const {
//		return kesimoRec(this->raiz, k);
//	}
//protected:
//	T const& kesimoRec(Set<T>::Link tree, int k) const {
//		if (tree == nullptr)
//			throw std::out_of_range("k fuera de rango");
//		// Casos base
//		if (Set<T>::size(tree) == k)
//			return tree->elem;
//		else if (Set<T>::size(tree) > k)
//			return kesimoRec(tree->iz, k);
//		else
//			return kesimoRec(tree->dr, k - Set<T>::size(tree));
//	}
//};
////@ <answer>
//
//bool resuelveCaso() {
//	// leer los datos de la entrada
//	int n, nk;
//	cin >> n;
//
//	if (n == 0)  // fin de la entrada
//		return false;
//
//	vector<int> ks;
//	ExtendedSet<int> tree;
//
//	for (size_t i = 0; i < n; i++)
//	{
//		int e;
//		cin >> e;
//		tree.insert(e);
//	}
//	cin >> nk;
//	for (size_t i = 0; i < nk; i++)
//	{
//		int e;
//		cin >> e;
//		try {
//			cout << tree.kesimo(e) << endl;
//		}
//		catch (out_of_range) {
//			cout << "??" << endl;
//		}
//	}
//	cout << "---" << endl;
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
//	std::ifstream in("casos1.2.txt");
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
