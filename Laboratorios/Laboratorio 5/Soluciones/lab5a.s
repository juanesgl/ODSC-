.data                           
 
.balign 4                       // Align the next label to a multiple of 4 bytes
scan_pattern: .asciz "%d"       // Define string "%d" (null-terminated) for scanf
 
.balign 4                       // Align the next label to a multiple of 4 bytes
print_pattern: .asciz "%d\n"    // Define string "%d\n" (null-terminated) for printf
 
.balign 4                       // Align the next label to a multiple of 4 bytes
a: .word 0                      // Reserve 4 bytes and initialize a = 0
b: .word 0                      // Reserve 4 bytes and initialize b = 0
c: .word 0                      // Reserve 4 bytes and initialize c = 0
x: .word 0                      // Reserve 4 bytes and initialize x = 0
polinomio: .word 0              // Reserve 4 bytes and initialize polinomio = 0
return:  .word 0                // Reserve 4 bytes to temporarily store LR (Link Register)
 
.text                           // Code section
 
.global main                    // Make the label 'main' visible to the linker
.global scanf                   // Declare scanf as an external global symbol
.global printf                  // Declare printf as an external global symbol
 
.func main                      // Mark the beginning of the 'main' function (for debugging)
main:                           // Entry point of the main function
        LDR R1, =return         // Load the address of 'return' into R1
        STR LR, [R1]            // Store the current value of LR (link register) in 'return'
 
        LDR R0, =scan_pattern   // Load the address of "%d" into R0 (format for scanf)
        LDR R1, =a              // Load the address of a into R1 (&a)
        BL scanf                // Call scanf to read an integer from input
 
        LDR R0, =scan_pattern   // Load the address of "%d" again
        LDR R1, =b              // Load the address of b into R1 (&b)
        BL scanf                // Call scanf to read the second integer
 
        LDR R0, =scan_pattern   // Load the address of "%d" again
        LDR R1, =c              // Load the address of c into R1 (&c)
        BL scanf                // Call scanf to read the third integer
 
        LDR R0, =scan_pattern   // Load the address of "%d" again
        LDR R1, =x              // Load the address of x into R1 (&x)
        BL scanf                // Call scanf to read x
 
        LDR R1, =a              // Load the address of a into R1
        LDR R1, [R1]            // Load the value stored in a into R1
 
        LDR R2, =b              // Load the address of b into R2
        LDR R2, [R2]            // Load the value stored in b into R2
 
        LDR R3, =c              // Load the address of c into R3
        LDR R3, [R3]            // Load the value stored in c into R3
 
        LDR R4, =x              // Load the address of x into R4
        LDR R4, [R4]            // Load the value stored in x into R4
 
// Computations
        MUL R5, R4, R4          // R5 = x * x
        MUL R5, R1, R5          // R5 = a * x * x
        MUL R6, R2, R4          // R6 = b * x
 
        ADD R5, R5, R6          // R5 = a*x*x + b*x
        ADD R5, R5, R3          // R5 = a*x*x + b*x + c
 
// Termination and output
        LDR R0, =print_pattern  // Load the address of "%d\n" into R0
        MOV R1, R5              // Move the result into R1
        BL printf               // Call printf to print the result
 
        LDR LR, =return         // Load the address of 'return' into LR
        LDR LR, [LR]            // Restore the saved LR value
        BX LR                   // Return from main
.endfunc                        
 
.end
