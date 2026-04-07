set title "Binary Search Algorithm Analysis"
set xlabel "Input size (n)"
set ylabel "Number of Basic operations"
set grid

plot "binarybest.txt" with linespoints title "Binary best",\
      "binaryavg.txt" with linespoints title "Binary average",\
      "binaryworst.txt" with linespoints title "Binary worst"