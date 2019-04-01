#include <string>
#include <iostream>

#define F
#ifdef F
#include <fstream>
#endif

using namespace std;
#define rep(i,s,e) for(int i = s;i<e;i++)

int n;

struct Node{
	int a,h;
};

Node m[2][8];

int s[2];

int player = 0;   //0 号先手
int	result = 0;

void insert(int p,int h,int a){
	for(int i = s[player]-p+1;i >= p ;i--){
		m[player][i+1] = m[player][i];
	}
	m[player][p].h = h;
	m[player][p].a = a; 
	s[player]++;
}

void del(int player,int p){
	for(int i = p+1;i <= s[player]-p+1 ;i++){
		m[player][i-1] = m[player][i];
	}
	s[player]--;
}



int main(){
	ios::sync_with_stdio(false);
#ifdef F
	ifstream fin("T2016093.in");
	cin.rdbuf(fin.rdbuf());
#endif

	cin >> n;
	m[0][0].a = 0;
	m[0][0].h = 30;
	m[1][0].a = 0;
	m[1][0].h = 30;
	string action;
	int p,h,a,attacker,defender;
	rep(i,0,n){
		cin >> action;
		if(action == "summon"){
			cin >> p >> a >>h;
			insert(p,h,a);
		}else if(action == "attack"){
			cin >> attacker >> defender;
			m[player][attacker].h -= m[1-player][defender].a;
			m[1-player][defender].h -= m[player][attacker].a;
			if(defender == 0 && m[1-player][0].h < 0){
				result = player == 0?1:-1;
				break;
			}
			if(m[player][attacker].h <= 0)
				del(player,attacker);
			if(m[1-player][defender].h <= 0)
				del(1-player,defender);
			
		} else{
			player = 1 - player;
		}				
	}
	cout << result << endl;
	cout << m[0][0].h << endl;
	cout << s[0];
	for(int i = 1;i<=s[0];i++){
		cout << " "<<m[0][i].h;
	}
	cout << endl;
	cout << m[1][0].h << endl;
	cout << s[1];
	for(int i = 1;i<=s[1];i++){
		cout << " "<<m[1][i].h;
	}
	return 0;
}
