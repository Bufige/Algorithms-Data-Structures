/** 
 *  @file    queue.h
 *  @author  Leonardo Igor de Oliveira Cavalcante (https://github.com/bufige, a.k.a, bufige)
 *  @date    05/08/2018  
 *  @version 1.0 
 *  
 *  @brief This is my implementation of the queue container.
 *
 *  
 *  This is a implementation of the queue container for practice, it features the core functions that the STL supports
 *  and briefs explanations of what it does and how it works in each step.
 *  
 *  
 *  @bug No known bugs.
 *
 */









#ifndef STACK_H
#define STACK_H


#include <cstddef>

namespace custom
{

	/**
	 * @brief      container stack.
	 *
	 * @tparam     T     type
	 */
	template<class T>  class stack
	{
	public:

		/**
		 * @brief      Constructs the object.
		 */
		stack();

		/**
		 * @brief      Destroys the object.
		 */
		~stack();

		/**
		 * @brief      checks if the container is empty.
		 *
		 * @return     true or false
		 */
		bool empty();

		/**
		 * @brief      push the data to the container.
		 *
		 * @param[in]  data  The data to be added.
		 */
		void push(const T& data);

		/**
		 * @brief      pop a element of the container.
		 */
		void pop();

		/**
		 * @brief      reference to the top of the container.
		 *
		 * @return     reference to the top of the container.
		 */
		T& top();

		/**
		 * @brief      reference to the back of the container.
		 *
		 * @return     reference to the back of the container.
		 */
		T& back();


		/**
		 * @brief      current size of the container.
		 *
		 * @return     the current size of the container.
		 */
		const std::size_t& size() const;

		/**
		 * @brief      operator equals, makes this(self) container equals to other.
		 *
		 * @param[in]  other  The other container
		 *
		 * @return     const reference to itself.
		 */
		const stack<T>& operator=(stack<T> &other)
		{
			// diferent objects
			if(this != &other)
			{
				// reset our current state.
				this->clear();
				
				//save the items in the order that we added.
				T * tmp = new T[other.size()];				
				std::size_t pos = 0;
				// go through each item of the copy and add to our own.
				while(!other.empty())
				{					
					tmp[pos] = other.top();
					other.pop();
					pos++;
				}	
				//while there are elements, push it to the stack.			
				while(pos)
				{
					this->push(tmp[--pos]);
				}
				//clear tmp array.
				delete[] tmp;				
			}
			// return this.
			return *this;
		}
	private:
		struct Node
		{
			T data;
			Node * next, * prev;
		};
		Node * new_node(T data)
		{
			Node * tmp = new Node;
			tmp->data = data;
			tmp->next = tmp->prev = NULL;
			return tmp;
		}
		void clear();
		Node *head, * tail;
		std::size_t _size;
	};
	
};


template<class T> custom::stack<T>::stack() 
{
	this->head = this->tail = NULL;
	this->_size = 0;
}

template<class T> custom::stack<T>::~stack() 
{
	//clear all the data.
	this->clear();
}

template<class T> bool custom::stack<T>::empty()
{
	//if the head is null, therefore the stack is empty.
	return this->head == NULL;
}

template<class T> void custom::stack<T>::push(const T& data)
{
	Node * nnode = new_node(data);
	if (!nnode) // can't allocate memory
		return ;
	//it is empty?
	if (this->empty())
	{
		//allocate to the head and point it as the tail.
		this->head = this->tail = nnode;
	}
	else
	{
		//ther are elements, all we need is to point to the next of the tail
		this->tail->next = nnode;
		// new tail to point to old tail.
		this->tail->next->prev = this->tail;
		//update the new tail.
		this->tail = nnode;
	}
	//update the total.
	++this->_size;
}

template<class T> void custom::stack<T>::pop()
{
	//there are elements?
	if(!this->empty())
	{
		// get the pointer that is poiting to the tail.
		Node * tmp = this->tail->prev;
		//delete the current head.
		delete this->tail;
		//update the head.
		this->tail = tmp;
		//update the total.
		--this->_size;

		//if the _size is 0.
		if(this->_size == 0)
		{
			// reset head and tail.
			this->head = this->tail = NULL;
		}
	}
}

template<class T> void custom::stack<T>::clear()
{
	// while there are elements, pop them.
	while(!this->empty())
	{
		this->pop();
	}
	//reset the pointers.
	this->head = this->tail = NULL;
	//reset the number of elements.
	this->_size = 0;
}

template<class T> T& custom::stack<T>::top()
{
	//back of the stack.
	return this->tail->data;
}

template<class T> T& custom::stack<T>::back()
{
	//back of the stack.
	return this->head->data;
}

template<class T> const std::size_t& custom::stack<T>::size() const
{
	// size of the container.
	return this->_size;
}
#endif