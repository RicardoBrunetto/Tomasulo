.data
zero: .int 0
um:   .int 1
exit: .int 17

.text
.globl main
main:
  lw $t0, zero
  lw $t1, um

  li $t7, 0
  li $s0, 10        #Fibonacci de s0

  blez $s0, fim

loop:

  move $s1, $t1
  add $t1, $t0, $t1
  move $t0, $s1

  addi $t7, $t7, 1
  beq $t7, $s0, fim
  j loop

fim:
  move $a0, $t0
  li $v0, 0
  syscall
  lw $v0, exit
  syscall
