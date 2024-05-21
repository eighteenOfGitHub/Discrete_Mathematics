#include"Huffman Tree.h"
//--------------------HTNode的构造与方法--------------------
HTNode::HTNode(){
	count = 0;
	left = NULL;
	right = NULL;
}

HTNode::HTNode(char c) {
	data = c;
	count = 0;
	left = NULL;
	right = NULL;
}

HTNode::HTNode(HTNode*& node1, HTNode*& node2){
	data = '\0';
	count = node1->count + node2->count;
	left = node1;
	right = node2;
}

//--------------------HuffmanTree的构造与方法--------------------

HuffmanTree::HuffmanTree(){
	//构建字符数组
	createArray();
	//录入
	readByFile();
	//测试
	//for (int i = 0; i < mycount; i++) {
	//	cout << charArray[i]->data << charArray[i]->count << endl;
	//}
	//排序
	createHuffmanTree();
	//编码
	string str;
	preOrder(root, str);
}

HuffmanTree::~HuffmanTree(){
	destory(root);
}


void HuffmanTree::createArray(){
	mycount = 26;
	for (int i = 0; i < mycount; i++) {
		HTNode* node = new HTNode('A' + i);
		charArray[i] = node;
	}
}

void HuffmanTree::readByFile(){
	ifstream ifs("text.txt", ios_base::in);
	char c;
	while (ifs>>c) {
		if (c >= 'a') {
			for (char i = 'a'; i < 'a' + 26; i++) {
				if (c == i) {
					charArray[i - int('a')]->count++;
				}
			}
		}
		else {
			for (char i = 'A'; i < 'A' + 26; i++) {
				if (c == i) {
					charArray[i - int('A')]->count++;
				}
			}
		}
	}
	ifs.close();
}

void HuffmanTree::createHuffmanTree(){
	//从大到小排序
	sortByCount(1);//1表示为第一次排序
	//去除权重为0的元素
	mycount = 0;
	for (int i = 0; charArray[i]->count != 0; i++) {
		mycount++;
	}
	for (int i = mycount; i < 26; i++) {
		delete charArray[i];
		charArray[i] = NULL;
	}
	//生成二叉树
	while (mycount > 1) {
		HTNode* temp = new HTNode(charArray[mycount - 1], charArray[mycount - 2]);
		charArray[mycount - 2] = temp;
		mycount--;
		sortByCount();
	}
	root = charArray[0];
}

void HuffmanTree::sortByCount(bool isFirst){
	if (isFirst == 1) {
		for (int i = 0; i < mycount; i++) {
			int max = i;
			for (int j = i + 1; j < mycount; j++) {
				if (charArray[j]->count > charArray[max]->count) {
					max = j;
				}
			}
			if (max != i) {
				HTNode* temp = charArray[i];
				charArray[i] = charArray[max];
				charArray[max] = temp;
			}
		}
	}
	else {
		for (int i = mycount - 1; i > 0; i--) {
			if (charArray[i]->count > charArray[i - 1]->count) {
				HTNode* temp = charArray[i];
				charArray[i] = charArray[i-1];
				charArray[i-1] = temp;
			}
			else {
				break;
			}
		}
	}
}

void HuffmanTree::preOrder(HTNode* T, string str){
	if (T == NULL) {
		return;
	 }
	T->newCode = str;
	if (T->data != '\0') {
		cout << T->data << "\t" << T->count << "\t" << T->newCode << endl;
	}
	else {
		string str1 = str;
		if (!str1.empty()) {
				str1.insert(0, "0");
		}
		else {
			str1.append("0");
		}
		preOrder(T->left, str1);

		string str2 = str;
		if (!str2.empty()) {
			str2.insert(0, "1");
		}
		else {
			str2.append("1");
		}
		preOrder(T->right, str2);
	}
}

void HuffmanTree::destory(HTNode* T){
	if (T == NULL) {
		return;
	}
	destory(T->left);
	destory(T->right);
	delete T;
	T = NULL;
}