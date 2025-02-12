#include<stdio.h>
#define gc getchar_unlocked

char mat[20][20];
bool traversed[20][20];
int e[2][2];

void traverse(int i, int j,int n, int m){
	traversed[i][j] = true;
	if(i>0&&mat[i-1][j]=='.'){
		if(!traversed[i-1][j]){
			traverse(i-1,j,n,m);
			if(traversed[e[1][0]][e[1][1]]) return;
		}
	}
	if(j>0&&mat[i][j-1]=='.'){
		if(!traversed[i][j-1]){
			traverse(i,j-1,n,m);
			if(traversed[e[1][0]][e[1][1]]) return;
		}
	}
	if(i<(n-1)&&mat[i+1][j]=='.'){
		if(!traversed[i+1][j]){
			traverse(i+1,j,n,m);
			if(traversed[e[1][0]][e[1][1]]) return;
		}
	}
	if(j<(m-1)&&mat[i][j+1]=='.'){
		if(!traversed[i][j+1]){
			traverse(i,j+1,n,m);
			if(traversed[e[1][0]][e[1][1]]) return;
		}
	}
}

int main(){
	int t,m,n,i,j,invalid,points;
	for(scanf("%d",&t);t--;){
		scanf("%d %d",&n,&m);
		invalid = 0;
		points = 0;
		for(i=0;i<n;i++){
			gc();
			for(j=0;j<m;j++){
				mat[i][j] = gc();
				traversed[i][j] = false;
				if((i==0||j==0||i==(n-1)||j==(m-1))&&(mat[i][j]=='.')){
					if(points>=2) invalid = 1;
					else {e[points][0] = i; e[points][1] = j;}
					points++;
				}
			}
		}
		if(points!=2){
			printf("invalid\n");
			continue;
		}
		traverse(e[0][0],e[0][1],n,m);
		if(traversed[e[1][0]][e[1][1]]){
			printf("valid\n");
		}
		else printf("invalid\n");
	}
	return 0;
}