# 256 / 4 = 64; width & height of screen in pixels
.eqv WIDTH 64
.eqv HEIGHT 64
#colors
.eqv RED 0x00FF0000
.eqv GREEN 0x0000FF00
.eqv BLUE 0x000000FF
.eqv YELLOW 0x00FFFF00
.eqv CYAN 0x0000FFFF
.eqv MAGENTA 0x00FF00FF


.data
DELAY: .word 5
colors: .word RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA
BLACK: .word 0

.text
main:
# starting position
li $v0, 32
lw $a0, DELAY
addi $a1, $0, WIDTH
sra $a1, $a1, 1
addi $a2, $0, HEIGHT
sra $a2, $a2, 1
la $a3, colors
la $s3, BLACK
addi $t2, $a3, 20 # address after last color in colors array
loop:
	jal draw_box
	# check for input
	lw $t9, 0xffff0000
	beq $t9, 0, loop
	# process input
	lw $s7, 0xffff0004
	beq $s7, 32, exit # space
	beq $s7, 119, up # w
	beq $s7, 115, down # s
	beq $s7, 97, left # a 
	beq $s7, 100, right # d
	j loop
	# valid input
	up:
		la $a3, BLACK # black out current box
		jal draw_box
		addi $a2, $a2, -1
		la $a3, colors
		j loop
	down:
		la $a3, BLACK # black out current box
		jal draw_box
		addi $a2, $a2, 1
		la $a3, colors
		j loop
	left:
		la $a3, BLACK # black out current box
		jal draw_box
		addi $a1, $a1, -1
		la $a3, colors
		j loop
	right:
		la $a3, BLACK # black out current box
		jal draw_box
		addi $a1, $a1, 1
		la $a3, colors
		j loop
		
exit: 
li $v0, 10
syscall

draw_pixel:
mul $s1, $a2, WIDTH # row
add $s1, $s1, $a1 # add X (column)
mul $s1, $s1, 4 # word offset
add $s1, $s1, $gp # add to base address
lw $t1, ($a3)
sw $t1, 0($s1) # store color (draw)
jr $ra

draw_box:
	add $t0, $0, $0 # reset control
	top_loop:
		syscall # delay
		
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_pixel
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		beq $a3, $s3, continue_top # keep current color as black when erasing previous box
		addi $a3, $a3, 4 # next color in array
		ble $a3, $t2, continue_top # if outside of array, reset $a3 to beginning of colors
		addi $a3, $a3, -24
		
		continue_top:
		addi $a1, $a1, 1 # add 1 to address (shift right)
		addi $t0, $t0, 1 
		ble $t0, 6, top_loop # 7 iterations
		
	add $t0, $0, $0 
	right_loop:
		syscall
		
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_pixel
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		beq $a3, $s3, continue_right
		addi $a3, $a3, 4 # next color in array
		ble $a3, $t2, continue_right
		addi $a3, $a3, -24
		
		continue_right:
		addi $a2, $a2, 1 # next row, same column
		addi $t0, $t0, 1
		ble $t0, 6, right_loop 
		
	add $t0, $0, $0
	bottom_loop:
		syscall
		
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_pixel
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		beq $a3, $s3, continue_bottom
		addi $a3, $a3, 4 # next color in array
		ble $a3, $t2, continue_bottom
		addi $a3, $a3, -24
		
		continue_bottom:
		addi $a1, $a1, -1 # subtract 1 from address (shift left)
		addi $t0, $t0, 1
		ble $t0, 6, bottom_loop
		
	add $t0, $0, $0
	left_loop:
		syscall
		
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_pixel
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		beq $a3, $s3, continue_left
		addi $a3, $a3, 4 # next color in array
		ble $a3, $t2, continue_left
		addi $a3, $a3, -24
		
		continue_left:
		addi $a2, $a2, -1 # previous row
		addi $t0, $t0, 1
		ble $t0, 6, left_loop
	jr $ra
	

