#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>
#include <iterator>
using namespace std;



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    long long int N;
    cin>>N;
    stack <int> mystack;
    long long int h;
     long long int m = INT_MAX;
    for(long long int i=0; i<N; i++)
    {
        cin>>h;
        mystack.push(h);
    }
     long long int maxx =  INT_MIN;
    long long int count = 0;
    //vector <long long int> v;
    for(long long int i=0; i<N; i++)
        {
        long long int height = mystack.top();
        mystack.pop();
     //   v.push_back(height);
        count++;
         m = min(m, height); 
        maxx = max(maxx, m*count);
    }
    cout <<maxx<<endl;
    return 0;
}
