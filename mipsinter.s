.text
main:
li	$t1, 0
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _max
lw	$t1, _max
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp._1
label_1:
li	$t1, 1
bgtz	$t1, label_2
j		label_3
label_2:
lw	$t1, _x
li	$v0, 5
syscall
sw	$v0, _x
lw	$t1, _x
lw	$t2, _max
slt	$t0,$t2,$t1
sw	$t0, _temp._2
lw	$t1, _temp._2
bgtz	$t1, label_4
j		label_5
label_4:
lw	$t1, _x
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _max
lw	$t1, _max
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp._3
label_5:
lw	$t1, _x
li	$t2, 0
slt	$t3,$t1,$t2
slt	$t4,$t2,$t1
or	$t5,$t3,$t4
xori	$t0,$t5,1
sw	$t0, _temp._4
lw	$t1, _temp._4
bgtz	$t1, label_6
j		label_7
label_6:
j		label_3
label_7:
lw	$t1, _max
li	$v0, 1
move	$a0, $t1
syscall
j		label_1
label_3:
jr	$ra
