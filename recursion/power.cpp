#include<iostream>
using namespace std;
int power(int x , int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return x;
    }
    int small_pow = power(x,n-1);
    return x*small_pow;
}
int main()
{
  int n,x;
  cin>>x>>n;
  cout<<power(x,n);

}
