//cnf input
//each line is a element of list.
//in order to break a line into propositions we need to distribute its literals in each list recursively.
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int flag=0,var;
void showlist(vector<int> g) 
{ 
    vector<int> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 
int check(vector<int> vect)
{ 
      int arr[10000];
      for(int i=0;i<10000;i++){
      	  arr[i]=-1;
      }
      vector<int> :: iterator it;
      for(it= vect.begin(); it!= vect.end();it++)
      {
             if(*it>0 && arr[*it]==-1)
             	arr[*it]=1;
             else if(*it<0 && arr[-*it]==-1)
             	arr[-*it]=2;
             else if(*it>0 && arr[*it]==2)
             	arr[*it]=0;
             else if(*it<0 && arr[-*it]==1)
             	arr[-*it]=0;

      }
      for(int i=0;i<10000;i++){
      	   if(arr[i]==0)
      	   	return 1;//closed
      }
      return 0;//open

}
void D(int line,vector<int> vect[10000],int line_idx,vector<int> arr)
{
	int chk;
	int A[var+1];
	for(int i=1;i<=var;i++)
		{
            A[i]=i;
		}
	chk=check(arr);
    if(line_idx!=-1 && chk==1)
    	return;
    if(line_idx==-1 && chk==1)
    return; 
	if(line_idx==-1 && chk==0)
	{
		cout <<"SAT"<<endl;
		flag=1;
		vector <int> :: iterator it;
		sort(arr.begin(),arr.end());
		it=arr.begin();
		int x=*it;
		if(x>0)
			A[x]=x;
		else
			A[-x]=x;
		for(it=arr.begin();it!=arr.end();it++)
		{
			
           if(*it!=x)
           {
           	  x=*it;
              if(x>0)
			A[x]=x;
		else
			A[-x]=x;

           }
		}
		for(int i=1;i<=var;i++)
		{
            cout << A[i] << " ";
		}
		return;
	}
    vector<int> :: iterator it;
    
    if(vect[line_idx].size()!=1){
    	
    arr.push_back(vect[line_idx].back());
    D(line,vect,line_idx-1,arr);
    
    arr.pop_back();
    if(flag==1)
    	return;
    int x=vect[line_idx].back();
    vect[line_idx].pop_back();
    D(line,vect,line_idx,arr);
    
    vect[line_idx].push_back(x);
    if(flag==1)
    	return;
}
else if(vect[line_idx].size()==1)
{
	arr.push_back(vect[line_idx].back());
    D(line,vect,line_idx-1,arr);
    arr.pop_back();
    if(flag==1)
    	return;
}
}
int main() {
	  int i=0,line,n;
	  cin >> var >> line;
	  vector<int> A[line]; 
	   vector<int> arr;
	   while(i<line)
	   {
	   	    cin >> n;
	   	    while(n!=0)
	   	    {
               A[i].push_back(n); 
               cin >> n;  
	   	    } 
           i++;
	   	     
	   	    
	   }
	   
       D(line,A,line-1,arr);
     if(flag==0)
     	cout <<"UNSAT"<<endl;
      return 0;
  }
