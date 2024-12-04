#include <iostream>
using namespace std;
int main() {
  int T;
  int N;
    
cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        int arr[N];
         int even=0;
         int odd=0;
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        for(int j=0;j<N;j++){
            if(arr[j]%2==0){
                even++;
            }
            else if(arr[j]%2!=0){
                odd++;
            }
        }
        if(even>odd){
            cout<<"Yes"<<endl;
        } if(even<odd){
            cout<<"No"<<endl;
        } if(even==odd){
            cout<<"No"<<endl;
        }
    }
    return 0;
}