.text
_add:
lw	$t1, _x.2
li	$t2, 0
slt	$t3,$t1,$t2
slt	$t4,$t2,$t1
or	$t5,$t3,$t4
xori	$t0,$t5,1
sw	$t0, _temp._1
lw	$t1, _temp._1
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp._2
lw	$t1, _temp._2
bgtz	$t1, label_1
j		label_2
label_1:
li	$t1, 0
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp._3
lw	$t1, _temp._3
move	$v0, $t1
jr	$ra
label_2:
lw	$t1, _x.2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp._4
lw	$t1, _temp._4
li	$v0, 1
move	$a0, $t1
syscall
lw	$t1, _x.2
li	$t2, 1
sub	$t0,$t1,$t2
sw	$t0, _temp._5
lw	$t1, _temp._5
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp._6
addi	$sp,$sp,-4
sw	$ra,0($sp)
lw	$t1, _tt
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp._7
lw	$t1, _temp._7
move	$v0, $t1
jr	$ra
jr	$ra
main:
