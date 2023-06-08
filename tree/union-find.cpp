vector<int> v(500001);

int getParent(int x) {
    if (v[x] == x) return x;
    return v[x] = getParent(v[x]);
}

int findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b) return true;
    else return false;
}

void union_(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(b > a) v[a] = b;
    else v[b] = a;
}

//가중법칙 : 노드가 많은 쪽을 root로 하면 O(logn)이 됨.
