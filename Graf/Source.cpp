#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<ranges>
#include<string>
#include<ctime>

#define voila(n,m,v) for(int i=0;i<n;++i){for(int j=0;j<n;++j){std::cout<<v[i][j]<<' ';}std::cout<<'\n';}
#define voila2(v) for (auto& t : vrr) {\
for (auto& r : t) {\
	std::cout << '\t'<<r.first << '('<<r.second<<')';\
}std::cout << '\n';}

//void DFS(std::vector<std::vector<int>>&gr, int v, std::vector<int>vis, int cpl, bool& Dvu) {
//	vis[v] = cpl;
//	for (int t : gr[v]) {
//		if (vis[t] == 0) {
//			DFS(gr, t, vis, 3 - cpl, Dvu);
//		}
//		else if (vis[t] == cpl) {
//			Dvu == false;
//		}
//	}
//}

	// ГРАФ
	/*std::cout << " Заполняем таблицу смежности : ";
	int n, m; std::cin >> n >> m; 
	*/
	// ориентированный с весом
	//std::vector<std::vector<std::pair<int, int>>>vrr(n, std::vector<std::pair<int, int>>(n, { 0,0 }));
	//for (int i = 0; i < m; ++i) {
	//	int u, v, b; std::cin >> u >> v >> b;
	//	vrr[u][v].first = 1;
	//	//vrr[v][u].first = 1;
	//	vrr[u][v].second = b;
	//	//vrr[v][u].second = b;
	//}
//	//voila2( vrr);
//	
//	std::vector<std::vector<int>>ver(n, std::vector<int>(n, 0));
//	for (int i = 0; i < m; ++i) {
//		int u, v; std::cin >> u >> v;
//		ver[u][v] = 1; ver[v][u] = 1;
//	}
//	voila(n, m, ver);
	//std::vector<int>boo(n, -1);
	//
	////DFS(n,boo, ver, 0);

	//// Компонент связности
	///*int nac, con; std::cin >> nac >> con;
	//DFS(n, boo, ver, nac);
	//if (boo[con]) { std::cout << " Норм \n"; }
	//else { std::cout << " Фигня \n"; }*/

	//int comp = 0;
	//for (int i = 0; i < n; ++i) {

	//	if (boo[i]==-1) {
	//		++comp;
	//		DFS2(n, boo, ver, i,comp);
	//	}
	//}
	//for (auto& c : boo) {
	//	std::cout << c<< ' ';
	//}
	//std::cout << '\n';
//
//
//	/////---------------------------//////////////
//	/*int h, w;
//	std::cin >> h >> w;
//	std::vector<std::string>a(h);
//	for (auto& r : a) {
//		std::cin >> r;
//	}
//	int cou = 0;
//	std::vector<std::vector<int>>vb(h, std::vector<int>(w));
//	for (int y = 0; y < h; ++y) {
//		for (int x = 0; x < w; ++x) {
//			if (a[y][x] == '#' && !vb[y][x]) {
//				cou++;
//				DFSCARTA(a, y, x, cou);
//			}
//		}
//	}
//	std::cout << cou << '\n';
//	for (auto& r : a) {
//		std::cout << r << '\n';
//	}*/
//	//////////////--------------/////////-------------///////------/
//	std::vector<int>booo(n);
//	std::vector<int>ot(n, -1);
//	std::vector<int>cic;
//	bool Dv = true;
//	for (int v = 0; v < n; ++v) {
//		if (booo[v]) {
//			DFS(ver, v, booo, 1, Dv);
//		}
//	}
//	if (Dv) {
//		std::cout << "АГА\n";
//		for (int col : booo) {
//			std::cout << col << ' ';
//		}
//	}
//	else { std::cout << "НЕТ\n"; }
//


class Graf {
	std::vector<std::vector<int>>vec, cev;
	std::vector<int>boo, por;

	void DFS1(int v) {
		boo[v] = 1;
		for (int& t : cev[v]) {
			if (!boo[t]) {
				DFS1(t);
			}
		}por.push_back(v);
	}
	void DFS2(int v, int cou) {
		boo[v] = cou;
		for (int& t : vec[v]) {
			if (!boo[t]) { DFS2(t, cou); }
		}
	}
public:
	Graf(int n) {
		vec.resize(n); cev.resize(n);
	}
	void Dob(int a, int b) {
		vec[a].push_back(b); cev[b].push_back(a);
	}
	std::vector<int> Poisk() {
		boo.assign(vec.size(), 0);
		for (int v = 0; v < vec.size(); ++v) {
			if (!boo[v]) {
				DFS1(v);
			}
		}
		std::ranges::reverse(por);

		boo.assign(vec.size(), 0);
		int ct = 0;
		for (auto& r : por) {
			if (!boo[r]) {
				DFS2(r, ++ct);
			}
		}
		return boo;
	}
};


int main() {
	setlocale(LC_ALL, "Ru");

	int n, m;
	std::cin >> n >> m;
	Graf graf(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		graf.Dob(a, b);
	}

	std::vector<int>vse = graf.Poisk();

	for (auto& t : vse) {
		std::cout << t << ' ';
	}
	std::cout << '\n';


	return 0;
}

