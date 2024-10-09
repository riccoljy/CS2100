# arrayCount.asm
  .data 
arrayA: .word 1, 2, 3, 4, 5, 6, 7, 8   # arrayA has 5 values
count:  .word 0

  .text
main:
    la $t0, arrayA #t0 = pointer
    addi $t1, $t0, 32 #t1 -> end
    lw $t8, count #t8 = count

    # code to setup the variable mapings
    #add $zero, $zero, $zero  #dummy instructions, can be removed
    #add $zero, $zero, $zero  #dummy instructions, can be removed
    #add $zero, $zero, $zero  #dummy instructions, can be removed

    # code for reading in the user value X
    li $v0, 5 #change syscall to read int
    syscall
    addi $t3, $v0, -1 #$t3 = mask (modulo)

    # code for counting multiples of X in arrayA
loop:
    beq $t0, $t1, end
    lw $t2, 0($t0) #$t2 = *ptr
    and $t4, $t2, $t3 #if result = 0, *ptr == multiple of X
    bne $t4, $0, skip
    addi $t8, $t8, 1 #count++ if $t4 (result) == 0
skip:
    addi $t0, $t0, 4 #ptr++
    j loop

end:
    # code for printing result
    li $v0, 1
    add $a0, $0, $t8
    syscall

    # code for terminating program
    li  $v0, 10
    syscall
