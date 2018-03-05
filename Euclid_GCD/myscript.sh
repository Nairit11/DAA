#!/bin/bash
gnuplot -e "set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 0.5;
set style line 2 lc rgb '#dd181f' lt 1 lw 2 pt 5 ps 0.5;
set style line 4 lt 2 lc rgb '#FF00FF' lw 2 ps 0.5;
set xlabel 'n';
set ylabel 'running time (units)';
plot '~/Desktop/DAA/Euclid_GCD/output.txt' title 'Running time' with linespoints ls 1;
pause -1"
