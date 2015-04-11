.data
_i:		.word 0
_j:		.word 0
_temp_1:		.word 0
_temp_2:		.word 0
.text
main:
li	$t1, 1
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _i
li	$t1, 0
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _j
label_1:
lw	$t1, _j
li	$t2, 10
slt	$t0,$t1,$t2
sw	$t0, _temp_1
lw	$t1, _temp_1
bgtz	$t1, label_2
j		label_4
label_2:
lw	$t1, _i
li	$t2, 2
mult	$t1,$t2
mflo	$t0
sw	$t0, _temp_2
lw	$t1, _temp_2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _i
label_3:
lw	$t1, _j
li	$t2, 1
add	$t0,$t1,$t2
sw	$t0, _j
j		label_1
label_4:
lw	$t1, _i
li	$v0, 1
move	$a0, $t1
syscall
jr	$ra
