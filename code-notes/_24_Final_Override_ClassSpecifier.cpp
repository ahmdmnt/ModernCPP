/*
 * _24_Final_Override_ClassSpecifier.cpp
 *
 *  Created on: May 12, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

/* Module Description:-
 * ---------------------
 * 	1. Keyword: final Specifier.
 * 	2. Keyword: final Specifier.
 *
 */

/* If i intended to create class that will not be inherited by other classes.
 * No Virtual functions is available, and no virtual destructor is created.
 * THEN: i need to protect this class from being wrongly inherited and cause memory leaks.
 *
 * SOLUTION: Keyword: [final]
 * ---------------------------
 * PREVENT CLASS FROM BEING INHERITED.
 */
class zip final {
public:
	zip() {}
	void compress(const std::string& filename) {}
	void decompress(const std::string& filename) {}
	void printStatistics() {}
	~zip();
};
//class fastZip : public zip {};		// ERROR: cannot derive from 'final' base 'zip' in derived type 'fastZip'


/* If i intended to create class that will be inherited by other classes.
 * which contains, method(s) that should be specifically implemented at each child.
 * Here Errors can happen if for example ...
 * 	> Parent Function to be overridden named: Foo(int num);
 * 	>> Child Function that overrides. named: Foo(float num);	..
 * 	this is not overriding parent function, instead it is new, and compiler won't sense this.
 *
 * SOLUTION: Keyword: [override]
 * ---------------------------
 * by typing override keyword, beside Child Method declaration
 * MAKE SURE THAT, the intention of impl. this function is overriding a parent function.
 */
class document {
public:
	document() {}
	virtual void serialize(float version) {
		std::cout << "document::serialize(float version) " << std::endl;
	}
	virtual void deserialize(float version) {
		std::cout << "document::deserialize(float version) " << std::endl;
	}
	virtual ~document() {};
};

/* Mixing between override and final: in Line #70, the override function is marked with final, so any child to below class, willnot be able to override this function
 */
class text: public document {
public:
	//	void serialize(int version) override {		// ERROR: 'void text::serialize(int)' marked 'override', but does not override "Compiler tells me".
	void serialize(float version) override {
		std::cout << "text::serialize(float version) " << std::endl;
	}
	void deserialize(float version) override final {
		std::cout << "text::deserialize(float version) " << std::endl;
	}
};

class richText: public text {
public:
	//	void serialize(int version) override {		// ERROR: 'void text::serialize(int)' marked 'override', but does not override "Compiler tells me".
	void serialize(float version) override {
		std::cout << "richText::serialize(float version) " << std::endl;
	}
	//	void deserialize(float version) override {}		// ERROR: : virtual function 'virtual void richText::deserialize(float)' overriding final function
};



void _24_Final_Override_ClassSpecifier(void) {
	text txt;
	document &refDoc_1 = txt;

	txt.serialize(1.2f);
	refDoc_1.serialize(1.2f);
	refDoc_1.deserialize(1.2f);


	richText rTxt;
	document &refDoc_2 = rTxt;
	text     &refTxt   = rTxt;

	rTxt.serialize(1.2f);
	refTxt.serialize(1.2f);
	refDoc_2.serialize(1.2f);
}

