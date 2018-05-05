
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

vector<double> square(vector<double> xs){
    vector<double> res;
    for (auto x:xs){
        res.push_back(x * x);
    }
    return res;
}        
        
int main(){
    vector<double> xs;
    for (int i=1; i<=5; i++){
        xs.push_back(i);
    }
    auto ys = square(xs);
    for (auto y:ys){
        cout << y << "\n";
    }
}