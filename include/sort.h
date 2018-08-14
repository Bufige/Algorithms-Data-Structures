/** 
 *  @file    sort.h
 *  @author  Leonardo Igor de Oliveira Cavalcante (https://github.com/bufige, a.k.a, bufige)
 *  @date    05/08/2018  
 *  @version 1.0 
 *  
 *  @brief This is my implementation of some of the most common sorting algorithms, usually common in programming courses.
 *
 *  
 *  This is a implementation of some of the most common sorting algorithms for practice, it features the most common sorting algorithms
 *  and briefs explanations of what it does and how it works in each step.
 *  
 *  
 *  @bug No known bugs.
 *
 */









#ifndef SORT_H
#define SORT_H


#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace custom
{
/*
 *	private members of the current namespace.
*/
namespace
{
/**
 * @brief      partition function from quick sort.
 *
 * @param[in]  first     pointing to the beggining.
 * @param[in]  last      pointing to the end.
 *
 * @tparam     T         description
 * @tparam     Iterator  {iterator
 *
 * @return     returns a pointer to the pivot
 */
template<class T, class Iterator> Iterator partition(Iterator first, Iterator last)
{
	Iterator i = first, k = last - 1, pos = (first + ((last - first) / 2));
	T pivot = *pos;
	while (1)
	{
		while (*i < pivot && i < last)
			++i;
		while (*k >= pivot && k > first)
			k--;
		if (i >= k)
			break;
		std::iter_swap(i, k);
	}
	std::iter_swap(pos, i);
	return i;
}

/**
 * @brief      merge function from merge sort
 *
 * @param[in]  first     pointing to the beggining.
 * @param      b         array hold the temporary values.
 * @param[in]  low       The low index
 * @param[in]  mid       The middle index
 * @param[in]  high      The high index
 *
 * @tparam     T          type
 * @tparam     Iterator  iterator
 */
template<class T, class Iterator> void merge(Iterator first, T b[], std::size_t low, std::size_t mid, std::size_t high)
{
	std::size_t left = low, right = mid + 1, index  = low, i, rest;
	// copy the array.
	for (i = low; i <= high; ++i)
	{
		b[i] = *(first + i);
	}
	//merge back to original container.
	while (left <= mid && right <= high)
	{
		//if the left left value is smaller than the right value.
		if (b[left] <= b[right])
		{
			*(first + index++) = b[left++];
		}
		else //otherwise.
		{
			*(first + index++) = b[right++];
		}
	}
	// copy whats left of the left side.
	rest = mid - left + 1;
	for ( i = 0; i < rest; ++i)
	{
		*(first + index++) = b[left + i];
	}
}


/**
 * @brief      merge sort algorithm helper function
 *
 * @param[in]  first     The first
 * @param      b         array hold the temporary values.
 * @param[in]  low       The low index
 * @param[in]  high      The high index
 *
 * @tparam     T         type
 * @tparam     Iterator  iterator
 */
template<class T, class Iterator> void merge_sort(Iterator first, T b[], std::size_t low, std::size_t high)
{
	// tranversed.
	if (low >= high)
		return ;
	// get middle.
	std::size_t mid = (low + high) >> 1;
	//left side.
	merge_sort<T>(first, b, low, mid);
	//right side
	merge_sort<T>(first, b, mid + 1, high);
	//merge right and left.
	merge<T>(first, b, low, mid, high);
}

/**
 * @brief      { merge sort algorithm - main function}
 *
 * @param[in]  first     The first
 * @param[in]  last      The last
 *
 * @tparam     T         type
 * @tparam     Iterator  iterator
 */
}
/**
 * @brief       bubble sort algoritmh.
 *
 * @param[in]  first     pointing to the beggining.
 * @param[in]  last      pointing to the end.
 *
 * @tparam     T          type
 * @tparam     Iterator   iterator
 */
template<class T, class Iterator> void bubble_sort(Iterator first, Iterator last)
{
	// keeps track if the container is sorted.
	bool swapped = 1;
	for (std::size_t i = 1, sz = last - first, k; i < sz ; ++i)
	{
		// let's say it is sorted.
		swapped = 0;
		for (k = 0; k < sz - i; ++k)
		{
			// we found a swap that could be made, therefore it is not sorted yet.
			if (*(first + k) > *(first + k + 1))
			{
				//swap the items.
				std::iter_swap((first + k), (first + k + 1));
				// set as swapped.
				swapped = 1;
			}
		}
		// if not swap has ocurred, therefore it is sorted.
		if (!swapped)
			break;
	}
}


/**
 * @brief      insertion sort algorithm
 *
 * @param[in]  first     pointing to the beggining.
 * @param[in]  last      pointing to the end.
 *
 * @tparam     T         type
 * @tparam     Iterator  iterator
 */
template<class T, class Iterator> void insertion_sort(Iterator first, Iterator last)
{
	T tmp;
	for (std::size_t i = 1, sz = last - first, k; i < sz; ++i)
	{
		//pick current item.
		tmp = *(first + i);
		//swap it into the sorted sequence.
		for (k = i; k > 0 && *(first + k - 1) > tmp; --k)
		{
			*(first + k) = *(first + k - 1);
		}
		//update its position.
		*(first + k) = tmp;
	}
}


/**
 * @brief       insertion sort algorithm
 *
 * @param[in]  first     pointing to the beggining.
 * @param[in]  last      pointing to the end.
 *
 * @tparam     T          type
 * @tparam     Iterator   iterator
 */
template<class T, class Iterator> void selection_sort(Iterator first, Iterator last)
{
	//pick the lowest element and put it at the first position.
	// then just get the second lowest and put it at the second position and so on.
	while (first != last)
	{
		std::iter_swap(first, std::min_element(first, last));
		++first;
	}
}


/**
 * @brief      quick sort algorithm
 *
 * @param[in]  first     pointing to the beggining.
 * @param[in]  last      pointing to the end.
 *
 * @tparam     T         type
 * @tparam     Iterator  iterator
 */
template<class T, class Iterator> void quick_sort(Iterator first, Iterator last)
{
	if (last - first <= 1)
		return ;
	Iterator pivot = partition<T>(first, last);
	quick_sort<T>(first, pivot);
	quick_sort<T>(pivot + 1, last);
}
/**
 * @brief      merge function from merge sort
 *
 * @param[in]  first     pointing to the beggining.
 * @param      b         array hold the temporary values.
 * @param[in]  low       The low index
 * @param[in]  mid       The middle index
 * @param[in]  high      The high index
 *
 * @tparam     T          type
 * @tparam     Iterator  iterator
 */
template<class T, class Iterator> void merge_sort(Iterator first, Iterator last)
{
	//size of the partition.
	std::size_t sz = last - first;
	// temporary array to save values.
	T * b = new T[sz];
	// call sort.
	merge_sort<T>(first, b, 0, sz - 1);
	// delete array.
	delete[] b;
}
}
#endif