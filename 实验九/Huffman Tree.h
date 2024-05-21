#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct HTNode {
	char data;			//�ַ�
	int count;			//Ȩ��
	string newCode;		//�±���
	HTNode* left, * right;
	HTNode();
	HTNode(char c);
	HTNode(HTNode*& node1, HTNode*& node2);
};

class HuffmanTree {
private:
	HTNode* root;
	HTNode* charArray[26];
	int mycount;
public:
	HuffmanTree();
	~HuffmanTree();
private:
	//���ķ���
	void createArray();
	void readByFile();
	void createHuffmanTree();
	//��������
	void sortByCount(bool isFirst = 0);
	void preOrder(HTNode* T,string str);
	void destory(HTNode* T);
};