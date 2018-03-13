#include <iostream>


using namespace std;

double operator +(int x, int* y){
    return (double)x +(double) *y;
}

int main(){
    auto x = new int{10};
    auto y = new int{20};
    double z = *x + y;
    cout << z << endl;
}
