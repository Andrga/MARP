/*@ <authors>
 *
 * Andres Garcia Navarro, MARP19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

/*@ <answer>

 @ </answer> */

//@ <answer>
struct Bateria
{
    int id,
        fin, maximo;

    bool operator<(Bateria const &other) const
    {
        if (fin == other.fin)
            return id > other.id;
        return fin > other.fin;
    }
};

bool resuelveCaso()
{
    // leemos la entrada.
    int B, R, Z, T;
    cin >> B;
    if (!cin)
        return false;
    priority_queue<Bateria> funcionamiento;
    for (int i = 0; i < B; i++)
    {
        int b;
        cin >> b;
        funcionamiento.push({i + 1, b, b});
    }
    cin >> R;
    vector<int> reserva(R);
    for (int i = 0; i < R; i++)
    {
        int b;
        cin >> b;
        reserva[i] = b;
    }
    cin >> Z >> T;

    int nextReserva = 0;
    while (!funcionamiento.empty() && funcionamiento.top().fin <= T)
    {
        Bateria b = funcionamiento.top();
        funcionamiento.pop();
        b.maximo -= Z;
        if (b.maximo > 0)
        {
            b.fin = b.fin + b.maximo;
            funcionamiento.push(b);
        }
        else if (nextReserva < R)
        {
            funcionamiento.push({
                B + nextReserva + 1,
                reserva[nextReserva] + b.fin,
                reserva[nextReserva],
            });
            nextReserva++;
        }
    }

    if (funcionamiento.size() > 0)
        if (funcionamiento.size() >= B)
            cout << "CORRECTO\n";
        else
            cout << "FALLO EN EL SISTEMA\n";
    else
        cout << "ABANDONEN INMEDIATAMENTE LA BASE\n";
    while (!funcionamiento.empty())
    {
        Bateria b = funcionamiento.top();
        funcionamiento.pop();
        cout << b.id << " " << b.fin << "\n";
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
    ifstream in("casosR12.txt");
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