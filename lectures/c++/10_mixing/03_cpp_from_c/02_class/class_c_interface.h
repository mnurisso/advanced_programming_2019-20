#ifndef _CLASS_C_INTERFACE_H_
#define _CLASS_C_INTERFACE_H_

typedef void* Foo_c;

/* This is how the whole C library is written
 * in order to be able to use it from a C++
 * without having problem of missing signatures */
#ifdef __cplusplus
extern "C" {
#endif

Foo_c create_foo(int b);
void free_foo(Foo_c);
void print_foo(Foo_c);
void set_a(Foo_c, int v);
int get_a(Foo_c);

#ifdef __cplusplus
}
#endif

#endif /* _CLASS_C_INTERFACE_H_ */
