#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<map>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

//void dfsFind(Node *node, int dep, int counter[]){
//	counter[dep]++;
//	for (int i = 0; i < node->sons.size(); i++){
//		dfsFind(node->sons[i], dep, counter);
//	}
//}
//int find(Node *root, int maxDep){
//	int depCounter[100000];
//	dfsFind(root, 0, depCounter);
//
//	int max, maxDep;
//	for (int i = 1; i <= maxDep; i++){
//		if (depCounter[i] > max){
//			max = depCounter[i];
//			maxDep = i;
//		}
//	}
//	return maxDep;
//}