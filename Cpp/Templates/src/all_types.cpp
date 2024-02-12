#include <algorithm>

template <class T>
T type_T(T value)
{
	return value;
}

template <class T>
T type_const_T(const T value)
{
	return value;
}

template <class T>
T type_T_ref(T& value)
{
	return value;
}

template <class T>
T type_const_T_ref(const T& value)
{
	return value;
}

template <class T>
T type_T_ref_ref(T&& value)
{
	return value;
}

template <class T>
T type_const_T_ref_ref(const T&& value)
{
	return value;
}

int main()
{
	int lvalue = 10;
	const int const_lvalue = 10;

	type_T(lvalue);
	type_T(const_lvalue);
	type_T(10);
	type_T(std::move(lvalue));


	type_const_T(lvalue);
	type_const_T(const_lvalue);
	type_const_T(10);
	type_const_T(std::move(lvalue));


	type_T_ref(lvalue);
	type_T_ref(const_lvalue);
	type_T_ref(10);
	type_T_ref(std::move(lvalue));


	type_const_T_ref(lvalue);
	type_const_T_ref(const_lvalue);
	type_const_T_ref(10);
	type_const_T_ref(std::move(lvalue));

	type_T_ref_ref(lvalue);
	type_T_ref_ref(const_lvalue);
	type_T_ref_ref(10);
	type_T_ref_ref(std::move(lvalue));


	type_const_T_ref_ref(lvalue);
	type_const_T_ref_ref(const_lvalue);
	type_const_T_ref_ref(10);
	type_const_T_ref_ref(std::move(lvalue));

	return 0;
}
