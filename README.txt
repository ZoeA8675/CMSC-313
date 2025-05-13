AUTHORING: 
    Zoe Astifidis, UMBC CMSC 313 Mon/Wed 10am, 05/12/2025

PURPOSE OF SOFTWARE: 
    Software takes 8 bits of data, translates it to ASCII characters, and prints the characters to the screen
    
FILES: 
    HW11.ASM: Assembly langauge file that takes data and translates it to ASCII

BUILD INSTRUCTIONS: 
    Step 1: Download the file 'HW11.asm' . 
    Step 2: Compile and run using commands below:
        Compile: nasm -f elf32 -g -F dwarf -o HW11.o HW11.asm
        Load: ld -m elf_i386 -o HW11 HW11.o
        Run: ./HW11

TESTING METHODOLOGY: 
    Assembly langauge was compiled in HW11.asm

ADDITIONAL INFORMATION: N/A