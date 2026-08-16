set terminal pngcairo size 1200,800 enhanced

set output 'search_comparison.png'

set title 'Binary Search vs Ternary Search' font ',18'

set xlabel 'Number of Elements (n)' font ',14'
set ylabel 'Number of Comparisons' font ',14'

set grid

set key top left

set tics font ',11'

plot 'search_comparison.dat' using 1:2 \
    with linespoints \
    linewidth 3 \
    pointtype 7 \
    pointsize 1.3 \
    title 'Binary Search', \
\
     'search_comparison.dat' using 1:3 \
    with linespoints \
    linewidth 3 \
    pointtype 5 \
    pointsize 1.3 \
    title 'Ternary Search'