#include <vector>
#include "vector.hpp"
#include <algorithm>

int main()
{
	try
	{
		std::cout << "DEFAULT CONSTRUCTOR | SIZE() | CAPACITY() CHECK : " <<
		std::endl;

		std::cout << "INT vector: " << std::endl;
		std::vector<int> std_vector;
		ft::vector<int> ft_vector;
		size_t std_size = std_vector.size();
		size_t ft_size = ft_vector.size();
		size_t std_capacity = std_vector.capacity();
		size_t ft_capacity = ft_vector.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;

		std::cout << "STRING vector: " << std::endl;
		std::vector<std::string> std_vector1;
		ft::vector<std::string> ft_vector1;
		std_size = std_vector1.size();
		ft_size = ft_vector1.size();
		std_capacity = std_vector1.capacity();
		ft_capacity = ft_vector1.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;
		std::cout << std::endl;

		std::cout << "PARAMETER CONSTRUCTOR CHECK : " << std::endl;

		std::cout << "INT vector: " << std::endl;
		std::vector<int> std_vector2(5, 3);
		ft::vector<int> ft_vector2(5, 3);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&(*std_vector2
		.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "								OK =)"
					  << std::endl;
		else
			std::cout << "								NOK!";
		std::cout << std::endl;

		std::cout << "STRING vector: " << std::endl;
		std::vector<std::string> std_vector3(5, "bla");
		ft::vector<std::string> ft_vector3(5, "bla");
		std_size = std_vector3.size();
		ft_size = ft_vector3.size();
		std_capacity = std_vector3.capacity();
		ft_capacity = ft_vector3.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector3.size(); ++i)
			std::cout << std_vector3[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector3.size(); ++i)
			std::cout << ft_vector3[i] << " ";
		if (std_vector3.size() == ft_vector3.size() && std::equal(&(*std_vector3
				.begin()), &(*std_vector3.end()), &(*ft_vector3.begin())))
			std::cout << "					OK =)"
					  << std::endl;
		else
			std::cout << "					NOK!";
		std::cout << std::endl;

		std::cout << "INT with no value: " << std::endl;
		std::vector<int> std_vector4(5);
		ft::vector<int> ft_vector4(5);
		std_size = std_vector4.size();
		ft_size = ft_vector4.size();
		std_capacity = std_vector4.capacity();
		ft_capacity = ft_vector4.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector4.size(); ++i)
			std::cout << std_vector4[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector4.size(); ++i)
			std::cout << ft_vector4[i] << " ";
		if (std_vector4.size() == ft_vector4.size() && std::equal(&(*std_vector4
				.begin()), &(*std_vector4.end()), &(*ft_vector4.begin())))
			std::cout << "								OK =)"
					  << std::endl;
		else
			std::cout << "								NOK!";
		std::cout << std::endl;

//		std::cout << "Negative parameter with no value: " << std::endl;
//		ft::vector<int> ft_vector5(-5);

		std::cout << "RANGE CONSTRUCTOR CHECK: " << std::endl;
		std::vector<int> std_vector6(5, 5);
		ft::vector<int> ft_vector6(&(*std_vector6.begin()), &(*std_vector6.end
		()));
		std_size = std_vector6.size();
		ft_size = ft_vector6.size();
		std_capacity = std_vector6.capacity();
		ft_capacity = ft_vector6.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector6.size(); ++i)
			std::cout << std_vector6[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector6.size(); ++i)
			std::cout << ft_vector6[i] << " ";
		if (std_vector6.size() == ft_vector6.size() && std::equal(&(*std_vector6
				.begin()), &(*std_vector6.end()), &(*ft_vector6.begin())))
			std::cout << "								OK =)"
					  << std::endl;
		else
			std::cout << "								NOK!";
		std::cout << std::endl;

		std::cout << "COPY CONSTRUCTOR CHECK: " << std::endl;
		std::vector<int> std_vector7(std_vector4);
		ft::vector<int> ft_vector7(ft_vector4);
		std_size = std_vector7.size();
		ft_size = ft_vector7.size();
		std_capacity = std_vector7.capacity();
		ft_capacity = ft_vector7.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector7.size(); ++i)
			std::cout << std_vector7[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector7.size(); ++i)
			std::cout << ft_vector7[i] << " ";
		if (std_vector7.size() == ft_vector7.size() && std::equal(&(*std_vector7
				.begin()), &(*std_vector7.end()), &(*ft_vector7.begin())))
			std::cout << "								OK =)"
					  << std::endl;
		else
			std::cout << "								NOK!";
		std::cout << std::endl;

		std::cout << "OPERATOR= CHECK: " << std::endl;
		std::vector<int> std_vector8 = std_vector4;
		ft::vector<int> ft_vector8 = ft_vector4;
		std_size = std_vector8.size();
		ft_size = ft_vector8.size();
		std_capacity = std_vector8.capacity();
		ft_capacity = ft_vector8.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector8.size(); ++i)
			std::cout << std_vector8[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector8.size(); ++i)
			std::cout << ft_vector8[i] << " ";
		if (std_vector8.size() == ft_vector8.size() && std::equal(&(*std_vector8
				.begin()), &(*std_vector8.end()), &(*ft_vector8.begin())))
			std::cout << "								OK =)"
					  << std::endl;
		else
			std::cout << "								NOK!";
		std::cout << std::endl;

		std::cout << "BEGIN() | END | RBEGIN() | REND() | MAX_SIZE() | "
					 "PUSH_BACK() CHECK: "
		<< std::endl;
		std::vector<int> std_vector9;
		std_vector9.push_back(1);
		std_vector9.push_back(2);
		std_vector9.push_back(3);
		std_vector9.push_back(4);
		std_vector9.push_back(5);
		ft::vector<int> ft_vector9;
		ft_vector9.push_back(1);
		ft_vector9.push_back(2);
		ft_vector9.push_back(3);
		ft_vector9.push_back(4);
		ft_vector9.push_back(5);
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "								OK =)"
					  << std::endl;
		else
			std::cout << "								NOK!";
		std::cout << "std_vector.begin() = " << *std_vector9.begin() <<
		"	ft_vector.begin() = " << *ft_vector9.begin();
		if (*std_vector9.begin() == *ft_vector9.begin())
			std::cout << "								OK =)"
					  << std::endl;
		else
			std::cout << "								NOK!";
		std::cout << "std_vector.end() - 1 = " << *(std_vector9.end() - 1) <<
				  "	ft_vector.end() - 1 = " << *(ft_vector9.end() - 1);
		if (*(std_vector9.end() - 1) == *(ft_vector9.end() - 1))
			std::cout << "							OK =)"
					  << std::endl;
		else
			std::cout << "							NOK!";
		std::cout << "std_vector.rbegin() = " << *std_vector9.rbegin() <<
				  "	ft_vector.rbegin() = " << *ft_vector9.rbegin();
		if (*std_vector9.rbegin() == *ft_vector9.rbegin())
			std::cout << "								OK =)"
					  << std::endl;
		else
			std::cout << "								NOK!";
		std::cout << "std_vector.rend() - 1 = " << *(std_vector9.rend() - 1) <<
				  "	ft_vector.rend() - 1 = " << *(ft_vector9.rend() - 1);
		if (*(std_vector9.rend() - 1) == *(ft_vector9.rend() - 1))
			std::cout << "						OK =)"
					  << std::endl;
		else
			std::cout << "						NOK!";
		std::cout << "std_vector.max_size() = " << std_vector9.max_size() <<
				  "	ft_vector.max_size() = " << ft_vector9.max_size();
		if (std_vector9.max_size() == ft_vector9.max_size())
			std::cout << "		OK =)"
					  << std::endl;
		else
			std::cout << "		NOK!";
		std::cout << std::endl;

		std::cout << "RESIZE() CHECK: " << std::endl;
		std::cout << "N = SIZE" << std::endl;
		std_vector9.resize(5);
		ft_vector9.resize(5);
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "								OK =)"
					  << std::endl;
		else
			std::cout << "								NOK!";
		std::cout << "N < SIZE" << std::endl;
		std_vector9.resize(3);
		ft_vector9.resize(3);
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "								OK =)"
					  << std::endl;
		else
			std::cout << "								NOK!";
		std::cout << "N = CAPACITY" << std::endl;
		std_vector9.resize(8);
		ft_vector9.resize(8);
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "						OK =)"
					  << std::endl;
		else
			std::cout << "						NOK!";
		std::cout << "N > CAPACITY && N < 2 * CAPACITY" << std::endl;
		std_vector9.resize(9);
		ft_vector9.resize(9);
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "						OK =)"
					  << std::endl;
		else
			std::cout << "						NOK!";
		std::cout << "N > 2 * CAPACITY" << std::endl;
		std_vector9.resize(40);
		ft_vector9.resize(40);
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << std::endl;
		std::cout << "ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "		OK =)"
					  << std::endl;
		else
			std::cout << "		NOK!";

		std::cout << "RESIZE with parameter" << std::endl;
		std::cout << "N < SIZE" << std::endl;
		std_vector9.resize(5, 9);
		ft_vector9.resize(5, 9);
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << "ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "								OK =)"
					  << std::endl;
		else
			std::cout << "								NOK!";

		std::cout << "N > CAPACITY && N < 2 * CAPACITY" << std::endl;
		std_vector9.resize(41, 9);
		ft_vector9.resize(41, 9);
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"
					  << std::endl;
		else
			std::cout << "										NOK!"
					  << std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"
					  << std::endl;
		else
			std::cout << "									NOK!"
					  << std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << std::endl;
		std::cout << "ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "		OK =)" << std::endl;
		else
			std::cout << "		NOK!";
		std::cout << std::endl;

		std::cout << "EMPTY() CHECK: " << std::endl;
		std::cout << "std_vector is empty ? - " << std_vector9.empty();
		std::cout << "	ft_vector is empty ? - " << ft_vector9.empty();
		if (std_vector9.empty() == ft_vector9.empty())
			std::cout << "						OK =)" << std::endl;
		else
			std::cout << "						NOK!";
		std::cout << std::endl;

		std::cout << "RESERVE() CHECK: " << std::endl;








	}
	catch (std::exception &x)
	{
		std::cerr << "Error: " << x.what() << std::endl;
	}
	return (0);
}