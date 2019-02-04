/**
Algorithm:
Floyd Warshall's all pairs shortest distance
and then brute force backtracking

Gotchas:
- There can be multiple edges between two stores
- Daniel can don't buy one or more operas (in that case, he won't save for
  those operas)
- The same store can sell more than one opera.
- Don't use doubles for prices. Convert prices to cents by multiplying by
  100, add Epsilon and then round to integer.
*/
#include<stdio.h>
#include<string.h>

int cost[52][52]; // min cost[i][j] between store i and j in terms of cents
int n;        // # total stores 
int nn;       // # stores that actually sell opera
int save[52]; // amount saved by visiting node i
int totalsave; // total amount that can be saved from all stores

inline int min(int a,int b){return a<b?a:b;}

#define MAX (0x7fffffff/2)

// floyd warshall
void doit(){
    int i,j,k;
    for (i=0;i <=n;i++){
        for (j= 0; j <= n;j++){
            for (k=0; k<=n;k++){
                int g = cost[j][i]+cost[i][k];
                cost[j][k] = min( cost[j][k], g);
            }
        }
    }
}

int maxsave; // in cents
char used[52];

void find(int cur, int sumsave, int sumcost, int k){
    // basic pruning
    if (totalsave - sumcost <= maxsave) return;

    // what if this guy returns back home now?
     if (cost[cur][0] < MAX) {
        int newcost =sumcost+ cost[cur][0];
        int netsave = sumsave-newcost;
        if (netsave>maxsave) maxsave = netsave;
    }

    if (k==nn){ // visited all stores
        return;
    }

    int i,j;
    for (i=1; i<=n;i++){
        if(used[i] || cost[cur][i]>=MAX) continue;
        used[i]=1;
        find (i, sumsave+save[i], sumcost+cost[cur][i], k+1);
        used[i]=0;
    }
}

int main(){
    int nu;scanf("%d", &nu);
    while (nu--){ int m; int i,j;
        scanf("%d%d", &n, &m);
        for (i=0;i<=n;i++) for (j=0;j<=n;j++) cost[i][j]=MAX;
        for (i=0;i<m;i++){
            double dd; int a,b;
            scanf("%d%d%lf", & a, & b, & dd);

            int kk =(int)(dd*100+.1);
            if (kk< cost[a][b] )  cost[a][b] = cost[b][a] = kk;
        }
        int pp;
        scanf ("%d", &pp);
        memset(used, 1,sizeof(used)); totalsave = 0;
        nn=0;
        memset(save,0,sizeof(save));
        for (j=0;j<pp;j++){ int a; double dd;
            scanf("%d%lf", &a, &dd);
            nn++;
            save[a] += (int)(dd*100+0.1);used[a]=0;
            totalsave+=save[a];
        }
        doit();
        
        maxsave = 0;
        find(0,0,0,0);
        if (maxsave) printf("Daniel can save $%d.%02d\n",maxsave/100,maxsave%100);
        else printf("Don't leave the house\n");

    }
}

