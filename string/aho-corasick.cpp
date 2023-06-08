#include <bits/stdc++.h>

using namespace std;

struct Trie{
    Trie *child[26];
    Trie *fail;
    string p;
    bool isEnd;
    
    Trie(){
        fill(child, child+26, nullptr);
        fail = nullptr;
        isEnd = false;
    }
    
    ~Trie(){
        for(int i = 0; i < 26; i++) 
            if(child[i]) delete child[i];
    }
    
    void insert(string key){
        Trie* cur = this;
        int m = key.length();
        for(int i = 0; i < m; i++){
            if(!cur->child[key[i]-'a'])
                cur->child[key[i]-'a'] = new Trie;
            cur = cur->child[key[i]-'a'];
            
            if(i == m-1){
                cur->p = key;
                cur->isEnd = true;
            }
        }
    }
    
    void failure(){
        Trie* root = this;
        queue<Trie*> q;
        q.push(root);
        
        while(!q.empty()){
            Trie* cur = q.front();
            q.pop();
            
            for(int i = 0; i < 26; i++){
                Trie* next = cur->child[i];
                if(!next) continue;
                
                if(cur == root) next->fail = root;
                else {
                    Trie* prev = cur->fail;
                    
                    while(prev != root && !prev->child[i])
                        prev = prev->fail;
                    
                    if(prev->child[i]) 
                        prev = prev->child[i];
                    
                    next->fail = prev;
                }
                
                if(next->fail->isEnd) next->isEnd = true;
                
                q.push(next);
            }
        }
    }
    
    vector<pair<string, int>> aho_corasick(string s){
        Trie* cur = this;
        vector<pair<string, int>> result;
        for(int i = 0; i < s.length(); i++){
            while(cur != this && !cur->child[s[i]-'a']) 
                cur = cur->fail;
            if(cur->child[s[i]-'a']) 
                cur = cur->child[s[i]-'a'];
            if(cur->isEnd)
                result.push_back({cur->p, i});
        }
        
        return result;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    string s;
    cin>>n;
    Trie* root = new Trie;
    for(int i = 0; i < n; i++){
        cin>>s;
        root->insert(s);
    }
    
    root->failure();
    
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>s;
         auto aho = root->aho_corasick(s);
         if(aho.size() > 0) cout<<"YES\n";
         else cout<<"NO\n";
    }

    return 0;
}
