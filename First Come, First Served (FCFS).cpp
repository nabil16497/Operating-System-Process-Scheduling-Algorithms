#include<iostream>



using namespace std;


int p[10][5],n,caln=0;



void FCFS()
{

    cout<<"\nGantt Chart-   "<<caln<<" ";
    caln+=p[0][2];
    for (int  i = 0; i < n ; i++ )
        {
            cout<<" [P "<<p[i][0]<<"] ";
            cout<<" "<<caln<<" ";


            p[i][3] =  caln- p[i][2]- p[i][1];



            caln+=p[i+1][2];
        }



    for (int  i = 0; i < n ; i++)
        {
            p[i][4] = p[i][2] + p[i][3];
        }




}


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
	caln=p[0][1];
}



main()
{
    cout<<"First Come, First Served\n";

    cout << "Enter the number of Process- ";
    cin >> n;

    for(int i=0; i<n;i++ ){

        cout<< "Enter Process Name P[_]- ";
        cin>>p[i][0];
        cout<< "Enter Arrival for "<<"[P "<<p[i][0]<<"]- ";
        cin>>p[i][1];
        cout<< "Enter Burst time for "<<"[P "<<p[i][0]<<"]- ";
        cin>>p[i][2];
    }

    SortArrivalTime();
	FCFS();

	float total_wt=0,total_tt=0;
	cout << "\n\nProcesses"<< "\tArrival Time" << "\tBurst Time" << "\tWaiting Time" << "\tTurnaround Time\n";

	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + p[i][3];
		total_tt = total_tt + p[i][4];
		cout << " [P" << p[i][0] << "]\t\t" << p[i][1] <<"\t\t"<< p[i][2] <<"\t\t"<< p[i][3] <<"\t\t " << p[i][4] <<"\n";
	}

	cout << "\nAverage Waiting Time- "<< total_wt / n;
	cout << "\nAverage Turnaround Time- "<<total_tt / n;
}
