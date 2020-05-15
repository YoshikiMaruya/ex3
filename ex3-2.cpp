#include<iostream>
#include<stack>
using namespace std;

const int N=10;
int g[N][N]={};
bool visit[N]={false};

void dfs(int start,int num){
   visit[start]=true;
   for(int i=0;i<=num;i++){
       if(!visit[i] && g[start][i]==1){
           dfs(i,num);
       }
   }
}

bool check(int S,int G){
    for(int i=S;i<=G;i++){
        if(!visit[i]) return false;
    }
    return true;
}

int main(){
    int num;
    int S,G;
    cout<<"Input #node: ";
    cin>>num;
    cout<<"Input Adjacent Matrix: "<<endl;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cin>>g[i][j];
        }
    }
    cout<<"Start and Goal: ";
    cin>>S>>G;
    dfs(S,G);
    if(check(S,G)){
        cout<<"Reachable!"<<endl;
    }
    else{
        cout<<"Unreachable!"<<endl;
    }
    return 0;
}