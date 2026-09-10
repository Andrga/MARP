///*@ <authors>
// *
// * Andres Garcia Navarro, MARP19
// *
// *@ </authors> */
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//struct Instrumento
//{
//	int nPers;
//	int nPart;
//
//	bool operator<(Instrumento const& other)const {
//		return ((nPers + nPart - 1) / nPart) < ((other.nPers + other.nPart - 1) / other.nPart);
//	}
//};
//
//bool resuelveCaso()
//{
//	int p, n;
//	cin >> p >> n;
//	if (!cin) return false;
//
//	priority_queue<Instrumento> pq;
//
//	for (int i = 0; i < n; ++i)
//	{
//		int npers;
//		cin >> npers;
//		pq.push({ npers, 1});
//	}
//	for (int i = 0; i < p - n; ++i)
//	{
//		Instrumento top = pq.top();
//		if (((top.nPers + top.nPart - 1) / top.nPart) == 1)
//			break;
//		pq.pop();
//		top.nPart++; pq.push(top);
//	}
//	Instrumento top = pq.top();
//	cout << ((top.nPers + top.nPart - 1) / top.nPart) << "\n";
//
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("T2/casos2.L.txt");
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
