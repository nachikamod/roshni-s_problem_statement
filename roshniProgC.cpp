#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> q;

    int k, m, v = 2;

    cout<<"k : ";cin>>k;
    cout<<"m : ";cin>>m;
    
    for (int toBeCutted = 0; toBeCutted < k; toBeCutted++) {
        if (q.size() != 0)
        {
            v = q.front();
            q.pop();
        }
        for (int toBePlanted = 0; toBePlanted < (v+1)%m; toBePlanted++)
        {
            q.push(toBePlanted);
        } 
    }

    cout<<"Trees planted : "<<q.size();

    return 0;
}
