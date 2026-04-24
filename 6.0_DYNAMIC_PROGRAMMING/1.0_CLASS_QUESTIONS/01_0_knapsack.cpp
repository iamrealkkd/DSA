#include <bits/stdc++.h>
using namespace std;

int t[102][1002];

int knapsack(int wt[], int val[], int W, int n) {
  // Base case
  if (n == 0 || W == 0)
    return 0;

  // Check if already computed
  if (t[n][W] != -1)
    return t[n][W];

  // Choice diagram
  if (wt[n - 1] <= W) {
    return t[n][W] = max(
               val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), // include
               knapsack(wt, val, W, n - 1)                           // exclude
           );
  } else {
    return t[n][W] = knapsack(wt, val, W, n - 1);
  }
}

int main() {
  int wt[] = {1, 3, 4, 5};
  int val[] = {1, 4, 5, 7};
  int W = 7;
  int n = 4;

  memset(t, -1, sizeof(t)); // initialize with -1

  cout << knapsack(wt, val, W, n);
}

/*
    0/1 Knapsack Problem (Recursion)

    Given:
    wt[]  -> weights of items
    val[] -> values of items
    W     -> capacity of knapsack
    n     -> number of items

    Goal:
    Maximize total value such that total weight <= W

    Approach:
    For every item, we have 2 choices:
    1. Include the item (if it fits)
    2. Exclude the item

    We take maximum of both choices.

    Time Complexity: O(2^n)  -> exponential (2 choices per item)
    Space Complexity: O(n)   -> recursion stack depth

int knapsack(int wt[], int val[], int W, int n) {

  // Base Case:
  // If no items left OR capacity is 0, profit = 0
  if (n == 0 || W == 0)
    return 0;

  // If current item weight is less than or equal to capacity
  if (wt[n - 1] <= W) {

    // Choice 1: Include the item
    // Add its value and reduce capacity
    int include = val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1);

    // Choice 2: Exclude the item
    int exclude = knapsack(wt, val, W, n - 1);

    // Return maximum of both choices
    return max(include, exclude);
  } else {
    // If item is too heavy, we cannot include it
    // So we skip it and move to next item
    return knapsack(wt, val, W, n - 1);
  }
}

int main() {
  // Example input
  int wt[] = {1, 3, 4, 5};  // weights
  int val[] = {1, 4, 5, 7}; // values
  int W = 7;                // capacity
  int n = 4;                // number of items

  // Function call
  cout << knapsack(wt, val, W, n);

  return 0;
}
  */