#include<iostream>
#include<vector>
using namespace std;
vector<vector<char> >grid;
vector<vector<string> >result;
bool canplacequeen(int row,int col,int n){
    for(int i=row-1;i>=0;i--){// column check
        if(grid[i][col]=='Q'){// we are attacked
            return false;
        }
    }   
    for(int i=row-1,j=col-1; i>=0 and j>=0; i--,j--){// left daigonal check
        if(grid[i][j]=='Q'){// we are attacked
            return false;
        }
    }
    for(int i=row-1,j=col+1; i>=0 and j<n; i--,j++){// right daigonal check
        if(grid[i][j]=='Q'){// we are attacked
            return false;
        }
    }
    return true;
}
void f(int row,int n){
    if(row==n){
      vector<string>temp;
        for(int i=0;i<n;i++){
            string res="";
            for(int j=0;j<n;j++){
                res+=grid[i][j];
            }
            temp.push_back(res);
        }
        result.push_back(temp);
        return;
    }
    for(int col=0;col<n;col++){
        if(canplacequeen(row,col,n)){
            grid[row][col]='Q';
            f(row+1,n);
            grid[row][col]='.';// backtracking step
        }
    }       
}
vector<vector<string> >nqueen(int n){
    grid.clear();
    result.clear();
    grid.resize(n,vector<char>(n,'.'));
    f(0,n);
    return result;
}
int main(){
    vector<vector<string> >ans=nqueen(8);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<"total possible arrangement is:"<<ans.size();
}