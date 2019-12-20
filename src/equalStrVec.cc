#include "../inc/func.h"

//获得两个字符串容器中相等字符串的个数
//输入：要比较的两个 vector<string>
//返回：相等的字符串个数
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
