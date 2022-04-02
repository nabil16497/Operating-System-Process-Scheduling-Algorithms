#include<iostream>

using namespace std;
 int p[10][7],n;
 double avgw=0,avgt=0,finish;



void SRTF(){



    int last,c=0,time =0,start=0;
    cout<<"\nGantt Chart- ";
     p[9][2]=9999;
    for(int t=0; c!=n; t++)
    {
        last=9;
        for(int i=0; i<n; i++)
        {
            if(p[i][1]<=t && p[i][2]<p[last][2] && p[i][2]>0 )
                {
                    last=i;
                }

        }
        p[last][2]--;




        if(p[last][0]==0)
        {
            time++;
        }

        else{
            if(p[last][0]!=start)
            {
                cout<<" "<<time<<" "<<" P["<<p[last][0]<<"] ";
                time++;
                start=p[last][0];
            }
            else
                time++;

        }




        if(p[last][2]==0)
        {
            c++;
            finish=t+1;
            p[last][6]=finish;
            p[last][4] = finish - p[last][1] - p[last][3];
            p[last][5] = finish - p[last][1];

        }
    }


    cout<<" "<<time;



}





main()
{

    cout<<"Shortest Remaining Time First (SRTF preemptive SJF)\n";
    cout<<"Enter the number of Processes: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"\nEnter Process Name P[_]- ";
        cin>>p[i][0];
        cout<<"Enter Arrival Time for [P"<<p[i][0]<<"]- ";
        cin>>p[i][1];
        cout<<"Enter Burst Time for [P"<<p[i][0]<<"]- ";
        cin>>p[i][2];
        p[i][3]=p[i][2];
    }


    SRTF();



     cout<<"\n\nProcess\t"<< "Burst Time\t"<<"Arrival Time\t"<<"Waiting Time\t"<<"Turnaround Time\t"<<"\n";
    for(int i=0; i<n; i++)
    {
        cout<<"P"<<p[i][0]<<"\t\t"<<p[i][3]<<"\t\t"<<p[i][1]<<"\t\t"<<p[i][4]<<"\t\t"<<p[i][5]<<"\t\t"<<"\n";
        avgw = avgw + p[i][4];
        avgt = avgt + p[i][5];
    }

    cout<<"\n\nAverage Waiting Time ="<<avgw/n;
    cout<<"  Average Turnaround Time ="<<avgt/n<<"\n";
}

