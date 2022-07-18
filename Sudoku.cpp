#include<bits/stdc++.h>
using namespace std;

int mapp[15][15],cnt;

bool is_row_have(int k,int row){
    for(int i=0;i<9;i++){
        if(mapp[row][i] == k)return true;
    }
    return false;
}

bool is_col_have(int k,int col){
    for(int i=0;i<9;i++){
        if(mapp[i][col] == k)return true;
    }
    return false;
}

bool is_group_have(int k,int row,int col){
    if(row>=0 && row<=2 && col>=0 && col<=2){
        for(int i=0;i<=2;i++){
            for(int j=0;j<=2;j++){
                if(mapp[i][j] == k)return true;
            }
        }
    }
    if(row>=0 && row<=2 && col>=3 && col<=5){
        for(int i=0;i<=2;i++){
            for(int j=3;j<=5;j++){
                if(mapp[i][j] == k)return true;
            }
        }
    }
    if(row>=0 && row<=2 && col>=6 && col<=8){
        for(int i=0;i<=2;i++){
            for(int j=6;j<=8;j++){
                if(mapp[i][j] == k)return true;
            }
        }
    }
    if(row>=3 && row<=5 && col>=0 && col<=2){
        for(int i=3;i<=5;i++){
            for(int j=0;j<=2;j++){
                if(mapp[i][j] == k)return true;
            }
        }
    }
    if(row>=3 && row<=5 && col>=3 && col<=5){
        for(int i=3;i<=5;i++){
            for(int j=3;j<=5;j++){
                if(mapp[i][j] == k)return true;
            }
        }
    }
    if(row>=3 && row<=5 && col>=6 && col<=8){
        for(int i=3;i<=5;i++){
            for(int j=6;j<=8;j++){
                if(mapp[i][j] == k)return true;
            }
        }
    }
    if(row>=6 && row<=8 && col>=0 && col<=2){
        for(int i=6;i<=8;i++){
            for(int j=0;j<=2;j++){
                if(mapp[i][j] == k)return true;
            }
        }
    }
    if(row>=6 && row<=8 && col>=3 && col<=5){
        for(int i=6;i<=8;i++){
            for(int j=3;j<=5;j++){
                if(mapp[i][j] == k)return true;
            }
        }
    }
    if(row>=6 && row<=8 && col>=6 && col<=8){
        for(int i=6;i<=8;i++){
            for(int j=6;j<=8;j++){
                if(mapp[i][j] == k)return true;
            }
        }
    }
    return false;
}

void print(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << mapp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void dfs(){
    for(int row=0;row<=9;row++){
        if(row == 9){
            cout << ++cnt << ":\n";
            print();
            return;
        }
        for(int col=0;col<9;col++){
            if(mapp[row][col]) continue;
            for(int k=1;k<=10;k++){
                if(k == 10)return;
                if(is_row_have(k,row) || is_col_have(k,col) || is_group_have(k,row,col)) continue;
                mapp[row][col] = k;
                dfs();
                mapp[row][col] = 0;   
            }
        }
    }
}

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> mapp[i][j];
        }
    }
    cout << "\n";
    dfs();
}
