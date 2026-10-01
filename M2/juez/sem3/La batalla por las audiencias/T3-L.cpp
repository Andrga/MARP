/*@ <authors>
 *
 * MARP02 Nieves Alonso Gilsanz 
 * MARP36 Pablo Iglesias Rodrigo
 * MARP30 Andrés García Navarro
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include "IndexPQ.h"
#include <algorithm>
using namespace std;

/*@ <answer>

 Hemos usado dos priority queues una en la que se almacenan los canales con sus audiencias
 y una segunda donde se ordenan los canales con su tiempo en primetime. 

 Cuando se termina de procesar una actualizacion, se mira el canal con mayor audiencia, 
 se resta la hora de la actualizacion actual menos el de la anterior y se asigna ese periodo
 de tiempo al canal ganador del primetime, eso se mete en la segunda IndexPQ (canal-tiempo).

 complejidad en tiempo: O(N*C*log(C)) siendo N el numero de actualizaciones y C el numero de canales
 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct canales
{
    int mins = 0;
    int id = 0; 
    bool operator>(const canales & other) const
    {
        return other.mins < mins ||
            (mins == other.mins && other.id > id);
    }
};

void resuelveCaso() 
{
		int D, C, N;
	cin >> D >> C >> N;

	IndexPQ<int, int, greater<>> canalesAudiencia;
	for (int i = 1; i <= C; i++)
	{
		int a; cin >> a;
		canalesAudiencia.push(i, a);
	}

	vector<int> minutos(C + 1, 0); // minutos como líder de cada canal
	int minsAnt = 0;

	for (int i = 0; i < N; i++)
	{
		int m, u; cin >> m >> u;

		// el líder actual lo ha sido desde minsAnt hasta m
		minutos[canalesAudiencia.top().elem] += m - minsAnt;
		minsAnt = m;

		for (int j = 0; j < u; j++)
		{
			int canal, audiencia;
			cin >> canal >> audiencia;
			canalesAudiencia.update(canal, audiencia);
		}
	}
	// tramo final hasta D
	minutos[canalesAudiencia.top().elem] += D - minsAnt;

	// mas minutos primero, empate por id menor
	vector<canales> ranking;
	for (int c = 1; c <= C; c++)
		if (minutos[c] > 0)
			ranking.push_back({ minutos[c], c });
	sort(ranking.begin(), ranking.end(), greater<>());

	for (auto const& r : ranking)
		cout << r.id << " " << r.mins << "\n";
	cout << "---\n";
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    if (!in.is_open())
        cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}