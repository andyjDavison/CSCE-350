#include <iostream>
#include <fstream>
#include <string>
#include <random>
using std::string;
using std::to_string;
using std::endl;

void generateInputFile(const string& filename, int size) {
    std::ofstream file(filename);
    float num = 0;

    for (int i = 0; i < size; ++i) {
        num = ((static_cast<float>(std::rand()) / RAND_MAX) * 200.0)-100.0;
        file << num << " ";
    }

    file.close();
    return;
}

int main() {
    const int sizes[] = {10, 100, 1000};
    
    for (int size : sizes) {
        for (int i = 1; i <= 25; ++i) {
            string filename = "input_" + to_string(size) + "_" + to_string(i) + ".txt";
            generateInputFile(filename, size);
        }
    }
    return 0;
}