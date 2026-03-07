
#include <bits/stdc++.h>
using namespace std;
/*
int func(vector<int> &piles, int h, int speed) {
    vector<int> arr = piles;
    int cnt = 0;
    int i = 0;
    while (i < arr.size()) {
        if (arr[i] == 0) {
            i++;
            continue;
        }
        if (arr[i] >= speed) {
            arr[i] -= speed;
        } else {
            arr[i] = 0;
        }
        cnt++;
    }
    return cnt;
}                                                                   //brute force approach (in func, we are simulating each hour by reducing bananas eaten by koko)

int minEatingSpeed(vector<int> &piles, int h) {
    int maximum = *max_element(piles.begin(), piles.end());
    int s = 1;
    int e = maximum;
    int ans = -1;

    while (s <= e) {
        int m = (s + e) / 2;
        int speed = m;
        int time = func(piles, h, speed);

        if (time <= h) {
            ans = speed;
            e = m - 1;  // try smaller speed
        } else {
            s = m + 1;  // need faster eating
        }
    }
    return ans;
}
*/

int func(vector<int> &piles, int h, int speed) {
    int totalHours = 0;
    for (int pile : piles) {
        totalHours += (pile + speed - 1) / speed;
        if (totalHours > h) return totalHours;
    }
    return totalHours;
}

int minEatingSpeed(vector<int> &piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (func(piles, h, mid) <= h) {
            ans = mid;         // try lower speed
            high = mid - 1;
        } else {
            low = mid + 1;     // need more speed
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {11, 3, 7, 6};
    cout << minEatingSpeed(arr, 8);
    return 0;
}
