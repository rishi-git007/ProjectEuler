/************************************************************
 *  Problem - Prime Digit Replacements
 *  solved by - N0T1C3
 ************************************************************/

/*
    Create masks and apply the masks on every prime.
    If the prime satisfies the mask, find all the possible numbers by replacing the digits.
    Count the no. of primes. 
    If count == 8 , then output the value of the prime.
    Answer = 121313
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
vector<bool> isPrime(N, 1);
vector<int> prime;

int pow(int a, int b){
	int prod = 1;
	while(b--){
		prod *= a;
	}
	return prod;
}


int main(){
	isPrime[0]=isPrime[1]=false;
	for(int i=2; i<N; i++){
		if(isPrime[i]){
			for(int j=2*i; j<N; j+=i){
				isPrime[j]=false;
			}
			prime.push_back(i);
		}
	}
	int ans=0, ansPrime=0;
	for(int mask=1; mask<(1<<7); mask++){
		int adder = 0;
		int temp = mask, bitcnt=0;
		while(temp){
			if(temp&1){
				adder += pow(10, bitcnt);
			}
			temp /= 2;
			bitcnt++;
		}
		//cout<<adder<<endl;
		for(int j=0; j<prime.size(); j++){
			int p = prime[j];
			int m = mask;
			bool flag = true;
			int prev=-1;
			while(m){
				int remp = p%10;
				if(m&1){
					if(remp==prev || prev==-1){
						prev = remp;
					}
					else {
						flag = false;
						break;
					}
				}
				m /= 2, p /= 10;
			}
			if(flag){
				int cnt=0;
				int temp = prime[j];
				for(int i=0; i<10-prev; i++){
					int num = temp+adder*i;
					if(adder > prime[j])break;
					if(num < N && isPrime[num])cnt++;
				}
				if(cnt > ans){
					cout<<cnt<<endl;
					cout<<temp<<" "<<adder<<endl;
					cout<<endl;
					ans = cnt;
					ansPrime = prime[j];
				}
			}
		}
	}
}
