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
  
  /***************************************************************/
  // insert a new node with the value v according to the method m
  /***************************************************************/
  void insert(const value_type& v, const Insertion_method m){
    if (m == push_back){
      push_back(v);
    }
  }

	//void insert(value_type&& v, const Insertion_method m);
	//arg value reference -> use the move semantic
	  
   /*********************************************************/
   // return the size of the list
   /*********************************************************/
   std::size_t size() const {return _size;}
   
  // delete all the nodes of the list
  //void reset();
   
   /*********************************************************/
   // public the n-th node (starting from n=0)
   /*********************************************************/
   void print() const{
     node* print_node;
     print_node = head.get();
     std::cout << "Entro in funzione\n" << print_node;
     if(print_node){
       std::cout << "print" << std::endl;
       print_node = print_node->next.get();
       std::cout << print_node->value << " ";
     }
   }
   
   ///*********************************************************/
   //// public the n-th node (starting from n=0)
   ///*********************************************************/
   //std::ostream& operator<<(std::ostream& os, const List<double>& l){
   //  node* print_node;
   //  print_node = head.get();
   //  
   //  if(print_node){
   //    print_node = print_node->next.get();
   //    //os << print_node.value << " ";
   //    os << "Printing node" << std::endl;
   //  }
   //  
   //  //for(std::size_t i=0; i<l.size(); ++i){
   //  //  print_node = print_node->next.get();
   //  //  os << print_node.value << " ";
   //  //}
   //  
   //  return os;
   //}
   //
   /*********************************************************/
   // Constructor for List
	  /*********************************************************/
   
   // Empty constructor
   List(): _size{0}, head{nullptr} {
     std::cout << "empty ctor\n";
   }
   
   // List list constructor v{1,2,3,4}
   List(const std::initializer_list<value_type> args)
			  : _size{args.size()}, head{nullptr} {
		   std::cout << "list ctor\n";
     List list{};
     
		   /* Create a node for every element in the initializer list */
     for (const auto& x : args){
       std::cout << "Starting push_back:" << std::endl;
       std::cout << "  value to push: " << x << std::endl;
       list.push_back(x);
       std::cout << "push_back # " << list._size << std::endl;
       ++list._size;
     }
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
    
    /*********************************************************/
    // implement suitable constructor(s) for node
    /*********************************************************/
    node(value_type v, std::unique_ptr<node> n): value{v}, next{n} {}
    node(value_type v): value{v}, next{nullptr} {}
    //node(): next{nullptr}{}
    
    // copy and move semantics if needed
    
    /*********************************************************/
    // default destructor
    /*********************************************************/
    ~node() = default;
  };

	 /*********************************************************/
  // append the newly created node at the end of the list
  /*********************************************************/
	 void push_back(const value_type& v){
    node* last_node = head.get();
    //last_node = head.get();
    
    std::cout << "Entering push_back:\n";
    while(last_node){
      last_node = last_node->next.get();
    }
    
    std::unique_ptr<node> new_ptr;
    new_ptr.reset(last_node);
    /* create the node */
    //node new_node{v,new_ptr};
    
    std::cout << "Exit push_back\n";
	 }
	 //void push_back(value_type&& v);
	
	/*********************************************************/
  // insert the newly created node in front of the list
  /*********************************************************/
//	void push_front(const value_type& v){
//		/* generating a new node pointing to the old first one*/
//		node new_node{v,head->next};
//		/* moving the head to the new first node */
//		//std::move(head, std::unique_ptr<node> node::new_node);
//  std::move(head, new_node);
//	}
	//void push_front(value_type&& v);
  
  std::unique_ptr<node> head;
  std::size_t _size;
};

///**************************************************************/
//// Overload of the << operator
///**************************************************************/
//template <class T>
//std::ostream& operator<<(std::ostream& os, const List<T>& l){
//  os << "List: ";
//  l.print();
//  //os << l;
//  //for(int i = 0u; i<l.size(); ++i){
//  //  os << l.print(i) << " ";
//  //}
//  
//  return os;
//}