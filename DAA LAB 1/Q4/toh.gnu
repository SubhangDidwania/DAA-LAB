set title "Tower of Hanoi - Number of Moves"

set xlabel "Number of Disks"

set ylabel "Moves"

plot "toh.dat" using 1:2 with linespoints title "2^n - 1"
