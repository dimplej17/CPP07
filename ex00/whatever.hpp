/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 16:07:27 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/21 16:13:30 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T> // means idk the type yet, I'll call it T
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T& a, T& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T max(T& a, T& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif