
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

#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1){
        cerr<< name << ": "<< arg1<<endl;
}

template<typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1,',');
        cerr.write(names, comma-names) <<": "<<arg1<<" |";
        __f(comma+1,args...);
}


int main(){


  
	return 0;
}
