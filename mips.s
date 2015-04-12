.data
_temp._1:		.word 0
_temp._2:		.word 0
_temp._3:		.word 0
_temp._4:		.word 0
_temp._5:		.word 0
_temp._6:		.word 0
_temp._7:		.word 0
_x.2:		.word 0
_y.2:		.word 0
_z.2:		.word 0
.text
add:
lw	$t1, _x.2
lw	$t2, _y.2
add	$t0,$t1,$t2
sw	$t0, _temp._1
lw	$t1, _temp._1
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp._2
lw	$t1, _temp._2
move	$v0, $t1
jr	$ra
main:
li	$t1, 4
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp._3
li	$t1, 5
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp._4
lw	$t1, _temp._3
lw	$t2, _x.2
lw	$t8, _temp._3
sw	$t8, _x.2
lw	$t1, _temp._4
lw	$t2, _y.2
lw	$t8, _temp._4
sw	$t8, _y.2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp._5
lw	$t1, _temp._5
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _z.2
lw	$t1, _z.2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp._6
lw	$t1, _z.2
li	$t2, 0
add	$t0,$t1,$t2
sw	$t0, _temp._7
lw	$t1, _temp._7
li	$v0, 1
move	$a0, $t1
syscall
jr	$ra
