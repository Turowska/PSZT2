#include "forest.h"
#include <iostream>

Forest::Forest(std::pair<std::vector<std::vector<float>>, std::vector<float>> test) {
	for(int i=0; i<NUM_OF_TREE; ++i){
		std::vector<int> D = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
		std::vector<std::vector<float>> X = test.first;
		std::vector<float> Y = test.second;
		std::vector<int> DTree;
		std::vector<std::vector<float>> XTree;
		std::vector<float> YTree;

		int countD = rand()%D.size() + 1;
		for(int j=0; j<countD; ++j){
			int count = rand()%D.size();
			DTree.push_back(D[count]);
			D.erase(D.begin()+count);
		}
		int countTest = rand()%X.size() + 1;
		for(int j=0; j<countTest; ++j){
			int count = rand()%X.size();
			XTree.push_back(X[count]);
			YTree.push_back(Y[count]);
			X.erase(X.begin()+count);
			Y.erase(Y.begin()+count);
		}
		forest_[i].buildTree(DTree, XTree, YTree);
	}
}

float Forest::predict(std::vector<float> X) {
	float score = 0;
	for(int i=0; i<NUM_OF_TREE; ++i){
		score += forest_[i].predict(X);
	}
	score = score/NUM_OF_TREE;
	return score;
}


Forest::~Forest() {
	/*for(int i=0; i<NUM_OF_TREE; ++i) {
		delete forest_[i];
	}*/
}
