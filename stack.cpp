#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    s.push(5);
    s.push(10);
    s.push(15);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    while(s.empty()==false)
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0; 
}