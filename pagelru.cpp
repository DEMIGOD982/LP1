#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	cout<<"....Page Replacement LRU...."<<endl;
	cout<<endl;
	int n,f,front;
	float hit=0.0;
	cout<<"enter size of input stream: ";
	cin>>n;
	char stream[n];
    char queue[n];
	cout<<endl;
	cout<<"enter input stream"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>stream[i];
	}
	cout<<endl;
	cout<<"enter frame size: ";
	cin>>f;
    for(int i=0;i<n;i++)
	{
		queue[i]=stream[i];
	}
    front=0;
	char table[f][n];
	char frame[f];
	for(int i=0;i<f;i++)
	{
		frame[i]='e';
	}
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<n;j++)
		{
			table[i][j]='e';
		}
	}
	for(int i=0;i<n;i++)
	{
		int re=0;
		for(int j=0;j<f;j++)
		{
			if(frame[j]=='e')
			{
				frame[j]=stream[i];
				re=1;
				for (int k = 0; k < f; k++)
				{
					table[k][i]=frame[k];
				}	
				break;
			}
			else if (stream[i]==frame[j])
			{
				hit=hit+1;
				re=1;
				for (int k = 0; k < f; k++)
				{
					table[k][i]=frame[k];
				}
				front++;
				break;
			}
		}
		if(re==0)
		{
			for(front;front<i;front++)
			{
				bool call=false;
				for(int j=0;j<f;j++)
				{
					if(queue[front]==frame[j])
					{
						frame[j]=stream[i];
						for (int k = 0; k < f; k++)
						{
							table[k][i]=frame[k];
						}
						call=true;
						front++;
						break;
					}
				}
				cout<<call<<" ";
				if(call==true)
				{
					break;
				}	
			}
		}
	}
	cout<<"\nstream ";
	for(int i=0;i<n;i++)
	{
		cout<<stream[i]<<"  ";
	}
    cout<<endl;	
	for(int i=0;i<f;i++)
	{
		cout<<"frame"<<i<<" ";
		for(int j=0;j<n;j++)
		{
			cout<<table[i][j]<<"  ";
		}
		cout<<endl;
	}
	cout<<"\nNumber of frames: "<<f<<endl;
	cout<<"Number of page hit: "<<hit<<endl;
	cout<<"Number of page fault: "<<n-hit<<endl;
	float hit_ratio=hit/n;
	cout<<"Hit Ratio= "<<hit_ratio<<endl;
	return 0;
}