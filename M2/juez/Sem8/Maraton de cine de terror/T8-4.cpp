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
using ll = long long;
/*@ <answer>
 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

constexpr int INF = std::numeric_limits<int>::max();

struct Peli{
    ll inicio;
    int duracion;

    bool operator<(Peli const& other){
        return inicio + duracion < other.inicio +  other.duracion;
    }
};

void resuelveCaso()
{
    int N; cin >> N;

    vector<Peli> peliculas(N);
    for (int i = 0; i < N; i++){
        int d,h,m, duracion;char c;        
        cin >> d>>h>>c>>m>> duracion;
        d--;
        ll inicio = (((d * 24) + h) *60) + m ;
        peliculas[i] = {inicio, duracion};
    }

    sort(peliculas.begin(), peliculas.end());

    int vistas = 0;
    ll finalAnterior = 0;
    for (int i = 0; i < N; i++)
    {    
        ll inicioSiguiente = peliculas[i].inicio;
        if (finalAnterior <= inicioSiguiente)
        {
            vistas++;
            finalAnterior = inicioSiguiente + peliculas[i].duracion + 10;
        }
    }

    cout << vistas << '\n';
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