bison -d awry.y
flex awry.l
g++ -g awry.tab.c lex.yy.c -o awry
awry < test.txt > out.txt