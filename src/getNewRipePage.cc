#include "../inc/func.h"

string getElemText(XMLElement* elem){
	const char* txt;
	string str;
	if(elem==nullptr){
		return "";
	}else{
		txt=elem->GetText();
		if(txt==nullptr){
			return "";
		}else{
			str=txt;
			return cleanXmlStr(str);
		}
	}
}
string itemTxtStr(XMLElement* Item,int docid){
	XMLElement* Title=Item->FirstChildElement("title");//title
	XMLElement* Link=Item->FirstChildElement("link");//link
	XMLElement* Description=Item->FirstChildElement("description");//description
	XMLElement* Content=Item->FirstChildElement("content:encoded");//content

	string titleStr=getElemText(Title);
	string linkStr=getElemText(Link);
	string descriptionStr=getElemText(Description);
	string contentStr=getElemText(Content);

	string resStr="<doc><docid>"+to_string(docid)+"</docid><url>"+linkStr
		+"</url><title>"+titleStr+"</title><content>"+descriptionStr+
		contentStr+"</content></doc>";
	return resStr;
}		
void test(string fileName){
	XMLDocument doc;
	XMLError errXml=doc.LoadFile(fileName.c_str());
	if(XML_SUCCESS==errXml){
		ofstream outPage;
		outPage.open("ripepage.lib",ios::out);
		ofstream outOffset;
		outOffset.open("offset.lib",ios::out);
		map<int,pair<long,size_t>> offsetLib;
		XMLElement* Rss=doc.RootElement();//rss
		XMLElement* Channel=Rss->FirstChildElement("channel");//channel

		int docid=1;
		string txt=itemTxtStr(Channel,docid);
		ofsFilePageLib(docid,txt,outPage,offsetLib);
		++docid;

		string s;
		XMLElement* Item=Channel->FirstChildElement("item");//item
		while(Item){
			cin>>s;
			txt=itemTxtStr(Item,docid);
			ofsFilePageLib(docid,txt,outPage,offsetLib);
			++docid;

			Item=Item->NextSiblingElement("item");
		}
		ofsFileOffsetLib(outOffset,offsetLib);
	}
}

int main(){
	string fileName;
	cin>>fileName;
	test(fileName);
}
