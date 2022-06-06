#include<iostream>
using namespace std;

int maze[20][20];
int visited[20][20];
int taken[20][20];

void display_input(int n){

    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){

            cout<<maze[row][col]<<" ";
        }
        cout<<endl;
    }
}


bool dfs(int row, int col, int n, int drow, int dcol){

    bool p1=false, p2=false, p3=false, p4=false;

    //out of range
    if(row >= n || col >= n ||row<0 ||col<0){
        return false;
    }

    //reached final destination
    if(row==drow && col==dcol){
        taken[row][col]=1;
        return true;
    }
    visited[row][col]=1;


    //down
    if(row+1<n && maze[row+1][col]==1){
        if(visited[row+1][col]==0){
            p1 = dfs(row+1, col, n, drow, dcol);
            if(p1){
                taken[row][col] = 1;
                return true;
            }

        }
    }

    //right
    if(col+1<n && maze[row][col+1]==1){
        if(visited[row][col+1]==0){
            p2 = dfs(row, col+1, n, drow, dcol);
            if(p2){
                taken[row][col] = 1;
                return true;
            }

        }
    }

    //left
    if(col-1>=0 && maze[row][col-1]==1){
        if(visited[row][col-1]==0){
            p3 = dfs(row, col-1, n, drow, dcol);
            if(p3){
                taken[row][col] = 1;
                return true;
            }

        }
    }

    //up
    if(row-1>=0 && maze[row-1][col]==1){
        if(visited[row-1][col]==0){
            p4 = dfs(row-1, col, n, drow, dcol);
            if(p4){
                taken[row][col] = 1;
                return true;
            }

        }
    }
}


void display_output(int n){

    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){

            cout<<taken[row][col]<<" ";
        }
        cout<<endl;
    }
}



int main(){

    int n=4, row, col;

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            maze[row][col]=1;  //valid path
            visited[row][col]=0;   //not visited
        }
    }

    //black blocks

    maze[0][1]=0;
    maze[0][2]=0;
    maze[0][3]=0;
    maze[1][2]=0;
    maze[2][0]=0;

    maze[2][2]=0;
    maze[2][3]=0;


    cout<<"Input Maze:";
    cout<<endl;
    display_input(n);

    dfs(0, 0, n, 3, 3);

    cout<<"Solved maze:";
    cout<<endl;
    display_output(n);
return 0;
}
