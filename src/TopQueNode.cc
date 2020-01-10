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
	bool operator<(const TopQueNode &a) const{//true，本体（不是传参）放后面，false，本体放前面
		if(a.frequency()<=_frequency){
			return true;
		}else{
			return false;
		}
	}
	friend ostream& operator<<(ostream &out,const TopQueNode &node);
	TopQueNode& operator=(const TopQueNode &a);
private:
	string _word;
	int _frequency;
};
ostream& operator <<(ostream &out,const TopQueNode &node){
	out<<node._word;
	return out;
}
TopQueNode& TopQueNode::operator=(const TopQueNode &a){
	_word=a.word();
	_frequency=a.frequency();
	return *this;
}
