#include <fstream>
#include <string>
#include <cstdlib>
#include <array>
#include "DecisionTree.h"

#define NUM_OF_TREE 200

class Forest {

public:
	Forest(std::pair<std::vector<std::vector<float>>, std::vector<float>> test);
	float predict(std::vector<float> X);

private:
	std::array<DecisionTree, NUM_OF_TREE> forest_;
};
