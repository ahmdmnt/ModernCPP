# Modern C++ Notes
---

## 1. Union 
### 1.1. Union Datatype

## 2. Struct 
### 2.1. Struct Datatype

## 3. Class 
### 3.1. Class Datatype

## 4. Enum 
### 4.1. Enum Datatype
### 4.2. Class Enum Datatype


## 1. Enum 
### 1.1. Enum Datatype
**A way to name set of Values and group them together**
- size = int .. can be changed with other integer datatypes.
- Normally values starts from 0 if not defined explicity.
- You can specify each value explicitly, or only define the 1st Value and the rest will be incremented by 1.
 
```cpp
    enum myEnum : unsigned char
    {
        A,  //= 0
        B,  //= 1
        C   //= 2
    };

    int main() {
        myEnum enum1 = A;

        std::cout<< enum1 << std::endl;
    }
```
### 1.2. Class Enum Datatype
**A way to name set of Values and group them together**
- size = int .. can be changed with other integer datatypes.
- Normally values starts from 0 if not defined explicity.
- You can specify each value explicitly, or only define the 1st Value and the rest will be incremented by 1.
 
```cpp
    enum myEnum : unsigned char
    {
        A,  //= 0
        B,  //= 1
        C   //= 2
    };

    int main() {
        myEnum enum1 = A;

        std::cout<< enum1 << std::endl;
    }
```
