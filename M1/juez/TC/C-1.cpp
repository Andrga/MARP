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
const long long INF = std::numeric_limits<long long>::max();
int costeMinCorte(vector<int> const &D)
{
    int n = D.size();
    Matriz<long long> matrices(n, n, 0);
    for (int d = 2; d <= n - 1; ++d) // recorre diagonales
        for (int i = 0; i + d <= n - 1; ++i)
        { // recorre elementos de diagonal
            int j = i + d;
            matrices[i][j] = INF;
            for (int k = i +1 ; k <= j - 1; ++k)
            {
                long long temp = matrices[i][k] + matrices[k][j] + 2LL * (D[j] - D[i]);
                if (temp < matrices[i][j])
                    matrices[i][j] = temp;
            }
        }
    return matrices[0][n-1];
}

bool resuelveCaso()
{
    // leer los datos de la entrada
    int L, N;
    cin >> L >> N;
    if (L == 0 && N == 0)
        return false;
    vector<int> cortes(N+2);
    cortes[0] = 0;
    for (int i = 1; i <= N; i++)
        cin >> cortes[i];
    cortes[N + 1] = L;

    cout << costeMinCorte(cortes) << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosC.1.txt");
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