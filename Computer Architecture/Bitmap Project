# Author: Nathaniel Tan
# Date: 22 April 2023
# This program allows you to choose between two games:
# Meteors, where you dodge falling meteors from the sky, and if you get hit, you lose!
# Or Connect Four, the classic game where you drop chips into a 6x7 board, and the first player to get four in a row wins!
# Begin by opening the Bitmap Display, and Keyboard and Display MMIO Simulator in MARS.
# Set unit width and height in pixels to 4, and set the base address to $gp. 
# Now, you can assemble and run the code!
# You will begin on a starting screen with the two games displayed; press 1 to select Meteors and 2 to select Connect Four.
# The screen will highlight the selected game.
# Once you are satisfied with your decision, press ENTER to begin playing the game!

###################################################################################

# 512 / 4 = 128; width of screen in pixels
.eqv WIDTH 128
# 256 / 4 = 64; height of screen in pixels
.eqv HEIGHT 64
# colors
.eqv RED 0xFF0000
.eqv BLUE 0xADD8E6
.eqv BROWN 0x964B00
.eqv GREEN 0x7CFC00
.eqv ORANGE 0xFFA500
.eqv BLACK 0x0
.eqv WHITE 0xFFFFFF
.eqv GRAY 0xD3D3D3
.eqv YELLOW 0xFFFF00
.eqv LIGHTRED 0xffcccb
.eqv LIGHTYELLOW 0xFDFD96
.eqv LIGHTGREEN 0x98fb98

.data        
mainScreenLine: .word BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
		      BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
		      WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
		      WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
		      WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
		      WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, 
		      BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
		      BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, 

mainScreenLineSelected: .word BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
		      	      BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
			      LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN,
			      LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN,
			      LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN,
			      LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN, LIGHTGREEN,
			      BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
		      	      BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK

blackLine: .word BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
		 BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
		 BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
		 BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
		 BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
		 BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
		 BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
		 BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK

groundLine: .word BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, 
		  BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN,
		  BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN,
		  BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN,
		  BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, 
		  BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN,
		  BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN,
		  BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN	
		    
grassLine: .word GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, 
		 GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, 
		 GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, 
		 GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
		 GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, 
		 GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, 
		 GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, 
		 GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN 
		 	 
line: .word BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
	    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
	    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
	    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
	    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
	    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
	    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
	    BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE
	    
tempLine: .word BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
	        BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
	        BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
	        BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
	        BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
	        BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
	        BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
	        BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE 
	        
connectFourBoard: .word WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
			WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
			WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
			WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
			WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
			WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE
  
chooseGame: .asciiz "Type 1 to play \"\Meteors\"\ or 2 to play \"\Connect Four.\"\ Press ENTER to confirm your choice. Press SPACE to exit.\n"
gameOver: .asciiz "Game Over!\n"
redWins: .asciiz "Red Wins!\n"
yellowWins: .asciiz "Yellow Wins!\n"
colors: .word RED, BLUE, ORANGE, WHITE, GRAY, YELLOW, LIGHTRED, LIGHTYELLOW, BLACK
meteorsControls: .asciiz "Press a to move left, d to move right, and SPACE to exit. Don't get hit by the meteors!\n"
connect4Controls: .asciiz "Press w to move the currently selected tile up, a to move it left, d to move it right, and s to move it down. \nPress ENTER to confirm your selection, and SPACE to exit. Be the first to connect four!\n"

.text
# $t0: address for drawing pixel
# $t1: address of color
# $t2: multiple of 4 to traverse line array
# $t3: iterator
# $t4: input value
# $t5: check for input
# $t6: iterator
# $t7: holds color for changing arrays
# $t8: iterator
# $t9: column of character
# $s0: address of index in line array
# $s1: tempLine
# $s2: holds row for connect 4 holes
# $s3: holds column for connect 4 holes
# $s4: turn bit (0 for red, 1 for yellow)
# $s5: holds array for connectFourBoard
# $s6: game bit (0 for meteors, 1 for connect four)
# $a0: Y (rows)
# $a1: X (columns)
main:
la $s0, blackLine
blackScreenLoop: # black out screen
	jal draw_line
	addi $a0, $a0, 1
	addi $t9, $t9, 1
	ble $t9, 63, blackScreenLoop
la $s0, mainScreenLineSelected
jal draw_first_game
la $s0, mainScreenLine
jal draw_second_game

la $a0, chooseGame
li $v0, 4
syscall
loop:
	# check for input
	lw $t5, 0xffff0000
	beq $t5, 0, loop
	# process input
	lw $t4, 0xffff0004
	beq $t4, 32, exit
	beq $t4, 49, selectMeteors
	beq $t4, 50, selectConnectFour
	beq $t4, 10, enterGame
	j loop

exit:
	la $a0, gameOver
	li $v0, 4
	syscall
	li $v0, 10
	syscall

###################################################################################

selectMeteors:
li $s6, 0
la $s0, mainScreenLineSelected

addi $sp, $sp, -4
sw $ra, 0($sp)
jal draw_first_game
lw $ra, ($sp)
addi $sp, $sp, 4

la $s0, mainScreenLine

addi $sp, $sp, -4
sw $ra, 0($sp)
jal draw_second_game
lw $ra, ($sp)
addi $sp, $sp, 4

jr $ra

selectConnectFour:
li $s6, 1
la $s0, mainScreenLine

addi $sp, $sp, -4
sw $ra, 0($sp)
jal draw_first_game
lw $ra, ($sp)
addi $sp, $sp, 4

la $s0, mainScreenLineSelected

addi $sp, $sp, -4
sw $ra, 0($sp)
jal draw_second_game
lw $ra, ($sp)
addi $sp, $sp, 4

jr $ra

enterGame:
beq $s6, 0, meteors
beq $s6, 1, connectFour

# load $s0 with mainScreenLine if not selected, mainScreenLineSelected if selected
draw_first_game:
li $a0, 8
firstGameLoop:
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_line
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	addi $a0, $a0, 1
	ble $a0, 24, firstGameLoop

# draw game name
la $s0, colors
addi $s0, $s0, 32 # black

li $a0, 12
li $a1, 37
addi $sp, $sp, -4
sw $ra, 0($sp)
jal drawM
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 12
li $a1, 46
addi $sp, $sp, -4
sw $ra, 0($sp)
jal drawE
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 12
li $a1, 54
addi $sp, $sp, -4
sw $ra, 0($sp)
jal drawT
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 12
li $a1, 61
addi $sp, $sp, -4
sw $ra, 0($sp)
jal drawE
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 12
li $a1, 69
addi $sp, $sp, -4
sw $ra, 0($sp)
jal drawO
lw $ra, ($sp)
addi $sp, $sp, 4

addi $sp, $sp, -4
sw $ra, 0($sp)
jal drawR
lw $ra, ($sp)
addi $sp, $sp, 4

addi $sp, $sp, -4
sw $ra, 0($sp)
jal drawS
lw $ra, ($sp)
addi $sp, $sp, 4

jr $ra

draw_second_game:
li $a0, 40
secondGameLoop:
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_line
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	addi $a0, $a0, 1
	ble $a0, 56, secondGameLoop

# draw game name
la $s0, colors
addi $s0, $s0, 32 # black

li $a0, 44
li $a1, 33
addi $sp, $sp, -4
sw $ra, 0($sp)
jal drawC
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 44
li $a1, 41
addi $sp, $sp, -4
sw $ra, 0($sp)
jal drawO
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 44
li $a1, 49
addi $sp, $sp, -4
sw $ra, 0($sp)
jal drawN
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 44
li $a1, 57
addi $sp, $sp, -4
sw $ra, 0($sp)
jal drawN
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 44
li $a1, 65
addi $sp, $sp, -4
sw $ra, 0($sp)
jal drawE
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 44
li $a1, 73
addi $sp, $sp, -4
sw $ra, 0($sp)
jal drawC
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 44
li $a1, 81
addi $sp, $sp, -4
sw $ra, 0($sp)
jal drawT
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 44
li $a1, 89
addi $sp, $sp, -4
sw $ra, 0($sp)
jal draw4
lw $ra, ($sp)
addi $sp, $sp, 4

jr $ra

###################################################################################

meteors:
la $a0, meteorsControls
li $v0, 4
syscall
addi $t9, $0, WIDTH
sra $t9, $t9, 1 # initial character position in the middle
la $s0, line
jal draw_screen
jal draw_ground

meteorsLoop:
	jal fall
	# check for input
	lw $t5, 0xffff0000
	beq $t5, 0, meteorsLoop
	# process input
	lw $t4, 0xffff0004
	beq $t4, 32, exit # space
	beq $t4, 97, left # a 
	beq $t4, 100, right # d
	j meteorsLoop


fall:
	# wait 1 ms
	li $v0, 32
	li $a0, 1
	syscall
	
	# create new line with generate_objs
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal generate_objs
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	# move lines down until ground (line 58)
	li $a0, -1
	li $t6, 0
	moveDownLoop:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal move_line_down
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		addi $t6, $t6, 1
		ble $t6, 58, moveDownLoop
		
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_character
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	jr $ra

generate_objs:
# for line array
# if random number 1-10 = 10
# replace BLUE with ORANGE
	li $v0, 42
	li $a1, 100 # 1/$a1 chance to be orange
	la $s0, line
	li $t8, 0
	objLoop:
		syscall
		beqz $a0, obj # replace with orange if 0; else replace with blue
		li $t7, BLUE
		sw $t7, ($s0)
		j cont # skip swap to orange
		obj:
			li $t7, ORANGE
			sw $t7, ($s0)
		cont:
			addi $t8, $t8, 1
			addi $s0, $s0, 4
			ble $t8, 127, objLoop
	la $s0, line
	jr $ra		

# start with current line saved
# start with $a0 as current row
move_line_down:
	addi $a0, $a0, 1 # next row
	mul $t0, $a0, WIDTH
	mul $t0, $t0, 4
	add $t0, $t0, $gp
	
	# save next line to tempLine
	la $s0, tempLine
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal save_line
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	# make next line current line
	la $s0, line
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_line
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	# save tempLine to current line
	la $s0, line
	la $s1, tempLine
	li $t8, 0
	
	copyArrayLoop: 
		lw $t7, 0($s1)
		sw $t7, 0($s0)
		addi $s0, $s0, 4
		addi $s1, $s1, 4
		addi $t8, $t8, 1
		ble $t8, 127, copyArrayLoop
	la $s0, line
	jr $ra
	
# load the array to save in in $s0
# load row # into $a0
save_line:
	mul $t0, $a0, WIDTH
	mul $t0, $t0, 4
	add $t0, $t0, $gp
	li $t8, 0
	saveLoop:
		lw $t7, 0($t0) # copy color of current pixel to array index
		sw $t7, 0($s0)
		addi $s0, $s0, 4 # next index 
		addi $t0, $t0, 4 # next pixel
		addi $t8, $t8, 1
		ble $t8, 127, saveLoop
	addi $s0, $s0, -512
	addi $t0, $t0, -512
	jr $ra

left:
	beq $t9, 0, exitLeft # can't move past screen border
	addi $t9, $t9, -1
	
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_character
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	exitLeft:
		jr $ra

right:
	beq $t9, 127, exitRight # can't move past screen border
	addi $t9, $t9, 1
	
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_character
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	exitRight:
		jr $ra

draw_screen:
	li $a0, 0 # iterator; also used for rows
	screenLoop:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_line
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		addi $a0, $a0, 1 # next row
		ble $a0, 58, screenLoop # ground takes up the lower 5 rows
	addi $a0, $a0, -1 # back up one row to draw character on top of the ground
	
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_character
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	jr $ra
		
draw_character:
	la $s0, colors
	addi $a1, $t9, 0
	
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_pixel
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	jr $ra
	
draw_ground: # draw 2 lines of green on top of 3 lines of brown
	addi $a0, $0, HEIGHT
	la $s0, groundLine
	li $t8, 0
	groundLoop:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_line
		lw $ra, ($sp)
		addi $sp, $sp, 4
		addi $a0, $a0 -1
		addi $t8, $t8, 1
		ble $t8, 3, groundLoop
	la $s0, grassLine
	li $t8, 0
	grassLoop:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_line
		lw $ra, ($sp)
		addi $sp, $sp, 4
		addi $a0, $a0 -1
		addi $t8, $t8, 1
		ble $t8, 1, grassLoop
	jr $ra

###################################################################################

connectFour:
la $a0, connect4Controls
li $v0, 4
syscall
li $t8, 0
li $a0, 0
la $s0, line
boardLoop: # fill screen with blue
	jal draw_line
	addi $a0, $a0, 1
	addi $t8, $t8, 1
	ble $t8, 63, boardLoop
	
li $a0, 0
li $t8, 0
li $s2, 2 # start at row 2
la $s0, colors
addi $s0, $s0, 12 # white
holesLoop:
	li $s3, 1 # start at column 1
	li $t6, 0
	holesRowLoop:
		jal draw_hole
		addi $s3, $s3, 18
		addi $t6, $t6, 1
		ble $t6, 6, holesRowLoop
	addi $s2, $s2, 10
	addi $t8, $t8, 1
	ble $t8, 5, holesLoop

la $s5, connectFourBoard # start at middle bottom hole
addi $s5, $s5, 152
li $s2, 52 
li $s3, 55
la $s0, colors
addi $s0, $s0, 24 # light red
jal draw_hole
	

connectFourLoop:
	# check for input
	lw $t5, 0xffff0000
	beq $t5, 0, connectFourLoop
	# process input
	lw $t4, 0xffff0004
	beq $t4, 32, exit # space
	beq $t4, 97, leftSlot # a 
	beq $t4, 100, rightSlot # d
	beq $t4, 115, downSlot # s
	beq $t4, 119, upSlot # w
	beq $t4, 10, fill # enter
	j connectFourLoop

leftSlot:
	ble $s3, 1, exitLeftSlot # leftmost column
	lw $t7, ($s5)
	bne $t7, WHITE, leftFilled # if a chip was already dropped, don't white out the slot
	la $s0, colors
	addi $s0, $s0, 12 # white
	
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_hole
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	leftFilled:
	addi $s3, $s3, -18 # each hole is 18 pixels apart horizontally
	addi $s5, $s5, -4
	
	lw $t7, ($s5)
	bne $t7, WHITE, upSlot # if a chip was already dropped in the new location, go to the next open slot in the column
	
	la $s0, colors
	addi $s0, $s0, 24 # light red
	
	beqz $s4, leftRedTurn
	la $s0, colors
	addi $s0, $s0, 28 # light yellow
	
	leftRedTurn:
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_hole
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	exitLeftSlot:
		jr $ra

rightSlot:
	bge $s3, 109, exitRightSlot # rightmost column
	lw $t7, ($s5)
	bne $t7, WHITE, rightFilled # if a chip was already dropped, don't white out the slot
	la $s0, colors
	addi $s0, $s0, 12 # white
	
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_hole
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	rightFilled:
	addi $s3, $s3, 18 # each hole is 18 pixels apart horizontally
	addi $s5, $s5, 4
	
	lw $t7, ($s5)
	bne $t7, WHITE, upSlot # if a chip was already dropped in the new location, go to the next open slot in the column
	
	la $s0, colors
	addi $s0, $s0, 24 # light red
	
	beqz $s4, rightRedTurn
	la $s0, colors
	addi $s0, $s0, 28 # light yellow
	
	rightRedTurn:
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_hole
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	
	exitRightSlot:
		jr $ra

downSlot:
	bge $s2, 50, exitDownSlot # lowest row
	lw $t7, ($s5)
	bne $t7, WHITE, downFilled # if a chip was already dropped, don't white out the slot
	la $s0, colors
	addi $s0, $s0, 12 # white
	
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_hole
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	downFilled:
	addi $s2, $s2, 10 # each hole is 10 pixels apart vertically
	addi $s5, $s5, 28
	
	lw $t7, ($s5)
	bne $t7, WHITE, upSlot # if a chip was already dropped in the new location, go to the next open slot in the column
	
	la $s0, colors
	addi $s0, $s0, 24 # light red
	
	beqz $s4, downRedTurn
	la $s0, colors
	addi $s0, $s0, 28 # light yellow
	
	downRedTurn:
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_hole
	lw $ra, ($sp)
	addi $sp, $sp, 4

	exitDownSlot:
		jr $ra

upSlot:
	ble $s2, 2, exitUpSlot # highest row
	lw $t7, ($s5)
	bne $t7, WHITE, upFilled # if a chip was already dropped, don't white out the slot
	la $s0, colors
	addi $s0, $s0, 12 # white
	
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_hole
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	upFilled:
	addi $s2, $s2, -10 # each hole is 10 pixels apart vertically
	addi $s5, $s5, -28
	
	lw $t7, ($s5)
	bne $t7, WHITE, upSlot # if a chip was already dropped in the new location, go to the next open slot in the column
	
	la $s0, colors
	addi $s0, $s0, 24 # light red
	
	beqz $s4, upRedTurn
	la $s0, colors
	addi $s0, $s0, 28 # light yellow
	
	upRedTurn:
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_hole
	lw $ra, ($sp)
	addi $sp, $sp, 4
	
	exitUpSlot:
		jr $ra
	
fill:
	bge $s2, 50, bottomRow # chips don't need another below them if they're in the bottom row
	lw $t7, 28($s5) # check value below current slot
	beq $t7, WHITE, fillExitFailed
	
	bottomRow:
	lw $t7, ($s5)
	bne $t7, WHITE, fillExit # cannot fill a slot that's already been filled
	beqz $s4, redFill
	
	la $s0, colors
	addi $s0, $s0, 20 # yellow
	
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal draw_hole
	lw $ra, ($sp)
	addi $sp, $sp, 4
	addi $s4, $s4, 1
	
	lw $t7, ($s0)
	sw $t7, ($s5) # store color in board array
	
	li $s4, 0
	
	# check for yellow vertical win
	lw $t7, 28($s5)
	bne $t7, YELLOW, checkHorizontalYellow
	lw $t7, 56($s5)
	bne $t7, YELLOW, checkHorizontalYellow
	lw $t7, 84($s5)
	bne $t7, YELLOW, checkHorizontalYellow
	la $a0, yellowWins
	li $v0, 4
	syscall
	j exit
	
	checkHorizontalYellow:
	div $t8, $s3, 18 # number of times to check left so that chips in the row above on the right don't get counted
	li $t6, 0 # used as counter
	li $t3, 0 # used to reset $s5 at the end of the loop
	leftYellowLoop:
		beqz $t8, rightYellow # leftmost column
		addi $t8, $t8, -1
		addi $s5, $s5, -4
		addi $t3, $t3, 4
		lw $t7, ($s5)
		bne $t7, YELLOW, rightYellow
		addi $t6, $t6, 1 # increase counter if left slot is yellow
		bgt $t8, 0, leftYellowLoop
	rightYellow:
	add $s5, $s5, $t3 # reset $s5
	div $t8, $s3, 18
	li $t3, 6
	sub $t8, $t3, $t8 # number of times to check right
	li $t3, 0
	rightYellowLoop:
		beqz $t8, finalHorizontalYellow
		addi $t8, $t8, -1
		addi $s5, $s5, 4
		addi $t3, $t3, -4
		lw $t7, ($s5)
		bne $t7, YELLOW, finalHorizontalYellow
		addi $t6, $t6, 1 # increase counter if right slot is yellow
		bgt $t8, 0, rightYellowLoop
	finalHorizontalYellow:
		add $s5, $s5, $t3
		blt $t6, 3, checkULLRDiagonalYellow # doesn't win if there are less than 3 directly adjacent yellows
		la $a0, yellowWins
		li $v0, 4
		syscall
		j exit
		
	checkULLRDiagonalYellow: # upper left/lower right diagonal
	div $t8, $s3, 18 # number of times to check left so that chips in the row above on the right don't get counted
	div $t9, $s2, 10 # number of times to check up
	li $t6, 0 # used as counter
	li $t3, 0 # used to reset $s5 at the end of the loop
	upperLeftYellowLoop:
		beqz $t8, lowerRightYellow # last column
		beqz $t9, lowerRightYellow # top row
		addi $s5, $s5, -32
		addi $t3, $t3, 32
		lw $t7, ($s5)
		bne $t7, YELLOW, lowerRightYellow
		addi $t6, $t6, 1 # increase counter if left slot is yellow
		bgt $t8, 0, upperLeftYellowLoop
	lowerRightYellow:
	add $s5, $s5, $t3
	div $t8, $s3, 18
	li $t3, 6
	sub $t8, $t3, $t8 # number of times to check right
	div $t9, $s2, 10
	li $t3, 5
	sub $t9, $t3, $t9 # number of times to check down
	li $t3, 0
	lowerRightYellowLoop:
		beqz $t8, finalULLRDiagonalYellow
		beqz $t9, finalULLRDiagonalYellow
		addi $s5, $s5, 32
		addi $t3, $t3, -32
		lw $t7, ($s5)
		bne $t7, YELLOW, finalULLRDiagonalYellow
		addi $t6, $t6, 1
		bgt $t8, 0, lowerRightYellowLoop
	finalULLRDiagonalYellow:
		add $s5, $s5, $t3
		blt $t6, 3, checkLLURDiagonalYellow
		la $a0, yellowWins
		li $v0, 4
		syscall
		j exit
		
	checkLLURDiagonalYellow: # lower left/upper right diagonal
	div $t8, $s3, 18 # number of times to check left so that chips in the row above on the right don't get counted
	div $t9, $s2, 10
	li $t3, 5
	sub $t9, $t3, $t9 # number of times to check down
	li $t6, 0 # used as counter
	li $t3, 0 # used to reset $s5 at the end of the loop
	lowerLeftYellowLoop:
		beqz $t8, upperRightYellow # last column
		beqz $t9, upperRightYellow # top row
		addi $s5, $s5, 24
		addi $t3, $t3, -24
		lw $t7, ($s5)
		bne $t7, YELLOW, upperRightYellow
		addi $t6, $t6, 1 # increase counter if left slot is yellow
		bgt $t8, 0, lowerLeftYellowLoop
	upperRightYellow:
	add $s5, $s5, $t3 # reset $s5
	div $t8, $s3, 18
	li $t3, 6
	sub $t8, $t3, $t8 # number of times to check right
	div $t9, $s2, 10 # number of times to check up
	li $t3, 0
	upperRightYellowLoop:
		beqz $t8, finalLLURDiagonalYellow
		beqz $t9, finalLLURDiagonalYellow
		addi $s5, $s5, -24
		addi $t3, $t3, 24
		lw $t7, ($s5)
		bne $t7, YELLOW, finalLLURDiagonalYellow
		addi $t6, $t6, 1
		bgt $t8, 0, upperRightYellowLoop
	finalLLURDiagonalYellow:
		add $s5, $s5, $t3
		blt $t6, 3, fillExit
		la $a0, yellowWins
		li $v0, 4
		syscall
		j exit
	
	redFill:
		la $s0, colors
		
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_hole
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		lw $t7, ($s0)
		sw $t7, ($s5) # store color in board array
	
		li $s4, 1
		
		# check for red vertical win
		lw $t7, 28($s5)
		bne $t7, RED, checkHorizontalRed
		lw $t7, 56($s5)
		bne $t7, RED, checkHorizontalRed
		lw $t7, 84($s5)
		bne $t7, RED, checkHorizontalRed
		la $a0, redWins
		li $v0, 4
		syscall
		j exit
		
		checkHorizontalRed:
		div $t8, $s3, 18 # number of times to check left so that chips in the row above on the right don't get counted
		li $t6, 0 # used as counter
		li $t3, 0 # used to reset $s5 at the end of the loop
		leftRedLoop:
			beqz $t8, rightRed # leftmost column
			addi $t8, $t8, -1
			addi $s5, $s5, -4
			addi $t3, $t3, 4
			lw $t7, ($s5)
			bne $t7, RED, rightRed
			addi $t6, $t6, 1 # increase counter if left slot is red
			bgt $t8, 0, leftRedLoop
		rightRed:
		add $s5, $s5, $t3 # reset $s5
		div $t8, $s3, 18
		li $t3, 6
		sub $t8, $t3, $t8 # number of slots to check right
		li $t3, 0
		rightRedLoop:
			beqz $t8, finalHorizontalRed
			addi $t8, $t8, -1
			addi $s5, $s5, 4
			addi $t3, $t3, -4
			lw $t7, ($s5)
			bne $t7, RED, finalHorizontalRed
			addi $t6, $t6, 1 # increase counter if right slot is yellow
			bgt $t8, 0, rightRedLoop
		finalHorizontalRed:
			add $s5, $s5, $t3
			blt $t6, 3, checkULLRDiagonalRed # doesn't win if there are less than 3 directly adjacent reds
			la $a0, redWins
			li $v0, 4
			syscall
			j exit
		
		checkULLRDiagonalRed: # upper left/lower right diagonal
		div $t8, $s3, 18 # number of times to check left so that chips in the row above on the right don't get counted
		div $t9, $s2, 10 # number of times to check up
		li $t6, 0 # used as counter
		li $t3, 0 # used to reset $s5 at the end of the loop
		upperLeftRedLoop:
			beqz $t8, lowerRightRed # last column
			beqz $t9, lowerRightRed # top row
			addi $s5, $s5, -32
			addi $t3, $t3, 32
			lw $t7, ($s5)
			bne $t7, RED, lowerRightRed
			addi $t6, $t6, 1 # increase counter if left slot is red
			bgt $t8, 0, upperLeftRedLoop
		lowerRightRed:
		add $s5, $s5, $t3
		div $t8, $s3, 18
		li $t3, 6
		sub $t8, $t3, $t8 # number of times to check right
		div $t9, $s2, 10
		li $t3, 5
		sub $t9, $t3, $t9 # number of times to check down
		li $t3, 0
		lowerRightRedLoop:
			beqz $t8, finalULLRDiagonalRed
			beqz $t9, finalULLRDiagonalRed
			addi $s5, $s5, 32
			addi $t3, $t3, -32
			lw $t7, ($s5)
			bne $t7, RED, finalULLRDiagonalRed
			addi $t6, $t6, 1
			bgt $t8, 0, lowerRightRedLoop
		finalULLRDiagonalRed:
			add $s5, $s5, $t3
			blt $t6, 3, checkLLURDiagonalRed
			la $a0, redWins
			li $v0, 4
			syscall
			j exit
		
		checkLLURDiagonalRed: # lower left/upper right diagonal
		div $t8, $s3, 18 # number of times to check left so that chips in the row above on the right don't get counted
		div $t9, $s2, 10
		li $t3, 5
		sub $t9, $t3, $t9 # number of times to check down
		li $t6, 0 # used as counter
		li $t3, 0 # used to reset $s5 at the end of the loop
		lowerLeftRedLoop:
			beqz $t8, upperRightRed # last column
			beqz $t9, upperRightRed # top row
			addi $s5, $s5, 24
			addi $t3, $t3, -24
			lw $t7, ($s5)
			bne $t7, RED, upperRightRed
			addi $t6, $t6, 1 # increase counter if left slot is red
			bgt $t8, 0, lowerLeftRedLoop
		upperRightRed:
		add $s5, $s5, $t3 # reset $s5
		div $t8, $s3, 18
		li $t3, 6
		sub $t8, $t3, $t8 # number of times to check right
		div $t9, $s2, 10 # number of times to check up
		li $t3, 0
		upperRightRedLoop:
			beqz $t8, finalLLURDiagonalRed
			beqz $t9, finalLLURDiagonalRed
			addi $s5, $s5, -24
			addi $t3, $t3, 24
			lw $t7, ($s5)
			bne $t7, RED, finalLLURDiagonalRed
			addi $t6, $t6, 1
			bgt $t8, 0, upperRightRedLoop
		finalLLURDiagonalRed:
			add $s5, $s5, $t3
			blt $t6, 3, fillExit
			la $a0, redWins
			li $v0, 4
			syscall
			j exit
		
		fillExit:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal upSlot
		lw $ra, ($sp)
		addi $sp, $sp, 4
		fillExitFailed:
		jr $ra

# load $s0 with the color
# load $s1 with the column
# load $s2 with the row
draw_hole:
	addi $a0, $s2, 1 # 1 row down
	addi $a1, $s3, 7 # 7 columns across
	li $t3, 1 # iterator starts at 1 to be used in subtraction later when moving to the next row
	firstLoop:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_pixel
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		addi $a1, $a1, 1
		addi $t3, $t3, 1
		ble $t3, 4, firstLoop
	addi $a0, $a0, 1
	sub $a1, $a1, $t3
	li $t3, 1
	secondLoop:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_pixel
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		addi $a1, $a1, 1
		addi $t3, $t3, 1
		ble $t3, 6, secondLoop
	addi $a0, $a0, 1
	sub $a1, $a1, $t3
	li $t3, 1
	thirdLoop:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_pixel
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		addi $a1, $a1, 1
		addi $t3, $t3, 1
		ble $t3, 8, thirdLoop
	addi $a0, $a0, 1
	sub $a1, $a1, $t3
	li $t3, 0
	fourthLoop:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_pixel
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		addi $a1, $a1, 1
		addi $t3, $t3, 1
		ble $t3, 9, fourthLoop
	addi $a0, $a0, 1
	sub $a1, $a1, $t3
	li $t3, -1
	fifthLoop:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_pixel
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		addi $a1, $a1, 1
		addi $t3, $t3, 1
		ble $t3, 8, fifthLoop
	addi $a0, $a0, 1
	sub $a1, $a1, $t3
	li $t3, -1
	sixthLoop:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_pixel
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		addi $a1, $a1, 1
		addi $t3, $t3, 1
		ble $t3, 6, sixthLoop
	addi $a0, $a0, 1
	sub $a1, $a1, $t3
	li $t3, -1
	seventhLoop:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_pixel
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		addi $a1, $a1, 1
		addi $t3, $t3, 1
		ble $t3, 4, seventhLoop
	addi $a0, $a0, 1
	sub $a1, $a1, $t3
	li $t3, 0
	eigthLoop:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_pixel
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		addi $a1, $a1, 1
		addi $t3, $t3, 1
		ble $t3, 3, eigthLoop
	jr $ra

###################################################################################

draw_pixel:
mul $t0, $a0, WIDTH # row	
add $t0, $t0, $a1 # add X (column)
mul $t0, $t0, 4 # word offset
add $t0, $t0, $gp # add to base address

lw $t1, ($s0)
lw $t7, ($t0)
bne $t7, RED, safe # if pixel to overwrite is not the character, skip collision check
beq $t1, ORANGE, exit # if pixel that will overwrite the character is orange, there is a collision; game over
safe:	
	sw $t1, 0($t0) # store color (draw)
jr $ra

# load $a0 with the row number before calling draw_line
# load $s0 with the line array before calling draw_line
draw_line:
	li $a1, 0 # iterator; also used for columns
	lineLoop:
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		jal draw_pixel
		lw $ra, ($sp)
		addi $sp, $sp, 4
		
		addi $s0, $s0, 4 # next array index
		addi $a1, $a1, 1
		ble $a1, 127, lineLoop
	addi $s0, $s0, -512 # reset to beginning of the array for the next draw_line call
	jr $ra
	
###################################################################################	
	
drawM:
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m1
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 12
addi $a1, $a1, 1
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m2
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a0, $a0, -1
addi $a1, $a1, 1
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m2
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a0, $a0, -1
addi $a1, $a1, 1
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m2
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a0, $a0, -3
addi $a1, $a1, 1
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m2
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a0, $a0, -3
addi $a1, $a1, 1
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m2
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a0, $a0, -2
addi $a1, $a1, 1
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m1
lw $ra, ($sp)
addi $sp, $sp, 4

jr $ra

m1:
addi $sp, $sp, -4
sw $ra, 0($sp)
jal draw_pixel
lw $ra, ($sp)
addi $sp, $sp, 4
addi $a0, $a0, 1
addi $t8, $t8, 1
ble $t8, 8, m1

jr $ra

m2:
addi $sp, $sp, -4
sw $ra, 0($sp)
jal draw_pixel
lw $ra, ($sp)
addi $sp, $sp, 4
addi $a0, $a0, 1
addi $t8, $t8, 1
ble $t8, 1, m2

jr $ra

drawE:
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal e1
lw $ra, ($sp)
addi $sp, $sp, 4

li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m1
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a0, $a0, -1
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal e1
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a0, $a0, -4
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal e2
lw $ra, ($sp)
addi $sp, $sp, 4

jr $ra

e1:
addi $sp, $sp, -4
sw $ra, 0($sp)
jal draw_pixel
lw $ra, ($sp)
addi $sp, $sp, 4
addi $a1, $a1, 1
addi $t8, $t8, 1
ble $t8, 5, e1
addi $a1, $a1, -6

jr $ra

e2:
addi $sp, $sp, -4
sw $ra, 0($sp)
jal draw_pixel
lw $ra, ($sp)
addi $sp, $sp, 4
addi $a1, $a1, 1
addi $t8, $t8, 1
ble $t8, 3, e2

jr $ra

drawT:
li $t8, 1
addi $sp, $sp, -4
sw $ra, 0($sp)
jal e1
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a1, $a1, 3
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m1
lw $ra, ($sp)
addi $sp, $sp, 4

jr $ra

drawC:
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal e1
lw $ra, ($sp)
addi $sp, $sp, 4

li $t8, 1
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m1
lw $ra, ($sp)
addi $sp, $sp, 4

li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal e1
lw $ra, ($sp)
addi $sp, $sp, 4

jr $ra

drawO:
addi $sp, $sp, -4
sw $ra, 0($sp)
jal drawC
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a0, $a0, -8
addi $a1, $a1, 5
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m1
lw $ra, ($sp)
addi $sp, $sp, 4

jr $ra

drawR:
li $a0, 12
li $a1, 77
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m1
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 12
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal e1
lw $ra, ($sp)
addi $sp, $sp, 4

li $a1, 82
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal r1
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 17
li $a1, 77
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal e1
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 18
li $a1, 81
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m2
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a0, $a0, -1
addi $a1, $a1, 1
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m2
lw $ra, ($sp)
addi $sp, $sp, 4

jr $ra

r1:
addi $sp, $sp, -4
sw $ra, 0($sp)
jal draw_pixel
lw $ra, ($sp)
addi $sp, $sp, 4
addi $a0, $a0, 1
addi $t8, $t8, 1
ble $t8, 4, r1

jr $ra

drawS:
li $a0, 12
li $a1, 85
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal e1
lw $ra, ($sp)
addi $sp, $sp, 4

li $a0, 12
li $a1, 85
li $t8, 1
addi $sp, $sp, -4
sw $ra, 0($sp)
jal r1
lw $ra, ($sp)
addi $sp, $sp, 4

li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal e1
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a1, $a1, 5
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal r1
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a0, $a0, -1
addi $a1, $a1, -5
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal e1
lw $ra, ($sp)
addi $sp, $sp, 4

jr $ra

drawN:
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m1
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a0, $a0, -9
addi $a1, $a1, 1
li $t8, -1
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m2
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a0, $a0, -1
addi $a1, $a1, 1
li $t8, -1
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m2
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a0, $a0, -1
addi $a1, $a1, 1
li $t8, -1
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m2
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a0, $a0, -1
addi $a1, $a1, 1
li $t8, -1
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m2
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a0, $a0, -9
addi $a1, $a1, 1
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m1
lw $ra, ($sp)
addi $sp, $sp, 4

jr $ra

draw4:
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal r1
lw $ra, ($sp)
addi $sp, $sp, 4

li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal e1
lw $ra, ($sp)
addi $sp, $sp, 4

addi $a1, $a1, 5
addi $a0, $a0, -5
li $t8, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal m1
lw $ra, ($sp)
addi $sp, $sp, 4

jr $ra
