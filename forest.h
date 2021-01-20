#include <fstream>
#include <string>
#include <cstdlib>
#include <array>
#include "DecisionTree.h"

#define NUM_OF_TREE 10

#define CRIM 1
#define ZN 2,
#define INDUS 3
#define CHAS 4
#define NOX 5
#define RM 6
#define AGE 7
#define DIS 8
#define RAD 9
#define TAX 10
#define PTRATIO 11
#define B 12
#define LSTAT 13

class Forest {

public:
	Forest(std::pair<std::vector<std::vector<float>>, std::vector<float>> test);
	float predict(std::vector<float> X);
	~Forest();

private:
	std::array<DecisionTree, NUM_OF_TREE> forest_;
};
