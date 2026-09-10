/*@ <authors>
 *
 * Andres Garcia Navarro, MARP19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <sstream>
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
void reconstruir(vector<string> const &song1, vector<string> const &song2, Matriz<int> const &m,
                 int i, int j, vector<string> &sol)
{
    if (i >= song1.size() || j >= song2.size())
        return;
    else if (song1[i] == song2[j]) // si misma cancion
    {
        sol.push_back(song1[i]);
        reconstruir(song1, song2, m, i + 1, j + 1, sol);
    }
    else if (m[i][j] == m[i + 1][j]) // si se ha avanzado en song1
        reconstruir(song1, song2, m, i + 1, j, sol);
    else // si se ha avanzado en song2
        reconstruir(song1, song2, m, i, j + 1, sol);
}

int rec(vector<string> const &song1, vector<string> const &song2, int i, int j, Matriz<int> &m)
{
    int &res = m[i][j];
    if (res == -1)
    {
        if (i == (int)song1.size() || j == (int)song2.size())
            res = 0;
        else if (song1[i] == song2[j]) // si son la misma cancion se añade
            res = rec(song1, song2, i + 1, j + 1, m) + 1;
        else // si son diferentes nos quedamos con el camino que de mas canciones
            res = max(rec(song1, song2, i + 1, j, m),
                      rec(song1, song2, i, j + 1, m));
    }
    return res;
}

bool resuelveCaso()
{ // leer los datos de la entrada
    string linea;
    if (!getline(cin, linea)) // lee la primera lista completa
        return false;         // fin de la entrada
    vector<string> linea1;
    {
        istringstream iss(linea);
        string w;
        while (iss >> w)
            linea1.push_back(w);
    }
    if (!getline(cin, linea)) // lee la segunda lista completa
        return false;
    vector<string> linea2;
    {
        istringstream iss(linea);
        string w;
        while (iss >> w)
            linea2.push_back(w);
    }
    Matriz<int> m(linea1.size() + 1, linea2.size() + 1, -1);
    rec(linea1, linea2, 0, 0, m);
    vector<string> sol;
    reconstruir(linea1, linea2, m, 0, 0, sol);

    for (size_t i = 0; i < sol.size(); ++i)
    {
        if (i > 0)
            cout << ' ';
        cout << sol[i];
    }
    cout << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosB.L.txt");
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