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

using namespace std;

/*@ <answer>

 @ </answer> */

//@ <answer>
struct Peli
{
    int comienzo;
    int final;

    bool operator<(Peli const &other) const
    {
        return final < other.final;
    }
};

int cuentaPeliculas(vector<Peli> const &peliculas, int N)
{
    int contador = 1;
    int ult = peliculas[0].final + 10; // ultima pelicula vista
    for (size_t i = 0; i < N; i++)
    {
        Peli act = peliculas[i];
        // 10 minutos para comprar palomitas
        if (ult > act.comienzo)
            continue;
        contador++;
        ult = act.final + 10;
    }
    return contador;
}

bool resuelveCaso()
{
    // leemos la entrada.
    int N;
    cin >> N;
    if (N == 0)
        return false;
    vector<Peli> peliculas(N);
    for (size_t i = 0; i < N; i++)
    {
        // dia, hora, minutos y duracion
        int d, h, m, dur;
        char c;
        cin >> d >> h >> c >> m >> dur;
        // dia+hora+minutos en minutos
        int ini = d * 24 * 60 + h * 60 + m;
        peliculas[i] = {ini, ini + dur};
    }

    sort(peliculas.begin(), peliculas.end());

    cout << cuentaPeliculas(peliculas, N) << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos8.4.txt");
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