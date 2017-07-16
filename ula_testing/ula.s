.section .data

controle:    .int    0
op1:         .int    0
op2:         .int    0
result:      .int    0

.section .text
.globl ula
.type ula, @function

ula:
  pushl %ebp
  movl %esp, %ebp

  movl 8(%ebp), %eax
  movl %eax, controle
  movl 12(%ebp), %eax
  movl %eax, op1
  movl 16(%ebp), %eax
  movl %eax, op2

  cmpl $0, controle
  je and_logico
  cmpl $1, controle
  je or_logico
  cmpl $2, controle
  je nor_logico
  cmpl $3, controle
  je xor_logico
  cmpl $4, controle
  je somador
  cmpl $5, controle
  je subtrator


# Funções da ULA
  and_logico:
    movl op1, %eax
    and op2, %eax
    movl %eax, result
    jmp fim

  or_logico:
    movl op1, %eax
    or op2, %eax
    movl %eax, result
    jmp fim

  nor_logico:
    movl op1, %eax
    or op2, %eax
    not %eax
    movl %eax, result
    jmp fim

  xor_logico:
    movl op1, %eax
    xor op2, %eax
    mov %eax, result
    jmp fim

  somador:
    movl op1, %eax
    add op2, %eax
    movl %eax, result
    jmp fim

  subtrator:
    movl op1, %eax
    sub op2, %eax
    movl %eax, result
    jmp fim

  fim:
    movl result, %eax
    movl %ebp, %esp
    popl %ebp
ret
