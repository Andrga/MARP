///*@ <authors>
// *
// * Andres, Garcia, Navarro, MARP19
// *
// *@ </authors> */
//
//#include <iostream>
//#include <fstream>
//#include <algorithm>
//#include <limits>
//#include <vector>
//
//using namespace std;
//
//
//
///*@ <answer>
//
//	Coste en tiempo = O(F*C + 4),
//	siendo F el numero de filas y C el numero de columnas.
//	el +4 viene de los 4 posibles vecinos maximos que puede tener un pixel
//	ya que se recorren los 4 adyacentes, arriba abajo izquierda y derecha.
//
// @ </answer> */
//
//
// //@ <answer>
//
//using Mapa = vector<string>;
//
//class Mancha
//{
//private:
//	vector<vector<bool>> visit;	// visit[v] = hay camino de s a v.
//	int maxMancha;				// Tamanyo de la mancha mas grande.
//	int nManchas;				// Numero de manchas negras.
//	int F, C;					// Filas y Columnas.
//public:
//	Mancha(Mapa const& m) :F(m.size()), C(m[0].size()),
//		visit(m.size(), vector<bool>(m[0].size(), false)), maxMancha(0), nManchas(0)
//	{
//		for (int i = 0; i < F; i++)
//		{
//			for (int j = 0; j < C; j++)
//			{
//				if (!visit[i][j] && m[i][j] == '#') {
//					int mancha = dfs(m, i, j);
//					maxMancha = max(maxMancha, mancha);
//					nManchas++;
//				}
//			}
//		}
//	}
//
//	int getMaxMancha() { return maxMancha; }
//
//	int getNumManchas() { return nManchas; }
//
//private:
//
//	bool enRango(int i, int j) const {
//		return 0 <= i && i < F && 0 <= j && j < C;
//	}
//	const vector<pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1} };
//
//	int dfs(Mapa const& m, int i, int j) {
//		visit[i][j] = true;
//		int tam = 1;
//		for (pair<int, int> d : dirs){
//			int newI = i + d.first, newJ = j + d.second;
//			if (enRango(newI, newJ) && m[newI][newJ] == '#' && !visit[newI][newJ])
//			{
//				tam += dfs(m, newI, newJ);
//			}
//		}
//		return tam;
//	}
//
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int F, C;
//	cin >> F >> C;
//	if (!cin) return false;
//
//	Mapa map(F);
//
//	for (size_t i = 0; i < F; i++)
//	{
//		cin >> map[i];
//
//	}
//
//	Mancha mancha(map);
//
//	cout << mancha.getNumManchas() << " " << mancha.getMaxMancha() << "\n";
//
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("T4/casos4.4.txt");
//	if (!in.is_open())
//		cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
//	auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
//
//	// Resolvemos
//	while (resuelveCaso());
//
//	// para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//	cin.rdbuf(cinbuf);
//#endif
//	return 0;
//}
