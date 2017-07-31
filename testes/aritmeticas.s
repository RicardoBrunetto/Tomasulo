.data
var1: .int 20
var2: .int 40
var3: .int 50
exit: .int 0

.text
.globl main
main:
  lw $s0, var1
  lw $s1, var2
  lw $s2, var3

  li $v0, 17
  sw $v0, exit

  add $s3, $s0, $s1
  sll $s2, $s0, 5

  sub $v1, $s0, $s3
  mult $s2, $s1

  mflo $v0
  move $a3, $v0

  move $a0, $a3
  syscall

fim:
  lw $v0, exit
  syscall
