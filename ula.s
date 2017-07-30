# 0   - ADD
# 1   - AND
# 2   - OR
# 3   - NOR
# 4   - SLL (op1 deslocado op2 vezes)
# 5   - SRL
# 6   - SRA
# 7   - SUB
# 8   - XOR
# 9   - A<B
# 10  - A>B
# 11  - A=B
# 12  - AxB (sig)
# 13  - AxB (sig hi)
# 14  - AxB (unsig)
# 15  - AxB (unsig hi)
# 16  - A/B (sig)
# 17  - A mod B

# ula(func, op1, op2);

.section .data

controle:    .int    0
op1:         .int    0
op2:         .int    0
result:      .int    0

.section .text
.globl ula
.type ula, @function

ula:
  push %rbp
  mov %rsp, %rbp

  # a = rdi
  # b = rsi
  # c = rdx
  mov %rdi, controle
  mov %rsi, op1
  mov %rdx, op2

  movl op1, %eax

  cmpl $0, controle
  je add_lb
  cmpl $1, controle
  je and_lb
  cmpl $2, controle
  je or_lb
  cmpl $3, controle
  je nor_lb
  cmpl $4, controle
  je sll_lb
  cmpl $5, controle
  je srl_lb
  cmpl $6, controle
  je sra_lb
  cmpl $7, controle
  je sub_lb
  cmpl $8, controle
  je xor_lb
  cmpl $9, controle
  je if_op1_menor_op2_lb
  cmpl $10, controle
  je if_op1_maior_op2_lb
  cmpl $11, controle
  je if_op1_igual_op2_lb
  cmpl $12, controle
  je mul_lb
  cmpl $13, controle
  je mul_hi_lb
  cmpl $14, controle
  je mul_unsigned_lb
  cmpl $15, controle
  je mul_hi_unsigned_lb
  cmpl $16, controle
  je div_lb
  cmpl $17, controle
  je mod_lb


# Funções da ULA
  add_lb:
    addl op2, %eax
    jmp fim

  and_lb:
    andl op2, %eax
    jmp fim

  or_lb:
    orl op2, %eax
    jmp fim

  nor_lb:
    orl op2, %eax
    not %eax
    jmp fim

  sll_lb:
    mov op2, %cl
    sall %cl, %eax
    jmp fim

  srl_lb:
    mov op2, %cl
    sarl %cl, %eax
    jmp fim

  sra_lb:
    mov op2, %cl
    rorl %cl, %eax
    jmp fim

  sub_lb:
    subl op2, %eax
    jmp fim

  xor_lb:
    xorl op2, %eax
    jmp fim

  if_op1_menor_op2_lb:
    cmpl op2, %eax
    jl ok_if_op1_menor_op2_lb
    movl $0, %eax
    jmp fim
    ok_if_op1_menor_op2_lb:
    movl $1, %eax
    jmp fim

  if_op1_maior_op2_lb:
    cmpl op2, %eax
    jg ok_if_op1_maior_op2_lb
    movl $0, %eax
    jmp fim
    ok_if_op1_maior_op2_lb:
    movl $1, %eax
    jmp fim

  if_op1_igual_op2_lb:
    cmpl op2, %eax
    je ok_if_op1_igual_op2_lb
    movl $0, %eax
    jmp fim
    ok_if_op1_igual_op2_lb:
    movl $1, %eax
    jmp fim

  mul_lb:
    imull op2, %eax
    jmp fim

  mul_hi_lb:
    movl $0, %edx
    imull op2, %eax
    movl %edx, %eax
    jmp fim

  mul_unsigned_lb:
    mull op2
    jmp fim

  mul_hi_unsigned_lb:
    movl $0, %edx
    mull op2
    movl %edx, %eax
    jmp fim

  div_lb:
    cltd
    idivl op2
    jmp fim

  mod_lb:
    cltd
    idivl op2
    movl %edx, %eax
    jmp fim

  fim:
    mov %rbp, %rsp
    pop %rbp
ret
