.section .data

operation: .asciz  "\nOperation: %d\n"
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

  pushl opcode
  pushl $operation
  call printf
  add $8, %esp

  cmpl $12, opcode
  je and_logico

  and_logico:
    movl rs, %eax
    and rt, %eax
    movl %eax, result
    jmp fim



  fim:
    movl result, %eax
    movl %ebp, %esp
    popl %ebp
ret
