#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct HTNode {
	char data;			//字符
	int count;			//权重
	string newCode;		//新编码
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
	HTNode* getroot();
	int GetHeight(HTNode* t);

private:
	//核心方法
	void createArray();
	void readByFile();
	void createHuffmanTree();
	//辅助方法
	void sortByCount(bool isFirst = 0);
	void preOrder(HTNode* T, string str);
	void destory(HTNode* T);
	void GetHeight(HTNode* t, int& depth, int curdepth);
};