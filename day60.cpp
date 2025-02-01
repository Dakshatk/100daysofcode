#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

void printMedians(vector<int>& branches) {
    priority_queue<int> maxHeap; // Max-heap to store the smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to store the larger half

    for (int i = 0; i < branches.size(); ++i) {
        int branch = branches[i];

        // Insert the new branch into the appropriate heap
        if (maxHeap.empty() || branch < maxHeap.top()) {
            maxHeap.push(branch);
        } else {
            minHeap.push(branch);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // Calculate the median
        if (maxHeap.size() == minHeap.size()) {
            // Even number of elements, median is the average of the two middle elements
            int median = (maxHeap.top() + minHeap.top()) / 2;
            cout << median << " ";
        } else {
            // Odd number of elements, median is the middle element
            cout << maxHeap.top() << " ";
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> branches(N);

        for (int i = 0; i < N; ++i) {
            cin >> branches[i];
        }

        printMedians(branches);
    }

    return 0;
}