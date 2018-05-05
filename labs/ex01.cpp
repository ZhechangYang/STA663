
#include <iostream>
using std::cout;

int main() {
    for (int i=1; i<=12; i++){
        for (int j=1; j<=12; j++){
            cout << i+j << "\t";
        }
        cout << "\n";
    }
}