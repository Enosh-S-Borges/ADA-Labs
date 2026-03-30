set title "Modified Euclid's Algorithm Analysis"
set xlabel "Input size (n)"
set ylabel "Number of Basic operations"
set grid

plot "modifiedBest.txt" with linespoints title "Modified Best",\
      "modifiedWorst.txt" with linespoints title "Modified Worst"