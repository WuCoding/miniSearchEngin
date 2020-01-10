#include "../inc/func.h"

//传入：目标字符串，要删掉的字字符串(set)
//返回：删除目标后的字符串
string strReplace(string resource_str,set<string> &repStr){
	string::size_type pos;
	for(auto i:repStr){
		pos=0;
		while((pos=resource_str.find(i))!=string::npos){
			resource_str.replace(pos,i.length(),"");
		}
	}
	return resource_str;
}
//传入：目标字符串
//返回：除掉<.*?>正则表达式的字符串
string cleanXmlStr(string resource_str){
	string pattern="<.*?>";
	regex r(pattern);
	set<string> replaceStr;

	for(sregex_iterator it(resource_str.begin(),resource_str.end(),r),end_it;
			it!=end_it;++it){
		replaceStr.insert(it->str());
	}
	return strReplace(resource_str,replaceStr);
}
