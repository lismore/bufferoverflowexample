# Buffer Overflow Example

This code is an example of a buffer overflow causing a segmentation fault.

Buffer Overflows in software are often exploited through a technique of using NOP's (No operation Commands) or a NOP sled that tell a processor to move to the next instruction.

***The buffer is padded with “\x90” —Intel NOPs. 
***This opcode tells the CPU to move on to the next operation, until we get to our shell code payload

    Lower Memory Address            Buffer Filled                                     Higher Memory Address
    0x00000000                      ------->                                                     0xfffffff0
    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    |         |     |      |              |         |                 |           |                       |
    | UNUSED  |     | NOPs | PAYLOAD CODE |         | PAYLOAD ADDRESS | ARGUMENTS |                       |   <- Process
    |         |     |      |              |         |                 |           |                       |
    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
             ESP     /|\                                       |                 EBP
                      |________________________________________|
                   
                   ----------
                   |>_      | Exploit Payload /bin/sh 
                   |        |
                   ----------
                   
  
