Va_list is used to declare a variable that will refer to each arg in turn , this variable is called ap (argument pointer) .

The macro va_start initialize ap to point to the first unamed argument . it must be called once before ap is used , it must be at least one named argument , here is an example of named and unamed args :

Named argument: Explicitly declared with a name (e.g., count in the example).

Unnamed argument: Passed without being explicitly named; accessed using <stdarg.h> macros.

each call of va_arg returns one arg , and move ap to the next arg. va_arg uses a type name to determine what type to return and how many bytes should it move . va_end cleans whats nessesary , it must be called before the program ends . we must call va_end , so it releases the ressource allocated by va_start, if we didnt it may give an undefined bihavior like memory leaks .

################################################

va_list as we v seen before is a struct , let’s break it down

typedef struct { unisgned int gp_offset; // 4bytes unisgned int fp_offset; // 4 bytes void *overflow_arg_area; // 8 bytes void *reg_save_area; // 8 bytes } va_list[1]; size of this stucrt is 24 bytes.

gp_offset and fp_offset track register usage for args. overflow_arg_area handles args that dont fit in registers. reg_save_area stores backup values og registers .

when we use c tutor to see what happend with the function we will realise that , some values are set to gp and fp offset :

you will see that gp_offset is set to 8 , it will be set to 8 after the first argument, since one register (which holds 8 bytes) has been used.

and fp_offset is set to (normaly its 64, but c tutor shows just 48) because we didnt have any arg that holds a float , and no register have been used.

gp_offset has 6 general purpose reg. [68] fp_offset has 8 floating point reg. [88]

the size of a register in 64bit system is 8bytes , 64bits == 8 bytes.

fp_offset will hadle the first 6 args , any more args will be handled by the overflow_arg_area(it is located in the stack btw)

reg_save_area saves the original state/value of the registers that have been used , so after we finish with the program the regs are back at there original state.
