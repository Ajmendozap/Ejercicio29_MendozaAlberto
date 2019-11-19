PuntoA.png : Ejercicio29.py data.dat
	python Ejercicio29.py

data.dat : Ejercicio29.x
	./Ejercicio29.x

Ejercicio29.x : Ejercicio29.cpp
	c++ Ejercicio29.cpp -o Ejercicio29.x

clean: 
	rm data.dat Ejercicio29.x Difusión.png 