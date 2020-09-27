#include<iostream>

using namespace std;

int p[10][7],n;

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



void PrioritySchedule()
{

    int service[50];

    service[0] = p[0][1];
    p[0][4]=0;




    for(int i=1;i<n;i++)
    {
        service[i]=p[i-1][2]+service[i-1];

        p[i][4]=service[i]-p[i][1];


        if(p[i][4]<0)
        {
        p[i][4]=0;
        }
    }

    for(int i=0;i<n;i++)
    {
        p[i][5]=p[i][2]+p[i][4];
    }
    cout<<"\nGantt Chart-  "<<p[0][1]<<" P["<<p[0][0]<<"] ";
    p[0][6] = p[0][1]+p[0][5];
    cout<<" "<<p[0][6]<<" ";
    for(int i=1; i<n ; i++)
    {
        p[i][6]=p[i-1][6]+p[i][5]-p[i][4];
        cout<<" P["<<p[i][0]<<"] "<<p[i][6];

    }

}

main()
{
    float wavg=0,tavg=0;
    cout<<"Enter The Number of Process- ";
    cin>>n;



    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Process Name P[_]- ";
        cin>>p[i][0];
        cout<<"Enter Arrival Time for P["<<p[i][0]<<"]- ";
        cin>>p[i][1];
        cout<<"Enter Burst Time for P["<<p[i][0]<<"]- ";
        cin>>p[i][2];
        cout<<"Enter Priority for P["<<p[i][0]<<"]- ";
        cin>>p[i][3];

	}


	SortArrivalTime();

	PrioritySchedule();




	cout<<"\n\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time"<<"\n";


    for(int i=0;i<n;i++)
	{
		wavg += p[i][4];
		tavg += p[i][5];

		cout<<p[i][0]<<"\t\t"<<p[i][1]<<"\t\t"<<p[i][2]<<"\t\t"<<p[i][4]<<"\t\t"<<p[i][5]<<"\n";
	}

	cout<<"Average Waiting Time is : "<<wavg/n<<"\n";
	cout<<"average turnaround Time : "<<tavg/n<<"\n";

}

