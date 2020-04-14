#include <stack>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::stack;

struct point{
    int x, y, dir, prev;//dir the current point search dirction, 
    point(){}
    point(int x1, int y1){
        x = x1; y = y1;
        dir = 0;
        prev = -1;
    }
};

class mazeSolution{
public:
    void solveMaze(){
        bool ret;
        point start(0,1);
        vector<vector<int>> maze{
            {1,0,1,1,1,1,1,1,1,1},
            {1,0,0,1,0,0,0,1,0,1},
            {1,0,0,1,0,0,0,1,0,1},
            {1,0,0,0,0,0,1,0,0,1},
            {1,1,1,1,1,0,0,0,0,1},
            {1,0,0,0,1,0,0,0,0,1},
            {1,0,1,0,0,0,1,0,0,1},
            {1,0,1,1,1,0,1,1,0,1},
            {1,1,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,1,1,1,1,1}};
        //vector<vector<int>> direct{{-1,0}, {0,1}, {1,0}, {0,-1}};
        //direction alway try to reach the right and bottom 
        vector<vector<int>> direct{{1,0}, {0,1}, {0,-1}, {-1,0}};

        stack<point> st;
        ret = bfs(maze, direct, st, start);
        if(ret == false){
            cout << "No solution"<<endl;
            return;
        }
        getResult(st, maze.size(), maze[0].size());
    }

    bool bfs(vector<vector<int>>& maze, vector<vector<int>>& direct, stack<point>& path, point start){
        int right, bottom , nextX, nextY, dir;
        bool flag;
        point top;

        right = maze[0].size();
        bottom = maze.size();
        path.push(start);//push the start point
        
        while(!path.empty()){
            top = path.top();//get top one
            dir = top.dir;
            flag = false;
            //if has been reach border, finish return
            if(top.x == right - 1 || top.y == bottom - 1){
                return true;
            }
            //search the four direction, always direction right and down is priority
            while(dir < 4 && !flag){
                nextX = top.x + direct[dir][0];
                nextY = top.y + direct[dir][1];
                dir++;
                //if something is out border
                if(nextX < 0 || nextX > right || nextY < 0 || nextY > bottom){
                    continue;
                }
                //find one
                if(maze[nextX][nextY] == 0){
                    path.top().dir = dir; //update parent direction
                    path.push(point(nextX, nextY));//add to stack
                    maze[nextX][nextY] = -1;//mark it has been visited
                    flag = true;//mark found one
                }
            }
            if(flag == false){//if none is found, pop the node
                path.pop();
            }
        }
        return false;
    }

    void getResult(stack<point>& path, int m, int n){
        point pt;
        int k = 1;
        vector<vector<int>>maze(m , vector<int>(n, 1));
        
        while(!path.empty()){
            pt = path.top();
            maze[pt.x][pt.y] = 9;
            path.pop();
        }

        for(auto mv : maze){
            cout <<"{";
            for(auto k : mv){
                cout << k <<",";
            }
            cout <<"}" <<endl;;
        }
        cout<<endl;
    }
};

int main(int argc, char const *argv[])
{
    mazeSolution solution;
    solution.solveMaze();
    return 0;
}
