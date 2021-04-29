/*
    Given a stream of integers , find median at each point;
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){

    priority_queue < int > pq1;
    priority_queue< int , vector< int > , greater< int > > pq2;

    cout<<"Enter number: ";
    vector<int> vr;
    int x;
    cin>>x;
    if(x != -1){
        pq1.push(x);
        vr.push_back(x);
        bool one = true , two = false;
        cin>>x;
        while(x != -1){

            if(x > pq1.top()){
                pq2.push(x);

                if(two){
                    pq1.push(pq2.top());
                    pq2.pop();
                    vr.push_back(pq1.top());
                    one = true;
                    two = false;
                }
                else{
                    int temp = pq1.top() + pq2.top();

                    vr.push_back(temp/2);
                    one = false; 
                    two = true;

                }

            }
            else{
                pq1.push(x);
                if(one){
                    pq2.push(pq1.top());
                    pq1.pop();
                    int temp = pq1.top() + pq2.top();
                    
                    vr.push_back(temp/2);
                    one = false;
                    two = true;
                }
                else{
                    vr.push_back(pq1.top());
                    one = true;
                    two = false;
                }

            }

            cin>>x;
        }
    }

    cout<<"Median are: ";
    for(int i = 0 ; i < vr.size() ; ++i){
        cout<<vr[i]<<" ";
    }

    return 0;
}