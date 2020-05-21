
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <unordered_set>
using namespace std;


struct modint{
	using i64 = int_fast64_t;
	i64 a;
	static constexpr i64 MOD= 1e9+7;
	modint(){
		a=0;
	};
	modint(i64 a_){
		a=a_ %MOD;
		if(a<0) a+=MOD;
	}

	modint inv()const{
		i64 n=1,m=MOD-2, A=a;
		while(m){
			if(m&1)(n*=A)%=MOD;
			(A*=A) %= MOD;
			m>>=1;
		}
		modint y(n);
		return y;
	}

	bool operator==(const modint& x){
		return a==x.a;
	}
	bool operator!=(const modint& x){
		return a!=x.a;
	}

	modint&  operator =(const modint& x){
		a= x.a;
		return *this;
	}
	modint operator+(const modint& x){

		modint y;
		y.a= a+x.a;
		if(y.a < 0) y.a+=MOD;
		return y;
	}
	modint operator-(const modint& x){

		modint y;
		y.a= a-x.a;
		if(y.a<0) y.a+=MOD;
		return y;
	}
	modint operator*(const modint& x){
		modint y;
		y.a=(a*x.a)%MOD;
		return y;
	}
	modint operator/(const modint& x){
		modint y;
		y.a=(a*(x.inv().a))%MOD;
		return y;
	}

	modint& operator +=(const modint& x){
		a=a+x.a;
		if(a>=MOD)a-=MOD;
		return *this;
	}
	modint& operator -=(const modint& x){
		a=a-x.a;
		if(a<0) a+=MOD;
		return *this;
	}
	modint& operator *=(const modint& x){
		(a*=x.a)%=MOD;
		return *this;
	}
	modint& operator /=(const modint& x){

		(a*=x.inv().a)%=MOD;
		return *this;
	}
};

istream& operator>> (istream& in, modint& x){
	int_fast64_t a_;
	in>>a_;
	modint y(a_);
	x=y;
	return in;
}

ostream& operator<< (ostream& out, const modint& x){
	out<<x.a;
	return out;
}

modint pwr(int_fast64_t a, int_fast64_t b){
	modint _;
	int_fast64_t n=1,A=a;
	while(b){
		if(b&1)(n*=A)%=modint::MOD;
		(A*=A)%=modint::MOD;
		b>>=1;
	}
	_.a=n;
	return _;
}

template<int n> struct COMB{
	int_fast64_t fc[n],ifc[n];

	constexpr COMB():fc(), ifc(){
		fc[0]=1;
		for(int i=1;i<n;++i) fc[i]=fc[i-1]* i % modint::MOD;
		int_fast64_t N=1, A=fc[n-1], b=modint::MOD-2;

		while(b){
			if(b & 1) (N*=A)%=modint::MOD;
			(A*=A)%= modint::MOD;
			b>>=1;
		}
		ifc[n-1]=N;
		for(int i=n-1 ;i>=1 ;--i) ifc[i-1]=ifc[i]*i % modint::MOD;
	};
	modint operator()(int N,int R)const{
		if(N<0|| R<0||N<R)return 0;
		return fc[N]*ifc[R]%modint::MOD* ifc[N-R];
	}
	modint operator[](int N)const{
		modint _;
		_.a= fc[N];
		return _;
	}
	modint operator()(int N)const{
		modint _;
		_.a=ifc[N];
		return _;
	}
};

const int maxp= 55;
struct Point{
	int x,y;

}p[maxp],stk[maxp],base;

double getdis(Point p1,Point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)*1.0+ (p1.y-p2.y)*(p1.y-p2.y));
}
int getCross(Point p1, Point p2, Point p3){

	return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);
}

bool cmp(Point p1,Point p2){

	if(getCross(base,p1,p2)==0){

		return getdis(base,p1)< getdis(base,p2);
	}
	if(getCross(base,p1,p2)>0){

		return true;
	}
}

void getBase(){

}
bool judge(double a, double b, double c){
	return a*a+b*b <c*c;
}
double calR(Point p0,Point p1, Point p2){
	double p0p1= getdis(p0,p1);
	double p0p2= getdis(p0,p2);
	double p1p2= getdis(p1,p2);

	if(judge(p0p1,p0p2,p1p2)|| judge(p0p1,p1p2,p0p2)||judge(p0p2,p1p2,p0p1)){
		return max(p0p1,max(p0p2,p1p2));
	}
	double S=fabs(getCross(p0,p1,p2))/2.0;
	return p0p1*p0p2*p1p2/4.0/S;
}

you

int main(){
	sort(A.begin(),A.end());
	
	modint ans{};

	for(int i=0;i<N;i++){
		ans-=comb(N-i-1,K-1)*A[i];
		ans+=comb(i,K-1)*A[i];
	}

	cout<<ans<<endl;
	return 0;
}
