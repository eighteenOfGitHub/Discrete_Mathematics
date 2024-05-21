#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
# define MAX 999	//表示无穷大
# define MVNum 20	//最大结点数

class Graph {
private:
	int vexs[MVNum];			//存储结点
	int arcs[MVNum][MVNum];		//邻接矩阵
	int vexnum, arcnum;			//图当前的顶点数和边数

	int start, end;					//dijkstra()用：起点和终点的标号
	int shortestDistance[MVNum];	//dijkstra()用：结点到所有结点的距离
	int preVex[MVNum];				//dijkstra()用：最短路径中每个结点的前驱结点
	bool greatestVex[MVNum];		//dijkstra()用：标记是否为最优路径中的结点
public:
	Graph();
	void show();
	void dijkstra();
private:
	void dijkstra(int cur);
	void create();
	int getIndex(int u);//查找Graph中的顶点u，并返回其对应在顶点表中的下标，未找到则返回-1
	void showShortestPath(int index);
};

//0 7

