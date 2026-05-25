set title "Comparison of DFS and Source Removal Topological Sort Algorithm -BORGES"
set xlabel "Input size (n)"
set ylabel "Number of Basic operations"
set grid

plot "bfsMatTopSort.txt" with linespoints title "DFS algorithm",\
     "srcrmMatTopSort.txt" with linespoints title "Source Removal algorithm",\
#     "Quickworst.txt" with linespoints title "Worst case"