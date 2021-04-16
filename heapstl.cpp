//heap example finding of k largest elements in a running stream using min heap with help of priority queue STL
#include<bits/stdc++.h>
using namespace std;

void printelements(priority_queue<int,vector<int>,greater<int> > pq2){//make a copy and print top most element and pop it
    cout<<"\nstart\n";
    while(!pq2.empty()){
        cout<<pq2.top()<<" ";
        pq2.pop();    
    }
    cout<<"\nend\n";
    return ;
}
int main(){
    priority_queue<int,vector<int>,greater<int> > pq1;//min heap means more priority to less value
    int k,variable,currentitem=0;
    cin>>k;
    cout<<"enter the numbers and enter -1 when you have to find largest k elements\n";
    while(scanf("%d",&variable)!=EOF){
        if(variable!=-1){
            if(currentitem<k){
                pq1.push(variable);
                currentitem++;
            }
            else{
                if(pq1.top()<variable){
                    pq1.pop();
                    pq1.push(variable);
                }
            }
        }
        else{
            printelements(pq1);
        }
    }
    return 0;
}