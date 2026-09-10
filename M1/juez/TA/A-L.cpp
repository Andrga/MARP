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
#include "EnterosInf.h"
#include "Matriz.h"

using namespace std;

/*@ <answer>
*
 @ </answer> */

//@ <answer>
void calcCambio(vector<int> const &M, int C)
{
    int n = M.size();
    int maxMoneda = *max_element(M.begin(), M.end());
    vector<EntInf> monedas(C + 1 + maxMoneda, Infinito);
    monedas[0] = 0;
    // calcular la matriz sobre el propio vector
    for (int i = 1; i <= n; ++i)
    {
        for (int j = M[i - 1]; j <= C + maxMoneda; ++j)
        {
            monedas[j] = min(monedas[j], monedas[j - M[i - 1]] + 1);
        }
    }
    int objetivo = C;
    while (monedas[objetivo] == Infinito)   // donde esta la cantidad pagada
        ++objetivo;

    int cant = 0;
    vector<int> sol;
    if (monedas[objetivo] != Infinito)
    {
        int i = n, j = objetivo;
        while (j > 0)
        { // no se ha pagado todo
            if (M[i - 1] <= j && monedas[j] == monedas[j - M[i - 1]] + 1)
            {
                // tomamos una moneda de tipo i
                sol.push_back(M[i - 1]);
                j = j - M[i - 1];
                cant += M[i - 1];
            }
            else // no tomamos más monedas de tipo i
                --i;
        }
    }
    cout << cant << " " << sol.size() << "\n";
}

bool resuelveCaso()
{
    int P, N;
    cin >> P >> N;
    if (!cin)
        return false;

    vector<int> monedas(N);
    for (int i = 0; i < N; i++)
        cin >> monedas[i];

    calcCambio(monedas, P);
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosA.L.txt");
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