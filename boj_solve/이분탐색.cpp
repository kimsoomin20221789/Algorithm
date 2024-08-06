#include <bits/stdc++.h>
using namespace std;

int a[100000];
int n;
int binarysearch(int target){
    int st = 0;
    int end = n-1;
    while (st<=end){
        int mid = (st+end)/2;
        if (a[mid] < target){
            st = mid + 1;
        } else if (a[mid] > target){
            end = mid - 1;
        }
        else return 1;
    }
    return 0;
}

int lower_idx(int target, int len){
    int st = 0;
    int end = len;
    while (st < end){
        int mid = (st+end) /2;
        if (a[mid] >= target) end = mid;
        else {st = mid+1;}
    }
}

int upper_idx(int target, int len){
    int st = 0;
    int end = len;
    while (st < end){
        int mid = (st+end) /2;
        if (a[mid] > target) end = mid;
        else {st = mid+1;}
    }
}