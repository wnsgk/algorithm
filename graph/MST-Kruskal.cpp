#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int root(vector<int>& parent, int x) 
{
    if (parent[x] == x) return x;
    return parent[x] = root(parent, parent[x]);
}

int union_(vector<int>& parent, int a, int b)  
{
    a = root(parent, a);
    b = root(parent, b);
    if(a == b) return 0;
    if(a < b) return parent[b] = a;
    else return parent[a] = b;
}

bool find(vector<int>& parent, int a, int b)
{
    int par_a = root(parent, a);
    int par_b = root(parent, b);
    if(par_a == par_b) return true;
    else return false;
}

bool compare(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
    int answer = 0;
    int v, e, a, b, c;
    cin>>v>>e;
    vector<vector<int>> costs(e+1, vector<int>(3));
    for(int i = 0; i < e; i++)
    {
        cin>>a>>b>>c;
        costs[i][0] = a;
        costs[i][1] = b;
        costs[i][2] = c;
    }
    sort(costs.begin(), costs.end(), compare);
    
    vector<int> parent(v+1);
    
    for(int i = 1; i < v+1; i++)
        parent[i] = i;
    
    for(int i = 0; i < costs.size(); i++)
    {
        if(union_(parent, costs[i][0], costs[i][1]))
        {
            answer += costs[i][2];
        }
    }
    
    cout<<answer;
    return 0;
}
