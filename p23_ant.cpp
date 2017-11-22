#include<cstdio>
#include<algorithm>
int const N_MAX = 1000000;

int main(){

    int l, n, x[N_MAX];
    scanf("%d %d",&l,&n);
    for(int i=0; i<n; i++){
        scanf("%d", &x[i]);
    }

    int maxT = 0;
    for(int i=0 ; i<n; i++){
        maxT = std::max(maxT, std::max(x[i], l-x[i]));
    }

    int minT = 1000000;
    for(int i=0 ; i<n; i++){
        minT = std::min(minT, std::min(x[i], l-x[i]));
    }

    printf("min = %d\n",minT);
    printf("max = %d\n",maxT);
}
