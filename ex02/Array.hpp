/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 23:37:20 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/22 16:13:52 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array
{
	private:
	T* _arr;
	unsigned int _size;
	
	public:
	// Nested exception class - must be declared before it's used anywhere
	class OutOfRangeException : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return ("Index is out of bounds");
		}
	};
	
	// Construction with no parameter
	Array() : _arr(NULL), _size(0) {}
 
	// Construction with an unsigned int n as a parameter
	explicit Array(unsigned int n) : _arr(NULL), _size(n)
	{
		if (_size > 0)
			_arr = new T[_size](); // value initialisation
	}
 
	// Copy Assignment Operator
	Array& operator=(const Array& real)
	{
		if (this != &real)
		{
			T* newArr = NULL;
			if (real._size > 0)
			{
				newArr = new T[real._size];
				for (unsigned int i = 0; i < real._size; ++i)
					newArr[i] = real._arr[i];
			}
			delete[] _arr;
			_arr = newArr;
			_size = real._size;
		}
		return (*this);
	}

	// Copy Constructor
	Array(const Array& real) : _arr(NULL), _size(0)
	{
		*this = real;
	}
 
	~Array()
	{
		delete[] _arr;
	}

	// Elements can be accessed through the subscript operator: [ ]
	T& operator[](unsigned int index)
	{
		if (index >= _size)
			throw OutOfRangeException();
		return (_arr[index]);
	}
 
	const T& operator[](unsigned int index) const
	{
		if (index >= _size)
			throw OutOfRangeException();
		return (_arr[index]);
	}
 
	unsigned int size() const
	{
		return (_size);
	}
 
};


#endif