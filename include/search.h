/** 
 *  @file    search.h
 *  @author  Leonardo Igor de Oliveira Cavalcante (https://github.com/bufige, a.k.a, bufige)
 *  @date    11/08/2018  
 *  @version 1.0 
 *  
 *  @brief This is my implementation of some of the most common searching algorithms, usually common in programming courses.
 *
 *  
 *  This is a implementation of some of the most common searching algorithms for practice, it features the most common searching algorithms
 *  and briefs explanations of what it does and how it works in each step.
 *  
 *  
 *  @bug No known bugs.
 *
 */









#ifndef SEARCH_H
#define SEARCH_H


namespace custom
{

	/**
	 * @brief      performs a linear search in a container.
	 *
	 * @param[in]  first     The first, points to the first element of the container.
	 * @param[in]  last      The last, points to the last element of the container.
	 * @param[in]  value     The value to be searched.
	 *
	 * @tparam     Iterator  Iterator
	 * @tparam     Value     Value to be searched.
	 *
	 * @return     a pointer to the element, otherwise returns last.
	 */
	template<class Iterator, class Value> Iterator lsearch(Iterator first, Iterator last, Value value)
	{
		while(first != last && *first != value)
		{
			++first;
		}
		return first;
	}

	/**
	 * @brief      performs a binary search in a container.
	 *
	 * @param[in]  first     The first, points to the first element of the container.
	 * @param[in]  last      The last, points to the last element of the container.
	 * @param[in]  value     The value to be searched.
	 *
	 * @tparam     Iterator  Iterator
	 * @tparam     Value     Value to be searched.
	 *
	 * @return     a pointer to the element, otherwise returns last.
	 */
	template<class Iterator, class Value> Iterator bsearch(Iterator first, Iterator last, Value value)
	{
		Iterator mid, tmp = last;
		while(first <= tmp)
		{
			mid = (first + ((tmp-first)/2));
			if(*mid == value)
			{
				return mid;
			}
			else if(*mid > value)
			{
				tmp = mid - 1;
			}
			else
			{
				first = mid + 1;
			}
		}
		return last;
	}
}


#endif