# Modern C++ Notes
---

## Function Overloading
**Define Functions with same name with different input parameters**
- return type is not traced in function overloading.
- each function of them have a unique identifier based on funName_inputParameters
- according to function call. Compiler will decide which function will use.
 
```cpp
    int max(int n1, int n2) {
        if( n1>n2 )
            return n1;
        return n2;
    }
    float max(float n1, float n2) {
        if( n1>n2 )
            return n1;
        return n2;
    }
    double max(double n1, double n2) {
        if( n1>n2 )
            return n1;
        return n2;
    }

    int main() {
        max(1, 2);          
        max(1.1f, 2.2f);
        max(1.1, 2.2);
        return 0;
    }
```

---


## Function Template
**Define a Generic Function that will be used with different Datatypes**
- minimize coding effort done by developer.
- according to usage of template function in code. Compiler will generate differet versions of functions.
- try to avoid C++ defined template function ex. max()
 
```cpp
    template<typename myType>
    myType myMax(myType n1, myType n2) {
        if ( n1>n2 ) 
            return n1;
        return n2;
    }

    int main() {
        myMax(1, 2);              // auto-deduced  
        myMax('A', 'B');   
        myMax<float>(1.1, 2.2);   //explicit 

        // myMax(1, 2.5);         // Compiler Error
        myMax<int>(1, 2.5);       // 2.5 will be casted
        return 0;
    }
```

- either use "typename" or "class" ... doesnt matter.
```cpp
    template<class myType1, class myType2>
    myType1 mySum(myType1 n1, myType2 n2) {
        myType1 result = n1 + n2;
        std::cout<< result << std::endl;
        return result;
    }

    int main() {
        mySum(1, 2);
        mySum<float, float>(1.1, 2.2);
        mySum(1.5, 2);
        mySum(1.5, 'A');
        mySum(std::string("Hello "), std::string("World!"));
        return 0;
    }
```

- IMPORTANT: Static Variables in Template Function .. Each Generated Function will have its static Variable.
```cpp
    int globalVariable;

    template<class myType>
    void myIncrement(myType n1) {
        static int staticVariable
        std::cout<< staticVariable++ << " - " << globalVariable++ << std::endl;
    }

    int main() {
        myIncrement(5);         // 1 - 1
        myIncrement(5);         // 2 - 2
        myIncrement(5);         // 3 - 3

        myIncrement(5.1);       // 1 - 4
        myIncrement(5.1);       // 2 - 5
        myIncrement(5.1);       // 3 - 6
        return 0;
    }
```
- Template Function Specialization
Special handling for specific function Parameters
```cpp
    template<class myType>
    void myIncrement(myType var) {
        std::cout<< var++ << std::endl;
    }

    template<>          // Template Function Specialization
    void myIncrement(std::string var) {
        for( auto letter: var) {
            std::cout<< letter++ << std::endl;
        }
    }

    int main() {
        myIncrement(5);
        myIncrement(std::string("ABCD"));
        return 0;
    }
```
