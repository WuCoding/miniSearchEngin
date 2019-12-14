#include "../inc/func.h"

#if 0
void test1(){
	ifstream in;
	in.open("inTest.txt",ios::in);
	char c;

	for(int n=0;n<4;++n){
		cout<<"before: "<<in.tellg();
		in>>c;
		cout<<" "<<c<<" after:"<<in.tellg()<<endl;
	}
}
#endif

void ofsFilePageLib(int docid,string txt,ofstream &out,map<int,pair<long,size_t>> &offsetLib){
	long offset=out.tellp();//偏移量
	cout<<"偏移量:"<<offset<<endl;
	size_t length=txt.size();//文章长度
	cout<<"文章长度:"<<length<<endl;
	out<<txt;
	pair<long,size_t> node(offset,length);
	offsetLib[docid]=node;
}

void ofsFileOffsetLib(ofstream &out,map<int,pair<long,size_t>> &offsetLib){
	for(auto i:offsetLib){
		out<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
	}
}

//obtaining file size
//const char * filename = "example.txt";

void test3(){
	ifstream in;
	in.open("ripepage.lib",ios::in);

	long int length;
	long int offset;

	cin>>offset>>length;

	char* buff= new char[length];
	in.seekg(offset,in.beg);
	in.read(buff,length);
	cout<<buff<<endl;
}

int main(){
	test3();
}

