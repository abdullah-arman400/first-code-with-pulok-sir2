#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct activity
{
    string name;
    int st;
    int ft;
};

int main()
{
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<activity> act(n);

    for(int i=0; i<n; i++)
    {
        cout<<"Enter activity name "<<i+1<<": ";
        cin>>act[i].name;

        cout<<"Enter start time: ";
        cin>>act[i].st;

        cout<<"Enter finish time: ";
        cin>>act[i].ft;
    }

    // Sorting by finish time
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(act[i].ft > act[j].ft)
            {
                activity temp = act[i];
                act[i] = act[j];
                act[j] = temp;
            }
        }
    }

    vector<string> selected_activity;

    selected_activity.push_back(act[0].name);

    int c = 1;
    int last_ft = act[0].ft;

    for(int i=1; i<n; i++)
    {
        if(act[i].st >= last_ft)
        {
            selected_activity.push_back(act[i].name);
            c++;
            last_ft = act[i].ft;
        }
    }

    cout<<"\nTotal selected activities: "<<c<<endl;
    cout<<"Selected activities: ";

    for(int i=0; i<selected_activity.size(); i++)
    {
        cout<<selected_activity[i]<<" ";
    }

    return 0;
}