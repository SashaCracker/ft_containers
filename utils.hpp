#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft {
    template <class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
    }

    template <class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp) {
		while (first1!=last1)
		{
			if (first2==last2 || comp(*first2<*first1)) return false;
			else if (comp(*first1<*first2)) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
    }

	template <class InputIterator1, class InputIterator2>
	bool equal( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1) {
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

    template <class InputIt1, class InputIt2, class BinaryPredicate>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate predicate) {
		while (first1!=last1) {
			if (!predicate(*first1,*first2))
				return false;
			++first1; ++first2;
		}
		return true;
    }

	//	Creates an integer constant from type and value.
	template <class T, bool val>
	struct integral_constant {
		static const bool value = val; // refers not to an instance but to the class itself, don't need to create an instance to refer to the parameter, const is at compile time and cannot be changed
		typedef T					value_type;
		typedef integral_constant	type;

		operator value_type() const {
			return value;
		}
	};

//	An instance of a type predicate has the value true if type T is a form of one of the integer types, otherwise it has the value false.
	template <class T>
	struct is_integral : public ft::integral_constant<T, false> {};

	template <>
	struct is_integral<bool> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<char> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<signed char> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned char> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<wchar_t> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<char16_t> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<short> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned short> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<int> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned int> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<long> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned long> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<long long> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned long long> : public ft::integral_constant<bool, true> {};

	template < bool B, class T =  void >
	struct enable_if { } ;

	template < class T >
	struct enable_if < true , T >  {  typedef T type ;  } ;

	template <class T>
	void swap(T& x, T& y)
	{
		T tmp(x);
		x = y;
		y = tmp;
	}
}
#endif

