#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &a, vector<int>&b, vector<int>&c){
	int n = a.size();
	bool flag = (n%2==0);
	if((!flag) || n==0)return false;
	for(int i=0; i<n/2; i++){
		if(a[i]!=a[i+n/2] || b[i]!=b[i+n/2] || c[i]!=c[i+n/2]){
			flag = false;
			break;
		}
	}
	return flag;
}

int period(int x){
	vector<int> p, q, r;
	int b = -floor(sqrt(x)), c = 1;
	//a.push_back(-b);
	int ans = 0;
	while((!check(p, q, r))){
		//cout<<"hi";
		int tempc = (x-b*b)/c;
		int tempa = floor((sqrt(x)-b)/tempc);
		int tempb = -(tempa*(x-b*b)/c+b);
		//cout<<tempa<<" "<<tempb<<" "<<tempc<<endl;
		b = tempb;
		c = tempc;
		p.push_back(tempa);
		q.push_back(tempb);
		r.push_back(tempc);
		ans++;
	}
	ans /= 2;
	return ans;
}

int main(){
	int n=10000;
	//cin>>n;
	int sum = 0;
	for(int i=1; i<=n; i++){
		int s = sqrt(i);
		if(s*s == i)continue;
		cout<<i<<" "<<period(i)<<endl;
		sum += period(i)&1;
		//cout<<endl;

	}
	cout<<sum<<endl;
}
