Andrew Davison CSCE 350 Final Project
This is a project, demonstrating the QuickSort algorithm, and its time complexity as it scales

Commands:
make InputFiles-
    this will generate 25 random input files, with different numbers 
    of floating point values (ex. 10, 100, 1000)
make-
    this will both compile and run the program using all of the generated 
    input files, and then will store execution times for each in executionTime.txt
make clean-
    this will remove the generated input files, and clean the output file.

./auto.sh <"input file name"> "output.txt" -
    this will output the sorted array from the selected input file, into output.txt,
    running this without parameters just does execution time
