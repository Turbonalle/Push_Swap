PUSH SWAP

In this project you're supposed to create an algorithm that sorts a stack with the help of a second empty stack.


RULES

Input:
- Numbers as arguments

Task:
- Create one stack with the numbers (stack A), where the first argument will be the top of the stack, and one empty stack (stack B).
- Using a certain set of commands, sort the numbers so that the smallest number will be on the top of the stack, and the largest number will be on the bottom of the stack.
- Print out the commands you make.
- Try using as few commands as possible.

Commands:
- sa: Swap the top two elements of stack A.
- sb: Swap the top two elements of stack B.
- ss: sa + sb.
- pa: Move the top of stack A to the top of stack B.
- pb: Move the top of stack B to the top of stack A.
- ra: Move the top element of stack A to the bottom, and shift every element up.
- rb: Move the top element of stack B to the bottom, and shift every element up.
- rr: ra + rb.
- rra: Move the bottom element of stack A to the top, and shift every element down.
- rrb: Move the bottom element of stack B to the top, and shift every element down.
- rrr: rra + rrb.

Allowed functions:
- read, write, malloc, free, exit
