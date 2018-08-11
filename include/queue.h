/** 
 *  @file    stack.h
 *  @author  Leonardo Igor de Oliveira Cavalcante (https://github.com/bufige, a.k.a, bufige)
 *  @date    05/08/2018  
 *  @version 1.0 
 *  
 *  @brief This is my implementation of the stack container.
 *
 *  
 *  This is a implementation of the stack container for practice, it features the core functions that the STL supports
 *  and briefs explanations of what it does and how it works in each step.
 *  
 *  
 *  @bug No known bugs.
 *
 */









#ifndef QUEUE_H
#define QUEUE_H


#include <cstddef>

namespace custom
{
	/**
	 * @brief      container queue.
	 *
	 * @tparam     T     type
	 */
	template<class T>  class queue
	{
	public:

		/**
		 * @brief      Constructs the object.
		 */
		queue();

		/**
		 * @brief      Destroys the object.
		 */
		~queue();

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
		 * @brief      reference to the front of the container.
		 *
		 * @return     reference to the front of the container.
		 */
		T& front();

		/**
		 * @brief      reference to the back of the container.
		 *
		 * @return     reference to the back of the container.
		 */
		T& back();

		/**
		 * @brief      size of the container
		 *
		 * @return     current size of the container.
		 */
		const std::size_t& size() const;

		/**
		 * @brief      operator equals, makes this(self) container equals to other.
		 *
		 * @param[in]  other  The other container
		 *
		 * @return     const reference to itself.
		 */
		const queue<T>& operator=(queue<T> other)
		{
			// diferent objects
			if(this != &other)
			{
				// reset our current state.
				this->clear();
				// go through each item of the copy and add to our own.
				while(!other.empty())
				{
					this->push(other.front());
					other.pop();
				}
			}
			// return this.
			return *this;
		}
	private:
		struct Node
		{
			T data;
			Node * next;
		};
		Node * new_node(T data)
		{
			Node * tmp = new Node;
			tmp->data = data;
			tmp->next = nullptr;
			return tmp;
		}
		void clear();
		Node *head, * tail;
		std::size_t _size;
	};
	
}




template<class T> custom::queue<T>::queue()
{
	this->head = this->tail = nullptr;
	this->_size = 0;
}
template<class T> custom::queue<T>::~queue()
{
	//clear all the data.
	this->clear();
}
template<class T> bool custom::queue<T>::empty()
{
	//if the head is null, therefore the queue is empty.
	return this->head == nullptr;
}

template<class T> void custom::queue<T>::push(const T& data)
{
	Node * nnode = new_node(data);
	if (nnode == nullptr) // can't allocate memory
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
		//update the new tail.
		this->tail = nnode;
	}
	//update the total.
	++this->_size;
}

template<class T> void custom::queue<T>::pop()
{
	//there are elements?
	if(!this->empty())
	{
		// get to where the head is poiting.
		Node * tmp = this->head->next;
		//delete the current head.
		delete this->head;
		//update the head.
		this->head = tmp;
		//update the total.
		--this->_size;

		//if the _size is 0.
		if(this->_size == 0)
		{
			// reset head and tail.
			this->head = this->tail = nullptr;
		}
	}
}

template<class T> void custom::queue<T>::clear()
{
	// while there are elements, pop them.
	while(!this->empty())
	{
		this->pop();
	}
	//reset the pointers.
	this->head = this->tail = nullptr;
	//reset the number of elements.
	this->_size = 0;
}

template<class T> T& custom::queue<T>::front()
{
	//front of the queue.
	return this->head->data;
}

template<class T> T& custom::queue<T>::back()
{
	//back of the queue.
	return this->tail->data;
}

template<class T> const std::size_t& custom::queue<T>::size() const
{
	// size of the container.
	return this->_size;
}
#endif