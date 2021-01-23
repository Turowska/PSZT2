#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
#include "forest.h"

#define NUM_OF_TRAINING_DATA 400
#define DATA_FILE_NAME "boston_housing.txt"

std::vector<int> getFeatures() {
    std::vector<int> features;
    for (int i = 0; i < D_SIZE; i++)
        features.push_back(i);
    return features;
}

std::pair<std::vector<std::vector<float>>, std::vector<float>> getTrainingData() {
    std::ifstream data_file;
    float tmp;
    data_file.open(DATA_FILE_NAME);
    std::string s;
    std::vector<std::vector<float>> X;
    std::vector<float> x;
    std::vector<float> Y;

    for (int i = 0; i < NUM_OF_TRAINING_DATA; i++) {
        for (int j = 0; j < D_SIZE; j++) {
            data_file >> tmp;
            x.push_back(tmp);
        }
        data_file >> tmp;
        Y.push_back(tmp);
        X.push_back(x);
        x.clear();
        std::getline(data_file, s);
    }
    data_file.close();

    std::pair<std::vector<std::vector<float>>, std::vector<float>> training_data;
    training_data.first = X;
    training_data.second = Y;

    return training_data;
}


std::pair<std::vector<std::vector<float>>, std::vector<float>> testing_data() {
    std::ifstream data_file;
    data_file.open(DATA_FILE_NAME);
    std::vector<std::vector<float>> X;
    std::string s;
    std::vector<float> x;
    std::vector<float> Y;
    float tmp;
    for (int i = 0; i < NUM_OF_TRAINING_DATA * 2; i++)
        std::getline(data_file, s);
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < D_SIZE; j++) {
            data_file >> tmp;
            x.push_back(tmp);
        }
        data_file >> tmp;
        Y.push_back(tmp);
        X.push_back(x);
        x.clear();
        std::getline(data_file, s);
    }
    data_file.close();

    std::pair<std::vector<std::vector<float>>, std::vector<float>> training_data;
    training_data.first = X;
    training_data.second = Y;
    return training_data;
}


int main(int argc, char* argv[]) {
    srand(time(NULL));
    float tr_data[NUM_OF_TRAINING_DATA][D_SIZE + 1];
    std::pair<std::vector<std::vector<float>>, std::vector<float>> U;

    std::vector<int> D;
    D = getFeatures();
    U = getTrainingData();

    Forest forest(U);
    std::pair<std::vector<std::vector<float>>, std::vector<float>> test;
    test = testing_data();
    std::vector<std::vector<float>> X = test.first;
    std::vector<float> Y = test.second;

    float prediction = 0;
    float max_error = 0;
    float error = 0;
    for (int i = 0; i < Y.size(); i++) {
        prediction = forest.predict(X[i]);
        if(abs(prediction - Y[i]) > max_error)
            max_error = abs(prediction - Y[i]);
        error += abs(prediction - Y[i]);
    }

    std::cout << "Number of predictions: " << Y.size() << std::endl;
    std::cout << "Average error: " << error / Y.size() << std::endl;
    std::cout << "Max error: " << max_error << std::endl;
    return 0;
}
