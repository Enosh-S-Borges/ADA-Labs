set title "Merge Sort Algorithm Analysis -BORGES"
set xlabel "Input size (n)"
set ylabel "Number of Basic operations"
set grid

plot "Mergebest.txt" with linespoints title "Best case",\
     "Mergeavg.txt" with linespoints title "Average case",\
     "Mergeworst.txt" with linespoints title "Worst case"