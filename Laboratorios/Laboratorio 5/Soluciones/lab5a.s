.data
.balign 4
scan_pattern:    .asciz "%d"

.balign 4
print_pattern:   .asciz "Result=%d\n"

.balign 4
a:       .word 0   // a
b:       .word 0   // b
c:       .word 0   // c
x:       .word 0   // x
polynomic: .word 0 // result
return:   .word 0

.text
.global main
.global scanf
.global printf

.func main
main:
    LDR R1, =return
    STR LR, [R1]

    // scanf("%d", &a)
    LDR R0, =scan_pattern
    LDR R1, =a
    BL scanf

    // scanf("%d", &b)
    LDR R0, =scan_pattern
    LDR R1, =b
    BL scanf

    // scanf("%d", &c)
    LDR R0, =scan_pattern
    LDR R1, =c
    BL scanf

    // scanf("%d", &x)
    LDR R0, =scan_pattern
    LDR R1, =x
    BL scanf

    // Cargar los valores a, b, c, x
    LDR R0, =a
    LDR R0, [R0]     // a

    LDR R1, =b
    LDR R1, [R1]     // b

    LDR R2, =c
    LDR R2, [R2]     // c

    LDR R3, =x
    LDR R3, [R3]     // x

    // Calcular a*x^2 + b*x + c
    MUL R4, R3, R3   // x*x
    MUL R5, R0, R4   // a*x^2
    MUL R6, R1, R3   // b*x
    ADD R7, R5, R6
    ADD R7, R7, R2   // R7 = a*x^2 + b*x + c

    // Guardar resultado
    LDR R0, =polynomic
    STR R7, [R0]

    // printf("Result=%d\n", polynomic)
    LDR R0, =print_pattern
    LDR R1, =polynomic
    LDR R1, [R1]
    BL printf

    // return 0
    MOV R0, #0
    LDR LR, =return
    LDR LR, [LR]
    BX LR
.endfunc