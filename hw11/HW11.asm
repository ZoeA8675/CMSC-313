; ASCII program coded by Zoe Astfidis for HW11

; SECTION .data(Lines 6-10) defines the imput the assembly is going to use. It also defines the space chracter between every byte of output.
; This section also defines the space for the new lines thats going to be printed after the output.

SECTION .data
inputBuf:
    db  0x83,0x6A,0x88,0xDE,0x9A,0xC3,0x54,0x9A 
newLine db 0x0A

;SECTION .bss(Lines 14-16) defines the data for the output, specificaly the number of bits the output(outputBuf) has. 
;In this case, this output has 80 bits of space.

SECTION .bss
outputBuf:
    resb 80 

;SECTION .text(21-76) defines the code the assmbler is going to process. global _start acts as the main clause for assembly langugage.

SECTION .text
global _start

_start:
;define the counters for input(ESI), output(EDI), and the loop specifically(ECX)
    XOR ESI, ESI 
    XOR EDI, EDI 
    MOV ECX, 8 

; .loop sets up the loop to be preformed 8 times for each bit(ECX = 8)
.loop:
    ;load input into AL and save a backup of the input into AH for converting the lower number (the 6 in 86)
    MOV AL, [inputBuf + ESI]
    MOV AH, AL

    ;Lines 37-41 convert the upper number (the 8 in 86).
    ; the AND command masks everything except the upper number
    AND AL, 0x00F0
    ; the SHR shifts the number over to the last digit so it can be converted to ASCII
    SHR AL, 4
    ; the CALL command calls the subroutine ASCII to take that digit and convert it into a number or letter
    CALL ASCII
    ; Lines 44-45 take the translated value and adds it into outputBuf, the output. 
    MOV [outputBuf + EDI], AL
    INC EDI
    
    ;Lines 37-41 convert the lower number (the 6 in 86).
    ; we move the copy of the input stored in AH and move it to AL to be used for processing
    MOV AL, AH
    ; the AND command masks everything except the lower number
    AND AL, 0x000F
    ; the CALL command calls the subroutine ASCII to take that digit and convert it into a number or letter
    CALL ASCII
    ; Lines 55-56 take the translated value and adds it into outputBuf, the output. 
    MOV [outputBuf + EDI], AL
    INC EDI

    ;Lines 59-62 adds a space between 2 chracters(1 byte) and finish loop
    MOV BYTE [outputBuf + EDI], ' '
    INC EDI
    INC ESI
    LOOP .loop

    ;Lines 64-68 print out ASCII character from outputBuf
    MOV EAX, 4
    MOV EBX, 1
    MOV ECX, outputBuf
    MOV EDX, EDI
    int 80h

    ;Lines 71-75 print out new line spaces for after the output and the space after that
    MOV EAX, 4
    MOV EBX, 1
    MOV ECX, newLine
    MOV EDX, 1
    int 80h

    MOV EAX, 4
    MOV EBX, 1
    MOV ECX, newLine
    MOV EDX, 1
    int 80h

    ;Lines 84-85 call for syscall to exit program
    mov eax, 1
    int 80h

;Lines 88-96 define subroutines to convert hex to ASCII
;The subroutine ASCII compares the digit in AL to the hex value 'A' (AKA 41 on the ASCII table) and see if AL is a value lower than 41.
; if AL is less than 41, it uses the JL command to jump to the subroutine digit. The subroutine digit takes the digit in AL, adds 30 (AKA '0') to convert
; it to a number 1-9 in ASCII, and uses the RET command to return that value. 
; If AL is greater than 41, the subroutine ASCII takes the digit AL, adds 37 to convert it to a letter A-F in ASCII, and uses the RET command to return that value. 
ASCII:
    CMP AL, 0xA
    JL digit
    ADD AL, 0x37
    RET

digit:
     ADD AL, 0x30
     RET
