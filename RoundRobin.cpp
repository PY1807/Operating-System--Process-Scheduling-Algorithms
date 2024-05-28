#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n,tq;
    cout<<"How many jobs do you want to perform ?"<<endl;
    cin>>n;
    cout<<"Input the Time Quantum as We are going to perform the Round Robin Algorithm"<<endl;
    cin>>tq;
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
        store.push_back({{arrive,i},burst});
    }
    sort(store.begin(),store.end());
    int time=0,r=0;
    
    
    queue<pair<pair<int,int>,int>> q;
  
    for(auto it:store)
    {
    q.push({{it.first.first,it.first.second},it.second});
    vis[it.first.second]=1;
    time=it.first.first;
    break;
    }
    
    while(!q.empty() && r<n)
    {
      if(q.empty())
      {
        
          time++;
          for(auto it:store)
        {
            if(it.first.first>check && it.first.first<=time && vis[it.first.second]==0)
            {
                q.push({{it.first.first,it.first.second},it.second});
                vis[it.first.second]=1;
            }
    
      }
      }
      else
      {
        int arrival=q.front().first.second;
        int burst=q.front().second;
        int process_no=q.front().first.second;
    
        q.pop();
        int flag=0,check=time;
        if(burst>tq)
        {
          time+=tq;
          burst-=tq;
        }
        else
        {
          time+=burst;
          completion[process_no]=time;
          flag=1;
        }
        for(auto it:store)
        {
            if(it.first.first>=check && it.first.first<=time && vis[it.first.second]==0)
            {
                q.push({{it.first.first,it.first.second},it.second});
                vis[it.first.second]=1;
            }
    
      }
      if(flag==0)
      {
        q.push({{arrival,process_no},burst});
      }
        
      }
    }
   
    
   
   int sumwt=0,sumtat=0;
    for(auto process:store)
    {
      int process_id=process.first.second;
      int arrival=process.first.first;
      int burst=process.second;
      tat[process_id]=completion[process_id]-arrival;
      wt[process_id]=tat[process_id]-burst;
      sumtat+=tat[process_id];
      sumwt+=wt[process_id];
    }
    cout<<endl<<" Pro No "<<"Arrival_Time"<<" Burst_Time"<<" Comp Time "<<" Waiting_Time"<<" TurnAround_Time "<<endl;
     for(auto process:store)
     {
       int process_id=process.first.second;
      int arrival=process.first.first;
      int burst=process.second;
      cout<<"    "<<process_id<<"       "<<arrival<<"           "<<burst<<"            "<<completion[process_id]<<"       "<<wt[process_id]<<"           "<<
      tat[process_id]<<endl;
     }
    float avg1=sumwt*1.0/n;
    float avg2=sumtat*1.0/n;
    cout<<"The average Waiting time = "<<avg1<<endl;
   cout<<"The average Turnaround time = "<<avg2<<endl;
    
    

}
