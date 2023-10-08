/*
 * SimpleUI.h
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */

#ifndef SIMPLEUI_H_
#define SIMPLEUI_H_

/**
 * Standard header file for write and read to file
 */
#include <fstream>

/**
 * Project header files
 */
#include"StudentDB.h"


/**
 * \brief: SimpleUI.h
 * Access the studentDB class through the argument StudentDB to constructor
 * Contains the class SimpleUI and attribute myDB is a pointer object of type StudentDB class
 */
class SimpleUI
{
private:
	StudentDB* myDB;


public:
	SimpleUI(StudentDB& db);
	virtual ~SimpleUI();
	/**
	 * Contains the commands to be executed
	 */
	void run();
};

#endif /* SIMPLEUI_H_ */
