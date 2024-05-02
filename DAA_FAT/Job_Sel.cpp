// Job_Selection

#include <iostream>
#include <climits>
using namespace std;

#define N 4

int costMatrix[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

int minCost = INT_MAX;

bool assigned[N];
int assignment[N];

void calculateCost(int worker, int costSoFar) {
    if (worker == N) {
        minCost = min(minCost, costSoFar);
        return;
    }

    for (int job = 0; job < N; job++) {
        if (!assigned[job]) {
            assigned[job] = true;
            assignment[worker] = job;
            calculateCost(worker + 1, costSoFar + costMatrix[worker][job]);
            assigned[job] = false;
        }
    }
}

int main() {
    calculateCost(0, 0);
    
    cout << "Minimum cost for job assignment: " << minCost << endl;

    return 0;
}
