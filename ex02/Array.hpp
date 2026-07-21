/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 23:37:20 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/21 23:41:42 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

template <typename T>
class Array
{
	private:
	T* _arr;
	unsigned int _size;

	std::string outOfRangeMsg(unsigned int index) const
	{
		std::ostringstream oss;
		oss << "Array: index " << index << " is out of bounds (size " << _size << ")";
		return (oss.str());
	}
	
	public:
	Array() : _arr(NULL), _size(0) {}
 
	explicit Array(unsigned int n) : _arr(NULL), _size(n)
	{
		if (_size > 0)
			_arr = new T[_size]();
	}
 
	Array(const Array& other) : _arr(NULL), _size(0)
	{
		*this = other;
	}
 
	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			T* newArr = NULL;
			if (other._size > 0)
			{
				newArr = new T[other._size];
				for (unsigned int i = 0; i < other._size; ++i)
					newArr[i] = other._arr[i];
			}
			delete[] _arr;
			_arr = newArr;
			_size = other._size;
		}
		return (*this);
	}
 
	~Array()
	{
		delete[] _arr;
	}
 
	T& operator[](unsigned int index)
	{
		if (index >= _size)
			throw std::out_of_range(outOfRangeMsg(index));
		return (_arr[index]);
	}
 
	const T& operator[](unsigned int index) const
	{
		if (index >= _size)
			throw std::out_of_range(outOfRangeMsg(index));
		return (_arr[index]);
	}
 
	unsigned int size() const
	{
		return (_size);
	}
 
};


#endif