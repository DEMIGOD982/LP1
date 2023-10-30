#include<iostream>
using namespace std;

void wt(string p2[],int tt[], int bt2[], int n)
{
    int wt[n];
    for(int i=0;i<n;i++)
    {
        wt[i]=tt[i]-bt2[i];
    }
    cout<<"\n\nwaiting time"<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<"wt["<<p2[j]<<"]= "<<wt[j]<<endl;
    }
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+wt[i];
    }
    cout<<"\nAverage WT= "<<sum/n<<endl;
}
void tt(string p2[],int ft[],int bt2[],int at1[], int n)
{
    int tt[n];
    for(int i=0;i<n;i++)
    {
        tt[i]=ft[i+1]-at1[i];
    }
    cout<<"\n\nturnaround time"<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<"tt["<<p2[j]<<"]= "<<tt[j]<<endl;
    }
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+tt[i];
    }
    cout<<"\nAverage TT= "<<sum/n<<endl;
    wt(p2,tt,bt2,n);   
}
void ganttchart(string p[],int pr[], int bt[],int at[],int n)
{
    int ft[n+1];
    string p2[n];
    int bt2[n];
    int at1[n];
    int k = n;
    for(int i=0;i<n;i++)
    {
       int m=pr[i];
       p2[m-1]=p[i];
       bt2[m-1]=bt[i];
       at1[m-1]=at[i];
    }
    ft[0]=0;
    for (int i=1;i<=n;i++)
    {
        ft[i]=bt2[i-1]+ft[i-1];
    }
    cout<<"\nganttchart"<<endl;
    cout<<"   ";
    for(int j=0;j<n;j++)
    {
        cout<<p2[j]<<"      ";
    }
    cout<<endl;
    for(int j=0;j<=n;j++)
    {
        cout<<ft[j]<<"      ";
    }
    tt(p2,ft,bt2,at1,k);
}

int main()
{
    cout<<"\n....PRIORITY...."<<endl;
    int n;
    cout<<"Enter total no. of processes: ";
    cin>>n;
    cout<<endl;
    string p[n];
    int bt[n];
    int at[n];
    int pr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter processes["<<i+1<<"] : ";
        cin>>p[i];
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Arrival Time of "<<p[i]<<" : ";
        cin>>at[i];
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
        cout<<"Enter priority of "<<p[i]<<" : ";
        cin>>pr[i];
    }
    cout<<endl;
    cout<<"\n\nprocesses"<<"\tA.time"<<"\t\tB.time"<<"\t\tPriority"<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<p[j]<<"\t\t"<<at[j]<<"\t\t"<<bt[j]<<"\t\t"<<pr[j]<<endl ;
    }
    cout<<"\n CONSIDERING 1 AS HIGHEST PRIORITY"<<endl;    
    ganttchart(p,pr,bt,at,n);
    return 0;
}

