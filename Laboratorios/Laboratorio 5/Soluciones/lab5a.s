.data
    a: .word 2              @ a = 2 (hardcoded para prueba)
    b: .word 3              @ b = 3
    c: .word 1              @ c = 1
    x: .word 5              @ x = 5
    result: .word 0         @ result = 0

.text
.global main

main:
    LDR R1, =a              @ Cargar a
    LDR R1, [R1]
    
    LDR R2, =b              @ Cargar b
    LDR R2, [R2]
    
    LDR R3, =c              @ Cargar c
    LDR R3, [R3]
    
    LDR R4, =x              @ Cargar x
    LDR R4, [R4]
    
    MUL R5, R4, R4          @ R5 = x * x
    MUL R5, R1, R5          @ R5 = a * x^2
    
    MUL R6, R2, R4          @ R6 = b * x
    ADD R5, R5, R6          @ R5 = a*x^2 + b*x
    ADD R5, R5, R3          @ R5 = a*x^2 + b*x + c
    
    LDR R7, =result         @ Guardar resultado
    STR R5, [R7]
    
    BX LR                   @ Retornar

.end
