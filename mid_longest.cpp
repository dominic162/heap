/*
    It is a well-researched fact that men in a restroom generally prefer to maximize their distance from already occupied stalls, by occupying the middle of the longest sequence of unoccupied places. For example, consider the situation where ten stalls are empty.
*/

#include<iostream>
#include<queue>
using namespace std;

int main(){

    int n;
    cin>>n;

    char * arr = new char[n];
    for(int i = 0 ; i < n ; ++i){
        arr[i] = '_';
    }

    queue <pair<int , int > > q;
    q.push({0,n-1});

    while(!q.empty()){

        pair<int , int > p = q.front();
        q.pop();

        int md = (p.first + p.second)/2;

        arr[md] = 'X';

        if(md + 1 <= p.second){
            pair<int,int> p1{md+1 , p.second};
            q.push(p1);
        }

        if(md - 1 >= p.first){
            pair<int,int> p2{p.first , md - 1};
            q.push(p2);
        }

        for(int i = 0 ; i < n ; ++i){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }

    return 0;
}