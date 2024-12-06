#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        int K;
        cin>>K;
        string s;
        cin>>s;
        reverse(s.begin(),s.begin()+K);
        cout<<s<<endl;
    }
    return 0;
}
