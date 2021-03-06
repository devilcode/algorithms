#include<iostream>
#include<cmath>

using namespace std;

#define llu long long unsigned

llu multiply(llu a, llu b, llu c) {
	if(b==0) return 0;
	
	llu z = multiply(a,(b>>1),c);
	
	if(b%2==0) return (z<<1)%c;
	else return (a+(z<<1)%c)%c;
}

int main() {
	llu a,b,c;
	
	cin>>a>>b>>c;
	while(a!=0) {
		cout<<multiply(a,b,c)<<endl;
	
		cin>>a>>b>>c;
	}
	return 0;
}
