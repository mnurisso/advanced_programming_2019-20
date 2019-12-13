# Python Intro

## Jupyter notebook

It's a tool to create readable documents embedding code, images, comments and formulas.

To open the jupyter notebook interface:

```bash
jupyter notebook
```

You can also open a lab interface for easy debugging in which you can have multiple pages, terminals opened at the same time.

```bash
jupyter-lab
```

To run a cell you need to use `shift+enter`.

### Magic Commands

It has some **magic** command that enable to run different kind of code:

- `%` at the beginning of inline commands
- `%%`at the beginning of multi-line commands

```
%lsmagic
```

to list the magic commands.

If you want to run a `bash` command:

```
%%bash
bash command here
```

To run inline shell commands you can use `!`:

```
!ls | grep ipy
```

### Python compiler

Compile and execute the code on a virtual machine. It survives any execution error, even syntax ones and if a cell is not working you have the problem only in that specific part of the code. An **expression** is a code that returns an object. The cell will automatically print the result on screen and assign the result to the variable `_`.

```
%reset
```

to reset the previously assigned variables.

## Intro

Python works like a sort of virtual machine, there is an interpreter, python itself, that convert the source code into language. In c++ you have to work with stack, heap, while instead in python you don't have to worry about that.

Python can be run from terminal, but the code is deleted when you exit from the program. The easy way is to write a `name.py` file and make it executable with `chmod u+x name.py`.

## Surviving kit

### Print

```python
print("hello world")
```

To know the type of a variable:

```python
print(type("hello"))
```

in python everything is a class, there are not built-in types like in C++.

### Help

Can be used to have documentation about a class in an interactive session.

### Dir

Without any argument it returns all the defined variables plus some other variable of particular methods.

`dir(1)` will return all the defined variables related to the integer. In the integer example we have all the member functions of the integer class. A lot of them are invoked only by an interface, e.g. `__abs__` is called by the interface `abs()`.

### Dynamically typed language

In python variables are simply label and you have to read from left to right. Writing `a=3` in python will create an object with the value `3` with a label referring to its name `a`. If I have already a label python will assign the label to the new object without checking if the object is of the same type of the previous one.

`a is b` will check the identity number with the `id()`.
`a == b` will check the equality referring to the value.

If I'm assigning the same id to two variables they will change together if I act on one of the two. In the example the b printed will contain also the number appended in a.

```python
a = [1,2,3]
b = a
print(a is b)
a.append(5)
print(b)
```



### List 

They're a container mutable, resizeable, stored objects and they contains object of different types.

```python
a = [1,2,3]
```

