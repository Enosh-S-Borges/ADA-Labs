set title "Brute Force string matching Algorithm Analysis -BORGES"
set xlabel "Input size (n)"
set ylabel "Number of Basic operations"
set grid

plot "strbest.txt" with linespoints title "Best case",\
     "stravg.txt" with linespoints title "Average case",\
     "strworst.txt" with linespoints title "Worst case"