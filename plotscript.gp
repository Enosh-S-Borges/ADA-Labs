set title "Comparison of DFS and BFS Algorithm -BORGES"
set xlabel "Input size (n)"
set ylabel "Number of Basic operations"
set grid

plot "bfsadjMat.txt" with linespoints title "BFS algorithm",\
     "dfsadjMat.txt" with linespoints title "DFS algorithm",\
#     "Quickworst.txt" with linespoints title "Worst case"