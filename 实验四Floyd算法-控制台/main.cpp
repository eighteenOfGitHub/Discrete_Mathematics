#include <iostream>
#define Max 503
#define INF 0xcffff

using namespace std;

typedef struct AMGraph {						//�����ڽӾ���
	int vex, arc;
	int arcs[Max][Max];
};

int dis[Max][Max], path[Max][Max];				//dis�����·�̣�path����·��

void Floyd(AMGraph& G){							
	for (int i = 1; i <= G.vex; i++)			//��ʼ��dis��path
		for (int j = 1; j <= G.vex; j++){
			dis[i][j] = G.arcs[i][j];
			path[i][j] = -1;
		}

	/***************Floyd�����㷨****************/
	for (int k = 1; k <= G.vex; k++)					//����ÿ������Ϊ�м��
		for (int i = 1; i <= G.vex; i++)				//����ÿ����
			for (int j = 1; j <= G.vex; j++){
				if (dis[i][k] + dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];			//�ɳڲ���
					path[i][j] = k;								//����jǰ�����k
				}
			}
}

void find(int x, int y){							//���·��
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

void putin(AMGraph& G){							//����ͼ
	int u, v, w;
	cin >> G.vex >> G.arc;

	for (int i = 1; i <= G.vex; i++)			//��ʼ���ڽӾ���
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

void putout(AMGraph& G){							//������·�������v1���������̾����·��
	cout << "���·������Ϊ��\n";
	for (int i = 1; i <= G.vex; i++){
		for (int j = 1; j < G.vex; j++)
			cout << path[i][j] << " ";
		cout << path[i][G.vex] << endl;
	}
	cout << "���·�̾���Ϊ��\n";
	for (int i = 1; i <= G.vex; i++) {
		for (int j = 1; j < G.vex; j++)
			cout << dis[i][j] << " ";
		cout << dis[i][G.vex] << endl;
	}
	for (int i = 1; i <= G.vex; i++){
		for (int j = 1; j <= G.vex; j++) {
			if (dis[i][j] == INF) {
				cout << "�޷��ӳ�ʼ�� v" << i << " ���� v" << j << endl;
				continue;
			}
			if(i != j) {
				cout << "�ӳ�ʼ�� v"<< i <<" �� v" << j << " �����·��·��Ϊ:" << dis[i][j] << endl;
				cout << "·��Ϊ: " << i;
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