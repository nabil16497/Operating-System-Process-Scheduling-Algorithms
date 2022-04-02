#include<iostream>

using namespace std;

int p[10][6],n;


void SortArrivalTime()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(p[j][1] > p[j+1][1])
			{
				for(int k=0; k<5; k++)
				{
					swap(p[j][k], p[j+1][k]);
				}
			}
		}
	}
}

void SJF()
{
	int temp, val;
	p[0][3] = p[0][1] + p[0][2];
	p[0][5] = p[0][3] - p[0][1];
	p[0][4] = p[0][5] - p[0][2];

	for(int i=1; i<n; i++)
	{
		temp = p[i-1][3];
		int low = p[i][2];
		for(int j=i; j<n; j++)
		{
			if(temp >= p[j][1] && low >= p[j][2])
			{
				low = p[j][2];
				val = j;
			}
		}
		p[val][3] = temp + p[val][2];
		p[val][5] = p[val][3] - p[val][1];
		p[val][4] = p[val][5] - p[val][2];
		for(int k=0; k<6; k++)
		{
			swap(p[val][k], p[i][k]);
		}
	}
}



main()
{

    cout<<"Shortest Job First (SJF non-preemptive SJF)\n";
	float totalw =0, totaltt =0;


	cout<<"Enter number of Process- ";
	cin>>n;

	for(int i=0; i<n; i++)
	{

		cout<<"Enter Process Name P[_]- ";
		cin>>p[i][0];
		cout<<"Enter Arrival Time For P["<<p[i][0]<<"]- ";
		cin>>p[i][1];
		cout<<"Enter Burst Time For P["<<p[i][0]<<"]- ";
		cin>>p[i][2];
	}

    SortArrivalTime();
	SJF();

	 cout<<"\nGantt Chart-  "<<p[0][1]<<" ";
    for(int i=0;i<n;i++)
    {
        cout<<" P["<<p[i][0]<<"] "<<p[i][3]<<" ";
    }

	cout<<"\n\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
	for(int i=0; i<n; i++)
	{
		cout<<p[i][0]<<"\t\t"<<p[i][1]<<"\t\t"<<p[i][2]<<"\t\t"<<p[i][4]<<"\t\t"<<p[i][5]<<"\n";

        totalw+=p[i][4];
        totaltt+=p[i][5];
	}

	cout<<"Average Waiting Time- "<<(totalw/n)<<"\n";
	cout<<"Average Turnaround Time- "<<(totaltt/n)<<"\n";
}

