/*@ <authors>
 *
 * MARP30 Andres Garcia Navarro
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
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
    int N, L; cin >> N >> L;

    vector<int> parches(N);
    for (int i = 0; i < N; i++)
        cin >> parches[i];
    
    int num = 0, hasta = 0;
    for (int i = 0; i < N; i++)
    {
        if (parches[i] > hasta){
            hasta = parches[i] + L;
            num++;
        }
    }
       

    cout << num << '\n';
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // entrada/salida rápida
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ajustes para que cin extraiga directamente de un fichero (solamente en local)
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    if (!in.is_open()) {
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