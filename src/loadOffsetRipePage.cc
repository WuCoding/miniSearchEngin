#include "../inc/func.h"

class WebPage{
public:
	WebPage(int docid,string title,string url,string content);
	void print() const{
		cout<<_docid<<" "<<_title<<" "<<_url<<" "<<_wordFreMap.size()<<endl;
		for(auto i:_wordFreMap){
			cout<<i.first<<" ";
		}
		cout<<endl;
	}
private:
	int _docid;
	string _title;
	string _url;
	string _content;
	map<string,int> _wordFreMap;
};
WebPage::WebPage(int docid,string title,string url,string content)
:_docid(docid),_title(title),_url(url),_content(content)
{
	string str=_title+_content;
	str=cleanCNString(str);
	vector<string> words;
	cutStringWithJieba(str,words);
	for(auto i:words){
		++(_wordFreMap[i]);
	}
}


void loadOffset(string offsetLib,map<int,pair<long int,long int>> &offsetMap){
	ifstream inOffset;
	inOffset.open(offsetLib,ios::in);
	string tmp;
	int docid;
	long int offset;
	long int length;
	while(getline(inOffset,tmp)){
		stringstream ss(tmp);
		ss>>docid>>offset>>length;
		pair<long int,long int> node(offset,length);
		offsetMap[docid]=node;
	}
}
void loadPage(
	string rapepageLib,
	map<int,pair<long int,long int>> &offsetMap,
	map<int,string> &txtLib){
	ifstream inPage;
	inPage.open(rapepageLib,ios::in);

	int docid;
	long int offset;
	long int length;
	char* buff;
	string txt;
	string str;
	for(auto i:offsetMap){
		docid=i.first;
		offset=i.second.first;
		length=i.second.second;

		buff=(char*)calloc(length,sizeof(char));
		if(buff==nullptr){
			cout<<"分配失败"<<endl;
		}
		inPage.seekg(offset,inPage.beg);
		inPage.read(buff,length);
		txt=buff;
		cout<<txt<<endl;
		txtLib[docid]=txt;
		free(buff);
		buff=nullptr;
	}
}
#if 0
<doc>
	<docid></docid>
	<url></url>
	<title></title>
	<content></content>
</doc>
#endif

void createPageMap(map<int,string> &txtLib,vector<WebPage> &myPage){
	int docid;
	string txt;
	XMLDocument docXml;
	XMLElement* Root;
	XMLElement* Url;
	XMLElement* Title;
	XMLElement* Content;
	string urlStr;
	string titleStr;
	string contentStr;
	for(auto i:txtLib){
		docid=i.first;
		txt=i.second;
		docXml.Parse(txt.c_str());
		Root=docXml.RootElement();
		Url=Root->FirstChildElement("url");
		Title=Root->FirstChildElement("title");
		Content=Root->FirstChildElement("content");

		urlStr=Url->GetText();
		titleStr=Title->GetText();
		contentStr=Content->GetText();
		WebPage newPage(docid,titleStr,urlStr,contentStr);
		myPage.push_back(newPage);
	}
}

int main(){
	string str;
	map<int,pair<long int,long int>> offsetMap;
	loadOffset("offset.lib",offsetMap);
	for(auto i:offsetMap){
		cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
	}
	map<int,string> txtLib;
	loadPage("ripepage.lib",offsetMap,txtLib);
	for(auto i:txtLib){
		cin>>str;
		cout<<i.first<<endl;
		cin>>str;
		cout<<i.second<<endl;
	}
	vector<WebPage> myPage;
	cout<<"woc"<<endl;
	createPageMap(txtLib,myPage);
	for(auto i:myPage){
		i.print();
	}
}
