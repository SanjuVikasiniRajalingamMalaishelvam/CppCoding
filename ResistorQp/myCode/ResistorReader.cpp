/*
 * ResistorReader.cpp
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#include "ResistorReader.h"

using namespace std;
ResistorReader::ResistorReader()
{
	// TODO Auto-generated constructor stub

}

ResistorReader::~ResistorReader()
{
	// TODO Auto-generated destructor stub
}

void ResistorReader::read(std::istream &in,
		std::map<std::string, ResisPtr> &found)
{
	cout << "In read" <<endl;
	ResistorPart *ptr = nullptr;
	string line = "";
	for (line =""; getline(in, line);)
	{
		if (!line.empty())
		{
			if (line[2] == '[')
			{
				//Is a resistor Connection
				char serialDelim = '-';
				char parallelDelim = '|';

				string::size_type positionSerial = line.find(serialDelim);
				string::size_type positionParallel = line.find(parallelDelim);

				if (positionSerial!= string::npos)
				{
					//serial connection
					string::size_type position = line.find('[');
					string serial = line.substr(0,position);
					line.erase(0, position+1);
					SerialResistorConnection *serialConn = new SerialResistorConnection(serial);
					string conn1 = line.substr(0,positionSerial);
					line.erase(0, positionSerial+1);
					position = line.find(']');
					string conn2 = line.substr(0,position);
					line.erase(0, position+2);

					*serialConn+=found[conn1];
					found.erase(conn1);
					*serialConn+=found[conn2];
					found.erase(conn2);

					found.insert(make_pair(serialConn->getName(), shared_ptr<Resistor>(serialConn)));

				}
				if(positionParallel!= string::npos)
				{
					// parallel connection

					string::size_type position = line.find('[');
					string parallel = line.substr(0,position);
					line.erase(0, position+1);
					ParallelResistorConnection *parallelConn = new ParallelResistorConnection(parallel);
					string conn1 = line.substr(0,positionParallel);
					line.erase(0, positionParallel+1);
					position = line.find(']');
					string conn2 = line.substr(0,position);
					line.erase(0, position+2);

					*parallelConn+=found[conn1];
					found.erase(conn1);
					*parallelConn+=found[conn2];
					found.erase(conn2);

					found.insert(make_pair(parallelConn->getName(), shared_ptr<Resistor>(parallelConn)));
				}
			}
			else
			{
				ResisPtr resistorPtr = ptr->from(line);
				found.insert(make_pair(resistorPtr->getName(), resistorPtr));
			}
		}
	}
	cout << "Outside read" <<endl;
}
