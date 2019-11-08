# Linked list

In nested classes the internal classes are not templated if not explicitly written with an another template.

Don't use header file AND .c file for functions if you're using a templated class, only a single header file (unless you have huge code).

```c++
head = std::make_unique<node>(v, nullptr);
```

since C++14 call the new operator inside.

To reach the end of the list you need a loop (with a raw )

Use friend syntax to let external function access private data. You're friend automatically of the same data of yourself

If you don't define functions for the R-values the class will try to use the L value one, but if the conversion it's not possible you will obtain an error.

```c++
std::forward<T>(d)
```

Will pass the value as R or L value according to its nature