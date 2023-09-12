#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
stack<int> s;
s.push(1);
s.push(2);
s.push(3);
s.pop();
//s.pop();
//s.pop();
if(s.empty()){
cout<<"The stack is empty: "<<endl;
}
else{
cout<<"The stack is not empty"<<endl;
}
cout<<s.top()<<endl;
cout<<s.size()<<endl;
}
