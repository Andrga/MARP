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
struct Punto
{
    int km;
    double beneficio;
};

int beneficio(vector<Punto> const &puntos, int N, int k, vector<int> &prev)
{
    vector<long long> dp(N, 0);
    for (int i = 0; i < N; i++)
    {
        long long noCojo = (i > 0 ? dp[i - 1] : 0);
        int limite = puntos[i].km - k;
        int lo = 0, hi = i - 1, j = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (puntos[mid].km <= limite)
            {
                j = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1; // se pasa => descarto esta y las de su derecha
        }

        long long cojo = puntos[i].beneficio + (j >= 0 ? dp[j] : 0);
        if (cojo >= noCojo)
        {
            dp[i] = cojo;
            prev[i] = j;
        }
        else
        {
            dp[i] = noCojo;
            prev[i] = -2;
        }
    }
    return dp[N - 1];
}

bool resuelveCaso()
{
    // leemos la entrada.
    int N, K;
    cin >> N >> K;
    if (!cin)
        return false;
    vector<Punto> puntos(N);
    for (size_t i = 0; i < N; i++)
        cin >> puntos[i].km;
    for (size_t i = 0; i < N; i++)
        cin >> puntos[i].beneficio;

    vector<int> prev(N);
    cout << beneficio(puntos, N, K, prev) << "\n";
    deque<int> pos;
    int i = N - 1;
    while (i >= 0)
    {
        if (prev[i] == -2)
        {
            --i;
            continue;
        }
        pos.push_front(puntos[i].km);

        i = prev[i];
    }
    for (int p : pos)
        cout << p << " ";

    // reconstrucciónç
    cout << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosEN2.txt");
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