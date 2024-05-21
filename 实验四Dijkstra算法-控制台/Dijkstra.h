#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
# define MAX 999	//��ʾ�����
# define MVNum 20	//�������

class Graph {
private:
	int vexs[MVNum];			//�洢���
	int arcs[MVNum][MVNum];		//�ڽӾ���
	int vexnum, arcnum;			//ͼ��ǰ�Ķ������ͱ���

	int start, end;					//dijkstra()�ã������յ�ı��
	int shortestDistance[MVNum];	//dijkstra()�ã���㵽���н��ľ���
	int preVex[MVNum];				//dijkstra()�ã����·����ÿ������ǰ�����
	bool greatestVex[MVNum];		//dijkstra()�ã�����Ƿ�Ϊ����·���еĽ��
public:
	Graph();
	void show();
	void dijkstra();
private:
	void dijkstra(int cur);
	void create();
	int getIndex(int u);//����Graph�еĶ���u�����������Ӧ�ڶ�����е��±꣬δ�ҵ��򷵻�-1
	void showShortestPath(int index);
};

//0 7

