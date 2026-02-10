#include <iostream>
#include <cmath>
using namespace std;

bool p[51];
void sieve(bool* p,long long lim=51)
{
    p[1]=true;
    int sqlim=sqrt(lim);
    for (long long i=2;i<=sqlim;++i)
    {
        if (!p[i])
        {
            for (long long j=i*i;j<=lim;j+=i)
                p[j]=true;
        }
    }
}
int main() {
    sieve(p);
    int n,m;	cin>>n>>m;
    while(1){
        if (!p[++n])	break;
    }
    if (n==m)	cout<<"YES";
    else	cout<<"NO";
    return 0;
}
