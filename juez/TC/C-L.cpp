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
const int INF = std::numeric_limits<int>::max();
int tiempo(vector<int> const &pdfs)
{
    int n = pdfs.size();

    vector pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] + pdfs[i - 1]; // pref[i] = paginas de los i primeros

    Matriz<int> matrices(n + 1, n + 1, 0);
    for (int d = 1; d < n; ++d) // recorre diagonales
        for (int i = 0; i + d <= n - 1; ++i)
        { // recorre elementos de diagonal
            int j = i + d;
            matrices[i][j] = INF;
            for (int k = i; k <= j - 1; ++k)
            {
                matrices[i][j] = 
                    min(matrices[i][j], 
                    matrices[i][k] + matrices[k + 1][j] + pref[j + 1] - pref[i]);
            }
        }
    return matrices[0][n - 1];
}

bool resuelveCaso()
{
    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;
    vector<int> pdfs(N);
    for (int i = 0; i < N; i++)
        cin >> pdfs[i];
    cout << tiempo(pdfs) << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosC.L.txt");
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