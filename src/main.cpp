#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <queue>


#include "sort.h"
#include "queue.h"
#include "stack.h"
#include "array.h"
#include "search.h"


void test_containers();
void test_sort_algorithms();
void test_searching_algorithms();


int main()
{
	test_containers();
	test_sort_algorithms();
	test_searching_algorithms();
	
	return 0;
}

void test_containers()
{
	std::cout << "\n\n-----ARRAY TESTING-----" << std::endl;
	custom::array<int, 3> a1 = { 1, 2, 3}, a3 = {7, 8, 9};
	std::array<int, 3> a2 = { 4, 5, 6};

	a1 = a3;
	for (std::size_t i = 0; i < a1.size(); ++i)
	{
		std::cout << "custom item[" << i << "]:" << a1.at(i) << std::endl;
		std::cout << "std item[" << i << "]:" << a2.at(i) << std::endl;
	}
	a1.fill(666);	
	int i = 0;
	for (auto &it : a1)
	{
		std::cout << "custom item[" << i << "]:" << it << std::endl;
		i++;
	}
	std::cout << "\n\n-----QUEUE TESTING-----" << std::endl;
	custom::queue<int> q1, q3;
	std::queue<int> q2;

	q3.push(10);
	q3.push(15);
	q2.push(10);
	q2.push(15);

	q1 = q3;
	std::cout << "total elements:" << q1.size() << std::endl;
	while (!q1.empty())
	{
		std::cout << "custom queue:" << q1.front() << std::endl;
		std::cout << "std queue:" << q2.front() << std::endl;
		q1.pop();
		q2.pop();
	}




	std::cout << "\n\n-----STACK TESTING-----" << std::endl;
	custom::stack<int> s1, s3;
	std::stack<int> s2;

	s3.push(10);
	s3.push(15);
	s2.push(10);
	s2.push(15);

	s1 = s3;
	std::cout << "total elements:" << s1.size() << std::endl;
	while (!s1.empty())
	{
		std::cout << "custom stack:" << s1.top() << std::endl;
		std::cout << "std stack:" << s2.top() << std::endl;
		s1.pop();
		s2.pop();
	}
}

void test_sort_algorithms()
{
	std::cout << "\n\n-----SORTING ALGORITHMS TESTING-----" << std::endl;
	int values[] = {55, 10, 44, 99, 34};

	std::vector<int> v;
	v.insert(v.end(), values, values + 5);
	custom::bubble_sort<int>(v.begin(), v.end());
	std::cout << "Bubble Sort:";
	for (std::size_t i = 0; i < v.size(); ++i)
	{
		std::cout << (i ? " " : "") << v[i];
	}
	std::cout << std::endl;
	v.clear();
	v.insert(v.end(), values, values + 5);
	custom::insertion_sort<int>(v.begin(), v.end());
	std::cout << "Insetion Sort:";
	for (std::size_t i = 0; i < v.size(); ++i)
	{
		std::cout << (i ? " " : "") << v[i];
	}
	std::cout << std::endl;
	v.clear();
	v.insert(v.end(), values, values + 5);
	custom::selection_sort<int>(v.begin(), v.end());
	std::cout << "Selection Sort:";
	for (std::size_t i = 0; i < v.size(); ++i)
	{
		std::cout << (i ? " " : "") << v[i];
	}
	std::cout << std::endl;
	v.clear();
	v.insert(v.end(), values, values + 5);
	custom::quick_sort<int>(v.begin(), v.end());
	std::cout << "Quick Sort:";
	for (std::size_t i = 0; i < v.size(); ++i)
	{
		std::cout << (i ? " " : "") << v[i];
	}
	std::cout << std::endl;
	v.clear();
	v.insert(v.end(), values, values + 5);
	custom::merge_sort<int>(v.begin(), v.end());
	std::cout << "Merge Sort:";
	for (std::size_t i = 0; i < v.size(); ++i)
	{
		std::cout << (i ? " " : "") << v[i];
	}
	std::cout << std::endl;

}


void test_searching_algorithms()
{
	std::cout << "\n\n-----SEARCHING TESTING-----" << std::endl;
	std::vector<int> searching_v = {1,2,4,5,88,-50,33,-22,134,-99,-5555,102};
	
	auto found = custom::lsearch(searching_v.begin(),searching_v.end(), -22);

	if(found != searching_v.end())
		std::cout << "Linear search: " << *found << std::endl;
	else
		std::cout << "Linear search: " << "not found" << std::endl;	

	custom::merge_sort<int>(searching_v.begin(),searching_v.end());

	found = custom::bsearch(searching_v.begin(),searching_v.end(), 33);

	if(found != searching_v.end())
		std::cout << "Binary search iterative: " << *found << std::endl;
	else
		std::cout << "Binary search iterative: " << "not found" << std::endl;


	found = custom::bsearchR(searching_v.begin(),searching_v.end(), 33);

	if(found != searching_v.end())
		std::cout << "Binary search recursive: " << *found << std::endl;
	else
		std::cout << "Binary search recursive: " << "not found" << std::endl;

	found = custom::tsearch(searching_v.begin(),searching_v.end(), 33);

	if(found != searching_v.end())
		std::cout << "Ternary search iterative: " << *found << std::endl;
	else
		std::cout << "Ternary search iterative: " << "not found" << std::endl;

	found = custom::tsearchR(searching_v.begin(),searching_v.end(), 33);

	if(found != searching_v.end())
		std::cout << "Ternary search recursive: " << *found << std::endl;
	else
		std::cout << "Ternary search recursive: " << "not found" << std::endl;



	found = custom::jsearch(searching_v.begin(),searching_v.end(), 102);

	if(found != searching_v.end())
		std::cout << "Jump search: " << *found << std::endl;
	else
		std::cout << "Jump search: " << "not found" << std::endl;


	found = custom::fsearch(searching_v.begin(),searching_v.end(), 88);

	if(found != searching_v.end())
		std::cout << "Fibonacci search: " << *found << std::endl;
	else
		std::cout << "Fibonacci search: " << "not found" << std::endl;

}