
#include "tree.h"

using namespace std;
using namespace huaguisoftware;

// 试题二说明：
// 要求设计并实现一个“完全二叉树”，处理加减乘除的计算公式
// 不考虑括号，遇到非数字或者运算符(+-*/)请抛出异常
//


void node::left_first(node *root)
{
    if (root != 0) {
        this->left_first(root->left);
        cout <<" " << root->value;
        this->left_first(root->right);
    }
}

void node::right_first(node *root)
{
    if (root != 0) {
        this->right_first(root->right);
        cout <<" " << root->value;
        this->right_first(root->left);
    }
}

string tree::standard_operators = "+-*/";
    //for time limit, use as global var here...
    vector<string> factors;

tree::tree(string input)
{
    factors.clear();
    this->parse(input);

    //Create complete tree for operators first
    size_t len = factors.size();
    size_t last_op_index = len/2 -1;

    root = new node();
    //size_t root_op_index = (last_op_index + 1)/2;

    size_t *nodes = new size_t[len/2];
    for (size_t i = 0; i < len/2; i++)
        nodes[i] = i;

    create_tree(*root, nodes, len/2);
}

tree::~tree()
{
}

bool tree::is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool tree::is_valid_num(char c)
{
    return c == '.' || ( c >= '0' && c <='9');
}
void tree::parse(string input)
{
    string::size_type len = input.length();
    string num;
    for (string::size_type i = 0; i < len; i++)
    {
        char c = input[i];
        if (this->is_operator(c))
        {
            factors.push_back(num);
            //cout << num << " in" << endl;
            string temp;
            temp += c;
            factors.push_back(temp);
            //cout << temp << " in" << endl;
            num.clear();
        }
        else if (this->is_valid_num(c))
        {
            num += c;
        }
    }
    factors.push_back(num);
    //cout << num << " in" << endl;
}

//void tree::create_tree(node& root, int op_index int left_nodes[], int left_node_num, int right_nodes[], int right_node_num)
node* tree::create_tree(node& root, size_t nodes[], size_t nodes_num)
{
    if (nodes_num == 1)
    {
        size_t ind = nodes[0] * 2 + 1;
        root.value = factors[ind];
        root.left = new node();
        root.left->value = factors[ind -1];
        root.right = new node();
        root.right->value = factors[ind + 1];

        return &root;
    }
    else if (nodes_num == 2)
    {
        root.value = factors[nodes[1] * 2 + 1];
        //cout <<root.value <<endl;
        root.left = new node();
        root.left->value = factors[nodes[0] * 2 + 1];
        //cout << root.left->value <<endl;
        root.right = 0;

        size_t ind = nodes[0] * 2 + 1;
        node *temp = new node;

        temp->left = new node();
        temp->left->value = factors[ind - 1];
        //cout << temp->left->value <<endl;
        temp->right = new node();
        temp->right->value = factors[ind + 1];
        root.left->left = temp;
        //cout << temp->right->value <<endl;

        return &root;
    }
    else if (nodes_num == 3)
    {
        root.value = factors[nodes[1] * 2 + 1];
        root.left = new node();
        root.left->value = factors[nodes[0] * 2 + 1];
        root.right = new node();
        root.right->value = factors[nodes[2] * 2 + 1];


        node *temp = new node();
        int ind = nodes[0] * 2 + 1;
        temp->value = factors[ind - 1];
        root.left->left = temp;
  //      cout << temp->value <<endl;
        temp = new node();
        temp->value = factors[ind + 1];
        root.left->right = temp;
//cout << temp->value <<endl;
        temp = new node();
        ind = nodes[2] * 2 + 1;
        temp->value = factors[ind - 1];
        root.right->left = temp;
//cout << temp->value <<endl;
        temp = new node();
        temp->value = factors[ind + 1];
        root.right->right = temp;
//cout << temp->value <<endl;
        return &root;
    }
    else
    {
        size_t mid = nodes_num/2;
        root.value = factors[mid*2 + 1];
        root.left = new node();
        root.right = new node();
        size_t *lefts = new size_t[mid];
        for(int i = 0; i < mid; i++)
            lefts[i] = nodes[i];

        int num_right = nodes_num - mid -1;
        size_t *rights = new size_t[num_right];
        for (int i = 0; i < num_right; i++)
            rights[i] = nodes[mid + 1 + i];

        create_tree(*root.left, lefts, mid);
        create_tree(*root.right, rights, num_right);
    }

}
// 左遍历
// suppose it's left -> root -> right
string tree::traverse_left_first()
{
    this->root->left_first(this->root);
	return "";
	// 注释上面的代码并在此实现题目的要求。
}

// 右遍历
string tree::traverse_right_first()
{
    this->root->right_first(this->root);
	return "";
	// 注释上面的代码并在此实现题目的要求。
}

// 深度优先遍历
string tree::traverse_depth_first()
{
	return "not implemented";
	// 注释上面的代码并在此实现题目的要求。
}

// 计算结果
double tree::calc()
{
	return -1;
	// 注释上面的代码并在此实现题目的要求。
}
