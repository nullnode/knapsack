#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int MAX(int a, int b) { return (a > b) ? a : b; }

int knapsack(int W, int weight[], int value[], int n, int s[])
{

	/* m[i][w] to be the maximum value that can be attained
	   with weight less than or equal to w using items up to i*/

	vector<vector<int> > m(n + 1, vector<int>(W + 1, 0));  	// m[n+1][W+1]

	for (int jw = 0; jw <= W; jw++) m[0][jw] = 0;

	for (int i = 1; i <= n; i++) {
		for (int jw = 0; jw <= W; jw++) {

			// A case when the new item is more than the current weight limit
			if (weight[i - 1] > jw)
				m[i][jw] = m[i - 1][jw];

			// A case for weight[i] < jw
			else {
				m[i][jw] = MAX(m[i - 1][jw], value[i - 1] + m[i - 1][jw - weight[i - 1]]);
				s[jw] = i;
			}
		}
	}
	return m[n][W];
}

int main()
{
	int weight[] = { 1, 2, 2, 3 };
	int value[] = { 10, 12, 15, 20 };
	int  wLimit = 5;
	int *s = new int[51];

	cout << "Max value: ";
	cout << knapsack(wLimit, weight, value, 3, s) << endl;  // $220

	int k = wLimit;
	cout << "weight used: ";
	while (k) {
		cout << weight[s[k] - 1] << " ";
		k = k - weight[s[k] - 1];
	}
	return 0;
}