#include <iostream>
#include <memory>  /* std::unique_ptr */
#include "ap_error.h"

enum class method {push_back, push_front};

template <class T>
class List{
	struct node{
		std::unique_ptr<node> next;
		T value;
		
		node(const T& v, node *p): next{p},value{v} {} /* use the same order for ctr */
		node(T&& v, node *p): next{p}, value{std::move(v)} {}
		node(const std::unique_ptr<node>& p): value{p->value}{/* recursive for copy*/
			if(p->next){/* there are mode nodes */
				next = std::make_unique<node>(p->next);
				//next.reset(new node{p->next}); /* equivalent */
			}
		}
		
	};
	
	std::unique_ptr<node> head;
	
	void push_back(const T& v);
	//template <class OT>
	//void push_back(OT&& v);
	
	//template <class OT>
	void push_front(const T& v);
	//void push_front(OT&& v);
	
	node* tail();
	
	public:
		/**********************************************************************
		 * Constuctor 
		 **********************************************************************/
		List() noexcept = default;
		/**********************************************************************
		 * Move semantic (use noexcept)
		 **********************************************************************/
		List(List&&) noexcept = default; /* fine because we're using a unique_ptr */	
		List& operator=(List&&) noexcept = default;
		/**********************************************************************
		 * Copy semantic (DON'T use noexcept)
		 **********************************************************************/
		List(const List& l);
		//List& operator=(const List& l);
		
		/**********************************************************************
		 * Insert public function
		 * Can call two different methods:
		 * 	1. push_back
		 * 	2. push_front
		 **********************************************************************/
		//template <class OT>
		void insert(const T& v, const method m); /* use copy semantic */
		//void insert(OT&& v, const method m);      /* use move semantic */
		
		/* Let the >> overload access to private data with friend keyword */
		template <class O> /* the function is templated outside */
		friend std::ostream& operator<<(std::ostream&, const List<O>&);
};

/*************************************************************************
 * Insert public function
 ************************************************************************/
template <class T>
void List<T>::insert(const T& v, const method m){
	/* Check if it's the first node */
	if (!head){ /* same as head == nullptr */
		//head.reset(new node{v, nullptr}); /* reset ptr to the new one to the first node */
		head = std::make_unique<node>(v, nullptr); /* since C++14 doing the same as the line before */
		return;
	}
	
	switch(m){
		case method::push_back:
			push_back(v);
			break;
		case method::push_front:
			push_front(v);
			break;
		default:
			AP_ERROR(false) << "Unknown insertion method";
	};
}
///* Rvalue - can we avoid to repeate the code? Yes but not easy */
//template <class T>
//void List<T>::insert(T&& v, const method m){
//	/* Check if it's the first node */
//	if (!head){ /* same as head == nullptr */
//		//head.reset(new node{v, nullptr}); /* reset ptr to the new one to the first node */
//		head = std::make_unique<node>(v, nullptr); /* since C++14 doing the same as the line before */
//		return;
//	}
//	
//	switch(m){
//		case method::push_back:
//			push_back(v);
//			break;
//		case method::push_front:
//			push_front(v);
//			break;
//		default:
//			AP_ERROR(false) << "Unknown insertion method";
//	};
//}

/************************************************************************
* Tail function, return the pointer to the last node
*************************************************************************/
template <class T>
typename List<T>::node* List<T>::tail(){
	auto tmp = head.get();
	
	while(tmp->next){/* if the list is empty you obtain a seg fault */
		tmp = tmp->next.get();
	}
	
	return tmp;
}

/*************************************************************************
 * Push_back private function
 ************************************************************************/
template <class T>
void List<T>::push_back(const T& v){
	auto last = tail(); /* function that return the last node, node* can create bug */
	//last->next.reset(new node{vm nullptr}); /* C++11 style */
	last->next = std::make_unique<node>(v,nullptr); /* C++14 */
}

/*************************************************************************
 * Push_front private function
 ************************************************************************/
template <class T>
void List<T>::push_front(const T& v){/* old function */
	//auto h = head.release(); /* release the ownership of head, retunr a raw pointer */
	//auto new_node = new node{v,h};
	//head.reset(new_node); /* not the best way to write it */
	
	head.reset(new node{v, head.release()});
	//head = std::make_unique<node>(v, head.release());/* C++ 14*/
}

/*************************************************************************
 * Copy semantic - deep copy
 ************************************************************************/
template <class T>
List<T>::List(const List& l){
	/* standard way */
	//auto tmp = l.head.get(); /* raw pointer to the list to copy*/
	//
	//while(tmp){
	//	/* Insert the first value to the new list */
	//	insert(tmp->value,method::push_back);
	//	tmp = tmp->next.get();
	//}
	
	head = std::make_unique<node>(l.head);
}

/*************************************************************************
 * << overload
 ************************************************************************/
template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& l){
	auto tmp = l.head.get(); /* I need a raw pointer for the loop */
	
	while(tmp){/* tmp!=nullptr*/
		/* print the node value */
		os << tmp->value << " ";
		/* go to the next node */
		tmp = tmp->next.get();
	}
	return os;
}