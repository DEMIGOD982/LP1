#include<iostream>
using namespace std;

void wt(int tt[], int bt[], int n)
{
    int wt[n];
    for(int i=0;i<n;i++)
    {
        wt[i]=tt[i]-bt[i];
    }
    cout<<"\n\nwaiting time"<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<"wt["<<j+1<<"]= "<<wt[j]<<endl;
    }
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+wt[i];
    }
    cout<<"\nAverage WT= "<<sum/n<<endl;
}

void tt(int ft[],int bt[], int at[], int n)
{
    int tt[n];
    for(int i=0;i<n;i++)
    {
        tt[i]=ft[i+1]-at[i];
    }
    cout<<"\n\nTurnaround Time"<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<"tt["<<j+1<<"]= "<<tt[j]<<endl;
    }
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+tt[i];
    }
    cout<<"\nAverage TT= "<<sum/n<<endl;
    wt(tt,bt,n);    
}

void ganttchart(string p[],int bt[],int at[], int n)
{
    int ft[n+1];
    int at1[n];
    ft[0]=0;
    for(int i=0;i<n;i++)
    {
        at1[i]=at[i];
    }
    for(int i=1;i<=n;i++)
    {
        ft[i]=bt[i-1]+ft[i-1];
    }
    cout<<"\nganttchart"<<endl;
    cout<<"   ";
    for(int j=0;j<n;j++)
    {
        cout<<p[j]<<"      ";
    }
    cout<<endl;
    for(int j=0;j<=n;j++)
    {
        cout<<ft[j]<<"      ";
    }
    tt(ft,bt,at1,n);
}

int main()
{
    cout<<"\n....FCFS...."<<endl;
    int n;
    cout<<"Enter total no. of processes: ";
    cin>>n;
    cout<<endl;
    string p[n];
    int bt[n];
    int at[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter processes["<<i+1<<"] : ";
        cin>>p[i];
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Burst Time of "<<p[i]<<" : ";
        cin>>bt[i];
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Arrival Time of "<<p[i]<<" : ";
        cin>>at[i];
    }
    cout<<endl;
    cout<<"\nProceses"<<"\tBurstTime"<<"\tArrival Time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<at[i]<<endl;
    }
    ganttchart(p,bt,at,n);
    return 0;
}

