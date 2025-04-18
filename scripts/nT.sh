gcc -o ../main ../testes/testeAlgoritmos.c ../algoritmos/InsertionSort/InsertionSort.c ../algoritmos/MergeSort/MergeSort.c ../algoritmos/QuickSort/QuickSort.c ../algoritmos/SelectionSort/SelectionSort.c ../algoritmos/ShellSort/ShellSort.c ../utils/utils.c ../testes/testeUtils.c

for i in 1 10 100 1000 10000 100000 1000000;
do
    for k in 1 2 3 4 5 6 7 8 9
    do
        for j in 1 2 3
        do
            echo "$j $((i*k))" | ../main
            sleep .01
        done

        echo "4 $((i*k)) $((10 + RANDOM % 81))" | ../main
        sleep .01
    done
done

rm ../main