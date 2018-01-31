#!/bin/bash
gnuplot -e "set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 1.5;
set style line 2 lc rgb '#dd181f' lt 1 lw 2 pt 5 ps 1.5;
set style line 4 lt 2 lc rgb '#FF00FF' lw 2;
plot '~/input1.txt' with linespoints ls 1, '~/input2.txt' with linespoints ls 2, '~/input3.txt' with linespoints ls 4;
pause -1"
