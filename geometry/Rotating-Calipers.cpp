#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct pos{
    ll x, y;
};

pos v[100001];

ll dist(pos a, pos b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

ll ccw(pos a, pos m, pos b){ // 2: 180미만, 0 : 180, -2 : 180 이상
    ll t = (a.x - m.x)*(b.y - m.y) - (a.y - m.y)*(b.x - m.x);
    return (t<0) - (t>0);
}

ll ccw2(pos a, pos b, pos c, pos d){
    d.x -= c.x - a.x;
    d.y -= c.y - a.y;
    return ccw(b, a, d);
}

bool cmp1(pos a, pos b) {
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool cmp(pos x, pos y) {
   ll cw = ccw(x, v[0], y);
   if (cw == 0) return dist(v[0], x) < dist(v[0], y);
   return cw > 0;
}

ll calipers(vector<pos>& p){
    ll mx = 0;
    int c = 1;
    int n = p.size();
    pos s, e;
    for(int a = 0; a < n; a++){
        while((c+1) != a && ccw2(p[a], p[a+1], p[c%n], p[(c+1)%n]) > 0){
            if(mx < dist(p[a], p[c%n])){
                s = p[a];
                e = p[c%n];
                mx = dist(p[a], p[c%n]);
            }
            c++;
        }
        if(mx < dist(p[a], p[c%n])){
            s = p[a];
            e = p[c%n];
            mx = dist(p[a], p[c%n]);
        }
    }
    
    return mx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>v[i].x>>v[i].y;
    }
    sort(v, v+n, cmp1);
    sort(v+1, v+n, cmp);
    
    vector<pos> hull;
    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 && ccw(hull.back(), hull[hull.size() - 2], v[i]) <= 0) {
          hull.pop_back();
        }
        hull.push_back(v[i]);
    }
    cout.precision(10);
    if(hull.size() == 2) cout<<sqrt(dist(hull[0], hull[1]));
    else cout<<sqrt(calipers(hull));
    
    return 0;
}
