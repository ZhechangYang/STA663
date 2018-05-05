
#include <iostream>
#include <cmath>
using std::cout;
using std::stod;
        
int main(int argc, char *argv[]) {
    if (argc ==2 ) {
        double x = stod(argv[1]);
        cout << x*x << "\n";
    } else {
        cout << "Usage: ex01.exe <n>\n";
    }
}