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
struct Cofre
{
    int peso;
    double valor;
};

double mochila_rec(vector<Cofre> const &obj, int i, int j,
                   Matriz<double> &mochila)
{
    if (mochila[i][j] != -1) // subproblema ya resuelto
        return mochila[i][j];
    if (i == 0 || j == 0)
        mochila[i][j] = 0;
    else if (obj[i - 1].peso + (2 * obj[i - 1].peso) > j)
        mochila[i][j] = mochila_rec(obj, i - 1, j, mochila);
    else
        mochila[i][j] = max(mochila_rec(obj, i - 1, j, mochila),
                            mochila_rec(obj, i - 1, j - (obj[i - 1].peso + (2 * obj[i - 1].peso)), mochila) + obj[i - 1].valor);
    return mochila[i][j];
}

double mochila(vector<Cofre> const &objetos, int M, vector<bool> &sol)
{
    int n = objetos.size();
    Matriz<double> mochila(n + 1, M + 1, -1);
    double valor = mochila_rec(objetos, n, M, mochila);
    // cálculo de los objetos
    int i = n, j = M;
    sol = vector<bool>(n, false);
    int nCofres = 0;
    while (i > 0 && j > 0)
    {
        if (mochila[i][j] != mochila[i - 1][j])
        {
            sol[i - 1] = true;
            j = j - (objetos[i - 1].peso + (2 * objetos[i - 1].peso));
            nCofres++;
        }
        --i;
    }
    cout << valor << "\n"
         << nCofres << "\n";
    return valor;
}

bool resuelveCaso()
{
    int T, N;
    cin >> T >> N;
    if (!cin)
        return false;
    vector<Cofre> cofres(N);
    for (int i = 0; i < N; i++)
    {
        int p;
        double v;
        cin >> p >> v;
        cofres[i] = {p, v};
    }
    vector<bool> sol;
    mochila(cofres, T, sol);

    for (int i = 0; i < N; i++)
    {
        if(sol[i])
        cout << cofres[i].peso << " " <<  cofres[i].valor << "\n";
    }
    cout << "---\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosB.1.txt");
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