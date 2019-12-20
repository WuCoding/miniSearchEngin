#include "../inc/func.h"

//获得一篇文章的起始位置和长度，加入到 map<int,pair<long,size_t>>容器，同时将文章输入到网页库中
//输入：文章id，文章内容，网页库输出流，记录文章起始位置和长度的容器
void ofsFilePageLib(int docid,string txt,ofstream &out,map<int,pair<long,size_t>> &offsetLib){
	long offset=out.tellp();//偏移量
	size_t length=txt.size();//文章长度
	out<<txt;
	pair<long,size_t> node(offset,length);
	offsetLib[docid]=node;
}
//将map<int,pair<long,size_t>>输出到偏移库中
//输入：偏移库输出流，记录文章起始位置和长度的容器
void ofsFileOffsetLib(ofstream &out,map<int,pair<long,size_t>> &offsetLib){
	for(auto i:offsetLib){
		out<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
	}
}
