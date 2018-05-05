
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

template<typename T>
vector<T> square(vector<T> xs){
    vector<T> res;
    for (auto x:xs){
        res.push_back(x * x);
    }
    return res;
}        
        
int main(){
    vector<int> xs;
    for (int i=1; i<=5; i++){
        xs.push_back(i);
    }
    auto ys = square(xs);
    for (auto y:ys){
        cout << y << "\n";
    }
}