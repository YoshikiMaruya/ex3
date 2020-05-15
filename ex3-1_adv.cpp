#include <iostream>
#include <queue>
using namespace std;

const int N=10;
int g[N][N]={};
bool visit[N]={false};

void dfs(int start,int num){
    queue<int> q;
    q.push(start);
    visit[start]=true;
    while(!q.empty()){ 
        int from=q.front();
        q.pop();
        for(int i=0;i<num;i++){ 
            if(!visit[i] && g[from][i]==1){ 
                q.push(i);
                visit[i]=true;
            }
        }
    }
    return;
}
bool check(int num){
    for(int i=0;i<num;i++){
        if(!visit[i]) return false;
    }
    return true;
}

int main(){
    int num;
    cout<<"Input #node: ";
    cin>>num;
    cout<<"Input Adjacent Matrix:"<<endl;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cin>>g[i][j];
        }
    }
    dfs(0,num);
    if(check(num)){
        cout<<"Connected!"<<endl;
    }else{
        cout<<"Unconnected!"<<endl;
    }
    return 0;
}