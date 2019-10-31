#include <iostream>
#include <memory>
#include <utility>
/* ******************************************************************** *
 * Defining the class List
 *
 * Attributes:
 *
 * Functions:
 * 
 * ******************************************************************** */
enum class Insertion_method { push_back, push_front };

template <class value_type>
class List {
 public:
  // insert a new node with the value v according to the method m
  // this method should be used to fill the list
  void insert(const value_type& v, const Insertion_method m);

	void insert(value_type&& v, const Insertion_method m);
	//arg value reference -> use the move semantic
	
  // return the size of the list
  std::size_t size() const;

  // delete all the nodes of the list
  void reset();
	
  // constructor(s) for List
	List(const std::initializer_list<value_type> args)
			: _size{args.size()}, head{nullptr}} {
		std::cout << "list ctor\n";
		/* Create a node for every element in the initializer list */
		/* for di push_back partendo dall'ultimo elemento */
	}
  
  // copy semantics (constructor + assignment)
  // move semantics
  
  // destructor

 private:
 
  
	/* ******************************************************************** *
	* Defining the class node:
	* private struct node with the proper value_type
	*
	* Attributes:
	*   value - saved value
	*   next  - pointer to the next node
	* Functions:
	* 
	* ******************************************************************** */
  struct node {
    value_type value;
    std::unique_ptr<node> next;

    // implement suitable constructor(s) for node
		node(value_type v, std::unique_ptr<node> n): value{v}, next{n} {}
		node(value_type v): value{v}, next{nullptr} {}
		
    // copy and move semantics if needed
    
    // destructor
  };

	/*********************************************************/
  // append the newly created node at the end of the list
  /*********************************************************/
	void push_back(const value_type& v){
		/* find the last node */
		std::unique_ptr<node> last_node{head};
		do{
			last_node = last_node->next;
		}while(last_node);
		/* generating a new node at the end of the list */
		node new_node{v};
		/* move old last node next ptr to the new last node */
		std::move(last_node->next,new_node.next);
	}
	void push_back(value_type&& v);
	
	/*********************************************************/
  // insert the newly created node in front of the list
  /*********************************************************/
	void push_front(const value_type& v){
		/* generating a new node pointing to the old first one*/
		node new_node{v,head->next};
		/* moving the head to the new first node */
		std::move(head, std::unique_ptr<node> new_node);
	}
	//void push_front(value_type&& v);

  std::unique_ptr<node> head;
  std::size_t _size;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& l);