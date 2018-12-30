#include <bits/stdc++.h>

using namespace std;
const int maxN = 3001;

long N;
vector<int> adj[maxN];
int color[maxN];

int Check(string inp, string out, string ans) {
    // ans --> hoc sinh
    // out --> me
    FILE *fileInput = fopen(inp.c_str(), "r");
    FILE *fileOut = fopen(out.c_str(), "r");
    FILE *fileAns = fopen(ans.c_str(), "r");
    
    int testCase = 0;
    int myAns = 0, yourAns;
    int isOk = 1;
    int u, v;
    
    fscanf(fileInput, "%d %d", &N, &testCase);

    for (int i=1; i<=N; i++) {

    	fscanf(fileInput, "%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
    }
    
    while (testCase-- > 0) {
        for (int i=1; i<=N; i++) {
        	int c;
        	fscanf(fileInput, "%d", &c);
        	color[i] = c;
        }
        
        // Get my ans
        fscanf(fileOut, "%d", &myAns);
        for (int i=1; i<=myAns; i++) {
        	int c;
        	fscanf(fileOut, "%d", &c);
        }
        
        // Get your ans
        if (fscanf(fileAns, "%d", &yourAns) != 1) {
        	isOk = 0;
        	break;
        }

        if (myAns == -1) {
        	if (yourAns != -1) {
        		isOk = 0;
        		break;
        	}
        }
        else {
        	if (yourAns == -1) {
        		isOk = 0;
        		break;
        	}

        	for (int i=1; i <= yourAns; i++) {
        		if (fscanf(fileAns, "%d", &u) != 1) {
        			isOk = 0;
        			break;
        		}
        		
        		if (isOk == 0) break;
        		
        		if ((u<1)||(u>N)) {
        			isOk = 0;
        			break;
        		}

        		color[u] = 1 - color[u];
        		for (int j=0; j < adj[u].size(); j++) {
        			v = adj[u][j];
        			color[v] = 1 - color[v];
        			
        		}
        	}

        	for (int j=1; j <= N; j++) 
        		if (color[j] != 1) {
        			isOk = 0;
        			break;
        		}

        	if (isOk == 0) break;

        }

    }
    
    fclose(fileInput);
    fclose(fileOut);
    fclose(fileAns);
    
    return isOk;
}

int main(int argc, const char * argv[]) {
    // Read Input
    
    //string inp(argv[1]);
    //string out(argv[2]);
    //string ans(argv[3]);
    string spath;
    getline(cin,spath);
    string inp = spath + "LAMPS2.INP";
    string out = spath + "LAMPS2.OUT";
    getline(cin,spath);
    string ans = spath + "LAMPS2.OUT";
    
    int result = Check(inp, out, ans);
    
    if (result == 1) {
        cerr << "DUNG" << endl;
		cout << "1.0" << endl;
	}
    else
        {
        cerr << "SAI" << endl;
		cout << "0.0" << endl;
	}

}
