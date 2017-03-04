#include <iostream>
#include <queue>

const int INF = 100000000;
const int N_MAX = 100, M_MAX = 100;

int N,M;
char field[M_MAX][N_MAX];

// to save shortest distances from start
int d[M_MAX][N_MAX];

// start point (x,y)
int sx, sy;
// goal point (x,y)
int gx, gy;

// vector for 4 direction
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

typedef std::pair<int, int> P;

// breath-first search :　幅優先探索
int bfs(){

	std::queue<P> que;

	for( int y=0; y<N; y++)
		for( int x=0; x<M; x++)	d[x][y] = INF;
	
	// push start pos into que
	que.push(P(sx, sy));
	d[sx][sy] = 0;	// set start pos d = 0

	// if que is empty. it'll finish
	while(que.size()){

		P p = que.front(); que.pop();

		if (p.first == gx && p.second == gy) break;

		for (int i=0; i<4; i++){
			
			int nx = p.first + dx[i], ny = p.second + dy[i];

			if (nx>=0 && nx<M && ny>=0 && ny<N && field[nx][ny]!='#' && d[nx][ny]==INF){

				que.push(P(nx,ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}

	}
	return d[gx][gy];

}

int main(){

	std::cin >> N >> M;

	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			std::cin >> field[x][y];
			if( field[x][y]== 'S'){
				sx = x;
				sy = y;	
			}else if(field[x][y] == 'G'){
				gx = x;
				gy = y;
			}
		}
	}
	std::cout << bfs() << "\n";
}


