// DP
#include <ioStream>

const int N_MAX = 1000, M_MAX = 1000;

int N, M;
char S[N_MAX], T[M_MAX];
int DP[N_MAX+1][M_MAX+1];

void solve(){

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(S[i] == T[j]){
				DP[i+1][j+1] = DP[i][j]+1;
			} else{
				DP[i+1][j+1] = std::max(DP[i][j+1], DP[i+1][j]);
			}

		}
	}

	std::cout << DP[N][M] << '\n';
}
int main(){

	std::cin >> N >> M;
	std::cin >> S;
	std::cin >> T;

	solve();
}