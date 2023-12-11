flags = -Wall -std=c++17 -I .
compile = g++ $(flags)
ExecutionTime : Davison_Andrew_QuickSort.cpp
	$(compile) Davison_Andrew_QuickSort.cpp && touch Davison_Andrew_executionTime.txt && chmod +x auto.sh && ./auto.sh

QuickSort : Davison_Andrew_QuickSort.cpp
	$(compile) Davison_Andrew_QuickSort.cpp && touch output.txt

InputFiles : Davison_Andrew_InputFileGenerator.cpp
	$(compile) Davison_Andrew_InputFileGenerator.cpp && ./a.out && rm a.out

clean:
	rm -f input* && rm -f output.txt && rm -f Davison_Andrew_executionTime.txt
