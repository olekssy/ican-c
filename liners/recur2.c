#include <stdio.h>

long rfact(int k);

int main(void) {
        int n;
        printf("Enter number 0 < n < 12\n");
        scanf("%d", &n);
        printf("%d! = %ld\n", n, rfact(n));
        return 0;
}

long rfact(int k) {
        long ans = 1;
        if (k > 0) {
                ans = k*rfact(k-1);
        }
        else {
                ans = 1;
        }
        return ans;
}
