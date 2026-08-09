reset

set terminal pngcairo size 1400,900 enhanced

set output "merge_k_comparison.png"


set title "Sequential Merge vs Pairwise Merge" font ",16"


set xlabel "Number of Sorted Arrays (k) (logscale)" font ",12"

set ylabel "Number of Comparisons" font ",12"


set grid


set logscale x


set key outside right center



plot "merge_k.dat" using 1:2 with linespoints title "Method 1: Sequential Merge", \
     "merge_k.dat" using 1:3 with linespoints title "Method 2: Pairwise Merge"