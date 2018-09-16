#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>ws;
        string a;
        getline(cin,a);
        char b[50];
        int k=a.length(),x=0,i;
        int ws=0;
        for(i=0;i<k;i++)
        {
            if(a[i]==' ')
                ws++;
        }
        if(ws==0)
        {
            if(a[0]>=97 && a[0]<=122)
                b[x++]=a[0]-32;
            else
                b[x++]=a[0];
            for(i=1;i<k;i++)
            {
                if(a[i]>=65 && a[i]<=90)
                    b[x++]=a[i]+32;
                else
                    b[x++]=a[i];
            }
        }
        if(ws==1)
        {
            if(a[0]>=97 && a[0]<=122)
                b[x++]=a[0]-32;
            else
                b[x++]=a[0];
            b[x++]='.';
            b[x++]=' ';
            for(i=1;a[i]!=' ';i++){}
            i++;
            if(a[i]>=97 && a[i]<=122)
                b[x++]=a[i]-32;
            else
                b[x++]=a[i];
            i++;
            for(;a[i]!='\0';i++)
            {
                if(a[i]>=65 && a[i]<=90)
                    b[x++]=a[i]+32;
                else
                    b[x++]=a[i];
            }
        }
        else if(ws==2)
        {
            if(a[0]>=97 && a[0]<=122)
                b[x++]=a[0]-32;
            else
                b[x++]=a[0];
            b[x++]='.';
            b[x++]=' ';
            for(i=1;a[i]!=' ';i++){}
            i++;
            if(a[i]>=97 && a[i]<=122)
                b[x++]=a[i]-32;
            else
                b[x++]=a[i];
            b[x++]='.';
            b[x++]=' ';
            for(;a[i]!=' ';i++){}
            i++;
            if(a[i]>=97 && a[i]<=122)
                b[x++]=a[i]-32;
            else
                b[x++]=a[i];
            i++;
            for(;a[i]!='\0';i++)
            {
                if(a[i]>=65 && a[i]<=90)
                    b[x++]=a[i]+32;
                else
                    b[x++]=a[i];
            }
        }
        b[x]='\0';
        for(i=0;i<x;i++)
            printf("%c",b[i]);
        printf("\n");
    }
    return 0;
}
