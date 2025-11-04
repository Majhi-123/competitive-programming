int par[100002];
int sz[100002];
void make(int temp){
    par[temp] =temp;
    sz[temp] = 1;
}

int findpar(int temp){
    if(par[temp]!=temp){
        
        return par[temp] = findpar(par[temp]);
    }

    return par[temp] ;
}

void add(int x,int y){
    x = findpar(x);
    y = findpar(y);

    if(x==y){
        return;
    }

    if(sz[x]>sz[y]){
        swap(x,y);
    }

    par[x] = y;
    sz[y] += sz[x];
}
