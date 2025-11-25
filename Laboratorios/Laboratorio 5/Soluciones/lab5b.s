.arch armv7-a
.arch_extension idiv

.data

.balign 4
scan_pattern:  .asciz "%d"        // format for scanf

.balign 4
print_pattern: .asciz "%d\n"      // format for printf

.balign 4
tc:        .word 0
belgium:   .word 0
england:   .word 0
norway:    .word 0
ireland:   .word 0
france:    .word 0
mcd_val:   .word 0
return:    .word 0

.text
.global main
.global scanf
.global printf

.func main
main:
        // Save link register
        LDR R1, =return
        STR LR, [R1]

        // Read number of test cases
        LDR R0, =scan_pattern
        LDR R1, =tc
        BL scanf

        LDR R1, =tc
        LDR R1, [R1]          // R1 = number of cases
        MOV R6, #0            // R6 = contador (no R0)

loop_cases:
        CMP R6, R1
        BEQ end_program

        // --- Read passengers for each country ---
        LDR R0, =scan_pattern
        LDR R1, =belgium
        BL scanf

        LDR R0, =scan_pattern
        LDR R1, =england
        BL scanf

        LDR R0, =scan_pattern
        LDR R1, =norway
        BL scanf

        LDR R0, =scan_pattern
        LDR R1, =ireland
        BL scanf

        LDR R0, =scan_pattern
        LDR R1, =france
        BL scanf

        // --- Compute GCD of the 5 countries ---
        LDR R1, =belgium
        LDR R1, [R1]
        LDR R2, =england
        LDR R2, [R2]
        BL gcd
        MOV R4, R0

        LDR R2, =norway
        LDR R2, [R2]
        MOV R1, R4
        BL gcd
        MOV R4, R0

        LDR R2, =ireland
        LDR R2, [R2]
        MOV R1, R4
        BL gcd
        MOV R4, R0

        LDR R2, =france
        LDR R2, [R2]
        MOV R1, R4
        BL gcd
        MOV R4, R0              // R4 = final gcd

        // Print gcd
        LDR R0, =print_pattern
        MOV R1, R4
        BL printf

        // --- Divide and print each country ---
        MOV R5, #0              // total = 0

        // Belgium
        LDR R1, =belgium
        LDR R1, [R1]
        UDIV R3, R1, R4
        ADD R5, R5, R3
        LDR R0, =print_pattern
        MOV R1, R3
        BL printf

        // England
        LDR R1, =england
        LDR R1, [R1]
        UDIV R3, R1, R4
        ADD R5, R5, R3
        LDR R0, =print_pattern
        MOV R1, R3
        BL printf

        // Norway
        LDR R1, =norway
        LDR R1, [R1]
        UDIV R3, R1, R4
        ADD R5, R5, R3
        LDR R0, =print_pattern
        MOV R1, R3
        BL printf

        // Ireland
        LDR R1, =ireland
        LDR R1, [R1]
        UDIV R3, R1, R4
        ADD R5, R5, R3
        LDR R0, =print_pattern
        MOV R1, R3
        BL printf

        // France
        LDR R1, =france
        LDR R1, [R1]
        UDIV R3, R1, R4
        ADD R5, R5, R3
        LDR R0, =print_pattern
        MOV R1, R3
        BL printf

        // Print total
        LDR R0, =print_pattern
        MOV R1, R5
        BL printf

        // Next test case
        ADD R6, R6, #1        // Incrementa R6, NO R0
        B loop_cases

end_program:
        // Proper exit syscall
        MOV R7, #1      // syscall number 1 = exit
        MOV R0, #0      // exit code = 0
        SVC 0
.endfunc

// ------------------------------------------------------------
// gcd(a, b) using Euclidâ€™s algorithm
// R1 = a, R2 = b
// Returns result in R0
// ------------------------------------------------------------
.func gcd
gcd:
        CMP R2, #0
        BEQ done_gcd
gcd_loop:
        UDIV R3, R1, R2         // R3 = a / b
        MLS R4, R3, R2, R1      // R4 = a - b*(a/b)
        MOV R1, R2              // a = b
        MOV R2, R4              // b = remainder
        CMP R2, #0
        BNE gcd_loop
done_gcd:
        MOV R0, R1
        BX LR
.endfunc

.end
