#include <bits/stdc++.h>

namespace DataStructure {
using namespace std;

template <class T>
struct dynamic_heap {
    T summax, summin;
    priority_queue<T> heapmax;
    priority_queue<T, vector<T>, greater<T>> heapmin;

    void clear_heaps() {
        summax = summin = 0;
        while (!heapmax.empty()) heapmax.pop();
        while (!heapmin.empty()) heapmin.pop();
    }

    T get_median(T x) {
        if (heapmax.empty() && heapmin.empty()) {
            heapmax.push(x);
            summax += x;
            return x;
        }

        T median = heapmax.size() >= heapmin.size() ? heapmax.top() : heapmin.top();
        if (x < median)
            heapmax.push(x), summax += x;
        else
            heapmin.push(x), summin += x;
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
}  // namespace DataStructure