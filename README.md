# Tarea 1 CC7515
## Estructura
```
├── CMakeLists.txt
├── README.md <- ESTE ARCHIVO
└── T1
    ├── example.cpp
    ├── src
    │   ├── make_unique.h
    │   ├── Matrix.cpp
    │   └── Matrix.h
    └── test
        ├── Matrix_test.cpp
        └── tests.cpp
```
## Implementación
### Matrix.cpp
### make_unique.h
Para implementar make_unique en C11 se crea este header basado en las siguientes fuentes:
* https://stackoverflow.com/q/17902405 "How to implement make_unique function in C++11"
* https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique "std::make_unique"
* https://github.com/llvm/llvm-project/blob/main/libcxx/include/memory Implementación de unique_ptr

### Test
Se utilizó google test para probar cada función.
Referencias:
* https://github.com/google/googletest/tree/main/googletest
* https://google.github.io/googletest/primer.html

### Como compilar example.cpp
```g++ -std=c++11 T1/example.cpp T1/src/Matrix.cpp -o T1/main.bin```

## Preguntas
Preguntas 
### ¿Afectaría en algo el tipo de dato de su matriz?

Si, por ejemplo, si se usa int en lugar de double se evita representar fracciones o valores decimales, 
lo cual afectaría operaciones como divisiones o promedios, y además truncaría resultados. 

### ¿Qué pasa si se usan números muy grandes, pequeños o primos?

Si se usan números muy grandes, con double pueden provocar overflow. Muy pequeños pueden resultar en ceros. 
Si se usan primos y operaciones de punto flotante, existe una pérdida de precisión asociada a la comparación y/o 
acumulación de errores en operaciones sucesivas.

### ¿Pueden haber problemas de precisión si se comparan dos matrices con diferente tipo?

Sí, porque al comparar una Matriz con valores float y otra con double puede generar errores por diferencias en la  
representación binaria. Además, el operador == comparará valor a valor exacto, lo que puede fallar si los tipos no coinciden.