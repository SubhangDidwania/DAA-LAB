reset

set terminal pngcairo size 1400,900 enhanced

set output "merge_comparison.png"


set title "Normal Merge Sort vs Three Way Merge Sort" font ",16"

set xlabel "Input Size (n)" font ",12"

set ylabel "Number of Comparisons" font ",12"


set grid

set key outside right center



plot "merge.dat" using 1:2 with linespoints title "Normal Merge Sort", \
     "merge.dat" using 1:3 with linespoints title "Three Way Merge Sort"