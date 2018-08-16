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
 * 	@date    14/08/2018  
 * 	@version 1.1
 * 	
 * 	added fibonacci search, jump search and ternary search. Also added recursive versions of binary and ternary search.
 * 	
 * 	@bug No know bugs.
 */









#ifndef SEARCH_H
#define SEARCH_H


#include <cmath>
#include <climits>

namespace custom
{
	namespace
	{
		//fibonnaci numbers up to INT_MAX.
		const std::size_t fib[48] = {
			0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,
			10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578,
			5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296,
			433494437, 701408733, 1134903170, 1836311903, INT_MAX
		};

		// min function
		template <class T> const T& min(const T& a, const T& b)
		{
			return a > b ? b : a;
		}

		template<class Iterator, class Value> Iterator lower_bound(Iterator first, Iterator last, const Value& value )
		{
			Iterator mid;
			while(last > first)
			{
				mid = (first + ((last-first)/2));
				if(value > *mid)
				{
					first = mid + 1;
				}
				else
				{
					last = mid;
				}
			}
			return first;
		}

		template<class Iterator, class Value> Iterator _bsearch(Iterator first, Iterator last,const Value& value)
		{
			//out of the interval.
			if(first > last)
			{
				//returns last
				return last;
			}
			// get mid
			std::size_t mid = (last-first)/2;
			// if mid is the value
			if(*(first + mid) == value)
			{
				//returns a pointer to mid,
				return (first + mid);
			}
			// if mid value is bigger than the value, call to interval first-mid-1, otherwise interval mid + 1 - last.
			return *(first + mid) > value ? _bsearch(first, (first + (mid-1)), value) : _bsearch((first + (mid + 1)), last, value);
		} 

		template<class Iterator, class Value> Iterator _tsearch(Iterator first, Iterator last,const Value& value)
		{
			// out of the interval
			if(first > last)
			{
				// returns last.
				return last;
			}
			// get the size of the segment
			std::size_t pos = (last-first)/3;
			//  first upperbound and last lowerbound.
			Iterator mid1 = (first + pos), mid2 = (last - pos);
			// if mid1 is the value.
			if(*mid1 == value)
			{
				//returns mid1.
				return mid1;
			}
			//if mid2 is the value
			else if(*mid2 == value)
			{
				// returns mid2.
				return mid2;
			}
			// if the value is lesser than the mid1.
			else if(value < *mid1)
			{
				// the value is in the interval first - mid - 1.
				return _tsearch(first, mid1 - 1, value);
			}
			//value is bigger than mid2
			else if(value > *mid2)
			{
				// the value is in the interval mid2 + 1 - last.
				return _tsearch(mid2 + 1, last, value);
			}
			//otherwise, it is between the interval mid1 + 1-mid2-1
			else
			{
				return _tsearch(mid1 + 1, mid2 - 1, value);
			}
		}
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
	template<class Iterator, class Value> Iterator lsearch(Iterator first, Iterator last,const Value& value)
	{
		while(first != last && *first != value)
		{
			++first;
		}
		return first;
	}

	/**
	 * @brief      performs a binary search in a container. Iterative implementation.
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
	template<class Iterator, class Value> Iterator bsearch(Iterator first, Iterator last,const Value& value)
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
	 * @brief      performs a binary search in a cointainer. Recursirve implementation.
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
	template<class Iterator, class Value> Iterator bsearchR(Iterator first, Iterator last,const Value& value)
	{
		Iterator found = _bsearch(first,last,value);
		return *found == value ? found : last; 
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
	template<class Iterator, class Value> Iterator tsearch(Iterator first, Iterator last,const Value& value)
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
	 * @brief      performs a ternary search in a container. Recursive implementation
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
	template<class Iterator, class Value> Iterator tsearchR(Iterator first, Iterator last,const Value& value)
	{
		Iterator found = _tsearch(first,last,value);
		return *found == value ? found : last; 
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
	template<class Iterator, class Value> Iterator jsearch(Iterator first, Iterator last, const Value& value)
	{
		//step is the size of the jump.
		std::size_t step, prev, n = last - first, sqrtN;
		sqrtN = sqrt(n);
		prev = step = sqrtN;
		// while the postion we are is lesser than the value, we make jumps.
		while(prev < n && value > *(first + (min(step, n) - 1)))
		{
			prev = step;
			step += sqrtN;
		}
		
		//do a linear search for the block.
		while(prev < n && value > *(first + prev))
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
		if(prev < n && *(first + prev) == value)
		{
			return (first + prev);
		}
		//not found, return last.
		return last;
	}

	/**
	 * @brief      performs a fibonacci search in a container.
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
	template<class Iterator, class Value> Iterator fsearch(Iterator first, Iterator last, const Value& value)
	{
		std::size_t n = (last-first) - 1,k = 0;
		// position of the first fib bigger than n.
		
		// otimization.
		const std::size_t * lb = lower_bound(fib, fib + (sizeof(fib)/sizeof(fib[0])), n);		
		k = (lb == (fib + (sizeof(fib)/sizeof(fib[0]))) ? (lb-1) : (lb)) - fib;
		/*
		while(n > fib[k])
			++k;
		*/
		Iterator mid, tmp = last;
		// while in the interval
		while(first <= tmp)
		{
			// length of the interval
			n = tmp - first;

			// we get the mid based on the fibonacci series. the min is a "supposed speed up". why? let's say, the fib number is bigger than the current segment? if it is, i set mid as the size of the segment.
			mid = (first + (min(fib[k-1] - 1, n)));
			// we found.
			if(*mid == value)
			{
				//reutrns mid
				return mid;
			}
			// mid is bigger da value, the set last as mid -1 and move to the previous fibonacci.
			else if(*mid > value)
			{
				tmp = mid - 1;
				--k;
			}
			// so it is bigger than first, move to mid + 1 and lets visit the k - 2 fibonacci.
			else
			{
				first = mid + 1;
				k -= 2;
			}
		}
		// returns last.
		return last;
	}
}


#endif