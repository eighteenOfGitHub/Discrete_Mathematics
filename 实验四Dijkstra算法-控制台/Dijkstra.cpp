#include "Dijkstra.h"


Graph::Graph(){
	create();
}

void Graph::show(){
	for (int i = 0; i < this->vexnum; i++){
		for (int j = 0; j < this->vexnum; j++){
			cout << setw(4) << this->arcs[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph::dijkstra(){
	//得到起点和终点的标号
	cout << "请输入起点和终点：";
	int m, n;
	cin >> m >> n;
	start = getIndex(m);
	end = getIndex(n);
	//初始化结点的最短路径、最短路径结点、前驱结点
	for (int i = 0; i < vexnum; i++) {
		shortestDistance[i] = MAX;
		greatestVex[i] = false;
		preVex[i] = -1;
	}
	//初始化起点
	shortestDistance[start] = 0;
	greatestVex[start] = true;
	//开始探索最短路径
	dijkstra(start);
	//输出最短路径长度并显示路径
	cout << "最短路径长度为" << shortestDistance[end] << endl;
	cout << "最短路径为 ";
	showShortestPath(end);
}

void Graph::dijkstra(int cur){
	//更新最短路径，更新前驱结点
	for (int i = 0; i < vexnum; i++) {
		if (arcs[cur][i] != MAX && greatestVex[i] == false) {
			int distance;
			if (preVex[cur] == -1) {
				distance = arcs[cur][i];
			}
			else {
				distance = arcs[cur][i] + shortestDistance[cur];
			}
			if (distance < shortestDistance[i]) {
				shortestDistance[i] = distance;	//更新最短路径
				preVex[i] = cur;				//更新前驱结点
			}
		}
	}

	//寻找最短路径结点并标记最短路径结点,并探索下一个最短路径结点
	int min_index;
	for (int i = 0; i < vexnum; i++) {
		if (greatestVex[i] == false) {	//初始化最短路径结点
			min_index = i;
			break;
		}
	}
	for (int i = 0; i < vexnum; i++) {	//找最短路径结点
		if (greatestVex[i] == false && shortestDistance[i] < shortestDistance[min_index]) {
			min_index = i;
		}
	}
	greatestVex[min_index] = true;
	if (greatestVex[end] == true)		//结束找到最优路径结束
		return;
	dijkstra(min_index);
}

void Graph::create(){
	vexnum = 9;
	arcnum = 14;
	for (int i = 0; i < vexnum; i++) {
		vexs[i] = i;
	}
	for (int i = 0; i < vexnum; i++){
		for (int j = 0; j < vexnum; j++){
			this->arcs[i][j] = MAX;
		}
	}
	arcs[0][1] = arcs[1][0] = 4;
	arcs[0][7] = arcs[7][0] = 8;
	arcs[1][2] = arcs[2][1] = 8;
	arcs[1][7] = arcs[7][1] = 11;
	arcs[8][7] = arcs[7][8] = 7;
	arcs[6][7] = arcs[7][6] = 1;
	arcs[6][8] = arcs[8][6] = 6;
	arcs[2][8] = arcs[8][2] = 2;
	arcs[2][3] = arcs[3][2] = 7;
	arcs[2][5] = arcs[5][2] = 4;
	arcs[6][5] = arcs[5][6] = 2;
	arcs[3][5] = arcs[5][3] = 14;
	arcs[4][5] = arcs[5][4] = 10;
	arcs[4][3] = arcs[3][4] = 9;
	//cout << "请输入总结点数和总边数(总结点数不超过20)：";
	//cin >> vexnum >> arcnum;
	//cout << "请输入结点信息（不可相同）：";
	//for (int i = 0; i < vexnum; i++) {
	//	cin >> vexs[i];
	//}
	////初始化邻接矩阵
	//for (int i = 0; i < vexnum; i++){
	//	for (int j = 0; j < vexnum; j++){
	//		this->arcs[i][j] = MAX;
	//	}
	//}
	////构造邻接矩阵
	//for (int i = 0; i < arcnum; i++){
	//	int v1, v2, w;
	//	cout << "请输入第" << i + 1 << "条边的起点和终点及其对应的权值:";
	//	cin >> v1 >> v2 >> w;
	//	int m = getIndex(v1);
	//	int n = getIndex(v2);
	//	while (m < 0 || n < 0) {
	//		cout << "输入有误！不存在该结点。请重新输入！" << endl;
	//		cout << "请输入第" << i + 1 << "条边的起点和终点及其对应的权值:";
	//		cin >> v1 >> v2 >> w;
	//		m = getIndex(v1);
	//		n = getIndex(v2);
	//	}
	//	arcs[m][n] = arcs[n][m] = w;
	//}
	return;
}

int Graph::getIndex(int u){
	for (int i = 0; i < vexnum; i++) {
		if (vexs[i] == u)
			return i;
	}
	return -1;
}

void Graph::showShortestPath(int index){
	if (preVex[index] == -1) {
		cout << vexs[index] << " ";
		return;
	}
	showShortestPath(preVex[index]);
	cout << vexs[index] << " ";
}
