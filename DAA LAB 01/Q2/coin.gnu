set title "Fair vs Biased Coin Simulation"

set xlabel "Number of Tosses"

set ylabel "Probability of Head"

set yrange [0:1]


plot "coin.dat" using 1:2 with lines title "Fair Coin",\
"coin.dat" using 1:3 with lines title "Biased Coin (0.7)"