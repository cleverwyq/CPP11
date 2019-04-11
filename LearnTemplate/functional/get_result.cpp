#include <functional>
#include <iostream>
#include <typeinfo>


using namespace std;

void func1(...)
{
    cout << "call func1 ...\n";

}

void func1(int* )
{
    cout << "call func1 int*\n";
}

int func2_with_param(double, string)
{
    return -1;
}
struct AwoResultType
{

};

struct AwithResultType
{
    typedef int result_type;
};


  template<typename _Tp>
    class __has_result_type_helper2
    {
      template<typename _Up>
	struct _Wrap_type
	{ };

      template<typename _Up>
	static true_type __test(_Wrap_type<typename _Up::result_type>*);

      template<typename _Up>
	static false_type __test(...);

    public:
      typedef decltype(__test<_Tp>(0)) type;
    };

  template<typename _Tp>
    struct __has_result_type2
    : public __has_result_type_helper2
			<typename remove_cv<_Tp>::type>::type
    { };

int main()
{
    func1(0);   //call func1(int*)
    func1(1);   //call func1 ...
    //error: no type named 'result_type' in 'class AwoResultType'|
    //_Maybe_get_result_type<true, AwoResultType> m;


    _Maybe_get_result_type<false, AwoResultType> m1;    //OK
    _Maybe_get_result_type<true, AwithResultType> m2;

    cout << "----------1------------\n";
    cout << std::boolalpha << __has_result_type_helper2<AwoResultType>::type::value << endl;   //false
    cout << std::boolalpha << __has_result_type_helper2<AwithResultType>::type::value << endl;  //true
    cout << std::boolalpha << __has_result_type2<AwithResultType>::value << endl; //true


    cout << "----------------2---\n";
    //error: 'result_type' is not a member of 'std::_Weak_result_type_impl<AwoResultType>'|
    //_Weak_result_type_impl<AwoResultType>::result_type m3;

    _Weak_result_type_impl<AwithResultType>::result_type m3;
    cout << "result type m3 is :" << typeid(m3).name() << endl;            //i

    typedef int(*PMF)(double, string);
     _Weak_result_type_impl<PMF>::result_type m4;
    cout << "result type m4 is :" << typeid(m3).name() << endl;

    cout << "Done!\n";
}
