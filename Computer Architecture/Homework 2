.data
prompt: .asciiz "Enter some text:"
.align 2
buff: .space 20
space: .byte ' '
end: .asciiz "the program is ending"
bye: .asciiz "goodbye | "
words: .asciiz " words "
chars: .asciiz " characters \n"
charCount: .word 0
wordCount: .word 0
newline: .asciiz "\n"

.text
main:
loop:
	lw $t0, newline #Used to see if the user enters a newline, since pressing "okay" with a blank string will still input a newline character, and pressing cancel will leave the current buffer unchanged
	sw $t0, buff
	li $v0, 54
	la $a0, prompt
	la $a1, buff
	li $a2, 20
	syscall
	la $a0, buff #reloading buff to a register
	lb $t0, 0($a0) #loading the first byte to check for a newline
	beq $t0, 10, exit #exit program if newline (if user enters a blank string or presses cancel)
	jal count #count function
	
	sw $v0, charCount #outputs user-inputted string
	sw $v1, wordCount
	li $v0, 4
	la $a0, buff
	syscall #outputs message displaying counts for words and characters
	li $v0, 1
	lw $a0, wordCount
	syscall
	li $v0, 4
	la $a0, words
	syscall
	li $v0, 1
	lw $a0, charCount
	syscall
	li $v0, 4
	la $a0, chars
	syscall
	j loop #repeats code until user enters blank string or presses cancel

exit:
li $v0, 59 #outputs dialogue message saying goodbye before program terminates
la $a0, bye
la $a1, end
syscall
li $v0, 10
syscall

count:
	addi $sp, $sp, -4 #push $s1 onto the stack
	sw $s1, 0($sp)
	li $v0, -1 #-1 to account for the newline character
	li $v1, 1 #1 to account for the user not putting a space after the last word
	lb $t0, space
	
	loop2: #loops through user-inputted string 
		lb $s1, ($a0)
		beq $s1, $0, return #terminates loop upon reaching null terminator
		addi $v0, $v0, 1 #increments per character
		addi $a0, $a0, 1 #increments address to evaluate the next byte
		beq $s1, $t0, word #branches if character is a space
		j loop2
		word:
			addi $v1, $v1, 1 #increments word by 1 for each space
			j loop2 
	return:
		lw $s1, 0($sp) #pop $s1 off the stack
		addi $sp, $sp, 4
		jr $ra
