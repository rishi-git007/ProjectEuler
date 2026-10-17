#include <bits/stdc++.h>
using namespace std;

struct data {
	int value;
	char type; //a, b, c, d, e, f
};

void print(vector<int> &a){
	int sum = 0;
	for(int &val : a){
		cout<<val<<" ";
		sum += val;
	}
	cout<<endl;
	cout<<"Sum is "<<sum<<endl;
	return;
}
unordered_map<int, vector<data>>mp;
void check(int num, vector<int> &ans){
	//cout<<num<<endl;
	int sum = 0;
	for(int i=0; i<6; i++){
		sum += (ans[i]!=0);
	}
	unordered_set<int> st;
	for(int i=0; i<6; i++){
		st.insert(ans[i]);
	}
	bool flag = (st.size() > 5);
	//print(ans);
	for(int i=0; i<mp[num].size(); i++){
		data x = mp[num][i];
		int value = x.value;
		int tail = value%100;
		int type = x.type-'a';
		//cout<<value<<" "<<type<<endl;
		if(sum==6 && type==5 && ans[type]==value){
			if(flag)print(ans);
			return;
		}
		else if(ans[type]>0){
			continue;
		}
		else{
			ans[type] = value;
			check(tail, ans);
			ans[type] = 0;
		}

	}
}

int main() {
	vector<int> oct;
	for(int i=1; i<=1e4; i++){
		vector<int> x(6, 0);
		x[0] = i*(i+1)/2;
		x[1] = i*i;
		x[2] = i*(3*i-1)/2;
		x[3] = i*(2*i-1);
		x[4] = i*(5*i-3)/2;
		x[5] = i*(3*i-2);
		for(int i=0; i<6; i++){
			if(x[i]>=1000 && x[i]<10000){
				int head = x[i]/100;
				if(head < 10)continue;
				data y;
				y.value = x[i];
				y.type = 'a'+i;
				mp[head].push_back(y);
				if(i==5){
					oct.push_back(x[i]);
				}
			}

		}
	}
	vector<int> ans(6, 0);
	for(int i=0; i<oct.size(); i++){
		int num = oct[i];
		int tail = num%100;
		ans[5] = num;
		//cout<<num<<endl;
		check(tail, ans);
		//cout<<endl;
	}

}
