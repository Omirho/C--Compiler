.data
_temp_1.int.2:		.word 0
_temp_10.int.2:		.word 0
_temp_11.int.2:		.word 0
_temp_12.int.2:		.word 0
_temp_13.int.2:		.word 0
_temp_14.int.2:		.word 0
_temp_15.int.2:		.word 0
_temp_16.int.2:		.word 0
_temp_17.int.2:		.word 0
_temp_18.int.2:		.word 0
_temp_2.int.2:		.word 0
_temp_3.int.3:		.word 0
_temp_4.int.2:		.word 0
_temp_5.int.2:		.word 0
_temp_6.int.2:		.word 0
_temp_7.int.2:		.word 0
_temp_8.int.2:		.word 0
_temp_9.int.2:		.word 0
_x.int.2:		.word 0
_z.int.2:		.word 0
.text
_fib:
lw	$t1, _x.int.2
li	$t2, 2
slt	$t3,$t2,$t1
xori	$t0,$t3,1
sw	$t0, _temp_1.int.2
lw	$t1, _temp_1.int.2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp_2.int.2
lw	$t1, _temp_2.int.2
bgtz	$t1, label_1
j		label_2
label_1:
lw	$t1, _x.int.2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp_3.int.3
lw	$t1, _temp_3.int.3
move	$v0, $t1
jr	$ra
label_2:
lw	$t1, _x.int.2
li	$t2, 2
sub	$t0,$t1,$t2
sw	$t0, _temp_4.int.2
lw	$t1, _temp_4.int.2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp_5.int.2
addi	$sp,$sp,-4
sw	$ra,0($sp)
lw	$t1, _temp_1.int.2
addi	$sp,$sp,-4
lw	$t8, _temp_1.int.2
sw	$t8,0($sp)
lw	$t1, _temp_2.int.2
addi	$sp,$sp,-4
lw	$t8, _temp_2.int.2
sw	$t8,0($sp)
lw	$t1, _temp_4.int.2
addi	$sp,$sp,-4
lw	$t8, _temp_4.int.2
sw	$t8,0($sp)
lw	$t1, _temp_5.int.2
addi	$sp,$sp,-4
lw	$t8, _temp_5.int.2
sw	$t8,0($sp)
lw	$t1, _x.int.2
addi	$sp,$sp,-4
lw	$t8, _x.int.2
sw	$t8,0($sp)
lw	$t1, _temp_5.int.2
lw	$t2, _x.int.2
lw	$t8, _temp_5.int.2
sw	$t8, _x.int.2
jal	_fib
lw	$t1, _x.int.2
lw	$t8,0($sp)
sw	$t8, _x.int.2
addi	$sp,$sp,4
lw	$t1, _temp_5.int.2
lw	$t8,0($sp)
sw	$t8, _temp_5.int.2
addi	$sp,$sp,4
lw	$t1, _temp_4.int.2
lw	$t8,0($sp)
sw	$t8, _temp_4.int.2
addi	$sp,$sp,4
lw	$t1, _temp_2.int.2
lw	$t8,0($sp)
sw	$t8, _temp_2.int.2
addi	$sp,$sp,4
lw	$t1, _temp_1.int.2
lw	$t8,0($sp)
sw	$t8, _temp_1.int.2
addi	$sp,$sp,4
lw	$ra,0($sp)
addi	$sp,$sp,4
lw	$t1, _temp_6.int.2
sw	$v0, _temp_6.int.2
lw	$t1, _x.int.2
li	$t2, 1
sub	$t0,$t1,$t2
sw	$t0, _temp_7.int.2
lw	$t1, _temp_7.int.2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp_8.int.2
addi	$sp,$sp,-4
sw	$ra,0($sp)
lw	$t1, _temp_1.int.2
addi	$sp,$sp,-4
lw	$t8, _temp_1.int.2
sw	$t8,0($sp)
lw	$t1, _temp_2.int.2
addi	$sp,$sp,-4
lw	$t8, _temp_2.int.2
sw	$t8,0($sp)
lw	$t1, _temp_4.int.2
addi	$sp,$sp,-4
lw	$t8, _temp_4.int.2
sw	$t8,0($sp)
lw	$t1, _temp_5.int.2
addi	$sp,$sp,-4
lw	$t8, _temp_5.int.2
sw	$t8,0($sp)
lw	$t1, _temp_6.int.2
addi	$sp,$sp,-4
lw	$t8, _temp_6.int.2
sw	$t8,0($sp)
lw	$t1, _temp_7.int.2
addi	$sp,$sp,-4
lw	$t8, _temp_7.int.2
sw	$t8,0($sp)
lw	$t1, _temp_8.int.2
addi	$sp,$sp,-4
lw	$t8, _temp_8.int.2
sw	$t8,0($sp)
lw	$t1, _x.int.2
addi	$sp,$sp,-4
lw	$t8, _x.int.2
sw	$t8,0($sp)
lw	$t1, _temp_8.int.2
lw	$t2, _x.int.2
lw	$t8, _temp_8.int.2
sw	$t8, _x.int.2
jal	_fib
lw	$t1, _x.int.2
lw	$t8,0($sp)
sw	$t8, _x.int.2
addi	$sp,$sp,4
lw	$t1, _temp_8.int.2
lw	$t8,0($sp)
sw	$t8, _temp_8.int.2
addi	$sp,$sp,4
lw	$t1, _temp_7.int.2
lw	$t8,0($sp)
sw	$t8, _temp_7.int.2
addi	$sp,$sp,4
lw	$t1, _temp_6.int.2
lw	$t8,0($sp)
sw	$t8, _temp_6.int.2
addi	$sp,$sp,4
lw	$t1, _temp_5.int.2
lw	$t8,0($sp)
sw	$t8, _temp_5.int.2
addi	$sp,$sp,4
lw	$t1, _temp_4.int.2
lw	$t8,0($sp)
sw	$t8, _temp_4.int.2
addi	$sp,$sp,4
lw	$t1, _temp_2.int.2
lw	$t8,0($sp)
sw	$t8, _temp_2.int.2
addi	$sp,$sp,4
lw	$t1, _temp_1.int.2
lw	$t8,0($sp)
sw	$t8, _temp_1.int.2
addi	$sp,$sp,4
lw	$ra,0($sp)
addi	$sp,$sp,4
lw	$t1, _temp_9.int.2
sw	$v0, _temp_9.int.2
lw	$t1, _temp_9.int.2
lw	$t2, _temp_6.int.2
add	$t0,$t1,$t2
sw	$t0, _temp_10.int.2
lw	$t1, _temp_10.int.2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp_11.int.2
lw	$t1, _temp_11.int.2
move	$v0, $t1
jr	$ra
jr	$ra
main:
li	$t1, 5
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp_12.int.2
lw	$t1, _temp_12.int.2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _z.int.2
lw	$t1, _z.int.2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp_13.int.2
li	$t1, 10
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp_14.int.2
addi	$sp,$sp,-4
sw	$ra,0($sp)
lw	$t1, _temp_12.int.2
addi	$sp,$sp,-4
lw	$t8, _temp_12.int.2
sw	$t8,0($sp)
lw	$t1, _temp_13.int.2
addi	$sp,$sp,-4
lw	$t8, _temp_13.int.2
sw	$t8,0($sp)
lw	$t1, _temp_14.int.2
addi	$sp,$sp,-4
lw	$t8, _temp_14.int.2
sw	$t8,0($sp)
lw	$t1, _z.int.2
addi	$sp,$sp,-4
lw	$t8, _z.int.2
sw	$t8,0($sp)
lw	$t1, _temp_14.int.2
lw	$t2, _x.int.2
lw	$t8, _temp_14.int.2
sw	$t8, _x.int.2
jal	_fib
lw	$t1, _z.int.2
lw	$t8,0($sp)
sw	$t8, _z.int.2
addi	$sp,$sp,4
lw	$t1, _temp_14.int.2
lw	$t8,0($sp)
sw	$t8, _temp_14.int.2
addi	$sp,$sp,4
lw	$t1, _temp_13.int.2
lw	$t8,0($sp)
sw	$t8, _temp_13.int.2
addi	$sp,$sp,4
lw	$t1, _temp_12.int.2
lw	$t8,0($sp)
sw	$t8, _temp_12.int.2
addi	$sp,$sp,4
lw	$ra,0($sp)
addi	$sp,$sp,4
lw	$t1, _temp_15.int.2
sw	$v0, _temp_15.int.2
lw	$t1, _temp_15.int.2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp_16.int.2
lw	$t1, _temp_16.int.2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _z.int.2
lw	$t1, _z.int.2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp_17.int.2
lw	$t1, _z.int.2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp_18.int.2
lw	$t1, _temp_18.int.2
li	$v0, 1
move	$a0, $t1
syscall
jr	$ra
