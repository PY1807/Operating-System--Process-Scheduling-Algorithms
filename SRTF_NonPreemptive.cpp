#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"How many jobs do you want to perform ?"<<endl;
    cin>>n;
    vector<pair<pair<int,int>,int>> store;
    vector<int>completion(n);
    vector<int>vis(n,0);
    vector<int>tat(n);
    vector<int>wt(n);
    int check=0;
    for(int i=0;i<n;i++)
    {
        int arrive,burst;
        cin>>arrive>>burst;
        store.push_back({{arrive,burst},i});
    }
    sort(store.begin(),store.end());
    int j=0,time=0;
   
     priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
    for(auto process:store)
    {

      pq.push({{process.first.second,process.first.first},process.second});
      time=process.first.first;
      vis[process.second]=1;
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
            if(it.first.first>check && it.first.first<=time && vis[it.second]==0)
            {
                pq.push({{it.first.second,it.first.first},it.second});
                vis[it.second]=1;
            }
        }
        }
        else
        {
        int arrival=pq.top().first.second;
        int burst=pq.top().first.first;
        int process_no=pq.top().second;
        pq.pop();
        
        check=time;
        
        time+=burst;
        
        completion[process_no]=time;
        
        r++;
        
        for(auto it:store)
        {
            if( it.first.first<=time && vis[it.second]==0)
            {
                pq.push({{it.first.second,it.first.first},it.second});
                vis[it.second]=1;
                
            }
        }
    }
    }
    
    
    int sumwt=0,sumtat=0;
    for(auto process:store)
    {
      int process_no=process.second;
      int arrival=process.first.first;
      int burst=process.first.second;
      tat[process_no]=completion[process_no]-arrival;
      wt[process_no]=tat[process_no]-burst;
      sumtat+=tat[process_no];
      sumwt+=wt[process_no];
    }
   
    cout<<endl<<" Pro No "<<"Arrival_Time"<<" Burst_Time"<<" Comp Time "<<" Waiting_Time"<<" TurnAround_Time "<<endl;
     for(auto process:store)
     {
       int process_no=process.second;
      int arrival=process.first.first;
      int burst=process.first.second;
      cout<<"    "<<process_no<<"       "<<arrival<<"           "<<burst<<"            "<<completion[process_no]<<"       "<<wt[process_no]<<"           "<<
      tat[process_no]<<endl;
     }
    float avg1=sumwt*1.0/n;
    float avg2=sumtat*1.0/n;
    cout<<"The average Waiting time"<<avg1<<endl;
   cout<<"The average Turnaround time"<<avg2<<endl;
    }
