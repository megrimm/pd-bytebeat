#bytebeat~ external for puredata

This is some helper code for easily compiling bytebeat C-like expressions as puredata externals.

On line 29 in bytebeat~.c "v000" can be replaced with any C-like expression. An example is on line 28.

There is also a header file (bytebeat~.h) that contains almost 95 different working expressions. The way it works at the moment is that "v000" on line 29 in bytebeat~.c can be replaced with a line from bytebeat~.h. So one could replace it with v101, v102, v103, v104, etc to reflect the expression in the header file.

In this case the Makefile might also need altering if one is to build [bytebeat~] with a numerical variation. [bytebeat~_175], [bytebeat~_143], etc

All of the expressions can be build using the automated system if one prefers. In the folder "bytebeat~-make" there is a Pd patch and a couple of python scripts that automatically alter the bytebeat~.c and Makefile to reflect different expressions from bytebeat~.h

Clicking the [bng] will randomly grab a line number and replace it in these files. One could easily alter this system to build objects sequentially instead of randomly if one preferred.

I have also included the [dexpr~] abstraction which creates [expr~] objects with expressions dynamically on the fly. This might actually be easier to use C-like expressions rather that compiling [bytebeat~]