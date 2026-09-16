/*@ <authors>
 *
 * MARP86 Nombre Apellidos
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// propios o los de las estructuras de datos de clase
#include "TreeSet_AVL.h"

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

bool resuelveCaso()
{

   // leer los datos de la entrada
   int N;
   std::cin >> N;
   if (N == 0) // fin de la entrada
      return false;
   Set<int> set;

   for (int i = 0; i < N; i++)
   {
      int n;
      std::cin >> n;
      set.insert(n);
   }

   int M;
   std::cin >> M;
   for (int i = 0; i < M; i++)
   {
      int k;
      std::cin >> k;
      try {
         std::cout << set.kesimo(k) << "\n";
      } catch (exception e) {
         std::cout << "??\n";
      }
   }
   std::cout << "---\n";

   return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main()
{
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   ifstream in("casos.txt");
   if (!in.is_open())
      cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
   auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso())
      ;

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   cin.rdbuf(cinbuf);
#endif
   return 0;
}
