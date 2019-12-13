#include "../inc/func.h"

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
void test2(){
	string str("test");
	ofstream out;
	out.open("outTest.txt",ios::out);
	for(int k=0;k<str.length();k++){
		cout<<"before:"<<out.tellp();
		out<<str[k];
		cout<<" "<<str[k]<<" after:"<<out.tellp()<<endl;
	}
	out.close();
}
//obtaining file size
//const char * filename = "example.txt";
#if 0
void test3(){
	long l,m;
	ifstream file(filename,ios::in|ios::binary);
	l=file.tellg();
	file.seekg (0, ios::end);
	m = file.tellg();
	file.close();
	cout << "size of " << filename;
	cout << " is " << (m-l) << "bytes.\n";
}
#endif
int main(){
	test2();
}
