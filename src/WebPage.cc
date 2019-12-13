#include "../inc/func.h"

class WebPage{
public:
	WebPage(int docid,string title,string url,
		string description,string content)
	:_docid(docid),_title(title),_url(url),
	_description(description),_content(content)
	{}
	void print() const;
private:
	int _docid;//文件序号
	string _title;//文章标题
	string _url;//文章链接
	string _description;//文章描述
	string _content;//文章内容
	map<string,int> _wordFreMap;//文章词频
};

void WebPage::print() const{
	cout<<_docid<<" "<<_title<<" "<<_url<<" "
		<<_description<<" "<<_content<<endl;
}

int main(){
	WebPage wp(1,"title","url","description","content");
	wp.print();
}
