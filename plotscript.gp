set title "Dijkstra's Algorithm -BORGES"
set xlabel "Input size (n)"
set ylabel "Number of Basic operations"
set grid

plot "dikstras.txt" with linespoints title "Average case",\
#     "warshallworst.txt" with linespoints title "Worst case",\
#     "warshallavg.txt" with linespoints title "Average case",\