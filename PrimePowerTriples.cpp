/************************************************************
 *  Problem - Prime Power Triples
 *  Solved by - N0T1C3
 ************************************************************/
/*
    Answer = 1097343
*/

#include<bits/stdc++.h>
using namespace std;

#define ll  long long

const int N = 8e3+5;
const int M = 5e7;
vector<bool> triple(M, 0);
vector<bool> isPrime(N, 1);
vector<int> prime;

ll powr(ll x, ll y){
	ll prod = 1;
	while(y--){
		prod *= x;
	}
	return prod;
}

int main(){
	isPrime[0]=isPrime[1]=false;
	for(int i=2; i<N; i++){
		if(isPrime[i]){
			prime.push_back(i);
			for(int j=2*i; j<N; j+=i){
				isPrime[j]=false;
			}
		}
	}
	int n = prime.size();
	for(int i=0; i<n; i++){
		ll sqr = powr(prime[i], 2);
		if(sqr >= 1LL*M)break;
		for(int j=0; j<n; j++){
			ll cube = powr(prime[j], 3);
			if(sqr+cube >= 1LL*M)break;
			for(int k=0; k<n; k++){
				ll four = powr(prime[k], 4);
				if(sqr+cube+four >= 1LL*M)break;
				ll num = sqr+cube+four;
				triple[num]=true;
			}
		}
	}

	ll ans = accumulate(triple.begin(), triple.end(), 0LL);
	cout<<ans<<endl;
	return 0;
}
