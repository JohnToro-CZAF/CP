#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int l = 1;
    int r = n;
    while(l != r){
        int t1, t2;
        printf("? %d %d \n", l, r);
        fflush(stdout);
        scanf("%d", &t1);
        int mid = (l+r+1)/2;
        if(mid == r){
            if(t1 == r){
                break;
            } else {
                l = r;
                break;
            }
        }
        if(mid >= t1){
            printf("? %d %d \n", l, mid);
            fflush(stdout);
            scanf("%d", &t2);
            if(t2 == t1){
                r = mid;
            } else {
                l = mid;
            }
            continue;
        } else {
            printf("? %d %d \n", mid, r);
            fflush(stdout);
            scanf("%d", &t2);
            if(t2 == t1){
                l = mid;
            } else {
                r = mid;
            }
            continue;
        }
    }
    printf("! %d", l);
    fflush(stdout);
}