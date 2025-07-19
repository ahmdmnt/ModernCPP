/*
 * _02_MemoryManagement_Part01.cpp
 *
 *  Created on: Apr 7, 2025
 *      Author: AhmedMontasser
 */

/*
 * Module Description:
 *	1. Dynamic Memory Allocation in C Language.
 *		> malloc(), calloc(), realloc(), free().
 *		> 1D Arrays.
 *	2. Dynamic Memory Allocation in C++ Language.
 *		> new, delete
 *		> 1D Arrays.
 *		> 2D Arrays.
 */

#include <iostream>


void _02_MemoryManagement_Part01() {

	/* Memory Area Types:-
	 * --------------------
	 * C and C++ programs provide dynamic memory allocation in runtime.
	 * All memory is taken from the reserved process address space.
	 *  1. Stack: Allocated for Function context switching and Local variables allocation.
	 *  2.  Data: Allocated for Global variables.
	 *  3.  Heap: Allocated for runtime variables (Dynamic Memory Allocations).
	 * Any Memory allocated in Heap have to be managed by the developer (allocation and deallocation).
	 */

	/* Dynamic Memory Allocation in C:-
	 * ------------------------------------
	 *  -  malloc(): Allocate RAW Memory in Heap.
	 *  -  calloc(): Allocate RAW Memory in Heap and init it with zeros.
	 *  - realloc(): Allocate larger chunk of Memory for an existing allocation.
	 *  -    free(): Deallocate and release allocated Memory area.
	 */
	int *ptrData1 = (int*)malloc(sizeof(int));		// C++ MANDATORY to cast the malloc output before saving it in, non-void pointer.
	int *ptrData2 = (int*)calloc(1, sizeof(int));	// calloc(NumberofElement, sizeof(Element))
	int *ptrArr1 = (int*)malloc(3*sizeof(int));		// Array of 3 Elements
	int *ptrArr2 = (int*)calloc(3, sizeof(int));	// Array of 3 Element
	/* If malloc(), calloc(), realloc(), failed to allocate the memory,
	 * Null will be returned in pointer value
	 */
	if(ptrData1!=NULL) {
		*ptrData1 = 123;
		std::cout << "*ptrData1 = " << *ptrData1 << std::endl;
	}
	else
		std::cout<< "Failed to allocated Memory in Heap." << std::endl;
	/*****************************************************************/
	if(ptrData2!=NULL) {
		*ptrData2 = 456;
		std::cout << "*ptrData2 = " << *ptrData2 << std::endl;
	}
	else
		std::cout<< "Failed to allocated Memory in Heap." << std::endl;
	/*****************************************************************/
	if(ptrArr1!=NULL) {
		ptrArr1[0] = 789;
		std::cout << "ptrArr1[0] = " << ptrArr1[0] << std::endl;
	}
	else
		std::cout<< "Failed to allocated Memory in Heap." << std::endl;
	/*****************************************************************/
	if(ptrArr2!=NULL) {
		ptrArr2[1] = 101112;
		std::cout << "ptrArr2[1] = " << ptrArr2[1] << std::endl;
	}
	else
		std::cout<< "Failed to allocated Memory in Heap." << std::endl;
	/*****************************************************************/
	/* Deallocating Runtime Data:
	 * ---------------------------
	 * 	1. free the Pointer:
	 * 		> Data is lost Memory used is release, but still the ptr variable has memory address.
	 * 		What if I free the Memory without removing pointer value?
	 * 			- Dangling Pointer Issue occurs; pointer points and may access invalid address.
	 * 	2. Remove Address from Pointer Variable.
	 * 		> Set Pointer Variable with Null Ptr.
	 * 		What if I Remove Pointer Data before free()?
	 * 			- Memory leak Issue occurs; Memory is reserved for data that no longer reachable.
	 */
	free(ptrData1);
	free(ptrData2);
	free(ptrArr1);
	free(ptrArr2);
	ptrData1 = NULL;
	ptrData2 = NULL;
	ptrArr1  = NULL;
	ptrArr2  = NULL;
	/*END OF DYNAMIC MEMORY ALLOCATION IN C **************************************************************************************/



	/* Dynamic Memory Allocation in C++:-
	 * ------------------------------------
	 * C++ provides two keywords for Memory Allocation
	 * 	-    new: allocate the memory in Heap, and capable of initialization
	 * 			> If new fails to allocate, it will through an Exception (TBD Later).
	 * 	- delete: deallocate the memory from Heap.
	 * 			> Remove Address from Pointer Variable.
	 *	Memory allocated with "new", shall be deleted with "delete"
	 * [SYNTAX]:
	 * 	variableType *variableName = new variableType(OPTIONAL ARGUMENTS)
	 * --------------------------------------------------------------------
	 * Difference between new and malloc()?
	 * ------------------------------------
	 * new								vs				malloc()
	 * - C++ Operator									- C Function
	 * - Size is defined from type.						- Require to pass the size during allocation.
	 * - Return correct type of pointer.				- Return void pointer, that needs to be casted.
	 * - Can initialize memory.							- Can not initialize the memory.
	 * - Can Create Object.								- Can not create Object.
	 * - So, it can call Constructor.					- Because, it can not call constructor.
	 * - Can be customized though overloading.			- Can not be customized.
	 * - One Operator with diferrent features.			- Different Functions, malloc, calloc, and realloc.
	 * - Allocation fails: Through Exception.			- Allocation fails: Return NULL pointer.
	 */
	int *pData1 {new int};
	*pData1 = 10;
	std::cout << "*pData1 = " << *pData1 << std::endl;
	delete pData1;
	pData1 = nullptr;

	pData1 = new int(12345);		// Initialize in variable declaration
	std::cout << "*pData1 = " << *pData1 << std::endl;
	delete pData1;
	pData1 = nullptr;

	/* Dynamic Memory Allocation for Arrays:
	 * -------------------------------------
	 * [SYNTAX]:
	 * 		variableType *variableName {new variableType[SIZE]}
	 * 		delete []variableName
	 */
	int *pAr {new int[4]{1, 2, 3, 4}};		// Create Array Memory and Initialize
	std::cout << "pAr  = " << pAr[0] << " - " << pAr[1] << " - " << pAr[2] << " - " << pAr[3] << std::endl;
	delete []pAr;				// delete Array Memory ,,, delete pArr; may delete only first element instead of whole array.
	pAr = nullptr;

	int *pArr {new int[4]};				// Create Array Memory
	pArr[0] = 0; pArr[1] = 10;
	pArr[2] = 20;pArr[3] = 30;
	std::cout << "pArr = " << pArr[0] << " - " << pArr[1] << " - " << pArr[2] << " - " << pArr[3] << std::endl;
	delete []pArr;
	pArr = nullptr;

	/* Dynamic Memory Allocation for 2D Arrays:
	 * -----------------------------------------
	 * Normal 2D array in Stack is actually one contiguous chunck of data "like 1D array"
	 * but Compiler give the ability to access it in 2D form, row and columns.
	 *
	 * But in Heap it is different
	 */
	int *pA0 {new int[3]{0, 0, 0}};			// Create  First Array.
	int *pA1 {new int[3]{0, 0, 0}};			// Create Second Array.

	int **p2A {new int *[2]{pA0, pA1}};		// Create Array of Pointers with 2 Elements.

	pA0[1] = 10;
	pA1[1] = 100;
	std::cout << "p2A[0][1] = " << p2A[0][1] << " - p2A[1][1]= " << p2A[1][1] << std::endl;

	/* BE CAUTIOUS WHEN DELETE:-
	 * 	1. Delete with SAME order of "new".
	 * 	2. Number of delete lines MUST match number of new lines. */
	delete []pA0;	// delete []p2A[0]
	delete []pA1;	// delete []p2A[1]

	delete []p2A;	// Array of Pointers

	/* HINT [IMPORTANT]:
	 * If the Pointer to Data is freed by end of function context, no need to remove pointer address after free() or delete.
	 * BECAUSE, anyways the pointer variable will be destroyed automatically. */
	/*END OF DYNAMIC MEMORY ALLOCATION IN C++ ************************************************************************************/
}
