/************************************************************
 *  Problem - 2025
 *  Solved by - N0T1C3
 ************************************************************/
/*
    Brute Force :(
    Answer = 72673459417881349
*/

#include<bits/stdc++.h>
using namespace std;

#define ll  long long

ll powr(ll x, ll y){
	ll prod = 1;
	while(y--){
		prod *= x;
	}
	return prod;
}
int main(){
	int lim = sqrt(1e17)+5;
	ll ans = 0;
	for(int i=1; i<lim; i++){
		ll a = i;
		ll cnt=0;
		while(a){
			a/=10;
			cnt++;
		}
		a = i;
		if(a*a >= 1e17)break;
		for(int j=cnt-1; j<=cnt+1; j++){
			if(j==0)continue;
			ll D = 4*powr(10, j)*a - 4*a + 1;
			if(sqrt(D)*sqrt(D) == D && (int)sqrt(D)%2){
				ll b = (-(2*a-1) + sqrt(D))/2;
				ll bCnt=0, temp=b;
				while(temp){
					temp/=10;
					bCnt++;
				}
				if(bCnt==j &&b>0&& powr((a+b), 2)==a*powr(10, j)+b && (cnt+bCnt)<=16){
					ans+= powr(a+b, 2);
					cout<<a<<" "<<b<<endl;
				}
			}
			else continue;
		}
	}
	cout<<ans<<endl;
}
