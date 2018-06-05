#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include<cmath>
#define MAX_INT 10000

using namespace std;
void dijkstra(int m);


const int n=100;
int a[100][100];
int dist[100];
int prev[100];
int z=10000;
 	int i;
int  main(void)
{
 /*{
    ifstream read("BA.txt");
    //read.open;
    int re[100][100];
    memset(re,sizeof(re),0);
    for(int i=0;i<100;i++)
    {
        int buffer[100];
        read.getline(buffer,100);
        memcpy(re[i],buffer,sizeof(int)*100);
        //    read>>re[i][j];
    }*/
    FILE* destFile=fopen("BA.txt","r");
    FILE* destFileWrite=fopen("res.txt","w");

    //int re[100][100];
    for( i=0;i<100;i++)
    {
      for(int j=0;j<100;j++)
        {
            fscanf(destFile,"%d",&a[i][j]);
            if(a[i][j]==0)a[i][j]=MAX_INT;
        }
    }


 for( i=0;i<100;i++)
 {
     dijkstra(i);
      for(int j=0;j<100;j++)
      {

            fprintf(destFileWrite,"%d ",dist[j]);
      }
      fprintf(destFileWrite,"\n");
 }
 //read.close();
 return 0;
}
void dijkstra(int m)
{
	if(m<0||m>n)
		return;
	bool *s=new bool[n+1];
	for(int i=0;i<n;i++)
	{
		dist[i]=a[m][i];
		s[i]=false;
		if(dist[i]==z)
			prev[i]=0;
		else
			prev[i]=m;
	}
	dist[m]=0;
	s[m]=true;
	for(int i1=0;i1<n;i1++)
	{
		float temp=z;
		int u=m;
		for(int j=0;j<n;j++)
			if((!s[j])&&(dist[j]<temp))
			{
				u=j;
				temp=dist[j];
			}
		s[u]=true;
		for(int j1=0;j1<n;j1++)
			if((!s[j1])&&(a[u][j1]<z))
			{
				float newdist=dist[u]+a[u][j1];
				if(newdist<dist[j1])
				{
					dist[j1]=newdist;
					prev[j1]=u;
				}
			}
	}
}
/*int main{}
{
     Ifstream read;
     read.open("µØÖ·")
    Int re[100][100]={0};
    for(int i=0;i<100;i++)
    {
         for(int j=0;j<100;j++)
         {
             read>>re[I][j];
         }
    }
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            cout<<re[i][j]<<"";
        }
       cout<<end1;
   }
   read.close();
   return 0;
}*/




