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

struct Pelicula
{
    int comienzo;
    int fin;
    int duracion;

    bool operator<(Pelicula const &other) const
    {
        return comienzo < other.comienzo;
    }
};
Pelicula justificar(vector<Pelicula> const &l)
{
    int n = l.size();
    vector<int> sol(n);
    for (int i = n-1; i >=0; i++)
    {
        int j = lower_bound(l.begin() + i, l.end(), Pelicula{ l[i].fin + 10, 0, 0 }) - l.begin();
        sol[i] = max(sol[i+1], sol[j] + l[i].duracion);
    }
    return sol[0];
}
const long long INF = std::numeric_limits<long long>::max();
bool resuelveCaso()
{
    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;
    vector<Pelicula> pelis(N);
    for (int i = 0; i < N; i++)
    {
        int d, h, m, dur;
        char b; // dejar los caracteres basura
        cin >> d >> h >> b >> m >> dur;
        int ini = (d * 24 * 60) + (h * 60) + m;
        pelis[i] = {ini, ini + dur, dur};
    }

    cout << costeMinCorte(cortes) << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosC.2.txt");
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