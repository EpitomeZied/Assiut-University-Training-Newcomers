#include <iostream>
using namespace std;

int main()
{
    int n, t;
    cin>>n>>t;
    if(t==10){
        if(n==1){
            cout<<-1;
            return 0;
        }
        n--;
    }
    cout<<t;
    for(int i=0;i<n-1;++i) cout<<0;
}
