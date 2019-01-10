#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
// CCO '16 P2 - Splitting Hares

using namespace std;

pair<pair<int,int>,int> bunnies[4001];
vector<pair<double,int>> toLeft,toRight;

double slope(double x1,double y1,double x2,double y2)
{
    return ((y1 - y2) / (x1 - x2));
}

double equalTo(double a,double b)
{
    return ((abs(a - b) < 1e-13));
}

int main()
{
    int N,i,j,k,onlineSum,x,y,leftSum,rightSum,maxSum,fromLeft,fromRight;
    double sl;
    freopen("hares.inp", "r", stdin);
    freopen("hares.out", "w", stdout);

    // Read the number of bunnies
    scanf("%d\n",&N);

    // Read the location and goodness of each bunny
    for (i = 0;i < N;i++)
        scanf("%d %d %d\n",&bunnies[i].first.first,&bunnies[i].first.second,&bunnies[i].second);

    // Sort the bunnies by x,y, then w
    sort(bunnies,bunnies + N);

    // Process lines that pass through each point
    maxSum = 0;
    for (i = 0;i < N;i++) {
        x = bunnies[i].first.first; y = bunnies[i].first.second;
        leftSum = 0; rightSum = 0;
        toLeft.clear(); toRight.clear();

        // Sort the points around point i, according to slope
        fromLeft = 0; fromRight = 0;
        for (j = 0;j < N;j++) {
            if (bunnies[j].first.first < x) {
                toLeft.push_back({slope(bunnies[j].first.first,bunnies[j].first.second,x,y),j});
                leftSum += bunnies[j].second;
            }
            else if (bunnies[j].first.first > x) {
                toRight.push_back({slope(bunnies[j].first.first,bunnies[j].first.second,x,y),j});
                rightSum += bunnies[j].second;
            }
            else {
                if (bunnies[j].first.second > y)
                    fromLeft += bunnies[j].second;
                else if (bunnies[j].first.second < y)
                    fromRight += bunnies[j].second;
            }
        }
        sort(toLeft.begin(),toLeft.end());
        sort(toRight.begin(),toRight.end());

        // First consider the points that are in the same verticle line; update the maxSum
        onlineSum = max(max(fromLeft,fromRight) + max(bunnies[i].second,0),fromLeft + fromRight + bunnies[i].second);
        maxSum = max(maxSum,max(onlineSum,0) + max(leftSum,rightSum));

        // Try other lines formed by point i and another point
        j = 0; k = 0; leftSum += fromRight; rightSum += fromLeft;
        while (j < toLeft.size() && k < toRight.size()) {
            sl = min(toLeft[j].first,toRight[k].first);
            fromLeft = 0; fromRight = 0;
            while (j < toLeft.size() && equalTo(toLeft[j].first,sl)) {
                leftSum -= bunnies[toLeft[j].second].second;
                fromLeft += bunnies[toLeft[j].second].second;
                j++;
            }
            while (k < toRight.size() && equalTo(toRight[k].first,sl)) {
                rightSum -= bunnies[toRight[k].second].second;
                fromRight += bunnies[toRight[k].second].second;
                k++;
            }
            onlineSum = max(max(fromLeft,fromRight) + max(bunnies[i].second,0),fromLeft + fromRight + bunnies[i].second);
            maxSum = max(maxSum,max(onlineSum,0) + max(leftSum,rightSum));
            leftSum += fromRight; rightSum += fromLeft;
        }
        while (j < toLeft.size()) {
            sl = toLeft[j].first;
            fromLeft = 0;
            while (j < toLeft.size() && equalTo(toLeft[j].first,sl)) {
                leftSum -= bunnies[toLeft[j].second].second;
                fromLeft += bunnies[toLeft[j].second].second;
                j++;
            }
            onlineSum = max(fromLeft,0) + max(bunnies[i].second,0);
            maxSum = max(maxSum,onlineSum + max(leftSum,rightSum));
            rightSum += fromLeft;
        }
        while (k < toRight.size()) {
            sl = toRight[k].first;
            fromRight = 0;
            while (k < toRight.size() && equalTo(toRight[k].first,sl)) {
                rightSum -= bunnies[toRight[k].second].second;
                fromRight += bunnies[toRight[k].second].second;
                k++;
            }
            onlineSum = max(fromRight,0) + max(0,bunnies[i].second);
            maxSum = max(maxSum,onlineSum + max(leftSum,rightSum));
            leftSum += fromRight;
        }
    }

    // Output
    printf("%d\n",maxSum);

    // Return
    return 0;
}