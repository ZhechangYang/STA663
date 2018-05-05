
#include <iostream>
#include <vector>
#include <numeric>

using std::cout;
using std::vector;

template<typename T>
auto cal_mean(vector<T> xs){
    auto avg = (double)std::accumulate(begin(xs),end(xs),0)/xs.size();
    return avg;
}
        
int main(){
    vector<int> xs;
    for (int i=1; i<=6; i++){
        xs.push_back(i);
    } 
    auto res = cal_mean(xs);
    cout << res << "\n";
}