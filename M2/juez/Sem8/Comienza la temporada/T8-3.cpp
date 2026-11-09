/*@ <authors>
 *
 * MARP30 Andres Garcia Navarro
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

/*@ <answer>
 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

constexpr int INF = std::numeric_limits<int>::max();

void resuelveCaso()
{
    int N, M; cin >> N >> M;

    vector<long> jugadores(N);
    vector<long> equipaciones(M);
    for (int i = 0; i < N; i++)
        cin >> jugadores[i];
    for (int i = 0; i < M; i++)
        cin >> equipaciones[i];

    sort(jugadores.begin(), jugadores.end());
    sort(equipaciones.begin(), equipaciones.end());

    int numero = 0;
    int i = 0, j = 0;
    while (i < N && j < M && numero < N)
    {
        int jugador = jugadores[i],
            talla = equipaciones[j];
        if (jugador == talla || jugador + 1 == talla)
        {
            numero++;
            i++; j++;
        }
        else if(jugador > talla)
            j++;
        else if(jugador < talla)
            i++;
    }

    cout << (N - numero) << '\n';
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main()
{
    // entrada/salida rápida
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ajustes para que cin extraiga directamente de un fichero (solamente en local)
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    if (!in.is_open())
    {
        cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
        // sin fichero no hay nada que leer, y cin >> ... dejaría las
        // variables sin tocar, con su valor basura
        return 1;
    }
    cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}