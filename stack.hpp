#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft{

	template <class T, class Container = ft::vector<T> >
	class stack{
	public:
		typedef T 									value_type;
		typedef Container 							container_type;
		typedef size_t								size_type;
		explicit stack( const container_type& cont = container_type() ):
				c(cont) {}
		stack( const stack& other ) { c.operator=(other.c); }
		~stack() {}

		stack& operator=( const stack& other ) {
			c.operator=(other.c);
			return *this;
		}
		bool empty() const { return c.empty(); }
		size_type size() const { return c.size(); }
		value_type& top() { return c.back(); }
		const value_type& top() const { return c.back(); }
		void push( const value_type& value ) { c.push_back(value); }
		void pop() { c.pop_back(); }

		template< class Tn, class Containern >
		friend bool operator==( const ft::stack<Tn,Containern>& lhs,
								const ft::stack<Tn, Containern>& rhs );

		template< class Tn, class Containern >
		friend bool operator!= ( const ft::stack<Tn,Containern>& lhs,
								 const ft::stack<Tn, Containern>& rhs );

		template< class Tn, class Containern >
		friend bool operator< ( const ft::stack<Tn,Containern>& lhs,
								const ft::stack<Tn, Containern>& rhs );

		template< class Tn, class Containern >
		friend bool operator<= ( const ft::stack<Tn,Containern>& lhs,
								 const ft::stack<Tn, Containern>& rhs );

		template< class Tn, class Containern >
		friend bool operator> ( const ft::stack<Tn,Containern>& lhs,
								const ft::stack<Tn, Containern>& rhs );

		template< class Tn, class Containern >
		friend bool operator>= ( const ft::stack<Tn,Containern>& lhs,
								 const ft::stack<Tn, Containern>& rhs );

	protected:
		container_type c;
	};

	template< class T, class Container >
	bool operator==( const ft::stack<T,Container>& lhs, const
	ft::stack<T,Container>& rhs )
	{
		return lhs.c == rhs.c;
	}
	template< class T, class Container >
	bool operator!=( const ft::stack<T,Container>& lhs, const
	ft::stack<T,
			Container>& rhs )
	{
		return (lhs.c != rhs.c);
	}
	template< class T, class Container >
	bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,
			Container>& rhs )
	{
		return (lhs.c < rhs.c);
	}
	template< class T, class Container >
	bool operator<=( const ft::stack<T,Container>& lhs, const
	ft::stack<T,
			Container>& rhs )
	{
		return (lhs.c <= rhs.c);
	}
	template< class T, class Container >
	bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,
			Container>& rhs )
	{
		return (lhs.c > rhs.c);
	}
	template< class T, class Container >
	bool operator>=( const ft::stack<T,Container>& lhs, const
	ft::stack<T, Container>& rhs )
	{
		return (lhs.c >= rhs.c);
	}

}

#endif