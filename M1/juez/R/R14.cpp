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
constexpr int INF = 1000000000;
int justificar(vector<int> const &l, int k)
{
    int N = l.size();
    vector<int> dp(N, 0);
    for (int i = 0; i < N; i++)
    {
        int noCoger = i > 0 ? dp[i - 1] : 0;
        int limite = l[i] - k;
        int j, h, l, mid;
        while (l < h)
        {
            mid = (l + h) / 2;
            if (mid <= limite)
            {
                j = mid;
                l = mid + 1;
            }
            else // se pasa
                h = mid - 1;
        }
        int coger = l[i] + (j >= 0 ? dp[j] : 0);
        dp[i] = max(noCoger, coger);
    }
    return dp[N-1];
}

bool resuelveCaso()
{
    int N; cin >> N;
    if(!cin) return false;

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosR14.txt");
    if (!in.is_open())
        cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}