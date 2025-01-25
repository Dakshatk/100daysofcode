#include <iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        long long X, Y;
        cin>>X>>Y;
        if (min(X, Y) % 2==0) {
            cout <<"Lakshya"<<endl;
        } else {
            cout<<"Kidambi"<<endl;
        }
    }
    return 0;
}