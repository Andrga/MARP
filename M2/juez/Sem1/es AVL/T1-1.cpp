/*@ <authors>
 *
 * MARP86 Nombre Apellidos
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

// propios o los de las estructuras de datos de clase
#include "bintree.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

// Funcion recursiva comprueba si el arbol dado es AVL
template <typename T>
int equilibrado(const BinTree<T>& tree, T& minval, T& maxval){
	// el arbol esta vacio el nivel es 0 y es avl
	if (tree.empty()) return 0;

	// inicializacion de variables locales
	T root = tree.root();
	minval = root;
	maxval = root;

	T minl, maxl, minr, maxr;
	int llevel = 0, rlevel = 0;

	if (!tree.left().empty()) {
		// recorremos las ramsas del arbol
		llevel = equilibrado(tree.left(), minl, maxl);
		// si el elemento izquierdo es mayor que el root no es avl
		if (llevel < 0 || maxl >= root) return -1;
		minval = minl;
	}
	if (!tree.right().empty()) {
		// recorremos las ramas del arbol
		rlevel = equilibrado(tree.right(), minr, maxr);
		// si el elemento derecho es menor que el root no es avl
		if (rlevel < 0 || minr <= root) return -1;
		maxval = maxr;
	}

	// el arbol es degenerado si hay un desnivel superior a 1
	if (abs(llevel - rlevel) > 1) return -1;
	return (llevel > rlevel ? llevel : rlevel) + 1;
}

bool resuelveCaso() {

   // leer los datos de la entrada
   char c;
   if (!(std::cin >> c))  // fin de la entrada
      return false;

    int sol = 0;
    if (c == 'P'){
        string min, max;
        BinTree<string> tree = read_tree<string>(cin);
        sol = equilibrado<string>(tree, min, max);
    }
    else{   
        int min, max;
        BinTree<int> tree = read_tree<int>(cin);
        sol = equilibrado<int>(tree, min, max);
    }

    cout << (sol == -1? "NO" : "SI") << "\n";
   return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   ifstream in("casos1-1.txt");
   if (!in.is_open())
      cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
   auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   cin.rdbuf(cinbuf);
#endif
   return 0;
}
