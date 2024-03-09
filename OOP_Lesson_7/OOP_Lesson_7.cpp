#include <iostream>
using namespace std;

class Message
{
	char* text{};
	unsigned size{};
	unsigned ID;
	static inline unsigned counter{};
public:
	Message(const char* data, unsigned count)// обычный конструктор
	{
		size = count;
		text = new char[size];
		for (unsigned i = 0; i < size; i++)
		{
			text[i] = data[i];
		}
		ID = ++counter;
		cout << "Create Message!!!     " <<this<< endl;
	}

	Message(const Message& copy) :Message{ copy.getText(),copy.size} // конструктор копироавния
	{
		cout << "Copy Message!!! " << copy.ID<<" on "<<ID<< endl;
	};

	Message(Message&& moved)// конструктор перемещения
	{
		ID = ++counter;
		cout << "Create R - konstructor message " << ID << endl;
		text = moved.text;
		size = moved.size;
		moved.text = nullptr;
		cout << "Create Moved  message      "<<this<<" " << moved.ID << " on " << ID << endl;
	}
	~Message()
	{
		cout << "Destructor       "<<this<<" " << ID << endl;
		delete[]text;
	}

	char* getText()const { return text; }
	unsigned getSize() const { return size; }
	unsigned getID() const { return ID; }

};

class Messenger
{
	Message message;
public:
	Messenger(Message mess) : message{move(mess) } {};
	void sendMessage()const
	{
		cout << "Send massage " << message.getID()<<" " << message.getText() << endl;
	}
};



int main()
{
	Messenger VK{ Message{"Hello PV 312",17}};
	VK.sendMessage();
	return 0;
}



//string defaulMess();
//void print(string&& text);
//int main()
//{
//	int b = 5;
//	//b - lvalue 
//	//5 - rvalue
//	const int n{ 5 };
//	  int&& ttempRef{ n + 5 };
//	cout << ttempRef << endl;
//	const int&& tempRef = move(n);
//
//	//print("Hello World!!!");
//	//string mess = "HI PV312";
//	//  print(mess); ошибка 
//	print(defaulMess());
//
//	string text = defaulMess();
//	cout << text << endl;
//
//	return 0;
//}
//
//string defaulMess()
//{
//	string message{ "Hello World"  };
//	return message;
//}
//
//void print(string&& text)
//{
//	cout << text << endl;
//}
