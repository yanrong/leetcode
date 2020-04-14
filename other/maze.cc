#include <cstdio>
#include <cstdlib>
#include <stack>
using std::stack;

int mg[10][10]= {
    {1,0,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,0,1,1}
};//map

int direct[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
//int direct[4][2]={{-1,0},{0,1},{1,0},{0,-1},};
int M=9;
int N=9;
struct point
{
    int x;
    int y;
    int dir;
};
stack<point> st;
bool mgpath(int xi,int yi,int xe,int ye)//(xi,yi)->(xe,ye)
{
    int i,j,k,dir;
    bool flag;
    point pt, top;
    pt.x = xi;
    pt.y = yi;
    pt.dir = -1;
    mg[xi][yi]=-1;
    st.push(pt);
    while(!st.empty())
    {
        flag = false;
        top = st.top();
        i = top.x;
        j = top.y;
        dir = top.dir;
        if(i == xe || j == ye){
            return true;
        }
        
        while(dir < 4 && !flag){
            dir++;
            i = top.x + direct[dir][0];
            j = top.y + direct[dir][1];
            if(i  <0 || i > xe || j < 0|| j > ye){
                continue;
            }
            //printf("x-y %d, %d --- dir %d\n", i, j, dir);
            if(mg[i][j] == 0){
                st.top().dir = dir;
                pt.x = i;
                pt.y = j;
                pt.dir = -1;
                mg[i][j] = -1;
                st.push(pt);
                flag = true;
            }
        }

        if(!flag){
            st.pop();
        }
    }
    return false;
}

int main()
{
    point pt;
    int k = 1;
    if(!mgpath(0,1,M,N))
        printf("NO");
    
    while(!st.empty())
    {
        pt = st.top();
        printf("\t(%d,%d)",pt.x, pt.y);
        if(k % 5 == 0)  printf("\n");
        k++;
        st.pop();
    }
    printf("\n");
    return 0;
}
