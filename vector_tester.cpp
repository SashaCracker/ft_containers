#include <vector>
#include "vector.hpp"
#include <algorithm>

int main()
{
	try
	{
		std::cout << "DEFAULT CONSTRUCTOR CHECK : " << std::endl;

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
		std::cout << std::endl;
		std::cout << "ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
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
		std::cout << std::endl;
		std::cout << "ft_vector: ";
		for (size_t i = 0; i < ft_vector3.size(); ++i)
			std::cout << ft_vector3[i] << " ";
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
		std::cout << std::endl;
		std::cout << "ft_vector: ";
		for (size_t i = 0; i < ft_vector4.size(); ++i)
			std::cout << ft_vector4[i] << " ";
		std::cout << std::endl;

//		std::cout << "Negative parameter with no value: " << std::endl;
//		ft::vector<int> ft_vector5(-5);
//		std::vector<int> std_vector5(-5);
//		std_size = std_vector5.size();
//		ft_size = ft_vector5.size();
//		std_capacity = std_vector5.capacity();
//		ft_capacity = ft_vector5.capacity();
//		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
//		if (std_size == ft_size)
//			std::cout << "										OK =)"
//					  << std::endl;
//		else
//			std::cout << "										NOK!"
//					  << std::endl;
//		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
//				  ft_capacity;
//		if (std_capacity == ft_capacity)
//			std::cout << "									OK =)"
//					  << std::endl;
//		else
//			std::cout << "									NOK!"
//					  << std::endl;
//		std::cout << "std_vector: ";
//		for (size_t i = 0; i < std_vector5.size(); ++i)
//			std::cout << std_vector5[i] << " ";
//		std::cout << std::endl;
//		std::cout << "ft_vector: ";
//		for (size_t i = 0; i < ft_vector5.size(); ++i)
//			std::cout << ft_vector5[i] << " ";
//		std::cout << std::endl;

		std::cout << "RANGE CONSTRUCTOR CHECK: " << std::endl;
		std::cout << "Applicable parameters: " << std::endl;
		std::vector<int> std_vector6(5, 5);
		ft::vector<int> ft_vector6(std_vector6.begin(), std_vector6.end());
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
		std::cout << std::endl;
		std::cout << "ft_vector: ";
		for (size_t i = 0; i < ft_vector6.size(); ++i)
			std::cout << ft_vector6[i] << " ";
		std::cout << std::endl;

		std::cout << " NOT Applicable parameters: " << std::endl;
		std::vector<int> std_vector7(5, 5);
		std::vector<int>::iterator Iter1 = std_vector7.begin();
		std::vector<int>::iterator Iter2 = std_vector7.end();
		--Iter1;
		ft::vector<int> ft_vector7(Iter1, Iter2);
		std::cout << std::endl;
	}
	catch (std::exception &x)
	{
		std::cerr << x.what() << std::endl;
	}
	return (0);
}