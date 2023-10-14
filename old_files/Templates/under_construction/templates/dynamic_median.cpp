#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: You have an array A. 
 * Each time you add one extra element to A, 
 * you have to find the minimum value x that minimizes the following identity: 
 * y = sum of |x - A[i]|.
 * One can find that x = the median of A would minimize y.
 * 
 * Idea: We use two heaps to maintain a structure
 * that could give us the median of A in O(logN).
 */
struct DynamicMedian {
    using ll = long long;
    ll summax, summin; // summax = sum of numbers belong to heapmax
    priority_queue<ll> heapmax;
    priority_queue<ll, vector<ll>, greater<ll>> heapmin;
    
    DynamicMedian() {
        clearHeaps();
    }
    
    /**
     * Reset the data structure
     */
    void clearHeaps() {
        summax = summin = 0LL;
        while (!heapmax.empty()) heapmax.pop();
        while (!heapmin.empty()) heapmin.pop();
    }
     
    /**
     * Insert a number
     * 
     * @param x A number to be inserted
     * @return The current median
     */
    int getMedian(ll x) {
        if (heapmax.empty() && heapmin.empty()) {
            heapmax.push(x);
            summax += x;
            return x;
        }
        ll median = heapmax.size() >= heapmin.size() ? heapmax.top() : heapmin.top();
        if (x < median) heapmax.push(x), summax += x;
        else heapmin.push(x), summin += x;
        if (heapmax.size() > heapmin.size() + 1) {
            heapmin.push(heapmax.top());
            summin += heapmax.top();
            summax -= heapmax.top();
            heapmax.pop();
        } else if (heapmin.size() > heapmax.size() + 1) {
            heapmax.push(heapmin.top());
            summax += heapmin.top();
            summin -= heapmin.top();
            heapmin.pop();
        }
        return heapmax.size() >= heapmin.size() ? heapmax.top() : heapmin.top();
    }
};

int main() {
    DynamicMedian DM = DynamicMedian();
    
    DM.getMedian(1);
    DM.getMedian(3);
    cout << DM.getMedian(4) << '\n';
    return 0;
}