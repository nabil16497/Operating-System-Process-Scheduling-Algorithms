#include<iostream>
using namespace std;

int p[10][7], caln=0;



int n;
int q[100];
int front=-1,rear=-1;


void enqueue(int i)
{
    if(rear==100)
    printf("overflow");
    rear++;
    q[rear]=i;
    if(front==-1)
    front=0;

}

int dequeue()
{
    if(front==-1)
    printf("underflow");
    int temp=q[front];
    if(front==rear)
    front=rear=-1;
    else
    front++;
    return temp;
}
int isInQueue(int i)
{int k;
    for(k=front;k<=rear;k++)
    {
        if(q[k]==i)
        return 1;
    }
    return 0;

}




void SortArrivalTime()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(p[j][1] > p[j+1][1])
			{
				for(int k=0; k<7; k++)
				{
					swap(p[j][k], p[j+1][k]);
				}
			}
		}
	}
}



main()
{
    int i,j,tq,totalbt=0,time=0;
    float avgwt=0, avgtt =0;
    cout<<"Enter number of Process- ";
    cin>>n;



    for(i=0;i<n;i++)
    {
        cout<<"Enter Process Name(P_)- ";
        cin>>p[i][0];


        cout<<"\nEnter Arrival Time for Process [P"<<p[i][0]<<"]- ";
        cin>>p[i][1];
        cout<<"\nEnter Burst Time for Process [P"<<p[i][0]<<"]- ";
        cin>>p[i][2];


        p[i][3]=p[i][2];
        p[i][4]=0;
        totalbt+=p[i][2];

    }


    cout<<"\nEnter Time Quantum- ";
    cin>>tq;


    SortArrivalTime();
    caln=p[0][1];
    enqueue(0);


    cout<<"\nGantt Chart-  "<<caln<<" ";

    for(time=p[0][1];time<totalbt;)
    {

        i=dequeue();

        if(p[i][3]<=tq)
        {
            caln+=p[i][3];
            time+=p[i][3];
            p[i][3]=0;
            p[i][4]=1;

            cout<<" P["<<p[i][0]<<"] ";

            cout<<" "<<caln<<" ";

            p[i][5]=time-p[i][1]-p[i][2];

            p[i][6]=time-p[i][1];

            for(j=0;j<n;j++)
            {
                if(p[j][1]<=time && p[j][4]!=1&& isInQueue(j)!=1)
                {
                    enqueue(j);

                }
            }
        }
        else
        {
            time+=tq;
            p[i][3]-=tq;
            cout<<" P["<<p[i][0]<<"] ";
            caln+=tq;
            cout<<" "<<caln<<" ";

            for(j=0;j<n;j++)
            {
                if(p[j][1]<=time && p[j][4]!=1&&i!=j&& isInQueue(j)!=1)
                {
                enqueue(j);

                }
            }
            enqueue(i);

        }



    }


    cout<<"\n\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time";


    for(i=0;i<n;i++)
    {
        avgwt+=p[i][5];
        avgtt+=p[i][6];

        cout<<"\n"<<p[i][0]<<"\t\t"<<p[i][1]<<"\t\t"<<p[i][2]<<"\t\t"<<p[i][5]<<"\t\t"<<p[i][6];
    }




    cout<<"\nAverage Waiting Time- "<<avgwt/n;
    cout<<"\nAverage Turnaround Time- "<<avgtt/n;

}
