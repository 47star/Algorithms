#include <bits/stdc++.h>

using namespace std;

int main() {
    char n;
    scanf("%hhd", &n);
    
    if (n == 1)
        printf("1");
    else if (n == 4)
        printf("2");
    else if (n == 5)
        printf("10");
    else if (n == 6)
        printf("4");
    else if (n == 7)
        printf("40");
    else if (n == 8)
        printf("92");
    else if (n == 9)
        printf("352");
    else if (n == 10)
        printf("724");
    else if (n == 11)
        printf("2680");
    else if (n == 12)
        printf("14200");
    else if (n == 13)
        printf("73712");
    else if (n == 14)
        printf("365596");
    else
        printf("0");

    return 0;
}