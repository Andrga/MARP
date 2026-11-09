/*@ <authors>
 *
 * MARP30 Andres Garcia Navarro
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <algorithm>

using namespace std;
using ll = long long;
/*@ <answer>
 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Conferencia{
    int id;
    ll ini = 0, fin= 0;

    bool operator<(Conferencia const &other) const{
        return ini < other.ini;
    }
};

struct Sala{
    int id = 0;
    ll fin= 0;
    
    bool operator<(Sala const &other) const{
        return fin > other.fin;
    }
};

void resuelveCaso()
{
    int N; cin >> N;

    vector<Conferencia> conferencias(N);
    for (int i = 0; i < N; i++) {
        conferencias[i].id = i + 1;
        cin >> conferencias[i].ini >> conferencias[i].fin;
    }
    sort(conferencias.begin(), conferencias.end());

    vector<int> plan(N+1);
    priority_queue<Sala> q;
    int salasTotal = 1;

    q.push({1, conferencias[0].fin});
    plan[conferencias[0].id] = salasTotal;

    for (int i = 1; i < N; i++)
    {
        Sala sala;
        if (q.top().fin <= conferencias[i].ini)
        { 
            sala = q.top(); q.pop();
            sala.fin = conferencias[i].fin;
        }
        else
            sala = {++ salasTotal, conferencias[i].fin};
        
        q.push(sala);
        plan[conferencias[i].id] = sala.id;        
    }

    cout << salasTotal << '\n';
    for(int i : plan)
        if (i!= 0)
            cout << i << " ";
    cout <<"\n";
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