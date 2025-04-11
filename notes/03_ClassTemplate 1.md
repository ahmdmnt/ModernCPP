# Modern C++ Notes
---

## Class Template
**Define a Generic Class that will be used with different Datatypes**
- minimize coding effort done by developer.
- according to usage of template function in code. Compiler will generate differet versions of functions.
- IMPORTANT: Class Template has also ... Special class template as function.
 

```cpp
    template<typename myType, int SIZE>     // SIZE SHOULD BE CONSTANT VALUE , BECUZ TEMPLATE IS GENERATED IN COMPILE-TIME
    struct myQueue {
        myType qArray[SIZE];
        int qPosition;

        myQueue() {
            qPosition = 0;
        }

        myQueue(myType l_arr[], int& len) {
            for(int itr=0; itr<len; itr++) {
                qArray[itr] = l_arr[itr];
            }
            qPosition = len;
        }

        void addElement(myType l_element) {
            qArray[qPosition++] = l_element;
        }

        template<typename otherType>
        void sumAddElement(myType l_element1, otherType l_element2) {
            qArray[qPosition++] = l_element1 + l_element2;
        }

        void printQueue() {
            for(int itr=0; itr<qPosition; itr++) {
                std::cout << qArray[itr] <<" ";
            }
            std::cout << std::endl;
        }
    };

    int main () {
        myQueue<int, 10> intQueue;
        intQueue.addElement(10);
        intQueue.addElement(20);
        intQueue.addElement(30);
        intQueue.addElement(40);
        intQueue.sumAddElement<double>(40, 10.5);
        intQueue.printQueue();

        return 0;
    }
```

