#!/bin/bash
gnuplot -e "set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 0.5;
set style line 2 lc rgb '#dd181f' lt 1 lw 2 pt 5 ps 0.5;
set style line 4 lt 2 lc rgb '#FF00FF' lw 2 ps 0.5;
set xlabel 'n (no. of elements)';
set ylabel 'running time (units)';
plot '~/Desktop/DAA/Divide and Conquer/best.txt' title 'Best' with linespoints ls 1, '~/Desktop/DAA/Divide and Conquer/worst.txt' title 'Worst' with linespoints ls 2, '~/Desktop/DAA/Divide and Conquer/average.txt' title 'Average' with linespoints ls 4;
pause -1"
