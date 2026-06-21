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
vector<int> calcDianas(vector<int> const &M, int C)
{
    int n = M.size();
    Matriz<EntInf> dianas(n + 1, C + 1, Infinito);
    dianas[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        dianas[i][0] = 0;
        for (int j = 1; j <= C; ++j)
            if (M[i - 1] > j)
                dianas[i][j] = dianas[i - 1][j];
            else
                dianas[i][j] = min(dianas[i - 1][j], dianas[i][j - M[i - 1]] + 1);
    }

    vector<int> sol;
    if (dianas[n][C] != Infinito)
    {
        int i = n, j = C;
        while (j > 0)
        { // no se ha pagado todo
            if (M[i - 1] <= j && dianas[i][j] != dianas[i - 1][j])
            {
                // tomamos una moneda de tipo i
                sol.push_back(M[i - 1]);
                j = j - M[i - 1];
            }
            else // no tomamos más monedas de tipo i
                --i;
        }
    }
    return sol;
}

bool resuelveCaso()
{
    int D, S;
    cin >> D >> S;
    if (!cin)
        return false;
    vector<int> secciones(S);
    for (int i = 0; i < S; i++)
    {
        int e;
        cin >> e;
        secciones[i] = e;
    }
    vector<int> sol = calcDianas(secciones, D);
    if (sol.empty())
        cout << "Imposible";
    else
    {
        cout << sol.size() << ": ";
        for (int s : sol)
            cout << s << " ";
    }
    cout << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosA.2.txt");
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