/*@ <authors>
 *
 * Andres Garcia Navarro, MARP19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <queue>
#include <string>
#include "Matriz.h"

using namespace std;

/*@ <answer>

 @ </answer> */

//@ <answer>
int idx(char c)
{
    switch (c)
    {
    case 'A':
        return 0;
    case 'C':
        return 1;
    case 'G':
        return 2;
    case 'T':
        return 3;
    default:
        return 4;
    }
}

constexpr int INF = 1000000000;
int align_rec(string const &cadena1, string const &cadena2, Matriz<int> const &S, int i, int j, Matriz<int> &dp)
{
    int &res = dp[i][j];
    if (res == INF)
    {
        if (i == cadena1.size() && j == cadena2.size())
            res = 0;
        else if (i == cadena1.size())
            res = S[idx(' ')][idx(cadena2[j])] + align_rec(cadena1, cadena2, S, i, j + 1, dp);
        else if (j == cadena2.size())
            res = S[idx(cadena1[i])][idx(' ')] + align_rec(cadena1, cadena2, S, i + 1, j, dp);
        else
            res = max({ S[idx(cadena1[i])][idx(cadena2[j])] + align_rec(cadena1, cadena2, S, i + 1, j + 1, dp),
                        S[idx(cadena1[i])][idx(' ')]        + align_rec(cadena1, cadena2, S, i + 1, j,     dp),
                        S[idx(' ')][idx(cadena2[j])]        + align_rec(cadena1, cadena2, S, i,     j + 1, dp) });
    }
    return res;
}

void resuelveCaso()
{
    // leemos la entrada.
    Matriz<int> S(5, 5);
    for (const auto i : {0, 1, 2, 3, 4})
        for (const auto j : {0, 1, 2, 3, 4})
            cin >> S[i][j];

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string cadena1, cadena2;
        cin >> cadena1 >> cadena2;
        Matriz<int> dp(cadena1.size() + 1, cadena2.size() + 1, INF);
        cout << align_rec(cadena1, cadena2, S, 0, 0, dp) << "\n";
    }
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosR15.txt");
    if (!in.is_open())
        cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    int casos;
    cin >> casos;
    while (casos--)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}