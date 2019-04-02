#include<memory>
#include<iostream>
using namespace std;

struct Node
{
	shared_ptr<Node> _pre;
	shared_ptr<Node> _next;

	~Node()
	{
		cout << "~Node():" << this << endl;
	}
	int data;
};

void FunTest()
{
	shared_ptr<Node> Node1(new Node);
	shared_ptr<Node> Node2(new Node);
	Node1->_next = Node2;
	Node2->_pre = Node1;

	cout << "Node1.use_count:"<<Node1.use_count() << endl;
	cout << "Node2.use_count:"<< Node2.use_count() << endl;
}

int main()
{
	FunTest();
	system("pause");
	return 0;
}
---------------------
作者：ycz_csdn
来源：CSDN
原文：https://blog.csdn.net/yc2zgh1314/article/details/51264963
版权声明：本文为博主原创文章，转载请附上博文链接！
