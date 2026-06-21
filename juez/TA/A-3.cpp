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
int calcCaminos(Matriz<char> const &calles, int N, int M)
{
    vector<int> C(M + 1, 0);
    C[1] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (calles[i-1][j-1] != 'X')
                C[j] = C[j - 1] + C[j];
            else
                C[j] = 0;
    return C[M];
}

bool resuelveCaso()
{
    int N, M;
    cin >> N >> M;
    if (!cin)
        return false;

    Matriz<char> calles(N, M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> calles[i][j];

    cout << calcCaminos(calles, N, M) << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosA.3.txt");
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