/** 
 *  @file    array.h
 *  @author  Leonardo Igor de Oliveira Cavalcante (https://github.com/bufige, a.k.a, bufige)
 *  @date    05/08/2018  
 *  @version 1.0 
 *  
 *  @brief This is my implementation of the array container.
 *
 *  
 *  This is a implementation of the array container for practice, it features the core functions that the STL supports
 *  and briefs explanations of what it does and how it works in each step.
 *  
 *  
 *  @bug No known bugs.
 *
 */









#ifndef ARRAY_H
#define ARRAY_H


#include <algorithm>
#include <cstddef>
#include <iostream>
#include <exception>

namespace custom
{
	/**
	 * @brief      container array.
	 *
	 * @tparam     T     type
	 * @tparam     sz    size
	 */
	template<class T, int sz> class array
	{

		public:

			/**
			 * @brief      Default constructor.
			 */
			array();

			/**
			 * @brief      Constructs the object as a copy of the other container.
			 *
			 * @param[in]  other  The other container
			 */
			array(const array<T, sz> &other);

			/**
			 * @brief      Constructs the object with a initializer list -> {a1,a2,a3,...}
			 *
			 * @param[in]  l     initializer list
			 */
			array(const std::initializer_list<T> &l);

			/**
			 * @brief      Destroys the object. clear all the data.
			 */
			~array();

			/**
			 * @brief      acess the a position of the container.
			 *
			 * @param[in]  pos   The index to be acessed
			 *
			 * @return     returns a reference to the container.
			 */
			T& at(const std::size_t &pos);

			/**
			 * @brief      reference to the front of the container.
			 *
			 * @return     a reference to the front of the container.
			 */
			T& front();

			/**
			 * @brief      reference to the back of the container.
			 *
			 * @return     a reference to the back of the container.
			 */
			T& back();

			/**
			 * @brief      check if the container is empty
			 *
			 * @return     true or false
			 */
			bool empty();

			
			/**
			 * @brief      fill the container with the data.
			 *
			 * @param[in]  data  The data to fill the container
			 */
			void fill(T data);

			/**
			 * @brief      acess a element of the container, performs no safe checks.
			 *
			 * @param[in]  pos   index
			 *
			 * @return     a reference to the container.
			 */
			T& operator[](const std::size_t& pos)
			{
				return items[pos];
			}

			/**
			 * @brief      make this container equals to the other.
			 *
			 * @param      other  The other container
			 *
			 * @return     returns a reference to itself.
			 */
			array<T,sz>& operator=(array<T,sz> &other)
			{
				if(!other.empty() && !this->empty())
				{
					this->clear();
					this->items = new T[other.size()];
					for(std::size_t i = 0; i < other.size(); ++i)
					{
						this->items[i] = other[i];
					}					
				}
				return *this;
			}

			/**
			 * @brief      swap both containers. make sure they are of the same size, otherwise the other container won't be fully copied.
			 *
			 * @param      other  The other container.
			 */
			void swap(array<T,sz> &other);

			/**
			 * @brief      custom begin
			 *
			 * @return     pointer to the beggining
			 */
			T * begin()
			{
				return &items[0];
			}

			/**
			 * @brief      custom end
			 *
			 * @return     pointer to the end
			 */
			T * end()
			{
				return &items[this->_size];
			}

			/**
			 * @brief      the size of the container.
			 *
			 * @return     the size of the container.
			 */
			const std::size_t& size() const;

		private:
			T * items;
			std::size_t _size;

			void clear()
			{
				//if not empty, delete the items.
				if(!this->empty())
				{
					delete[] this->items;
 				}
			}
	};
}
template<class T, int sz> custom::array<T,sz>::array()
{
	//init our variables.
	this->items = new T[sz];
	this->_size = sz;	
}

template<class T, int sz> custom::array<T,sz>::array(const array<T,sz> &other)
{
	if(this != &other)
	{
		//make array to hod the objects.
		this->items = new T[sz];
		//set current size.
		this->_size = sz;		
		//assign each of them to our own.
		for(std::size_t i = 0; i < other.size() && i < this->size() ; ++i)
		{
			this->items[i] = other[i];
		}
	}
}
template<class T, int sz> custom::array<T,sz>::array(const std::initializer_list<T> &l)
{
	//if(this != &other)
	{
		this->items = new T[l.size()];
		this->_size = sz;		
		
		std::size_t i = 0;
		for(auto it = l.begin(); it != l.end(); ++it, ++i)
		{
			this->items[i] = *it;
		}		
	}
}
template<class T, int sz> custom::array<T,sz>::~array()
{
	//clear the memory.
	this->clear();
}

template<class T, int sz> bool custom::array<T,sz>::empty()
{
	// it is empty?
	return !this->_size;
}

template<class T, int sz> T& custom::array<T,sz>::front()
{
	//reference to the first to beggining.
	return items[0];
}

template<class T, int sz> T& custom::array<T,sz>::back()
{
	//reference to the last item.
	return items[this->_size-1];
}


template<class T, int sz> const std::size_t& custom::array<T,sz>::size() const
{
	//total size.
	return this->_size;
}


template<class T, int sz> void custom::array<T,sz>::fill(T data)
{
	// go through each item and assign the data.
	for(std::size_t i = 0; i < this->size(); ++i)
	{
		items[i] = data;
	}
}

template<class T, int sz> void custom::array<T,sz>::swap(array<T,sz> &other)
{
	//swap each item.
	for(std::size_t i = 0; i < this->size() && i < other.size(); ++i)
	{
		std::swap(this->items[i], other[i]);
	}

}
template<class T, int sz> T& custom::array<T,sz>::at(const std::size_t& pos)
{
	//it is not between the boundaries.
	if(pos < 0 || pos >= _size)
	{
		throw std::out_of_range("out of range");
	}
	return items[pos];
}
#endif