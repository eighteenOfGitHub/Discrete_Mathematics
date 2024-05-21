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
	//�õ������յ�ı��
	cout << "�����������յ㣺";
	int m, n;
	cin >> m >> n;
	start = getIndex(m);
	end = getIndex(n);
	//��ʼ���������·�������·����㡢ǰ�����
	for (int i = 0; i < vexnum; i++) {
		shortestDistance[i] = MAX;
		greatestVex[i] = false;
		preVex[i] = -1;
	}
	//��ʼ�����
	shortestDistance[start] = 0;
	greatestVex[start] = true;
	//��ʼ̽�����·��
	dijkstra(start);
	//������·�����Ȳ���ʾ·��
	cout << "���·������Ϊ" << shortestDistance[end] << endl;
	cout << "���·��Ϊ ";
	showShortestPath(end);
}

void Graph::dijkstra(int cur){
	//�������·��������ǰ�����
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
				shortestDistance[i] = distance;	//�������·��
				preVex[i] = cur;				//����ǰ�����
			}
		}
	}

	//Ѱ�����·����㲢������·�����,��̽����һ�����·�����
	int min_index;
	for (int i = 0; i < vexnum; i++) {
		if (greatestVex[i] == false) {	//��ʼ�����·�����
			min_index = i;
			break;
		}
	}
	for (int i = 0; i < vexnum; i++) {	//�����·�����
		if (greatestVex[i] == false && shortestDistance[i] < shortestDistance[min_index]) {
			min_index = i;
		}
	}
	greatestVex[min_index] = true;
	if (greatestVex[end] == true)		//�����ҵ�����·������
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
	//cout << "�������ܽ�������ܱ���(�ܽ����������20)��";
	//cin >> vexnum >> arcnum;
	//cout << "����������Ϣ��������ͬ����";
	//for (int i = 0; i < vexnum; i++) {
	//	cin >> vexs[i];
	//}
	////��ʼ���ڽӾ���
	//for (int i = 0; i < vexnum; i++){
	//	for (int j = 0; j < vexnum; j++){
	//		this->arcs[i][j] = MAX;
	//	}
	//}
	////�����ڽӾ���
	//for (int i = 0; i < arcnum; i++){
	//	int v1, v2, w;
	//	cout << "�������" << i + 1 << "���ߵ������յ㼰���Ӧ��Ȩֵ:";
	//	cin >> v1 >> v2 >> w;
	//	int m = getIndex(v1);
	//	int n = getIndex(v2);
	//	while (m < 0 || n < 0) {
	//		cout << "�������󣡲����ڸý�㡣���������룡" << endl;
	//		cout << "�������" << i + 1 << "���ߵ������յ㼰���Ӧ��Ȩֵ:";
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
