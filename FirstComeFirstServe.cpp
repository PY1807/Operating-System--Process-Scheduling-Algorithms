#include<iostream>
#include<bits/stdc++.h>
#include<iostream>
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
    for(int i=0;i<n;i++)
    {
        int arrive,burst;
        cin>>arrive>>burst;
        store.push_back({{arrive,i},burst});
    }
    sort(store.begin(),store.end());
    int time=0;
    int count=1;
   
  
    for(auto process:store)
    {
      int arrival=process.first.first;
      int process_id=process.first.second;
      int burst=process.second;
      if(count==1 || time<arrival)
      {
        time=arrival;
      }
      time+=burst;
      count++;
      completion[process_id]=time;
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
    cout<<endl<<" Pro No "<<"Arrival_Time"<<" Burst_Time"<<" Comp Time "<<" Waiting_Time"<<" TAT "<<endl;
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
