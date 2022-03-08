#ifndef TOOLS_HPP
# define TOOLS_HPP

namespace ft {

    // INTEGRAL_CONST
	template <class T, T v>
	struct integral_const {
		static const T value = v;
		typedef T value_type;
		typedef integral_const<T,v> type;
		operator T() { return v; }
	};

	//Instantiations
	typedef integral_const<bool,true> t_type;
	typedef integral_const<bool,false> f_type;

    // ENABLE
    template <bool Cond, class T = void>
	struct enable
	{};

	template<class T> 
	struct enable<true, T>
	{ typedef T type; };

    // INTEGRAL
    template <class T>
	struct integral : ft::f_type
	{};
	
	template <>
	struct integral<bool> : ft::t_type
	{};

	template <>
	struct integral<char> : ft::t_type
	{};

	template <>
	struct integral<wchar_t> : ft::t_type
	{};

	template <>
	struct integral<signed char> : ft::t_type
	{};

	template <>
	struct integral<short int> : ft::t_type
	{};

	template <>
	struct integral<int> : ft::t_type
	{};

	template <>
	struct integral<long int> : ft::t_type
	{};

	template <>
	struct integral<long long int> : ft::t_type
	{};
	
	template <>
	struct integral<unsigned char> : ft::t_type
	{};
	
	template <>
	struct integral<unsigned short int> : ft::t_type
	{};


	template <>
	struct integral<unsigned int> : ft::t_type
	{};

	template <>
	struct integral<unsigned long int> : ft::t_type
	{};
	
	template <>
	struct integral<unsigned long long int> : ft::t_type
	{};
}

#endif