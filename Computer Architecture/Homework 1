.data
a: .word 0 #memory to store input values
b: .word 0
c: .word 0

out1: .word 0 #memory to hold output values
out2: .word 0
out3: .word 0

name: .asciiz "" #memory for name

msgName: .asciiz "Please enter your name: "               #messages
msgInt: .asciiz "Please enter an integer between 1-100: "
msgAns: .asciiz "Your answers are: "
space: .asciiz " "
	
.text
main:
li $v0, 4 #prompts user for name
la $a0, msgName
syscall
li $v0, 8 #reads string and stores it in name
la $a0, name
la $a1, 20
syscall

li $v0, 4 #prompts user for integer
la $a0, msgInt
syscall
li $v0, 5 #reads and stores integer in a
syscall
sw $v0, a
li $v0, 4 
la $a0, msgInt
syscall
li $v0, 5 #stores in b
syscall
sw $v0, b
li $v0, 4 
la $a0, msgInt
syscall
li $v0, 5 #stores in c
syscall
sw $v0, c

lw $t0, a #load a, b, and c for arithmetic
lw $t1, b
lw $t2, c

li $t3, 4
add $t4, $t0, $t0 #a+a
sub $t4, $t4, $t2 #-c
add $t4, $t4, $t3 #+4
sw $t4, out1

li $t3, 2
sub $t4, $t1, $t2 #b-c
sub $t5, $t0, $t3 #a-2
add $t4, $t4, $t5 #b-c + (a-2)
sw $t4, out2

li $t3, 1
li $t4, 3
add $t5, $t0, $t4 #a+3
sub $t6, $t1, $t3 #b-1
add $t7, $t2, $t4 #c+3
sub $t5, $t5, $t6 #(a+3) - (b-1)
add $t5, $t5, $t7 #(a+3)-(b-1) + (c+3)
sw $t5, out3

li $v0, 4  #Prints name
la $a0, name
syscall    #Prints results message
la $a0, msgAns
syscall #Prints each result with a space in between
li $v0, 1
lw $a0, out1
syscall
li $v0, 4
la $a0, space
syscall
li $v0, 1
lw $a0, out2
syscall
li $v0, 4
la $a0, space
syscall
li $v0, 1
lw $a0, out3
syscall
li $v0, 4
la $a0, space
syscall

exit:
li $v0, 10
syscall

#Sample Run #1
#Test Values: a=86, b=31, c=42
#Expected Results: 134, 73, 104
#Please enter your name: Nathaniel
#Please enter an integer between 1-100: 86
#Please enter an integer between 1-100: 31
#Please enter an integer between 1-100: 42
##Nathaniel
#Your answers are: 134 73 104 
#-- program is finished running --

#Sample Run #2
#Test Values: a=3, b=54, c=92
#Expected Results: -82, -37, 48
#Please enter your name: Nathaniel
#Please enter an integer between 1-100: 3
#Please enter an integer between 1-100: 54
#Please enter an integer between 1-100: 92
#Nathaniel
#Your answers are: -82 -37 48 
#-- program is finished running --
