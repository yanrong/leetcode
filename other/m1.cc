#include <stdio.h>
#include<stdlib.h>
int mg[10][10]= {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};//地图
int M=8;//行数
int N=8;//列数
typedef struct
{
    int i;//当前方块行号
    int j;//当前方块列号
    int di;//下一个可走的相邻方块的方位号
} Box; //定义方块类型
typedef struct
{
    Box data[100];
    int top;//栈顶指针
} StType; //定义顺序栈类型
bool mgpath(int xi,int yi,int xe,int ye)//求解路径为：(xi,yi)->(xe,ye)
{
    int i,j,k,di,find;
    StType st;//定义栈st
    st.top=-1;//初始化栈顶指针
    st.top++;//初始方块进栈
    st.data[st.top].i=xi;
    st.data[st.top].j=yi;
    st.data[st.top].di=-1;
    mg[xi][yi]=-1;
    while(st.top>-1)//栈不为空时循环
    {
        i=st.data[st.top].i;
        j=st.data[st.top].j;
        di=st.data[st.top].di;//取栈顶方块
        if(i==xe&&j==ye)//找到出口，输出路径
        {
            printf("迷宫路径如下：\n");
            for(k=0; k<=st.top; k++)
            {
                printf("\t(%d,%d)",st.data[k].i,st.data[k].j);
                if((k+1)%5==0)
                    printf("\n");
            }
            printf("\n");
            return true;
        }
        find=0;
        while(di<4&&find==0)//站下一个可走方块
        {
            di++;
            switch(di)
            {
            case 0:
                i=st.data[st.top].i-1;
                j=st.data[st.top].j;
                break;
            case 1:
                i=st.data[st.top].i;
                j=st.data[st.top].j+1;
                break;
            case 2:
                i=st.data[st.top].i+1;
                j=st.data[st.top].j;
                break;
            case 3:
                i=st.data[st.top].i;
                j=st.data[st.top].j-1;
                break;
            }
            if(mg[i][j]==0)
                find=1;//找下一个可走相邻方块
        }
        if(find==1)//找到了下一个可走方块
        {
            st.data[st.top].di=di;//修改原栈顶元素的di值
            st.top++;//下一个可走方块进栈
            st.data[st.top].i=i;
            st.data[st.top].j=j;
            st.data[st.top].di=-1;
            mg[i][j]=-1;//避免重复走到该方块
        }
        else//没有路径可走则退栈
        {
            mg[st.data[st.top].i][st.data[st.top].j]=0;//让该位置变为其他路径可走方块
            st.top--;//将该方块退栈
        }
    }
    return false;
}
int main()
{
    if(!mgpath(1,1,M,N))
        printf("无解");
    return 0;
}
