#include "../inc/func.h"

void print(XMLElement* elem,string elemName){
	const char* txt;
	string str;
	if(elem==nullptr){
		cout<<elemName<<" is null"<<endl;
	}else{
		txt=elem->GetText();
		if(txt==nullptr){
			cout<<elemName<<" :null"<<endl;
		}else{
			str=txt;
			cout<<elemName<<": "<<cleanXmlStr(str)<<endl;
		}
	}
}

void test(string fileName){
	XMLDocument doc;
	XMLError errXml=doc.LoadFile(fileName.c_str());
	if(XML_SUCCESS==errXml){
		XMLElement* Rss=doc.RootElement();//rss
		XMLElement* Channel=Rss->FirstChildElement("channel");//channel

		XMLElement* Title=Channel->FirstChildElement("title");//title
		XMLElement* Link=Channel->FirstChildElement("link");//link
		XMLElement* Description=Channel->FirstChildElement("description");//description
		XMLElement* Content=Channel->FirstChildElement("content:encoded");//content
		
		print(Title,"title");
		print(Link,"link");
		print(Description,"description");
		print(Content,"content");

		string s;
		XMLElement* Item=Channel->FirstChildElement("item");//item
		while(Item){
			Title=Item->FirstChildElement("title");
			Link=Item->FirstChildElement("link");
			Description=Item->FirstChildElement("description");
			Content=Item->FirstChildElement("content:encoded");

			cin>>s;
			print(Title,"title");
			cin>>s;
			print(Link,"link");
			cin>>s;
			print(Description,"description");
			cin>>s;
			print(Content,"content");

			Item=Item->NextSiblingElement("item");
		}
	}
}

int main(){
	string fileName;
	cin>>fileName;
	test(fileName);
}
