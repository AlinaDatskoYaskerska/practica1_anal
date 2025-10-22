#-----------------------
# IMPORTANTE: The values of the parameters for exercise?_test have to be conveniently adjusted.
# It is assumed that the name of the source files is exercise1.c, exercise2.c,...,exercise.h
#-----------------------

CC = gcc -ansi -pedantic
CFLAGS = -Wall
EXE = exercise1 exercise2 exercise3 exercise4 exercise5_insert exercise5_bubble exercise5_insert_mejor_caso exercise5_bubble_mejor_caso exercise5_insert_peor_caso exercise5_bubble_peor_caso

all : $(EXE)

.PHONY : clean
clean :
	rm -f *.o core $(EXE)

exercise5_insert exercise5_bubble : % : %.o sorting.o times.o permutations.o
	$(CC) $(CFLAGS) -o $@ $@.o sorting.o times.o permutations.o

exercise5_insert_mejor_caso exercise5_bubble_mejor_caso : % : %.o sorting.o times_mejor_caso.o permutations.o
	$(CC) $(CFLAGS) -o $@ $@.o sorting.o times_mejor_caso.o permutations.o

exercise5_insert_peor_caso exercise5_bubble_peor_caso : % : %.o sorting.o times_peor_caso.o permutations.o
	$(CC) $(CFLAGS) -o $@ $@.o sorting.o times_peor_caso.o permutations.o

exercise1 exercise2 exercise3 exercise4 : % : %.o sorting.o times.o permutations.o
	$(CC) $(CFLAGS) -o $@ $@.o sorting.o times.o permutations.o

permutations.o : permutations.c permutations.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

sorting.o : sorting.c sorting.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

times.o : times.c times.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

times_mejor_caso.o : times_mejor_caso.c times.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

times_peor_caso.o : times_peor_caso.c times.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<
	
exercise1_test:
	@echo Running exercise1
	@./exercise1 -limInf 1 -limSup 100 -numN 100000 

exercise1_test_plot:
	@echo Running exercise1
	@./exercise1 -limInf 1 -limSup 100 -numN 100000000 | sort | uniq -c > resultados.dat
	@echo "Graficando resultados con gnuplot"
	@gnuplot -persist -e "set title 'Frecuencia de números'; \
		set xlabel 'Número'; \
		set ylabel 'Frecuencia'; \
		plot 'resultados.dat' using 2:1 with impulses title ''"

exercise2_test:
	@echo Running exercise2
	@./exercise2 -size 5 -numP 100

exercise3_test:
	@echo Running exercise3
	@./exercise3 -size 5 -numP 100

exercise4_test:
	@echo Running exercise4
	@./exercise4 -size 100

exercise5_test_insert_mejor_caso:
	@echo Running exercise5 using Insert Sort
	@./exercise5_insert_mejor_caso -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_insert.log

exercise5_test_bubble_mejor_caso:
	@echo Running exercise5 using Bubble Sort
	@./exercise5_bubble_mejor_caso -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_bubble.log

exercise5_test_insert_peor_caso:
	@echo Running exercise5 using Insert Sort
	@./exercise5_insert_peor_caso -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_insert.log

exercise5_test_bubble_peor_caso:
	@echo Running exercise5 using Bubble Sort
	@./exercise5_bubble_peor_caso -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_bubble.log

exercise5_test_insert:
	@echo Running exercise5 using Insert Sort
	@./exercise5_insert -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_insert.log

exercise5_test_bubble:
	@echo Running exercise5 using Bubble Sort
	@./exercise5_bubble -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_bubble.log

exercise5_test_insert_plot_ob:
	@echo Graficando tiempos mejor, peor y medio en OBs del Insert Sort
	@./exercise5_insert -num_min 100 -num_max 1500 -incr 10 -numP 1000 -outputFile exercise5_insert.log
	@gnuplot -persist -e "set title 'Comparación de mejor, peor y media OBs (Insert Sort)'; \
		set xlabel 'Tamaño de N'; \
		set ylabel 'Cantidad de OBs'; \
		plot 'exercise5_insert.log' u 1:3 w lines title 'Caso medio', \
		     'exercise5_insert.log' u 1:4 w lines title 'Peor caso', \
		     'exercise5_insert.log' u 1:5 w lines title 'Mejor caso'"

exercise5_test_insert_plot_time:
	@echo Graficando tiempo de ejecución del Insert Sort
	@./exercise5_insert -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_insert.log
	@gnuplot -persist -e "set title 'Tiempo de ejecución del Insert Sort'; \
		set xlabel 'Tamaño de N'; \
		set ylabel 'Tiempo de ejecución (s)'; \
		plot 'exercise5_insert.log' u 1:2 w lines title 'Tiempo'"

exercise5_test_bubble_plot_ob:
	@echo Graficando tiempos mejor, peor y medio en OBs del Bubble Sort
	@./exercise5_bubble -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_bubble.log
	@gnuplot -persist -e "set title 'Comparación de mejor, peor y media OBs (Bubble Sort)'; \
		set xlabel 'Tamaño de N'; \
		set ylabel 'Cantidad de OBs'; \
		plot 'exercise5_bubble.log' u 1:3 w lines title 'Caso medio', \
		     'exercise5_bubble.log' u 1:4 w lines title 'Peor caso', \
		     'exercise5_bubble.log' u 1:5 w lines title 'Mejor caso'"

exercise5_test_bubble_plot_time:
	@echo Graficando tiempo de ejecución del Bubble Sort
	@./exercise5_bubble -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_bubble.log
	@gnuplot -persist -e "set title 'Tiempo de ejecución del Bubble Sort'; \
		set xlabel 'Tamaño de N'; \
		set ylabel 'Tiempo de ejecución (s)'; \
		plot 'exercise5_bubble.log' u 1:2 w lines title 'Tiempo'"

exercise5_test_comparacion_ob:
	@echo Comparando el tiempo medio de OBs para InsertSort y BubbleSort
	@./exercise5_insert -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_insert.log
	@./exercise5_bubble -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_bubble.log
	@gnuplot -persist -e "set title 'Comparación de media de OBs para Insert Sort y Bubble Sort'; \
		set xlabel 'Tamaño de N'; \
		set ylabel 'Cantidad de OBs'; \
		plot 'exercise5_insert.log' u 1:3 w lines title 'Media del Insert Sort', \
			 'exercise5_bubble.log' u 1:3 w lines title 'Media del Bubble Sort'"

exercise5_test_comparacion_time_medio:
	@echo Comparando el tiempo de ejecución para InsertSort y BubbleSort
	@./exercise5_insert -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_insert.log
	@./exercise5_bubble -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_bubble.log
	@gnuplot -persist -e "set title 'Comparación del tiempo de ejecución del Insert Sort y Bubble Sort'; \
		set xlabel 'Tamaño de N'; \
		set ylabel 'Tiempo (s)'; \
		plot 'exercise5_insert.log' u 1:2 w lines title 'Tiempo del Insert Sort', \
			 'exercise5_bubble.log' u 1:2 w lines title 'Tiempo del Bubble Sort'"

exercise5_test_comparacion_time_peor:
	@echo Comparando el tiempo de ejecución para InsertSort y BubbleSort
	@./exercise5_insert_peor_caso -num_min 1 -num_max 400 -incr 5 -numP 100 -outputFile exercise5_insert.log
	@./exercise5_bubble_peor_caso -num_min 1 -num_max 400 -incr 5 -numP 100 -outputFile exercise5_bubble.log
	@gnuplot -persist -e "set title 'Comparación del tiempo peor de ejecución del Insert Sort y Bubble Sort'; \
		set xlabel 'Tamaño de N'; \
		set ylabel 'Tiempo (s)'; \
		plot 'exercise5_insert.log' u 1:2 w lines title 'Tiempo del Insert Sort', \
			 'exercise5_bubble.log' u 1:2 w lines title 'Tiempo del Bubble Sort'"

exercise5_test_comparacion_time_mejor:
	@echo Comparando el tiempo de ejecución para InsertSort y BubbleSort
	@./exercise5_insert_mejor_caso -num_min 1 -num_max 8000 -incr 12 -numP 500 -outputFile exercise5_insert.log
	@./exercise5_bubble_mejor_caso -num_min 1 -num_max 8000 -incr 12 -numP 500 -outputFile exercise5_bubble.log
	@gnuplot -persist -e "set title 'Comparación del tiempo mejor de ejecución del Insert Sort y Bubble Sort'; \
		set xlabel 'Tamaño de N'; \
		set ylabel 'Tiempo (s)'; \
		plot 'exercise5_insert.log' u 1:2 w lines title 'Tiempo del Insert Sort', \
			 'exercise5_bubble.log' u 1:2 w lines title 'Tiempo del Bubble Sort'"

exercise5_test_insert_plot_fit_time:
	@echo "Graficando tiempo de ejecución del Insert Sort y ajustando a función cuadrática"
	@./exercise5_insert -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_insert.log
	@gnuplot -persist -e "set title 'Ajuste cuadrático del tiempo de ejecución (Insert Sort)'; \
		set xlabel 'Tamaño de N'; \
		set ylabel 'Tiempo (s)'; \
		f(x) = a*x**2 + b*x + c; \
		fit f(x) 'exercise5_insert.log' using 1:2 via a,b,c; \
		plot 'exercise5_insert.log' using 1:2 with lines title 'Datos experimentales', \
		     f(x) with lines title sprintf('Ajuste cuadrático: y = %.2e*x^2 + %.2e*x + %.2e', a, b, c)"

exercise5_test_insert_plot_fit_ob:
	@echo "Graficando y ajustando la media de OBs del Insert Sort a una función cuadrática"
	@./exercise5_insert -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_insert.log
	@gnuplot -persist -e "set title 'Ajuste cuadrático de la media de OBs (Insert Sort)'; \
		set xlabel 'Tamaño de N'; \
		set ylabel 'Operaciones básicas (media)'; \
		f(x) = a*x**2 + b*x + c; \
		fit f(x) 'exercise5_insert.log' using 1:3 via a,b,c; \
		plot 'exercise5_insert.log' using 1:3 with lines title 'Datos experimentales', \
		     f(x) with lines title sprintf('Ajuste cuadrático: y = %.2e*x^2 + %.2e*x + %.2e', a, b, c)"

exercise5_test_bubble_plot_fit_time:
	@echo "Graficando tiempo de ejecución del Bubble Sort y ajustando a función cuadrática"
	@./exercise5_bubble -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_bubble.log
	@gnuplot -persist -e "set title 'Ajuste cuadrático del tiempo de ejecución (Bubble Sort)'; \
		set xlabel 'Tamaño de N'; \
		set ylabel 'Tiempo (s)'; \
		f(x) = a*x**2 + b*x + c; \
		fit f(x) 'exercise5_bubble.log' using 1:2 via a,b,c; \
		plot 'exercise5_bubble.log' using 1:2 with lines title 'Datos experimentales', \
		     f(x) with lines title sprintf('Ajuste cuadrático: y = %.2e*x^2 + %.2e*x + %.2e', a, b, c)"

exercise5_test_bubble_plot_fit_ob:
	@echo "Graficando y ajustando la media de OBs del Bubble Sort a una función cuadrática"
	@./exercise5_bubble -num_min 100 -num_max 1500 -incr 10 -numP 100 -outputFile exercise5_bubble.log
	@gnuplot -persist -e "set title 'Ajuste cuadrático de la media de OBs (Bubble Sort)'; \
		set xlabel 'Tamaño de N'; \
		set ylabel 'Operaciones básicas (media)'; \
		f(x) = a*x**2 + b*x + c; \
		fit f(x) 'exercise5_bubble.log' using 1:3 via a,b,c; \
		plot 'exercise5_bubble.log' using 1:3 with lines title 'Datos experimentales', \
		     f(x) with lines title sprintf('Ajuste cuadrático: y = %.2e*x^2 + %.2e*x + %.2e', a, b, c)"


runv:
	@echo ">>>>>> Running exercise1 with Valgrind"
	valgrind --leak-check=full ./exercise1 -limInf 1 -limSup 100 -numN 100
	@echo ">>>>>> Running exercise2 with Valgrind"
	valgrind --leak-check=full --track-origins=yes ./exercise2 -size 5 -numP 10
	@echo ">>>>>> Running exercise3 with Valgrind"
	valgrind --leak-check=full ./exercise3 -size 5 -numP 10
	@echo ">>>>>> Running exercise4 with Valgrind"
	valgrind --leak-check=full ./exercise4 -size 100
	@echo ">>>>>> Running exercise5_insert with Valgrind"
	valgrind --leak-check=full ./exercise5_insert -num_min 100 -num_max 500 -incr 50 -numP 10 -outputFile exercise5_insert.log
	@echo ">>>>>> Running exercise5_bubble with Valgrind"
	valgrind --leak-check=full ./exercise5_bubble -num_min 100 -num_max 500 -incr 50 -numP 10 -outputFile exercise5_bubble.log


