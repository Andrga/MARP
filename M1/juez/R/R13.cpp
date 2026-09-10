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
struct Bombilla
{
    int coste, potencia;
};

constexpr int INF = 1000000000;
vector<int> coste(vector<Bombilla> const &bombillas, int Pmax)
{
    vector M(Pmax + 1, INF); // vector de potencias => potencia i tiene suma de costes x
    int N = bombillas.size();
    M[0] = 0;
    for (Bombilla b :bombillas)
        for (int j = b.potencia; j <= Pmax; ++j)
            // solo cambiar si ha sido cambiado antes y la potencia es mayor a la bombilla que estamos explorando
            if (M[j - b.potencia] != INF)
                M[j] = min(M[j], M[j - b.potencia] + b.coste);

    return M;
}

bool resuelveCaso()
{
    // leemos la entrada.
    int N, Pmax, Pmin;
    cin >> N >> Pmax >> Pmin;
    if (!cin)
        return false;
    vector<Bombilla> bombillas(N);
    for (int i = 0; i < N; i++)
        cin >> bombillas[i].potencia;
    for (int i = 0; i < N; i++)
        cin >> bombillas[i].coste;

    auto costes = coste(bombillas, Pmax);

    int mejCoste = INF,
        mejPotencia = INF;
    for (int i = Pmin; i <= Pmax; i++)
    {
        if (mejCoste > costes[i])
        {
            mejCoste = costes[i];
            mejPotencia = i;
        }
    }

    cout << (mejCoste != INF ? to_string(mejCoste) + ' ' + to_string(mejPotencia) : "IMPOSIBLE") << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casosR13.txt");
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