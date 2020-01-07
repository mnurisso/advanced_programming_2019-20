# Symbols

A library is a collection of symbols, without a `main`. I cannot compile a library alone, the linker will complain about the missing `main`.

Usually the prototype are stored in a separate folder (can be named `include`). Remember that including an header file means to copy paste it in your code.
The same can be done for the source files, in which functions are defined. They're usually stored in a folder name `src`.

A library can be **shared** or **static**. A library must be compiled (the source files)  and linked. By compiling the file I obtain an **object file** (`lib_file.o`).  Then the different object files are linked into a binary file (doesn't contain a `main` so it's not called executable).

The bottleneck of this process is the compiling phase. So you don't want to recompile stuff, you don't want to waste time in this phase, in C++ you really want to avoid to recompile code without a valid reason. Compilation is an unbiased parallel process, instead link is not.

## Compile a library

```bash
c++ -c src/file.cc -I include
```

- `-c` is the flag to require only the compile phase
- `-I` to include a folder with header files. More folders can be added with another `-I` flag with the additional folders.
- `-fPIC` generate a **position independent code**. Some compiler automatically insert it.

The files `src.o` are generated in the folder in which the compilation is executed, not in the `src` folder.

## Link a library

```bash
c++ obj1.o obj2.o -shared -o libgreetings.so
```

- `-shared` to ask for a shared library
- For the name a convention is used. The name must start with `lib` and have the `.so` format.

You want an automatic way to help yourself in these steps, because the command, excluding the different name of the source files, are the same.

## Makefile

You can write:

- **macros**: `VAR = value` and can be accessed by `$(VAR)` to access the value.

- **comments**: by adding `#` at the beginning of a comment line.

- **targets**: 

  ```makefile
  target: dep1 dep2 ... depN
  	action1
  	action2
  ```

  You have to use the tab after the `target` command, spaces don't work. Actions performed after are performed in subshells, for loops have to be performed in the same line.

  The bash command `make` without any specification simply executes only the first action for every target defined in the makefile.

```makefile
%o:%.cc
	$(CXX) -c %< %(CXXFLAGS) -o $@
```

The makefile, before starting to execute an action, check is the target is up to date or not in order to avoid useless actions.

```makefile
OBJ = $(SRC:.cc=.o)
```

Changes the `SRC` content substituting `.cc` with `.o`.

```makefile
libgreetings.so: $(OBJ)
        $(CXX) -shared -o $@ $^
```

- `$@` is by convention the name of the target itself
- `$^` it the list of dependencies in the `OBJ` macro.

```makefile
%.o:%.cc
        $(CXX) -fpic -D$(LANG) -o $@ -c $< -Iinclude
```

- `%` is used as a wildcard to evaluate every element in a defined macro. The file to be compiled is `$<`
- `-D$(MACRO)` is used to generate a macro that can be used for pre-processor macro in the code.
- `-fpic` for position independent code

Targets with no actions are called **prerequisites** or the **default target**:

```makefile
all: libgreetings.so
```

The simple `make` command in the terminal will check if the `libgreetings.so` is up to date, otherwise will look how to generate it.

```makefile
src/greetings.o: include/greetings.h
```

It's a way to check if the header file has been modified, creating a prerequisite, in order to recompile the source files if the header file included in them has been modified.

### Clean

```makefile
clean:
        @rm -f *~ */*~ libgreetings.so src/*.o
        
.PHONY: clean all format
```

Will allow you to delete all the compiled code by typing `make clean` in the bash. Adding `.PHONY` to the target will force the makefile to perform the action also if there is by mistake a file named `clean` that it's up to date.

If you put an `@` in front of an action, like in the `clean` one, the command is not shown in the bash. By default instead they're shown.

### Tricks

- `make -B` to force the compilation.
- `make -j 9` to compile in parallel. 9 is the maximum number of parallel compilation that can be performed.
- `make -n` print the actions that are performed by the bash without executing them.

## Linked library

- compile:

  ```bash
  c++ -c -I include/ -I ../01_greetings_library/include/ main.cc
  ```

- link:

  ```bash
  c++ date.o student.o main.o -l greetings -L ../01_greetings_library/
  ```

- run: the `a.out` so generated cannot be simply executed.

  ```bash
  export LD_LIBRARY_PATH=../01_greetings_library:$LD_LIBRARY_PATH
  ```

  I have to say to the code where is it the shared library.

Using a shared library it's useful because any update that is performed doesn't require a recompilation of the whole code for the user, that can simply use the new features. The drawback is that you have to remember the `LD_LIBRARY_PATH`.

When you're installing a library it's better to require the specification of the prefix in order to have different copies of the code for different versions and to avoid to have copies of useless file that are remnants of previous versions.

```bash
configure --prefix=/path/to/smart/place
```

This is the standard way to specify a different folder for installation. You should find a coherent way to install everything in the same folder without root permission in order to fix better problems like typos.