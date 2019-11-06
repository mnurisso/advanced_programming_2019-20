# Error Handling

The `return` value of a function can be an error handling.

There is a macro in C called `errno` which value is different from 0 if the called function has an internal error. For example the `std::sqrt` function can evaluate a negative number obtaining a `nan`, but the `errno` value is then changed.

Calling again a function without errors doesn't reset the` errno` value because it's left to the user how to manage the obtained error.

## Exception

In main

```c++
try { // standard code
    auto d = square_root(number);
    return 0;
  } catch (const Negative_number) { // exception 1
    return 1;
  } catch (const Bigger_than_expected) { // exception 2
    return 2;
  }
}
```

This is the standard way in which errors are handled in C++.

Outside the main:

```c++
struct Negative_number {}; // are type value to define exceptions, empty classes
struct Bigger_than_expected {};
```

And the external function can handle the exception by:

```c++
double square_root(const double d) {
  // test the pre-conditions
  if (d < 0)
    throw Negative_number{}; // call 
  if (d > 50)
    throw Bigger_than_expected{};
  return std::sqrt(d);
}
```

## Exception 2

In this case I'm reporting a generic error message that is written by the developer in the functions outside the main. This leave more freedom to the developer to describe the errors and to the user less problem in understanding all the possible different errors.

```c++
double square_root(const double d);

struct Square_root_invalid {/* define a structure for generic error messages */
  std::string message;
  Square_root_invalid(const std::string& s) : message{s} {}
};
```

That can be called inside the functions defined outside the main by:

```c++
throw Square_root_invalid{"Cannot handle negative numbers. You gave me " + std::to_string(d)}; 
```

## Assert

```c++
#include <assert.h>
```

Allow to use the function `assert` with a condition:

```c++
assert(d >= 0 && d <= 50);  // provided by C, no execeptions
```

If the value is `true` nothing happen otherwise it abort the function. The advantage is that it can be turned off a flag in the compiler

```bash
g++ 04_assert.cc -DNDEBUG
```

If you think that some check can slow down your code is suggested to use `assert` strategy so that in the final release you can turn it off. In general if you're reading external inputs always use errors, instead for internal routine, after debug and verification you can turn off all the check and so it's better to use `assert`.

## Stack unwinding

In the file 05 the code enter in the` try` part, but encounters an error in the `ManyResource` constructor, so it go back to before the `try` calling the destructor of what was generated inside the `try`.

Don't use raw pointers because an efficient treatment of them with the exceptions require a lot of `try` in almost every part of the code, use `std::unique_ptr`. In case of an error with the unique ptrs they will be automatically deleted.

## No exception

If you're sure that a function cannot produce exception you can speed up the code putting the `noexcept` keyword (from C++11), but then if an exception is generated the code will be aborted.

```c++
double& operator[](const unsigned int i) noexcept {
    return elem[i];
}
```

## Main structure

So from now on a usual main should look like:

```c++
int main(){
	try{
		code...
	} catch (...){
		some exception...
		return 1;
	}
	return 0;
}
```

## Macro

Something elaborated by the processor.

```c++
#define MACRO_NAME (args) what_is_substituted_as_line_in_the_code
```

A macro should be a single line so that if you want or need to go to a new line you need to put \ at the end of the line:

```c++
#define AVERAGE_XYZ(q,k,j,i)  (0.25*(  q[0][j][i]   + q[0][j][i+1]        \
                                     + q[0][j+1][i] + q[0][j+1][i+1]))
```

