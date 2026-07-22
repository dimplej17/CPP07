/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:59:52 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/22 15:01:54 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>
#include <iostream>
#include <string>

template <typename T>
void iter (T* arr, size_t const arr_len, void (*f)(T&)) // for functions that would modify the array, ex. increment()
{
	for (size_t i = 0; i < arr_len; i++)
		f(arr[i]);
}

template <typename T>
void iter (const T* arr, size_t const arr_len, void (*f) (const T&))
{
	for (size_t i = 0; i < arr_len; i++)
		f(arr[i]);
}

template <typename T>
void print(const T &x) // const so that it works for both const and non-const objects
{
	std::cout << x << std::endl;
}

#endif