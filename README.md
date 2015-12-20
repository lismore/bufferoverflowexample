# Buffer Overflow Example

This code in file "bufferoverflow.c" is an example of vulnerable code that can be exploited through a buffer overflow causing a segmentation fault (Program Crash).

Buffer Overflows in software are often exploited through a technique of using NOP's (No operation Commands) or a NOP sled that tell a processor to move (or slide across the NOPs) to the next instruction.

***The buffer is typically padded with “\x90” —Intel NOPs.

***This opcode tells the CPU to move on to the next operation, until we get to our shell code payload

This illustration below helps to visualize what is going on in terms of memory of a process.


    Lower Memory Address            Buffer Filled                                     Higher Memory Address
    0x00000000                      ------->                                                     0xfffffff0
    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    |         |     |      |              |         |                 |           |                       |
    | UNUSED  |     | NOPs | PAYLOAD CODE |         | PAYLOAD ADDRESS | ARGUMENTS |                       |   <- Process
    |         |     |      |              |         |                 |           |                       |
    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
             ESP   /|\                                       |                   EBP
                    |________________________________________|
                   
                   ----------
                   |>_      | Exploit Payload /bin/sh 
                   |        |
                   ----------
                   
  
Each process is allocated its own stack

Each function ia given its own stack frame

Stack Registers:

• The Extended Base Pointer (EBP) is the Base Address of current stack frame

• The Extended Stack Pointer (ESP) is the Address of Top of the stack

    Lower Memory Address                                                              Higher Memory Address
    0x00000000                                                                                   0xfffffff0
    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    |                                       |                                      |                      |
    |               UNUSED                  |           Stack Frame                |                      |
    |                                       |                                      |                      |
    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                            ESP                                   EBP
                             
