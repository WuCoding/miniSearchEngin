#include "../inc/func.h"

int equalStrVec(const vector<string> &m,const vector<string> &n){
	set<string> mSet;
	mSet.insert(m.cbegin(),m.cend());
	int equelCount=0;
	for(auto i:n){
		if(mSet.find(i)!=mSet.end()){
			++equelCount;
		}
	}
	return equelCount;
}

int main(){
	vector<string> v1;
	vector<string> v2;
	cout<<equalStrVec(v1,v2)<<endl;
}
