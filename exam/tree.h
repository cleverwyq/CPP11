#pragma once
#include "Stdafx.h"

using namespace std;

namespace huaguisoftware
{
    class node
    {
    public:
        node() {
            left = right = 0;
        }
        string value;
        node* left;
        node* right;
        void left_first(node *);
        void right_first(node *);
    };

	class tree
	{
    private:
        node *root;


    private:
        void parse(string input);
        bool is_operator(char c);
        bool is_valid_num(char c);
        static string standard_operators;
        //void create_tree(node& root, int left_nodes[], int left_node_num, int right_nodes[], int right_node_num);
        node* create_tree(node& root, size_t nodes[], size_t nodes_num);
	public:
		tree(string input);
		~tree();
	public:
		string traverse_left_first();
		string traverse_right_first();
		string traverse_depth_first();
		double calc();
	};
}

