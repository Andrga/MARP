/*@ <authors>
 *
 * Andres Garcia Navarro, MARP19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <string>
#include "IndexPQ.h"
#include <algorithm>
using namespace std;

struct Canal{
	int canal;
	int audiencia;
	int minsTotales;

	bool operator<(Canal const& other)const{
		if ( audiencia == other.audiencia) return canal < other.canal;
		return audiencia > other.audiencia;
	}

};

bool resuelveCaso()
{
	int D, C, N;
	cin >> D >> C >> N;
	if(!cin) return false;

	IndexPQ<int, Canal> pq;

	for (int i = 0; i < C; i++)
	{
		int a; cin >> a;
		pq.update(i, {i+1,a,0});
	}
	int lastM=0;
	for (int i = 0; i < N; i++)
	{
		int m, c = 0, a = 0; cin >> m >> c ;

		auto top = pq.top();
		top.prioridad.minsTotales += m - lastM;
		pq.update(top.elem, top.prioridad);
		lastM = m;

		while (c != -1)
		{
			cin >> a;
			Canal prio = pq.priority(c-1);
			prio.audiencia = a;
			pq.update(c-1,prio);
			cin >> c ;
		}
	}
	
	auto top = pq.top();
	top.prioridad.minsTotales += D - lastM;
	pq.update(top.elem, top.prioridad);

	vector<Canal> res;
    while (!pq.empty()) {
        auto e = pq.top(); pq.pop();
        if (e.prioridad.minsTotales > 0) res.push_back(e.prioridad);
    }
    sort(res.begin(), res.end(), [](Canal const& a, Canal const& b) {
        if (a.minsTotales != b.minsTotales) return a.minsTotales > b.minsTotales;
        return a.canal < b.canal;
    });
    for (auto const& ch : res)
        cout << ch.canal << " " << ch.minsTotales << "\n";
	cout << "---\n";

	return true;
};

 //@ </answer>
 //  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("casos3.L.txt");
	if (!in.is_open())
		cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
#endif
	return 0;
}
