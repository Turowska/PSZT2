#include <fstream>
#include <string>
#include <cstdlib>
#include <array>
#include "DecisionTree.h"

#define NUM_OF_TREE 10

#define CRIM 0
#define ZN 1
#define INDUS 2
#define CHAS 3
#define NOX 4
#define RM 5
#define AGE 6
#define DIS 7
#define RAD 8
#define TAX 9
#define PTRATIO 10
#define B 11
#define LSTAT 12

class Forest {

public:
	Forest(std::pair<std::vector<std::vector<float>>, std::vector<float>> test);
	float predict(std::vector<float> X);
	~Forest();

private:
	std::array<DecisionTree, NUM_OF_TREE> forest_;
};
