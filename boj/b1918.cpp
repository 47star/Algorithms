#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

char infix[100], *d, t = 0, np = 100;

bool fuck(char f, char l) {
    if (infix[f++] == '(' && infix[l--] == ')') {
        char a = 0;
        for (char i = f; i < l; i++) {
            if (infix[i] == '(')
                a++;
            else if (infix[i] == ')')
                a--;
            if (a < 0) {
                return false;
            }
        }
        return true;
    }
    return false;
}

void yeah(char f, char l) {
    if (f < 0 || np <= l || l < f)
        return;

    if (f == l) {
        d[t++] = infix[f];
        return;
    }

    if (fuck(f, l))
        return yeah(f + 1, l - 1);
    
    char i, lat = l, p = 0;

    for (i = l; f <= i; i--) {
        if (infix[i] == '(')
            p++;
        else if (infix[i] == ')')
            p--;
        else if (p == 0 && (infix[i] == '+' || infix[i] == '-')) {
            d[t++] = infix[i];
            if (i + 1 == lat)
                d[t++] = infix[lat];
            else
                yeah(i + 1, lat);
            lat = i - 1;
        }
    }

    p = 0;

    if (lat == l)
        for (i = l; f <= i; i--) {
            if (infix[i] == '(')
                p++;
            else if (infix[i] == ')')
                p--;
            else if (p == 0 && (infix[i] == '*' || infix[i] == '/')) {
                d[t++] = infix[i];
                if (i + 1 == lat)
                    d[t++] = infix[lat];
                else
                    yeah(i + 1, lat);
                lat = i - 1;
            }
        }

    if (f == lat)
        d[t++] = infix[f];
    else
        yeah(f, lat);
}

int main() {
    char i;
    scanf("%s", &infix);

    for (i = 0; i < 100; i++) {
        if (!infix[i]) {
            np = i;
            break;
        }
    }

    d = (char*)malloc(np * sizeof(char));

    yeah(0, np - 1);

    for (i = t - 1; 0 <= i; i--) {
        printf("%c", d[i]);
    }

    return 0;
}