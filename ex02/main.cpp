/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 23:42:34 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/21 23:43:04 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// A non-trivial class type, to show the template isn't just working for built-in types by accident
class Point
{
public:
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
 
	int x;
	int y;
};
 
static void testEmptyArray()
{
	std::cout << "=== default constructor (empty array) ===" << std::endl;
	Array<int> a;
	std::cout << "size: " << a.size() << std::endl;
	try
	{
		a[0] = 42;
		std::cout << "KO: should have thrown" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "OK, caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}
 
static void testDefaultInit()
{
	std::cout << "=== parameterized constructor: default-init check ===" << std::endl;
	Array<int> a(5);
	std::cout << "size: " << a.size() << std::endl;
	for (unsigned int i = 0; i < a.size(); ++i)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;
 
	Array<Point> pts(3);
	for (unsigned int i = 0; i < pts.size(); ++i)
		std::cout << "pts[" << i << "] = (" << pts[i].x << ", " << pts[i].y << ")" << std::endl;
	std::cout << std::endl;
}
 
static void testDeepCopyConstructor()
{
	std::cout << "=== copy constructor independence ===" << std::endl;
	Array<int> original(3);
	for (unsigned int i = 0; i < original.size(); ++i)
		original[i] = static_cast<int>(i) * 10;
 
	Array<int> copy(original);
 
	original[0] = 999;
	copy[1] = -1;
 
	std::cout << "original: ";
	for (unsigned int i = 0; i < original.size(); ++i)
		std::cout << original[i] << " ";
	std::cout << std::endl;
 
	std::cout << "copy:	 ";
	for (unsigned int i = 0; i < copy.size(); ++i)
		std::cout << copy[i] << " ";
	std::cout << std::endl << std::endl;
}
 
static void testDeepCopyAssignment()
{
	std::cout << "=== assignment operator independence ===" << std::endl;
	Array<std::string> a(2);
	a[0] = "hello";
	a[1] = "world";
 
	Array<std::string> b(5);
	b = a;
 
	a[0] = "changed";
	b[1] = "also changed";
 
	std::cout << "a: ";
	for (unsigned int i = 0; i < a.size(); ++i)
		std::cout << "[" << a[i] << "] ";
	std::cout << std::endl;
 
	std::cout << "b: ";
	for (unsigned int i = 0; i < b.size(); ++i)
		std::cout << "[" << b[i] << "] ";
	std::cout << std::endl;
 
	// self-assignment shouldn't corrupt or double-free anything
	b = b;
	std::cout << "b after self-assignment, size: " << b.size() << std::endl;
	std::cout << std::endl;
}
 
static void testOutOfBounds()
{
	std::cout << "=== out-of-bounds access ===" << std::endl;
	Array<int> a(4);
	try
	{
		std::cout << a[10] << std::endl;
		std::cout << "KO: should have thrown" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "OK, caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}
 
static void testConstAccess(const Array<int>& a)
{
	std::cout << "=== const correctness ===" << std::endl;
	std::cout << "const size(): " << a.size() << std::endl;
	for (unsigned int i = 0; i < a.size(); ++i)
		std::cout << "const a[" << i << "] = " << a[i] << std::endl;
	std::cout << std::endl;
}
 
int main()
{
	testEmptyArray();
	testDefaultInit();
	testDeepCopyConstructor();
	testDeepCopyAssignment();
	testOutOfBounds();
 
	Array<int> forConst(3);
	for (unsigned int i = 0; i < forConst.size(); ++i)
		forConst[i] = static_cast<int>(i) * 100;
	testConstAccess(forConst);
 
	return (0);
}