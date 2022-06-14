// Created by Arunachalam, Sanjay Pranao, Srirambabu

#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

class File{
	public:
			ifstream graph_file,myfile,myfile1;
		File()
		{
    		graph_file.open("graph_plot.txt",ios::in);
    		myfile.open("places.txt",ios::in);
    		myfile1.open("directions.txt",ios::in);
		}
		~File()
		{
		    myfile.close();
		    myfile1.close();
		    graph_file.close();	
		}
};
vector<int> getpath(vector<pair<int,int>> adj[],int n,int m,int source,int destination)
{
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    
    vector<int> dist(n+1,INT_MAX);
    vector<int> parent(n+1,-1);

    dist[source]=0;
    pq.push({0,source});
    vector<int> path;

    while(!pq.empty())
    {
        int next=pq.top().first;
        int prev=pq.top().second;

        pq.pop();
        for(auto it:adj[prev])
        {
            int nextnode=it.first;
            int nextdistance=it.second;
            if(dist[nextnode]>dist[prev]+nextdistance)
            {
                dist[nextnode]=dist[prev]+nextdistance;
                pq.push({dist[nextnode],nextnode});
                parent[nextnode]=prev;
            }
        }
    }

    for (int x = destination; x != -1; x = parent[x])
        path.push_back(x);

    reverse(path.begin(),path.end());   
    
    return path;
}
void menu(map<int,string> &m)
{
	cout<<"\t\t\tCAMPUS NAVIGATION SYSTEM\n\n";
	cout<<" List of Places : \n\n";
	for(auto it:m)
	{
		cout<<"\t"<<it.first<<" "<<it.second<<endl;
	}
	cout<<endl;
}

void printpath(vector<int> &pts,map<int,string> &loc){
	map<int,vector<int>> co;
    ifstream fin;
    int i;
    string nm;
    setcolor(YELLOW);
    outtextxy(270,30,"CEG NAVIGATION SYSTEM");
    fin.open("coordinates.txt",ios::in);
    while(getline(fin,nm))
    {
        int u,v,w,b1,b2,k=0;
        for(int j=0;j<nm.length();j++)
            if(nm[j]==' ' && k==0)
            b1=j,k++;
            else if(nm[j]==' ' && k==1)
            {
                b2=j;
                break;
            }
                
        u=stoi(nm.substr(0,b1));
        v=stoi(nm.substr(b1+1,b2-b1+1));
        w=stoi(nm.substr(b2+1));
        vector<int> t(2);
        t[0]=v;
        t[1]=w;
        co[u]=t;
    }
    vector<int> t(4);
    for(i=0;i<pts.size()-1;i++){
    	int c=0;
        for(auto it:co[pts[i]])
    		t[c++]=it;
    	for(auto it:co[pts[i+1]])
    		t[c++]=it;
    	char *s=&loc[pts[i]][0];
    	outtextxy(t[0]-30,t[1],s);
    	sleep(1);
    	line(t[0],t[1],t[2],t[3]);
	}
	char *s=&loc[pts[i]][0];
	outtextxy(t[2]-30,t[3],s);
//	getch();
}

int main()
{

    File f;
    
    // Graph input
    int n,m,i;
    string nm;
    getline(f.graph_file,nm);
    for(i=0;i<nm.length();i++)
        if(nm[i]==' ')
            break;
    n=stoi(nm.substr(0,i));
    m=stoi(nm.substr(i+1));
    vector<pair<int,int>> adj[n+1];

    for(i=0;i<m;i++)
    {
        int u,v,w,b1,b2,k=0;
        getline(f.graph_file,nm);
        for(int j=0;j<nm.length();j++)
            if(nm[j]==' ' && k==0)
            b1=j,k++;
            else if(nm[j]==' ' && k==1)
            {
                b2=j;
                break;
            }
                
        u=stoi(nm.substr(0,b1));
        v=stoi(nm.substr(b1+1,b2-b1+1));
        w=stoi(nm.substr(b2+1));

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    // Declarations
    
    string s;
	vector<pair<int,string>> places;
	map<int,string> loc;
    map<string,string> direction;
    
    while(getline(f.myfile,s)){
	        int i;
	
	        for(i=0;i<s.length();i++)
	            if(s[i]==' ')
	                break;
	
	        string no=s.substr(0,i);
	        string name=s.substr(i);
	
	        int x=stoi(no);
	        places.push_back({x,name});
	        loc[x]=name;
	}
	
	while(getline(f.myfile1,s)){
	        int i;
	        for(i=0;i<s.length();i++)
	            if(s[i]==' ')
	                break;
	
	        string edge=s.substr(0,i);
	        string dir=s.substr(i+1);
	        direction[edge]=dir;
	
	}
	
    while(1)
    {
    	menu(loc);
    	// Accepting source and destination
	    int source,destination;
	    while(1)
	    {
		    cout<<"\n  Enter Source and Destination: ";
		    cin>>source>>destination;
		    
		    try{
		    	if(source<=0 || source>=17 || destination<=0 || destination>=17)
		    		throw -1;
		    	else
		    		break;
			}
			catch(int)
			{
				cout<<"\nEnter proper Source and Destination \n";
			}
		}
		if(source!=destination){
		    vector<int> path=getpath(adj,n,m,source,destination);
		    vector<string> final_path;
		    for(i=0;i<path.size()-1;i++)
		    {
		        string temp;
		        temp=temp+to_string(path[i])+"-"+to_string(path[i+1]);
		        final_path.push_back(temp);
		    }    
		
		    vector<string> route;
		    map<char,string> cmd;
		    for(auto i:final_path)
		    {
		        route.push_back(direction[i]);
		    }
		
		    cmd['L']="Take Left ";
		    cmd['R']="Take Right ";
		    cmd['O']="Turn Around ";
		    cmd['S']="Head Straight ";
		
		    //Printing final path
		    cout<<"\n  Directions : ( Always face the building and then follow the directions )\n\n";
		    int c=1;
		    for(i=0;i<path.size()-1;i++)
		    {
		        cout<<"\t"<<c++<<". From"<<loc[path[i]]<<" ";
		        if(route[i].length()==1)
		        {
		        	cout<<cmd[route[i][0]]<<"towards"<<loc[path[i+1]]<<endl;
				}
				else
				{
			        for(int j=0;j<route[i].length();j++)
			        {
			            if(j!=route[i].length()-1)
			            cout<<cmd[route[i][j]]<<endl;
			            else
			                cout<<"\t"<<c++<<". "<<cmd[route[i][j]]<<"towards"<<loc[path[i+1]]<<endl;
			        }
				}
		    }
		    cout<<"\t"<<c++<<". You have arrived at"<<loc[path[path.size()-1]]<<endl;
		    initwindow(750,800,"Graph");
		    printpath(path,loc);
		    
		}
		else{
			cout<<"\n\tYou are already at the Destination\n";
		}
	    
	    // While condition
	    string condition="yes";
	    int flag=0;
	    
	    while(1)
	    {
	    	cout<<"\n  Do you want to continue(YES/NO) : ";
		    cin>>condition;
		    transform(condition.begin(),condition.end(),condition.begin(),::tolower);
		    if(condition=="no")
			{
				cout<<"\n\n\t\tThank you!!\n\n";
				flag++;
				break;	
			}
			else if(condition=="yes")
			break;
		}
		if(flag==1)
		break;
		else
			system("cls");
			
	}
	   
}