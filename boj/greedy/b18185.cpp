#include <stdio.h>
#include <algorithm>

using namespace std;
    
int main()
{
    int n, i, v[10050], m, c = 0;

    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    for (i = 0; i < n; i++) {
        if (v[i + 2] < v[i + 1]) {
            m = min(v[i], v[i + 1] - v[i + 2]);
            c += m * 5;
            v[i] -= m;
            v[i + 1] -= m;
            
            m = min(v[i], min(v[i + 1], v[i + 2]));
            c += m * 7;
            v[i] -= m;
            v[i + 1] -= m;
            v[i + 2] -= m;
        } else {
            m = min(v[i], min(v[i + 1], v[i + 2]));
            c += m * 7;
            v[i] -= m;
            v[i + 1] -= m;
            v[i + 2] -= m;
            
            m = min(v[i], v[i + 1]);
            c += m * 5;
            v[i] -= m;
            v[i + 1] -= m;
        }
        
        c += v[i] * 3;
    }
    
    printf("%d", c);

    return 0;
}
