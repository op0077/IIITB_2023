#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[0];
    int b[4]={1,2};
    a[0]=9;
    a[1]=2;
    int d[2]{1,2};
    int c[4];
    int x(99);
    fill_n(c,3,8);
    cout<<a[0]<<a[1]<<b[0]<<b[3]<<endl;
    cout<<c[1]<<" "<<c[3]<<endl;
    cout<<d[1]<<endl;
    cout<<x;
    return 0;
    
}