# file-reader
File reader
Write a program, called parseC, to parse a C++ program into tokens. You should recognize and discard program comments (/* to */ or after //). 

Input:
a C++ program file

Output:
the parsed program to stdout, one token per line


Example:
input:
sample_cppProgram.cpp


output:
#
include

<

stdio
.

h

>

int

main

(

int

argc

,

char

*

argv

[

]

)

{

char

my_char

=


‘A’

;

for

(


int

i

=

0

;

i

<

1024

;

++

i

)

printf

(

“\”Hello\” she said.\n”

)

;

}





