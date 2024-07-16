# Introduction

Welcome! This is your exam sheet. It consists of two parts, one about theoretical concepts, and another about 
practical programming skills. You have 4 hours to complete the exercises below, and submit your solution. You 
can earn bonus points throughout the exam, make sure to collect as many as you can! You can use anything during 
the exam, even online resources.

Good luck!

# Setup & submission (5p + 1p)

You will use Git to submit your solution, follow the below steps:  
* fork this repository on Github (1p)
* clone the forked repository to your local machine (1p)
* commit your solutions as you work through the exam (1p + 1p if the commit history is clean)
* keep pushing your local changes to your fork (1p)
* when you are ready to submit your final solution, open a pull request from your fork to the original repository (1p)

# Theory (17p + (4p + ???p))

See the `theory.md` file, and answer the questions in there!

# Programming assignment (32p + 16p)

In this exercise, you'll implement the vector data structure, that is basically an array, but it can automatically 
expand if needed.

You'll work with multiple files in this exercise:
* `vector.h` the header file for the vector, this is read-only, please don't modify it.
* `vector.c` the implementation file for the vector, this is where you'll work.
* `main.c` the main entry point for the application containing mostly tests. You can add more tests if you'd like to, but please don't modify the existing ones.

In `vector.h` you'll see documentation for each function. Your implementation should respect the documentation!
For further guidance on how the functions should work exactly, check out the tests in `main.c`!

Some tips for the exercise:
* always enable the `-Wall` and `-Wextra` flags so that you see all warnings
* feel free to comment out the tests until you actually implement the function
* try compiling with different levels of optimization, and even different compilers to catch undefined behaviour

## Point system

Each exercise awards a given set of points. You can check the number of points above the docstring for each function.
If the tests pass, your code is probably correct, but these tests can't cover all cases, so the solution will be checked 
manually too.

### Bonus points

Some exercises award bonus points, make sure to collect them!

### Side quests

There are side quests that apply to your whole solution. Failing some can result in point deductions, but completing
others will award you extra points!

#### Three-headed kittens take over the Earth (-???)

For each instance of undefined behaviour in your code, you lose 2 points. During the defense of your solution, you'll have 
the chance to correct these. If you successfully correct one, you only lose 1 point for that.

Note that the amount of points you can lose is not capped, so make sure to double-check your code before submission!

#### We are sinking (max -3p)

For each instance of memory leak in your code, you lose 1 point. During the defense of your solution, you'll have
the chance to correct these. If you successfully correct one, you won't lose points for that.

#### Nits, nits everywhere (max +3p)

Follow these stylistic guidelines:
* DRY: don't repeat yourself. if you find some code duplication try to move it to a function
* reuse: if a function can be expressed in terms of another function, reuse it
* naming: try to use descriptive variable and helper function names

#### Fastest copies on the west (max +3p)

Whenever you are copying data between memory locations, try using `memcpy`. This is the fastest way! Make sure to check 
out the standard about `memcpy`, sometimes it cannot be used!

#### Copy fast and DON'T break things (+2p)

There's a function where you'd be tempted to use `memcpy`, but you cannot. Which function is this? What other standard 
library function you can use to efficiently copy the data?

#### Only change is constant (max +2p)

There are a few functions where we could add `const` qualifiers to some pointers. Which ones are those?

For an extra point: why don't we need to add `const` qualifiers to non-pointer function parameters?

#### The mathematician (max +3p)

For every 4 functions you you calculate the runtime complexity correctly, you get 1 additional point. 
Add a comment about the complexity to the docstring in the header file in BigO notation!

Yes, you can modify the header file for this. 

# Grades

* 1: 0p - 27p 
* 2: 28p - 39p
* 3: 40p - 48p
* 4: 49p - 53p
* 5: 54p -




















