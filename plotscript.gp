set title "Heap Sort Algorithm -BORGES"
set xlabel "Input size (n)"
set ylabel "Number of Basic operations"
set grid

plot "heapBest.txt" with linespoints title "Best case",\
     "heapAvg.txt" with linespoints title "Average case",\
     "heapWorst.txt" with linespoints title "Worst case"