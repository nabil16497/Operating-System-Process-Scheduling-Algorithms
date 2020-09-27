#include<iostream>
using namespace std;
int p[10][16], a[5], pn, an, totala[5], first = -1, working[5], workingc[5], cw = 0, tw = 0;

bool checktotal() {
    for (int i = 0;i < an;i++)
    {
        if (totala[i] != a[i])
        {
            return true;
        }
    }
    return false;
}

bool iscapable(int i) {
    for (int al = 0, n = 2 * an; al < an, n < 3 * an; al++, n++)
    {
        if (p[i][n] > a[al])
        {
            return false;
        }
    }
    return true;
}

void makechange(int i)
{
    cout << "\n\nAvailable- ";
    for (int x = 0;x < an;x++)
    {
        cout << a[x] << "\t";
    }
    cout << "\nP" << i << "- ";
    for (int x = 2 * an;x < 3 * an;x++)
    {
        cout << p[i][x] << "\t";
    }
    for (int x = 0, y = 2 * an;x < an;x++, y++)
    {
        a[x] = a[x] - p[i][y];

    }
    cout << "\nRemaining Available- ";
    for (int x = 0;x < an;x++)
    {
        cout << a[x] << "\t";
    }
    if (first == -1)
    {
        first = i;
    }
    p[i][15] = 0;
    working[cw] = i;
    workingc[tw] = i;
    cw++;
    tw++;


}

void callback()
{
    for (int i = 0; i < cw; i++)
    {
        cout << "\n\nNo needs can be satisfied. Return all resources consumed by P" << working[i] << "\nAvailable= Available+Need+Allocated= ";
        for (int x = 0;x < an;x++)
        {
            cout << a[x] << " ";
        }
        cout << "+ ";
        for (int x = 2 * an;x < 3 * an;x++)
        {
            cout << p[working[i]][x] << " ";
        }
        cout << "+ ";
        for (int x = 0;x < an;x++)
        {
            cout << p[working[i]][x] << " ";
        }
        cout << "= ";
        for (int x = 0, y = 2 * an;x < an, y < 3 * an;x++, y++)
        {
            a[x] = a[x] + p[working[i]][y] + p[working[i]][x];

        }
        for (int x = 0;x < an;x++)
        {
            cout << a[x] << " ";
        }
        working[i] = 0;
    }
    cw = 0;
    first = -1;
}

int main()
{
    cout << "Number of process- ";
    cin >> pn;
    cout << "Number of instance- ";
    cin >> an;
    cout << "Enter Available Process- ";
    for (int i = 0; i < an; i++)
    {
        cin >> a[i];
        totala[i] = a[i];

    }
    for (int i = 0; i < pn; i++)
    {
        cout << "Enter Allocated and Max for Process P" << i << "\n";
        for (int j = 0; j < an * 2; j++)
        {
            cin >> p[i][j];

        }
        for (int al = 0, m = an, n = 2 * an; al < an, m < 2 * an, n < 3 * an; al++, m++, n++)
        {
            p[i][15] = 1;
            p[i][n] = p[i][m] - p[i][al];
            totala[al] += p[i][al];
        }

    }
    cout<<"\n\nNeed\n";
     for (int i = 0; i < pn; i++)
     {  cout<<"P"<<i<<" ";
        for (int n = 2 * an; n < 3 * an; n++)
            {
                cout<<p[i][n]<<" ";
            }
        cout<<"\n";
     }
    int countap = 0;
   while (checktotal() && countap < pn*an)
    {

        for (int i = 0;i < pn;i++)
        {
            if (first == i)
            {
                callback();
            }
            if (iscapable(i) && p[i][15] == 1)
            {
                makechange(i);
                countap = 0;
            }
            else countap++;

        }

    }


    if (tw == pn)
    {
        cout << "\nNow Total Available resources-\t";
        for (int i = 0;i < an;i++)
        {
            cout << totala[i] << "\t";
        }
        cout << "\nThe system is in a safe state since the sequence <\t";
        for (int i = 0;i < tw;i++)
        {
            cout << "P" << workingc[i] << "\t";
        }
        cout << "> satisfies safety criteria";

    }
    else {
        cout << "\nThe system is in Deadlock\n";
    }


    return 0;

}

