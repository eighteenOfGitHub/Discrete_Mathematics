#include <iostream>
#define Max 503
#define INF 0xcffff

using namespace std;

typedef struct AMGraph {						//定义邻接矩阵
	int vex, arc;
	int arcs[Max][Max];
};

int dis[Max][Max], path[Max][Max];				//dis存最短路程，path保存路径

void Floyd(AMGraph& G){							
	for (int i = 1; i <= G.vex; i++)			//初始化dis和path
		for (int j = 1; j <= G.vex; j++){
			dis[i][j] = G.arcs[i][j];
			path[i][j] = -1;
		}

	/***************Floyd核心算法****************/
	for (int k = 1; k <= G.vex; k++)					//遍历每个点作为中间点
		for (int i = 1; i <= G.vex; i++)				//遍历每条边
			for (int j = 1; j <= G.vex; j++){
				if (dis[i][k] + dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];			//松弛操作
					path[i][j] = k;								//保存j前驱结点k
				}
			}
}

void find(int x, int y){							//输出路径
	if (path[x][y] == -1) {
		return;
	}
	else {
		int mid = path[x][y];
		find(x, mid);
		cout << "->" << mid;
		find(mid, y);
	}
}

void putin(AMGraph& G){							//输入图
	int u, v, w;
	cin >> G.vex >> G.arc;

	for (int i = 1; i <= G.vex; i++)			//初始化邻接矩阵
		for (int j = 1; j <= G.vex; j++){
			if (i == j) G.arcs[i][j] = 0;
			else G.arcs[i][j] = INF;
		}

	for (int i = 0; i < G.arc; i++){
		cin >> u >> v >> w;
		G.arcs[u][v] = w;
		//		G.arcs[v][u] = w;
	}
}

void putout(AMGraph& G){							//输出最短路矩阵、起点v1到各点的最短距离和路径
	cout << "最短路径矩阵为：\n";
	for (int i = 1; i <= G.vex; i++){
		for (int j = 1; j < G.vex; j++)
			cout << path[i][j] << " ";
		cout << path[i][G.vex] << endl;
	}
	cout << "最短路程矩阵为：\n";
	for (int i = 1; i <= G.vex; i++) {
		for (int j = 1; j < G.vex; j++)
			cout << dis[i][j] << " ";
		cout << dis[i][G.vex] << endl;
	}
	for (int i = 1; i <= G.vex; i++){
		for (int j = 1; j <= G.vex; j++) {
			if (dis[i][j] == INF) {
				cout << "无法从初始点 v" << i << " 到达 v" << j << endl;
				continue;
			}
			if(i != j) {
				cout << "从初始点 v"<< i <<" 到 v" << j << " 的最短路径路程为:" << dis[i][j] << endl;
				cout << "路径为: " << i;
				find(i, j);
				cout << "->" << j << endl;
			}
		}

	}
}

int main(){
	AMGraph G;
	putin(G);
	Floyd(G);
	putout(G);
	return 0;
}

/*
5 8
1 2 2
2 3 3
3 4 4
4 5 5
5 3 3
3 1 4
2 5 7
1 5 10
*/