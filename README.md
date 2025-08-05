# holbertonschool-printf
holbertonschool-printf

.SH DESCRIPTION
The
.B _printf()
function produces output according to a specified format, similar to the standard
.BR printf (3)
function. It writes the output to the standard output (file descriptor 1) using the
.B write(2)
system call.

It handles a limited set of format specifiers, including:

.TP
.BR %c
Print a single character.

.TP
.BR %s
Print a string of characters. If the string is NULL, the output is
.BR "(null)" .

.TP
.BR %d , %i
Print a signed decimal integer.

.TP
.BR %%
Print a literal percent sign.

For any other unrecognized format specifier, the
.B _
.B printf()
function will print the percent sign followed by the character (e.g., `%z` will be printed as `%z`).

.SH RETURN VALUE
The function returns the total number of characters printed to the standard output.

If
.I format
is
.B NULL,
the function returns
.B -1.

