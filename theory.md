# Theory quiz

Answer the below question in your own words in this file! The answers should be detailed, but they don't need to be too long
(<= 5 sentences).

## What is the size of an int in C? (1p)
It depends on the OS and the CPU, but in modern devices usually 4 bytes.

## What is the difference between the below two code snippets? (1p)
The firt uses stack memory, and will be freed automatically when the fuction terminates, therefore the pointer to that array should not be used after that, while the second uses heap memory and it has to be freed manually when it is no longer needed.

Snippet 1:
```c
int arr[] = {0, 1, 2};
```

Snippet 2:
```c
int* arr = malloc(3 * sizeof(int));
arr[0] = 0;
arr[1] = 1;
arr[2] = 2;
```

## If a program is processing a text file, and needs to keep the whole file in memory, which memory segment should it use and why? (1p) 
Heap, so it is accessable from different functions, and it will not cause a stack overflow, as there is more space in heap than stack area.

## What is the biggest difference between Scala and C in terms of memory management? (2p) 
Scala has a garbage collector, which optimizes memory management without the programmers involvement, while in C memory management has to be done manually, otherwise there could be memory leaks.

## Write a program that terminates due to a stack overflow! (2p)
void foo(void)
{
  long arr[10000000000];
  for(int i = 1; i > 0; i++)
  {
    arr[i % 1000000000] = 1;
  }
}

## What's the difference between `gets` and `gets_s`? (1p)
gets is vulnerable to buffer-owerflow attacks, as there is no bounds checking in it, therefore it was removed in C11 standard and can be replaced with gets_s, which has an additional parameter besides the pointer to the string: the maximum size of chars that will be written to the buffer.

## How much memory can a 32-bit system have theoretically (if the smallest piece of addressable memory is 1 byte)? (1p)
2 ^32 = 4294967295 bytes, less than 4,3 GB, and more than 1 GiB

## How much memory can a 64-bit system have theoretically (if the smallest piece of addressable memory is 1 byte)? (1p)
2 ^64 = 1.8446744e+19 bytes, which is more than 18.4 EB and more than 1 EiB

## What properties does a hash table need to be performant? (2p)
The hash algorithm should perform well (spread inputs evenly with minimal collisions)
The size of the table should be optimal (enough elements to avoid collisions but not needing unnecessary memory usage)
The structure of the table should be optimal (the less time it takes to reach an element the better)

## In general, which data structure would be faster to sort: an array or a linked list? Why? (2p)
An array, as its elements are loaded into memory, so it does not hve to jump betweeen different locations of memory.

## What happens to unfreed memory when the program terminates? (1p)
It leakes, which will result in less unused memory, and it can also fragment the unused parts.

## Why do we care about memory leaks? Mention a use case where it could lead to trouble! (1p)
For example if the unfreed memory fragments the unused parts that could be reserved for a new memory allocation, that needs a continuous memory part, and it could be impossible to allocate the needed size of memory as the unused parts are fragmented.

## What is the difference between an exception and a type error? (1p)
Errors are system-level issues that cannot typically be recovered from, while Exceptions are application-level anomalies that can be caught and handled by the developer.

## BONUS: what is a buffer overflow attack, why is it dangerous? (+2p)
When giving a bigger piece of data to a program than was meant for it, when it reached the pointer that should forward the execution the the next section of the code after finishing the function, another pointer could be passed, that could lead to another part of the code where there might be vulnerabilities.

## BONUS: If I compile a C program on Linux, and send the executable to Windows, will it run? If yes why, if not why not? (+2p)
Probably not, as the executable code needs to suite the OS and CPU, it would be better to compile on that device so their systems can create the executable that will be understood by that computer

## BONUS: Scala compiles to JVM byte code, C compiles to native machine code. What are the pros/cons of these approaches? (+ ???p)
Any system equipped with a JVM can run byte code regardless of the operating system. This makes Java a platform-independent language, resulting in a portable code due to its adaptability.
Machine code is a set of instructions directly readable and understandable by a machine, CPU can directly understand and process it, it doesn't require a virtual machine, but it is not portable, and another CPU might not be able to execute.



















