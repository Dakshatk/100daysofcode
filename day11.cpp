#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        sort(arr,arr+N);
        int n=(N*(N+1))/2,sum=0;
        for(int i=0;i<N;i++){
            sum=sum+arr[i];
        }
        int missing=n-sum;
        cout<<missing;
        
        
    }
       
    return 0;
}