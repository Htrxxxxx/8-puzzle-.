#include <bits/stdc++.h>
using namespace std ;
void fast(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
}
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
#define INF 1000000000000000000
#define all(s) s.begin(),s.end()
const int N = 2e5+5 ;
//int edges[N][N];
vector<int> visited(N) ;
set<pair<int , int>> adj[N] ;
int n , m ;
// explored set for all states that used before .
set <vector<vector<char>>> explored_set ;
// goal state .
vector<vector<char>> goal = {{'1' , '2' , '3'},
                             {'4' , '5' , '6'},
                             {'7' , '8' , '*'}};

vector<vector<char>> puzzle( 3 , vector<char>(3)) ;
int cnt_states = 0 ;
bool dfs(vector<vector<char>> &p){
    if(p == goal){
        cout<<"found a soultion" << endl ;
        for(int i=0 ; i<3 ; i++){
            for(int j=0 ; j<3 ; j++){
                cout<<p[i][j]<<' ' ;
            }
            cout<<endl;
        }
        cout<<"Number of states required to reach the goal " << cnt_states << endl;
        return true ;
    }
    cout<<"Next state"<<endl;
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            cout<<p[i][j]<<' ' ;
        }
        cout<<endl;
    }
    cout<<endl;
    explored_set.insert(p) ;
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            if(p[i][j]=='*'){
                for(int k=0 ; k<4 ; k++){
                    int nx = i + dx[k] , ny = j + dy[k] ;
                    vector<vector<char>> child = p ;
                    if(nx>=0 && ny>=0 && nx<3 && ny<3 ) {
                        swap(child[i][j], child[nx][ny]);
                        if(explored_set.find(child)==explored_set.end()) {
                            explored_set.insert(child) ;
                            cnt_states ++ ;
                            if(dfs(child)) return true ;

                        }
                    }
                }
            }
        }
    }
    return false ;
}
int main() {
    fast() ;

    cout<<"Enter the intial state of the puzzle" <<endl;
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            cin>>puzzle[i][j] ;
        }
    }
    if(dfs(puzzle)) ;
    else cout<<"There is no solution" <<endl;

}
