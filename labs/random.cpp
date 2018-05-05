
#include <iostream>
#include <random>
#include <functional>
#include <fstream>  
#include <sstream>
#include <string> 

using std::cout;
using std::endl;
using std::default_random_engine;
using std::exponential_distribution;
using std::bind;
using std::ofstream;
        
default_random_engine re{123};

exponential_distribution<double> expo(3);

int main() 
{
    auto rexp = bind(expo, re);
    ofstream outputFile;
    outputFile.open("random.csv");
    outputFile << "random numbers" <<"\n"; //header
    for (int i=0; i<1000; i++) {       
        outputFile << rexp() <<"\n";
    }
    outputFile.close();
}