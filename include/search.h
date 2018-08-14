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


#include <cmath>

namespace custom
{
	namespace
	{
		typedef long long ll;

		template <class T> T& min(T& a, T& b)
		{
			return a < b ? a : a;
		}
		// fast doubling , Karatsuba multiplication.
		// for implementation of the fibonnaci search.
		/*
		ll fib(ll n, ll mod)
		{
			ll a = 0, b = 1, c , d, e;

			for (ll i = 63; i >= 0; --i)
			{
				// + mod conserta.
				d = (a % mod) * ((b % mod) * 2 - (a % mod) + mod),
				e = (a % mod) * (a % mod) + (b % mod) * (b % mod);
				a = d % mod;
				b = e % mod;

				if ((n >> i) & 1)
				{
					c = (a + b) % mod;
					a = b;
					b = c;
				}
			}
			return a;
		}*/
	}
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
			//get mid.
			mid = (first + ((tmp-first)/2));
			// it is equal?
			if(*mid == value)
			{
				//retuns the current position.
				return mid;
			}
			// mid is bigger?
			else if(*mid > value)
			{
				//make last as mid -1.
				tmp = mid - 1;
			}
			else
			{
				//otherwise, make first to be mid + 1
				first = mid + 1;
			}
		}
		// not found, returns last.
		return last;
	}

	/**
	 * @brief      performs a ternary search in a container.
	 *
	 * @param[in]  first     The first, points to the first element of the container
	 * @param[in]  last      The last, points to the last element of the container
	 * @param[in]  value     The value be searched.
	 *
	 * @tparam     Iterator  Iterator
	 * @tparam     Value     Value to be searched
	 *
	 * @return     a pointer to the element, otherwise returns last.
	 */
	template<class Iterator, class Value> Iterator tsearch(Iterator first, Iterator last, Value value)
	{
		Iterator mid1,mid2,tmp = last;
		//only calculate once.
		std::size_t pos;
		while(first <= tmp)
		{
			// get the position.
			pos = (tmp-first)/3;
			// upper bound of first
			mid1 = (first + pos);
			// lower bound of last.
			mid2 = (tmp - pos);

			// it is mid1?
			if(*mid1 == value)
			{
				//return mid1.
				return mid1;
			}
			// it is mid2?
			else if(*mid2 == value)
			{
				// returns mid2
				return mid2;
			}
			// mid1 is bigger
			else if(value < *mid1)
			{
				// set last as mid1-1
				tmp = mid1 - 1;
			}
			//value is bigger than mid2
			else if(value > *mid2)
			{
				//set first as mid2 + 1
				first = mid2 + 1;
			}
			//otherwise, it is between the interval mid1 + 1-mid2-1
			else
			{
				//set first as mid1 + 1
				first = mid1 + 1;
				//set last as mid2 - 1
				tmp = mid2 - 1;
			}
		}
		return last;
	}

	/**
	 * @brief      performs a jump search in a container.
	 *
	 * @param[in]  first     The first, points to the first element of the container
	 * @param[in]  last      The last, points to the last element of the container
	 * @param[in]  value     The value be searched.
	 *
	 * @tparam     Iterator  Iterator
	 * @tparam     Value     Value to be searched
	 *
	 * @return     a pointer to the element, otherwise returns last.
	 */
	template<class Iterator, class Value> Iterator jsearch(Iterator first, Iterator last, Value value)
	{
		//step is the size of the jump.
		std::size_t step, prev, n = last - first, sqrtN;
		sqrtN = sqrt(n);
		prev = step = sqrtN;
		// while the postion we are is lesser than the value, we make jumps.
		while(value > *(first + (min(step, n) - 1)))
		{
			prev = step;
			step += sqrtN;
			if(prev >= n)
			{
				return last;
			}
		}
		//do a linear search for the block.
		while(value > *(first + prev))
		{
			++prev;
			//block is ended. therefore, ther evalue is not in the array.
			if(prev == min(step,n))
			{
				//return last.
				return last;
			}
		}
		//found?
		if(*(first + prev) == value)
		{
			return (first + prev);
		}
		//not found, return last.
		return last;
	}
}


#endif