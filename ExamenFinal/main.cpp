//
//  main.cpp
//  ExamenFinal
//
//  Created by Zareek Galvan on 02/05/15.
//  Copyright (c) 2015 Zareek Galvan. All rights reserved.
//

#include <iostream>
using namespace std;
#include <fstream>
#include <stack>
#include <queue>


void mayores(int n, int mat[n][n], int arr[])
{
    int mayor;
    int index;
    for (int i=0; i<n; i++)
    {
        mayor=0;
        index=0;
        for (int e=0; e<n; e++)
        {
            if (mat[e][i]>mayor)
            {
                mayor=mat[e][i];
                index=e;
            }
        }
        arr[i]=index;
    }
}

void ordenaB(int arr[], int size)
{
    int k;
    for (int c = 0 ; c < ( size - 1 ); c++)
    {
        for (int d = 0 ; d < size - c - 1; d++)
        {
            if (arr[d] > arr[d+1])
            {
                k       = arr[d];
                arr[d]   = arr[d+1];
                arr[d+1] = k;
            }
        }
    }
}

stack<int> ordenaPila(stack<int> miPila)
{
    int s=miPila.size();
    int a[s];
    for (int i=0; i<s; i++)
    {
        a[i]=miPila.top();
        miPila.pop();
    }
    
    ordenaB(a, s);
    stack<int> x;
    for (int i=0; i<s; i++)
    {
        x.push(a[i]);
    }
    for (int i=0; i<s; i++)
    {
        miPila.push(x.top());
        x.pop();
    }
    return miPila;
}

int main()
{
//    //          Problema 1
//    int matriz[5][5];
//    int arreglo[5];
//    ifstream datos;
//    int n,d;
//    datos.open("");
//    datos>>n;
//    for (int i=0; i<n; i++)
//    {
//        for (int e=0; e<n; e++)
//        {
//            datos>>d;
//            matriz[i][e]=d;
//        }
//    }
//    mayores(n, matriz, arreglo);
    
    
    //          Problema 2
    
    int arreglo[6];
    stack<int> q;
    arreglo[0]=5;
    arreglo[1]=4;
    arreglo[2]=2;
    arreglo[3]=9;
    arreglo[4]=1;
    arreglo[5]=0;
    
    for (int i=0; i<6; i++)
    {
        q.push(arreglo[i]);
    }
    for (int i=0; i<6; i++)
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
    for (int i=0; i<6; i++)
    {
        q.push(arreglo[i]);
    }
    q=ordenaPila(q);
    for (int i=0; i<6; i++)
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    
}
