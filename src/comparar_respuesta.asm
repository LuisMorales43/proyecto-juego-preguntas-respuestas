section .data
    respuestas_usuario db 3, 1, 2, 3, 4   ; Array de respuestas del usuario
    respuestas_correctas db 3, 2, 2, 3, 1 ; Array de respuestas correctas

    msg_aprobado db "Aprobado. Aciertos = ", 0
    msg_reprobado db "Reprobado. Aciertos = ", 0
    msg_cero db "Wow. Creo que toca estudiar un poco, tuviste cero aciertos...", 0

section .text
    global comparar_respuesta_start  ; Cambiamos _start por comparar_respuesta_start

comparar_respuesta_start:
    mov rdi, respuestas_usuario
    mov rsi, respuestas_correctas
    mov rcx, 5         ; Número de preguntas
    xor rax, rax       ; Contador de aciertos

comprobar:
    mov al, [rdi]
    cmp al, [rsi]
    jne siguiente

    inc rax            ; Incrementa el contador de aciertos

siguiente:
    inc rdi            ; Mueve al siguiente elemento del array
    inc rsi
    loop comprobar     ; Decrementa rcx y salta a comprobar si rcx != 0

    ; Mostrar resultado
    cmp rax, 0
    je mostrar_cero
    cmp rax, 3
    jae mostrar_aprobado
    cmp rax, 2
    jbe mostrar_reprobado

mostrar_aprobado:
    mov rdi, msg_aprobado
    call imprimir_mensaje
    jmp fin

mostrar_reprobado:
    mov rdi, msg_reprobado
    call imprimir_mensaje
    jmp fin

mostrar_cero:
    mov rdi, msg_cero
    call imprimir_mensaje
    jmp fin

imprimir_mensaje:
    mov rdx, rax  ; Guarda la cantidad de aciertos en rdx
    mov rsi, rdi  ; rdi ya tiene la dirección del mensaje
    mov rdi, 1    ; 1 es el descriptor de archivo de stdout
    mov rax, 1    ; sys_write
    syscall
    ret

fin:
    mov rax, 60   ; sys_exit
    xor rdi, rdi  ; estado de salida 0
    syscall
