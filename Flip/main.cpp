#include <iostream>
#include <fstream>

#define LIN 100
#define COL 100

using namespace std;

ifstream f("file.in");
ofstream g("file.out");


bool LineSumNegLineSum(int line, int Matrix[LIN][COL], int M)
{
    int sum=0,nsum=0;
    for(int i=0; i<M; i++)
    {
        sum = sum + Matrix[line][i];
        Matrix[line][i]=Matrix[line][i]*-1;
        nsum = nsum + Matrix[line][i];
    }
    if(sum<nsum)
        return false;
    else return true;
}

bool ColumnSumNegColumnSum(int column, int Matrix[LIN][COL], int N)
{
    int sum=0,nsum=0;
    for(int i=0; i<N; i++)
    {
        sum = sum + Matrix[i][column];
        Matrix[i][column]=Matrix[i][column]*-1;
        nsum = nsum + Matrix[i][column];
    }
    if(sum<nsum)
        return false;
    else return true;
}

void LineSignSwitch(int line, int (&Matrix)[LIN][COL], int M)
{
    for(int i=0; i<M; i++)
        Matrix[line][i] = Matrix[line][i]*-1;
}

void ColumnSignSwitch(int column, int (&Matrix)[LIN][COL], int N)
{
    for(int i=0; i<N; i++)
        Matrix[i][column] = Matrix[i][column]*-1;
}

int MatrixTotalSum(int Matrix[LIN][COL], int N, int M)
{
    int sum=0;
    for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
    {
        sum = sum+Matrix[i][j];
    }
    return sum*-1;

}

void LineColumnSignSwitch(int (&Matrix)[LIN][COL], int N, int M)
{
    for(int i=0; i<N; i++)
    {
        if(LineSumNegLineSum(i,Matrix,M)==false)
        {
            LineSignSwitch(i,Matrix,M);
            for(int j=0; j<M; j++)
                if(ColumnSumNegColumnSum(j,Matrix,N)==false)
                    ColumnSignSwitch(j,Matrix,N);
        }
        else
            for(int j=0; j<M; j++)
                if(ColumnSumNegColumnSum(j,Matrix,N)==false)
                    ColumnSignSwitch(j,Matrix,N);
    }
}

int main()
{
    int Matrix[LIN][COL];
    int N,M;
    f>>N;
    f>>M;
    int i,j;
    for(i=0;i<N;i++)
    for(j=0;j<M;j++)
    {
        f>>Matrix[i][j];
    }
    LineColumnSignSwitch(Matrix,N,M);
    g<<MatrixTotalSum(Matrix,N,M);
    cout<<MatrixTotalSum(Matrix,N,M);
    return 0;
}
