reset

set terminal pngcairo size 1400,900 enhanced

set output "predsucc_comparison.png"



set title "Dictionary Predecessor/Successor Operation Comparison"


set xlabel "Input Size (n)"

set ylabel "Number of Operations"


set grid


set key outside right center



plot "predsucc.dat" using 1:2 with linespoints title "Unsorted Array", \
     "predsucc.dat" using 1:3 with linespoints title "Sorted Array", \
     "predsucc.dat" using 1:4 with linespoints title "Unsorted Singly List", \
     "predsucc.dat" using 1:5 with linespoints title "Sorted Singly List", \
     "predsucc.dat" using 1:6 with linespoints title "Unsorted Doubly List", \
     "predsucc.dat" using 1:7 with linespoints title "Sorted Doubly List"