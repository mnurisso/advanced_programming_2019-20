# Vector

I want a **class** because I want to keep the size as a private variable. I want a templated class.

The private variables will be:

- `std::size_t _size{};` size of the vector,
- `std::unique_ptr<T[]> elem{};` to have the vector stored in the **heap** as a unique pointer,
- `std::size_t _capacity{};` how big is the actual array. 

## Constructor

```c++
Vector() = default;

/* custom ctor */
explicit Vector(const std::size_t& lenght):
_size{lenght}, /* by constructing here you're avoiding the std ctor for them */
elem{new T[lenght]{}}, /* elements initialized with their std ctor */
_capacity{lenght}
{}
```



## PushBack

```c++
void push_back(const T& x)
{
    check_increase_capacity();
    elem[_size] = x;
    ++_size;
}
```

Always delay part of the code in other functions if it's possible. You don't want to modify x during the `push_back` and not knowing the type of `T` it's a good idea to pass it by reference.

After C++11, with the move semantic you can do an overload:

```c++
void push_back(T&& x)
{
    check_increase_capacity();
    elem[_size] = std::move(x);
    ++_size;
}
```

The `check_increase_capacity` has to check if the memory allocated is enough and if it's not the case it has to allocate a new array, copy the old one, delete the old one.

### Check and increase of capacity

```c++
void check_increase_capacity()
{
    if(_capacity == 0) reserve(8); /* because allocation is expensive */
    if(_size == _capacity) reserve(2*_size); //delegate to reserve the increase
}
```

Without a default constructor an empty array will be a problem, we need to add a specific `if` to avoid the problem.

### Reserve

It's a public function because as a user you can know in advance that you will need to reserve memory multiple times and you want to avoid useless calls to this function.

```c++
void reserve(const std::size_t new_size)
{
    if(_capacity < new_size){
        T* new_array = new T[new_size]; /* define a ptr to the new array */
    
    	for(std::size_t i=0; i<_size; ++i)
        	new_array[i] = std::move(elem[i]);
    
    	elem.reset(new_array); /* reassign the unique ptr */
    	_capacity = new_size;
    }
}
```

## Sub-scripting overload

```c++
T& operator[](const std::size_t i) noexcept
{
    /* preconditions: elem!= nullptr and i<_size */
    return element[i];
}

/* for the const value I have to copy-paste the code */
const T& operator[](const std::size_t i) const noexcept
{
    /* preconditions: elem!= nullptr and i<_size */
    return element[i];
}
```

