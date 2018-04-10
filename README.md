# pic-debug-goodies #

This is a small library of debugging/instrumentation functions for PIC microcontrollers.
Its purpose is to provide a easy, painless way to debug firmware outside of MPLABX's debugger, while being as 
flexible and low-memory as possible. A sample program showing the use of these library functions can be found in src/main.c.

At the moment, pic-debug-goodies contains three libraries:

* *softUart*: a dead-simple, transmit-only software UART for sending status and debugging information to a host PC. Since it's software-based, a debug port can be connected to any pin on the MCU without having to remap peripheral pins. Instructions for initializing this module can be
found in include/softUart.h.

* *dlibc*: libc-like functions (ex. dprintf()) which wraps softUart routines for generating debugging messages. 

* *assert*: provides assert(), a macro function for validating code. Upon assertion failures, all interrupts are disabled, diagnostic information is printed to the software UART debug port (or stored in local variables, to be viewed using MPLABX's debugger if the soft UART is not being used), and execution is halted. Another routine (assertResetCondition()) is provided to assert that the MCU did not reset due to an error condition, such as a stack overflow.