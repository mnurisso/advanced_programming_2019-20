#include <dlfcn.h>

/* This can be used to enrich functions that you 
 * want to debug without changing the actual 
 * implementation */

int main(int argc, char* argv[]) {
  void* handle; /* handle for dynamic object */
  void (*hi)(); /* function pointer for symbol */
  int (*rep)(char*);
  handle = dlopen("./libhello.so", RTLD_LAZY);
  if (handle) {
    hi = (void (*)())dlsym(handle, "hello");
    (*hi)();
    rep = (int (*)(char*))dlsym(handle, "repeat");
    rep("I dont't care what fox says");
    dlclose(handle);
  }
  return 0;
}
