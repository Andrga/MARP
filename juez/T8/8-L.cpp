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
#include <queue>
#include <string>

using namespace std;

/*@ <answer>

 @ </answer> */

//@ <answer>
struct Conferencia
{
    int id;
    long long ini, fin;

    bool operator<(Conferencia const &other) const
    {
        return ini < other.ini;
    }
};
struct Sala
{
    int id;
    long long ultFin;

    bool operator<(Sala const &other) const
    {
        return ultFin > other.ultFin;
    }
};

int nSalas(vector<Conferencia> const &conferencias, vector<int> &planificacion, int N)
{
    int maxSalas = 1;
    priority_queue<Sala> q;
    q.push({maxSalas, conferencias[0].fin});
    planificacion[conferencias[0].id] = maxSalas;
    for (int i = 1; i < N; ++i) // O(N)
    {
        int sala = 0;
        if (q.top().ultFin <= conferencias[i].ini) // O(N)
        {
            sala = q.top().id;
            q.pop();
        }
        else
        {
            sala = ++maxSalas;
        }

        q.push({sala, conferencias[i].fin});
        planificacion[conferencias[i].id] = sala;
    }
    return maxSalas;
};

bool resuelveCaso()
{
    // leemos la entrada.
    int N;
    cin >> N;
    if (N == 0)
        return false;
    vector<Conferencia> conferencias(N);
    for (int i = 0; i < N; i++)
    {
        int ini, fin;
        cin >> ini >> fin;
        conferencias[i] = {i, ini, fin};
    }
    sort(conferencias.begin(), conferencias.end()); // O(N * log(N))
    vector<int> planificacion(N);
    cout << nSalas(conferencias, planificacion, N) << "\n";

    for (size_t i = 0; i < N; i++)
        cout << planificacion[i] << " ";
    cout << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos8.L.txt");
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