//  Copyright © 2019 Kadir Gönül. All rights reserved.
//

#include <stdio.h>

int lcs(int ls1, char s1[ls1], int ls2, char s2[ls2]) {
    int arr[ls1+1][ls2+1];
    for(int i=0;i<ls1+1;i++) {
        arr[0][i] = 0;
    }
    for(int i=0;i<ls2+1;i++) {
        arr[i][0] = 0;
    }
    for(int i=1;i<(ls1+1);i++) {
        for(int j=1;j<(ls2+1);j++) {
            if (s1[i-1] == s2[j-1]) {
                arr[i][j] = arr[i-1][j-1]+1;
            }
            else {
                int max = arr[i-1][j] > arr[i][j-1] ? arr[i-1][j] : arr[i][j-1];
                arr[i][j] = max;
            }
        }
    }
    return arr[ls1][ls2];
}

int main(int argc, const char * argv[]) {
    char s1[] = "agcat";
    char s2[] = "gac";
    int x = lcs(5, s1, 3, s2);
    printf("val: %d\n", x);
    return 0;
}
