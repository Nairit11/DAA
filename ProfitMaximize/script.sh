#!/bin/bash
gnuplot -e "set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 0.5;
set style line 2 lc rgb '#dd181f' lt 1 lw 2 pt 5 ps 0.5;
set style line 4 lt 2 lc rgb '#FF00FF' lw 2 ps 0.5;
set xlabel 'no. of producers';
set ylabel 'Running Time';
plot '~/Desktop/DAA/ProfitMaximize/output.txt' title 'Running Time' with linespoints ls 1;
pause -1"
