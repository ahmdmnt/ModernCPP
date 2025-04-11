# Modern C++ Notes
---


## 1. Static Keyword in Class or Struct
### 1.1. Static Member "Variable"
**One Variable across all instance:**
Static inside a class means only one instance of that Variable will be available across all class instances/objects
- Can be called directly through class name.
- If a class instance changes the value of that variable it will reflect in all other class instances.
- Better Practice: Refer for the static member through its Global Instance "Class Name".
- Variable Initialization is done outside class scope, only declaration is inside the scope. 

```cpp
    class myClass {
        static int number1;
        int number2;
    };
    int myClass::number1;       // Definition should be outside class scope

    int main() {
        myClass class1;

        myClass::number1 = 10;  // myClass::number1 == class1.number1
        class1.number2 = 20;
    }
```

### 1.2. Static Method "Function"
**Global Method Instance**
Can be called without creation of a class instance, just by using the class name.
- Can not use non-static members in static method.
- Better Practice: Refer for the static member through its Global Instance "Class Name".

```cpp
    class myClass {
        static int number1;
        int number2;

        static void print() {
            /* IMPORTANT: Can not use non-static variables here */
            std::cout<< number1 << std::endl;
        }
    };
    int myClass::number1= 100;
    
    int main() {
        myClass class1;
        
        myClass::print();   // myClass::print == class1.print
    }
```

