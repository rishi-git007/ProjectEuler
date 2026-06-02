/************************************************************
 *  Problem - Cubic Permutations
 *  Solved by - N0T1C3
 ************************************************************/
/*
    Answer = 127035954683
*/

#include<bits/stdc++.h>
using namespace std;

#define ll  long long

const int N = 1e6;

int main(){
	vector<vector<int>> v(N);
	multiset<vector<int>> s;
	for(int i=1; i<N; i++){
		ll temp = 1LL*i*i*i;
		vector<int> cnt(10, 0);
		while(temp){
			int rem = temp%10;
			cnt[rem]++;
			temp /= 10;
		}
		v[i] = cnt;
		s.insert(cnt);
	}
	set<vector<int>> needed;
	int digits=20;
	for(auto &vec : s){
		int cnt = s.count(vec);
		if(cnt==5){
			int digcnt=0;
			for(int i=0; i<10; i++){
				digcnt += vec[i];
			}
			if(digcnt < digits){
				digits = digcnt;
			}
		}
	}
	for(auto &vec : s){
		int cnt = s.count(vec);
		if(cnt==5){
			int digcnt=0;
			for(int i=0; i<10; i++){
				digcnt += vec[i];
			}
			if(digcnt==digits){
				needed.insert(vec);
			}
		}
	}
	ll ans = LLONG_MAX;
	for(int i=1; i<N; i++){
		vector<int> cnt = v[i];
		for(auto & vec : needed){
			bool flag = true;
			for(int j=0; j<10; j++){
				if(cnt[j]!=vec[j]){
					flag = false;
					break;
				}

			}
			if(flag){
				ans = min(ans, 1LL*i*i*i);
			}
		}
	}
	cout<<ans<<endl;

}
