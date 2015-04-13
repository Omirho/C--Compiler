win_bison -d awry.y
win_flex awry.l
g++ -g awry.tab.c lex.yy.c -o awry
awry < test.txt > out.txt