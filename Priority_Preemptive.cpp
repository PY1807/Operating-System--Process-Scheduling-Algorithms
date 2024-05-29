#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Lower number means higher priority that is 0 has higher prioirity than 1
    int n;
    cout<<"How many jobs do you want to perform ?"<<endl;
    cin>>n;
    vector<pair<pair<int,int>,pair<int,int>>> store;
    vector<int>completion(n);
    vector<int>vis(n,0);
    vector<int>tat(n);
    vector<int>wt(n);
    int check=0;
    for(int i=0;i<n;i++)
    {
        int arrive,burst,priority;
        cin>>arrive>>burst>>priority;
        store.push_back({{arrive,priority},{i,burst}});
    }
    sort(store.begin(),store.end());
    int j=0,time=0;
   
     priority_queue<pair<pair<int, int>,pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> pq;
    for(auto process:store)
    {

      pq.push({{process.first.second,process.first.first},{process.second.first,process.second.second}});
      time=process.first.first;
      vis[process.second.first]=1;
      break;
    }
    int r=0;
    while(!pq.empty() || r<n)
    {
      if(pq.empty())
        {
          time++;
          for(auto it:store)
        {
            if(it.first.first>=check && it.first.first<=time && vis[it.second.first]==0)
            {
                pq.push({{it.first.second,it.first.first},{it.second.first,it.second.second}});
                vis[it.second.first]=1;
            }
        }
        }
        else
        {
        int arrival=pq.top().first.second;
        int priority=pq.top().first.first;
        int process_no=pq.top().second.first;
        int burst=pq.top().second.second;
        pq.pop();
        check=time;
        time++;
        burst--;
        if(burst==0)
        {
            completion[process_no]=time;
            r++;
        }
        else
        {
        pq.push({{priority,arrival},{process_no,burst}});
        
        for(auto it:store)
        {
            if( it.first.first>=check && it.first.first<=time && vis[it.second.first]==0)
            {
                pq.push({{it.first.second,it.first.first},{it.second.first,it.second.second}});
                vis[it.second.first]=1;
                
            }
        }
    }
    }
    //it.first.first>check &&
    }
    int sumwt=0,sumtat=0;
    for(auto process:store)
    {
      int process_no=process.second.first;
      int arrival=process.first.first;
      int burst=process.second.second;
      tat[process_no]=completion[process_no]-arrival;
      wt[process_no]=tat[process_no]-burst;
      sumtat+=tat[process_no];
      sumwt+=wt[process_no];
    }
    cout<<endl<<" Pro No "<<" Comp Time "<<" Wait-Time"<<" TAT "<<endl;
     for(int i=0;i<n;i++)
    {
        cout<<"   P"<<i+1<<"         "<<completion[i]<<"       "<<wt[i]<<"        "<<tat[i]<<endl;
    }
    float avg1=sumwt*1.0/n;
    float avg2=sumtat*1.0/n;
    cout<<"The average Waiting time"<<avg1<<endl;
   cout<<"The average Turnaround time"<<avg2<<endl;
    
}
