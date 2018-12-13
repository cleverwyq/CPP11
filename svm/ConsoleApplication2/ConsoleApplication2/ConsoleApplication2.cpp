// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <typeinfo>
#include <tuple>

using namespace std;
auto ttt = make_tuple(1, 2.3, 'c', "Hello");

template<int N>
int tuple_iterator2(){
	//    if ( N != 1)
	//    {
	//        tuple_iterator2<T, N-1>(t);
	//        cout << get<N-1>(t)<< endl;
	//    }
	//    else {
	//        cout << std::get<0>(t)<<endl;
	//    }
	tuple_iterator2<N - 1>();
	cout << get<N - 1>(ttt) << endl;
	return 0;
}

template<>
int tuple_iterator2<1>()
{
	cout << get<0>(ttt) << endl;
	return 0;
}

template<class... Types>
void f(Types... rest)
{
	//    for (auto r : &rest...) {
	//        cout << r << endl;
	//    }

	//     cout<< typeid(&rest).name() << endl; error: parameter packs not expanded with '...':|
	auto a = forward_as_tuple(rest...);
	cout << "type of this tuple a :" << typeid(a).name() << endl;
	auto b = forward_as_tuple(&rest...);
	//      for (auto i : a) {
	//        cout << i << endl;
	//      }
	auto first = std::get<0>(a);  //OK
	cout << first << endl;
	cout << std::get<1>(a) << endl;

	cout << get<2>(b) << endl;
	cout << "Total of size :" << sizeof...(rest) << endl;

	cout << "function template" << endl;

	
	tuple_iterator2<4>();

	//      for (size_t i = 1; i < sizeof...(rest); i++) error: the value of 'i' is not usable in a constant expression|
	//        cout << std::get<i>(a) <<endl;
}


void h(int) {
	cout << "h(int)" << endl;
}

void h(int*){
	cout << "h(int*)" << endl;
}
template<class... Types>
void g(Types... rest) {
	h(rest...);   //call h(int)
	h(&rest...); //call h(int*) , &rest is pattern
}


template<class... Types>
void i(Types*... rest) {
	h(rest...);
	h(*rest...);
}



int main()
{
	f(1, 2.3, 'c', "Hello");
	int j = 3;
	g(j);
	i(&j);
	return 0;
}
