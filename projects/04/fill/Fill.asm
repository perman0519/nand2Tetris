// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
	// the screen should remain fully black as long as the key is pressed.
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

// while (1)
// 	if (key_in)
// 		print_screen()

(CHECK_KEY)

	@SCREEN
	D = A
	@screen_address
	M = D
	@8191
	D = A
	@n
	M = D
	@i
	M = 0
	@KBD
	D = M
	@BLACK
	D;JGT

	(WHITE)
		@i
		D = M
		@n
		D = D - M
		@CHECK_KEY
		D;JGT
		//if
		@KBD
		D = M
		@BLACK
		D;JGT
		//false
		@screen_address
		A = M
		M = 0
		@IF_BREAK
		0;JMP
		//true
		(BLACK)
		@screen_address
		A = M
		M = -1
		(IF_BREAK)

		@i
		M = M + 1
		@screen_address
		M = M + 1

		@WHITE
		0;JMP
