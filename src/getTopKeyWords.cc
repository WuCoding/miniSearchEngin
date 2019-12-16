#include "../inc/func.h"

class TopQueNode{
public:
	TopQueNode(string word,int frequency)
	:_word(word),_frequency(frequency)
	{}
	string word()const{
		return _word;
	}
	int frequency()const{
		return _frequency;
	}
	bool operator<(const TopQueNode &a) const{//true放后面，false放前面
		if(a.frequency()<=_frequency){
			return true;
		}else{
			return false;
		}
	}
	TopQueNode& operator=(const TopQueNode &a){
		_word=a.word();
		_frequency=a.frequency();
		return *this;
	}
private:
	string _word;
	int _frequency;
};
ostream& operator <<(ostream &out,const TopQueNode& node){
	out<<node.word();
	return out;
}
#if 0
int main(){
	priority_queue<TopQueNode> q;
	TopQueNode n1("wu",2),n2("wang",3);
	q.push(n1);
	q.push(n2);
	cout<<q.top()<<endl;
	q.pop();
	cout<<q.top()<<endl;
}
#endif


#if 1
void getTopKeyWords(map<string,int> &wordFreMap,set<string> &stopWords){
	priority_queue<TopQueNode> q;
	for(auto i:wordFreMap){
		if(stopWords.find(i.first)!=stopWords.end()){//该词为停用词
			continue;
		}
		TopQueNode newNode(i.first,i.second);
		q.push(newNode);
		if(q.size()>5){
			q.pop();
		}
	}
	for(int i=q.size();i>0;--i){
		cout<<q.top()<<endl;
		q.pop();
	}
}
int main(){
	map<string,int> m1;
	m1["1"]=1;
	m1["2"]=2;
	m1["10"]=10;
	m1["4"]=4;
	m1["123"]=123;
	m1["32"]=32;
	m1["78"]=78;
	m1["1235"]=1234;
	set<string> s1;
	s1.insert("1235");
	getTopKeyWords(m1,s1);
}


#endif
