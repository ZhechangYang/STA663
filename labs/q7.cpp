#include <iostream>
#include <fstream>
#include <random>
#include <Eigen/Dense>
#include <functional>
#include <cmath>

using std::cout;
using std::endl;
using std::ofstream;
using std::pow; 
using std::default_random_engine;
using std::normal_distribution;
using std::bind;

default_random_engine re{12345};
normal_distribution<double> norm(0, 1);
auto rnorm = bind(norm, re);

double func(double x){
    return 3*x*x-7*x+2;
}
int main() 
{
    using namespace Eigen;
    using namespace std;
    
    VectorXd x = VectorXd::LinSpaced(10, 10, 15);
    VectorXd y(10);
    for (int i=0; i<10; i++) {
        y(i) = func(x(i)) + 10*rnorm();
    }
    cout << "10 x-coordinates: "<< x.transpose() << "\n\n";
    cout << "10 y-coordinates: "<< y.transpose() << "\n\n";
    cout << "The distance is: " << sqrt((x-y).transpose()*(x-y))<< endl;
    
    double cov = (x.rowwise() - x.colwise().mean()).transpose()*(y.rowwise() - y.colwise().mean());
    double x_norm_sq = (x.rowwise() - x.colwise().mean()).transpose()*(x.rowwise() - x.colwise().mean());
    double y_norm_sq = (y.rowwise() - y.colwise().mean()).transpose()*(y.rowwise() - y.colwise().mean());
    double corr = cov / sqrt(x_norm_sq * y_norm_sq);
    cout << "The correlation is: " << corr << endl;
    
    int m = 10, n = 3;
    VectorXf coeff(n), b(m);
    MatrixXf A(m,n);
    for(int i=0; i<m; i++){
        A(i,0) = 1;
        A(i,1) = x(i);
        A(i,2) = x(i)*x(i);
        b(i) = y(i);
    }
    cout << "The solution is: " << A.jacobiSvd(ComputeThinU | ComputeThinV).solve(b).transpose() << endl;
}