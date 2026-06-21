/*@ <authors>
 *
 * Andres Garcia Navarro, MARP19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include "Matriz.h"

using namespace std;

/*@ <answer>
*
 @ </answer> */

//@ <answer>
int palin_rec(string const &palabraOrg, int i, int j, Matriz<int> &palindromo)
{
    int &res = palindromo[i][j];
    if (res == -1)
    {
        if (i > j)
            res = 0;
        else if (i == j)
            res = 1;
        else if (palabraOrg[i] == palabraOrg[j])
            res = palin_rec(palabraOrg, i + 1, j - 1, palindromo) + 2;
        else // si la letra es diferente
             // se coge el palindromo con menor tamaño añadiendo una letra por izquierda o por derecha.
            res = max(palin_rec(palabraOrg, i + 1, j, palindromo),
                      palin_rec(palabraOrg, i, j - 1, palindromo));
    }
    return res;
}

int reconstruir(string const &palabraOrg, Matriz<int> const &palindromo,
                int i, int j, string &solBack, string &solFront)
{
    if (i > j)
        return 0;
    if (i == j) // solo queda 1 caracter
    {
        solFront += (palabraOrg[i]);
        return 0;
    }
    else if (palabraOrg[i] == palabraOrg[j]) // si son la misma letra
    {
        // se añade por delante y por detras
        solFront += palabraOrg[i];
        solBack = palabraOrg[j] + solBack;
        return reconstruir(palabraOrg, palindromo, i + 1, j - 1, solBack, solFront);
    }
    /* se comprueba que camino se ha escogido
        palin_rec(palabraOrg, i + 1, j, palindromo),    palindromo [i+1][j]
        palin_rec(palabraOrg, i, j - 1, palindromo));   palindromo [i][j-]
    */
    else if (palindromo[i][j] == palindromo[i + 1][j]) // se ha insertado por delante
    {
        solBack = palabraOrg[i] + solBack;
        solFront += palabraOrg[i];
        return reconstruir(palabraOrg, palindromo, i + 1, j, solBack, solFront) + 1;
    }
    else // si se ha insertado por detras
    {
        solBack = palabraOrg[j] + solBack;
        solFront += palabraOrg[j];
        return reconstruir(palabraOrg, palindromo, i, j - 1, solBack, solFront) + 1;
    }
}

bool resuelveCaso()
{
    string palabra;
    cin >> palabra;
    if (!cin)
        return false;
    int n = palabra.size();

    Matriz<int> palin(n, n, -1);
    palin_rec(palabra, 0, n - 1, palin);
    string front = "", back = "";
    int c = reconstruir(palabra, palin, 0, n - 1, back, front);

    cout << c << " " << front << back << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosB.2.txt");
    if (!in.is_open())
        cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso())
        ;

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}