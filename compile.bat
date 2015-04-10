bison -d awry.y
flex awry.l
g++ awry.tab.c lex.yy.c -o awry
awry < test.txt > out.dot
dot -Tjpg out.dot -o tree.jpg
.\tree.jpg