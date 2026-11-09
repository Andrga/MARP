/*@ <authors>
 *
 * MARP02 Nieves Alonso Gilsanz
 * MARP30 Andres Garcia Navarro
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
#include <limits>
#include <deque>
using namespace std;

/*@ <answer>

 Definimos el grafo como vertices el numero de lugares y aristas conexiones entre estos (en un unico sentido),
 Aldea1, Aldea2 y pueblo son lugares en el grafo (vertices).

 Se ejecuta 3 veces el algoritmo dijkstra que calcula los caminos minimos entre:
     Aldea1 -> resto de vertices, Aldea2 -> resto de vertices y pueblo -> resto de vertices,
     para este último el grafo, sobre el que se realiza el algoritmo, es el inverso al definido en un primer lugar.

 El coste total de nuestro algoritmo en tiempo es O(A*log(V)) siendo A el numero de conexiones entre lugares, y V el numero de lugares.
 El coste de nuestro algoritmo en espacio adicional es O(V).

 Finalmente hacemos un recorrido (de 0 -> V-1: O(V) en tiempo) donde se calcula el tiempo minimo que se tardaria en limpiar las carreteras
 desde cada uno de los lugares de interes hasta el resto de vertices.
 En cada una de las vueltas del bucle  se comprueba si la suma de los tiempos es menor que la previamente calculada (inicializada a INF).

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

const int INF = std::numeric_limits<int>::max();

template <typename Valor>
class Dijkstra
{
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF) // Tiempo: O(AlogV) ; Espacio: O(V)
    {
        dist[origen] = 0;

        pq.push(origen, 0);

        while (!pq.empty())
        {
            int v = pq.top().elem; pq.pop();

            for (auto a : g.ady(v))
                relajar(a);
        }
    }

    Valor distancia(int v) const { return dist[v]; }

private:
    int origen;
    std::vector<Valor> dist;
    IndexPQ<int, Valor> pq;

    void relajar(AristaDirigida<Valor> a)
    {
        int v = a.desde(), w = a.hasta();

        if (dist[w] > dist[v] + a.valor())
        {
            dist[w] = dist[v] + a.valor();
            pq.update(w, dist[w]);
        }
    }
};

void resuelveCaso()
{
    // leer los datos de la entrada
    int N, // lugares de la comarca
        C, // tramos de carretera
        // aldea1 -> pueblo <- aldea2
        aldea1, aldea2,
        pueblo;
    cin >> N >> C >> aldea1 >> aldea2 >> pueblo;

    // leer el resto del caso y resolverlo posiblemente llamando a otras funciones

    DigrafoValorado<int> carreteras(N);

    int v, w, minutos;
    for (int i = 0; i < C; ++i)
    {
        cin >> v >> w >> minutos;
        carreteras.ponArista(AristaDirigida<int>(v - 1, w - 1, minutos));
        carreteras.ponArista(AristaDirigida<int>(w - 1, v - 1, minutos));
    }

    // escribir la solución
    // linea con el numero minimo de minutos de trabajo necesarios para que las dos aldeas queden comunicadas con el pueblo

    Dijkstra p(carreteras.inverso(), pueblo - 1);
    Dijkstra a1(carreteras, aldea1 - 1);
    Dijkstra a2(carreteras, aldea2 - 1);

    // 3 dijkstra: O(A*logV)

    unsigned int minMinutos = INF;

    for (int i = 0; i < N; ++i) // O(V)
    {
        int pMin = p.distancia(i);
        int a1Min = a1.distancia(i);
        int a2Min = a2.distancia(i);

        unsigned int sum = pMin + a1Min + a2Min;

        minMinutos = min(sum, minMinutos);
    }

    cout << minMinutos << '\n';
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