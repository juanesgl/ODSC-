        // Evaluate a polynomial of the form a*x^2 + b*x + c 

        .global _start
        .text 
_start: 
        MOV R0, #2      // a
        MOV R1, #6      // b
        MOV R2, #9      // c 
        MOV R3, #5      // x

        MUL R4, R3, R3  // x*x 
        MUL R5, R0, R4  // a*x^2 
        MUL R6, R1, R3  // b*x 

        ADD R0, R5, R6  
        ADD R1, R0, R2  // result in R1

        MOV R7, #1      // syscall: exit
        MOV R0, R1      // return value = result
        SWI 0
