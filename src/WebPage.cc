#include "../inc/func.h"

class WebPage{
public:
	WebPage(int docid,string title,string url,string content);
	void print() const;
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
void WebPage::print() const{
	cout<<_docid<<" "<<_title<<" "<<_url<<" "<<_wordFreMap.size()<<endl;
	for(auto i:_wordFreMap){
		cout<<i.first<<" ";
	}
	cout<<endl;
}
