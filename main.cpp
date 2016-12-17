#include <iostream>
#include <algorithm>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
char a[16][16];
int creareAvion(int x, int y, int d)
{
    //d e directia capului
    if(d==1)
    {
        a[x][y]='z';
        a[x-1][y+1]='z';
        a[x][y+1]='z';
        a[x+1][y+1]='z';
        a[x][y+2]='z';
        a[x-1][y+3]='z';
        a[x][y+3]='z';
        a[x+1][y+3]='z';
    }
    return 1;
}
int main()
{

    for(int i=1;i<=15; i++)
    {
        for(int j=1; j<=15; j++)
            a[j][i]='H';
    }
    srand(time(NULL));
    for(int hh=1; hh<=3; hh++)
    {
        coordonate:
        int x =  rand()%15+1;
        int y =  rand()%15+1;
            srand((x+y)*15/7);
        if(a[y][x]!='H') goto coordonate;
        creareAvion(x,y,1);
    }
    for(int i=1;i<=15; i++)
    {
        for(int j=1; j<=15; j++)
            cout<<a[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}
