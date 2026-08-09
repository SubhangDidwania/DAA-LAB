reset

set terminal pngcairo size 1400,900 enhanced

set output "search_comparison.png"


set title "Dictionary Search Operation Comparison"

set xlabel "Input Size (n)"

set ylabel "Number of Comparisons"


set grid

set key outside right center



plot "search.dat" using 1:2 with linespoints title "Unsorted Array", \
     "search.dat" using 1:3 with linespoints title "Sorted Array", \
     "search.dat" using 1:4 with linespoints title "Unsorted Singly List", \
     "search.dat" using 1:5 with linespoints title "Sorted Singly List", \
     "search.dat" using 1:6 with linespoints title "Unsorted Doubly List", \
     "search.dat" using 1:7 with linespoints title "Sorted Doubly List"