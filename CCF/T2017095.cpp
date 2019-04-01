/*
 * 区间更新 区间求和 用线段树 实现更好
 *
 */
#include <iostream>

#define rep(i,s,e) for(int i = s;i<e;i++)
#define lowbit(i) -(i)&(i)

using namespace std;

const int maxN = 100001;

int n;
int m;
long long tree[maxN];
int a[maxN];

void update(int i,int val){
	while(i<=n){
		tree[i] += val;
		i += lowbit(i);
	}
}

long long getsum(int i){
	long long sum = 0;
	while(i>0){
		sum += tree[i];
		i -= lowbit(i);
	}
	return sum;
}


int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int t;
	fill(tree,tree+n,0);
	a[0] = 0;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		update(i,a[i]);
	}
	int l, r,v;
	rep(i,0,m){
		cin >> t >> l >> r;
		if(t == 2) {
			cout << getsum(r) - getsum(l-1)<<endl;
		}else{
			//更新
			cin >> v;
			if(v == 1) continue;
			for(int j = l;j <= r;j++){
				if(a[j] >= v && a[j] % v == 0){
					update(j,-(a[j]-a[j]/v));
					a[j] /= v;
				}
			}
		} 
	}
	return 0;
}

