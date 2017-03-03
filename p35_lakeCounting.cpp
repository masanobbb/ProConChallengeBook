#include <iostream>

int const N_MAX = 100, M_MAX =100;
int n,m;
char field[N_MAX][M_MAX];

void printField(){
	std::cout << "------------------------------" << std::endl;
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			printf("%c", 'a');
		}
		std::cout << std::endl;
	}
	return ;
}

void dfs(int y, int x){

	field[y][x] = '.';

	for(int dy=-1; dy<=1; dy++){
		for(int dx=-1; dx<=1; dx++){
			int ny=y+dy, nx=x+dx;
			if(0<=ny && 0<=nx && ny<n && nx<m && field[ny][nx]=='w'){
				printf("wow\n");
				dfs(ny, nx);
			}
		}
	}
	return ;
}



int main(){

	// I defined n,m here again although they are global var, 
	// so it coused a problem...
	std::cin >> n;
	std::cin >> m;

	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			std::cin >> field[y][x];
			//scanf("%c",&(field[y][x]));
			printf("%c",field[y][x]);
		}
	}

	int ans = 0;
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			if(field[y][x] == 'w'){
				ans += 1;
				dfs(y,x);
			}			
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
