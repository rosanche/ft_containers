#ifndef TOOLS_HPP
#define TOOLS_HPP

namespace ft
{

	// INTEGRAL_CONST
	template <class T, T v>
	struct integral_const
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_const<T, v> type;
		operator T() { return v; }
	};

	// Instantiations
	typedef integral_const<bool, true> t_type;
	typedef integral_const<bool, false> f_type;

	// ENABLE_IF
	template <bool Cond, class T = void>
	struct enable_if
	{
	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	// INTEGRAL
	template <class T>
	struct is_integral : ft::f_type
	{
	};

	template <>
	struct is_integral<bool> : ft::t_type
	{
	};

	template <>
	struct is_integral<char> : ft::t_type
	{
	};

	template <>
	struct is_integral<wchar_t> : ft::t_type
	{
	};

	template <>
	struct is_integral<signed char> : ft::t_type
	{
	};

	template <>
	struct is_integral<short int> : ft::t_type
	{
	};

	template <>
	struct is_integral<int> : ft::t_type
	{
	};

	template <>
	struct is_integral<long int> : ft::t_type
	{
	};

	template <>
	struct is_integral<long long int> : ft::t_type
	{
	};

	template <>
	struct is_integral<unsigned char> : ft::t_type
	{
	};

	template <>
	struct is_integral<unsigned short int> : ft::t_type
	{
	};

	template <>
	struct is_integral<unsigned int> : ft::t_type
	{
	};

	template <>
	struct is_integral<unsigned long int> : ft::t_type
	{
	};

	template <>
	struct is_integral<unsigned long long int> : ft::t_type
	{
	};
}

#endif