/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 18:00:27 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/22 16:56:46 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main (void)
{
	int arr[] = {1, 2, 3, 4};
	double f_arr[] = {45.6,65.8,75.3,85.2};
	const int const_arr[] = {42, 43, 44, 45};
	char s[] = {'d','j'};
	std::string str[] = {"hello", "world", "42"};
	
	iter(arr, 4, print);
	iter(f_arr, 4, print);
	iter(const_arr, 4, print);
	iter(s, 2, print);
	iter(str, 3, print);

	return (0);
}