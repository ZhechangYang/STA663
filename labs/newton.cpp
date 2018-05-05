
#include <iostream>
#include <cmath>
#include <vector>

using std::cout;
using std::endl;
using std::abs;
using std::pow;
using namespace std;
double tol = 1e-6;

double func(double x){
    return x*x*x-7*x-6;
}
double grad(double x){
    return 3*x*x - 7.0;
}

double findroot(double x_start){
    double x = x_start;
    double alpha = 0.1;
    double error = tol + 1; 
    int i = 0;
    int max_iter = 200;

    double x1;

    while (error > tol && i < max_iter)
    {
        x = x - alpha * func(x) / grad(x);
        error = abs(func(x));
        i++;
    }
    return x;
}
int main(){
    double x_start = -3;
    vector<double> roots;
    double root;
    int num = 0;
    while(num < 3){
        root = findroot(x_start);
        if(roots.size()==0){
            roots.push_back(root);
            num++;
        }
        else{
            if(abs(roots[num-1]-root) > tol){
                roots.push_back(root);
                num++;
            }
        }
        x_start++;
    }
    for(int i = 0; i < 3; i++){       
        cout<<"Root "<<i+1 << " is: "<<roots[i]<<endl;       
    }
}