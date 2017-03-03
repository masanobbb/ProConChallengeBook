#include<cstdio>

int const N_MAX = 100;

int max(int a, int b);

int main(){

    int n, k[N_MAX];
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d", &k[i]);
    }

    int a, b, c;
    int ans=0;

    //棒を重複して選ばないようにループをずらす
    for(a=0 ;a<n; a++){
        for(b=a+1; b<n; b++){
            for(c=b+1; c<n; c++){

                int len = k[a] + k[b] + k[c];
                int maxk = max(k[a], max(k[b],k[c]));
                int rest = len - maxk;

                if (maxk < rest){
                    ans = max(ans, len);
                }
            }
        }
    }

    printf("%d\n",ans);
}

int max(int a, int b){

    if(a>b) return a;
    else return b;
}
