# Hanoi
Code the Towers of Hanoi

<div id="header">

# 103 Project 5: Towers of Hanoi

</div>

### _Due:_ Tuesday, November 15th @ 11:59pm

## Synopsis

In this project, you are asked to implement a general solution to the _Towers of Hanoi_ puzzle. Here are a few things you should learn from this:

*   The basics of recursion
*   Basics of the [runtime stack](http://en.wikipedia.org/wiki/Call_stack), and some of the low-level details of how function calls work
*   A bit about command line arguments, and the standard ways for handling them

### Suggested Reading

*   Chapter 8 of the book. 8.4 and 8.5 are the particularly relevant parts, but you should read all of it.
*   Charles Li’s notes – [Lecture 26](http://www.charlesli.org/pic10a/lectures/lecture26/index.html).

### Important Notes on Grading

As always,

*   Code that does not compile will receive a 0.
*   Files that are not properly named will receive a 0\. (See the section below on “what to submit.”)

## Introduction

The Towers of Hanoi puzzle is described as follows: there are <span class="math inline">_n_</span> disks on one of 3 pegs, with each disk smaller than the one below it. The goal is to move all of the disks from the initial peg to another (distinct) peg of your choice **subject to the following rules**:

1.  You can only move one disk at a time.
2.  You can not place a bigger disk on top of a smaller one (i.e., you must maintain the ordering at all times). An illustration is provided below.

<div class="figure">![Fig. 1: Animation for 4 disks](http://upload.wikimedia.org/wikipedia/commons/6/60/Tower_of_Hanoi_4.gif)

Fig. 1: Animation for 4 disks

</div>

The main goal (for you as a student) is to learn about recursion, and indeed, you can write a recursive solution for this problem with relative ease (maybe 4 - 6 lines, not counting `#includes` and the boilerplate stuff in the `main()` function). Given that simplicity, one could almost apply a “brute force” attack on this project, just writing down all random 5 line programs that even remotely make sense until one works. **Please don’t do that**. I want you to really understand the basics of recursion once you are done with this, and be able to trace through every function call that is invoked during the execution of your solution. It might be frustrating, and you might be tempted to look up an answer somewhere, but **you must resist the temptation!** You have an entire week. Keep thinking about it until you get it. Otherwise, you will learn nothing, it will be a complete waste of time, and it will hurt you in the future.

## Details

### Command line arguments

One of the goals of this project is to teach you something about command line arguments. These are kind of like function parameters, but passed to your entire program from the command line. You have seen this all before. For example, when you invoke something like `g++ -c blah.cpp -o blah.o`. The `-c blah.cpp` tells g++ to compile `blah.cpp` and the `-o blah.o` says “put the output in `blah.o`”. To make options more readable, a lot of command line utilities also make use of _long options_, like `--version`. These typically (but not always) start with two dashes, and have a more descriptive name. We’ll make use of both for our program.

Parsing the arguments from the command line can be kind of annoying. However, it is an extremely common task, and as such, there’s fortunately an “easy button” for it, called [getopt](http://www.gnu.org/software/libc/manual/html_node/Getopt.html#Getopt). The [getopt](http://www.gnu.org/software/libc/manual/html_node/Getopt.html#Getopt) and [getopt_long](http://www.gnu.org/software/libc/manual/html_node/Getopt-Long-Options.html#Getopt-Long-Options) functions take most, if not all of the pain out of processing arguments. I’ll leave it to you to read the documentation – I’ve given you skeleton code in `towers.cpp` that shows you the basic usage. Here’s a quick summary of the options we’ll implement.

#### `-n,--num-disks`

This is the number of disks to use.

#### `-s,--start`

This is the starting post.

#### `-e,--end`

This is the ending post.

**Important:** your program should just print the steps of the solution in the following format: `<start post><tab><end post><newline>`. Here is an example:

<div class="sourceCode">

    $ ./towers -n 4 -s 1 -e 3
    1   2
    1   3
    2   3
    1   2
    3   1
    3   2
    1   2
    1   3
    2   3
    2   1
    3   1
    2   3
    1   2
    1   3
    2   3

</div>

_NOTE:_ Don’t worry so much about all this `getopt` stuff. This is of far lesser importance than getting the solution right. It is of course good to know, and this knowledge will serve you well in the future, but don’t let it distract you much – get help quickly via the message board if you are having trouble with this part.

### Other notes and hints

#### Regarding the organization

You will probably want to isolate the function that solves the puzzle so that it has a nice recursive breakdown (it would be pretty awkward to make `main(...)` recursive). A prototype might take three integers for the inputs, and then just print to `cout`. It probably doesn’t need to return a value.

#### Input and output

If strange things are entered into your program (e.g., pegs that don’t exist) you can just terminate the program. If people enter strange command line options or leave out values when then need to be specified, then you can just exit the program. It will only be tested on sane inputs.

#### Notes on `getopt`

The option processing is all done for you, but if you want to understand what happened, here is an explanation.

The loop for processing arguments looks something like the following:

<div class="sourceCode">

<table class="sourceCode cpp numberLines">

<tbody>

<tr class="sourceCode">

<td class="lineNumbers">

<pre>1
2
3
4
5
6
7
8
9
</pre>

</td>

<td class="sourceCode">

    while ((c = getopt_long(argc, argv, "s:e:n:", long_opts, &opt_index)) != -1) {
        switch (c) {
            case 's': // process option s
                break;
            case 'e': // process option e
                break;
            // ...  handle other cases...
        }
    }

</td>

</tr>

</tbody>

</table>

</div>

Some of the options require an argument, e.g. the start post. For such options, a special variable called `optarg`, is used to store the argument during the loop. It is defined in `getopt.h`, like this:

<div class="sourceCode">

    extern char *optarg;

</div>

Note that it is a _c-style string_, which is just a plain array of characters with a 0-character at the end. You will need to convert this into an integer. One convenient way is the [`atol` function](http://www.cplusplus.com/reference/clibrary/cstdlib/atol/). You can use it like this:

<div class="sourceCode">

    case 's': // process option s
        start = atoi(optarg);
        break;

</div>

### Testing

You should be able to test this out with some spare change, or maybe some stray coasters at your home. Alternatively, I gave you a test script, and the output of my program on it. You can run the test script with `./test.sh`, which will produce a file called `output` based on your program. My output file is located in `souput`. You can check those against each other if you want. _Note:_ It is possible that a correct answer will have slightly different output, but not likely. Check with me if you are concerned.

## Feeling Bored?

If you’re feeling good about your progress and your understanding of recursion, and if you’d like an extra challenge, try this: re-write the algorithm for the Towers of Hanoi problem _non-recursively_. It really isn’t too hard, but it certainly takes more than 5 lines of code! It might give you some additional appreciation for the power and elegance that recursive algorithms can have. **Extra-extra challenge:** run some timing tests and make sure that your non-recursive version actually _goes faster._ This is not entirely trivial, depending on how you came up with your non-recursive solution. Your first correct attempt will likely be slower than the recursive version (especially if you used 1 disk as your base case, rather than letting the recursion run all the way to <span class="math inline">_n_ = 0</span>).

## Submission Procedure

Turn your assignment in [here](https://www-cs.ccny.cuny.edu/~wes/CSC103F16/upload.html). A few **important notes:**

*   _Save the receipt._ You will need this to get your homework score back later from [the hw download page](https://www-cs.ccny.cuny.edu/~wes/CSC103F16/download.html).
*   _Don’t change the filename._ Just edit and submit the file from the repository (`towers.cpp`). If you turn a file with a different name, it will not be graded.
*   _Respect the deadline._ Turning in homework past the deadline will be noticed, and may lead to a zero.