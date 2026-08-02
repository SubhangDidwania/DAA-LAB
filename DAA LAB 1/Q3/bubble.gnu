set title "Bubble Sort Comparison Count"

set xlabel "Array Size (n)"

set ylabel "Number of Comparisons"


plot "bubble.dat" using 1:2 with lines title "Optimized Bubble Sort",\
"bubble.dat" using 1:3 with lines title "Normal Bubble Sort"