/*
  Name: BubbleSort
  Copyright: 
  Author: 
  Date: 19/03/06 21:05
  Description: Simple BubbleSort sorts a single array
*/

#include <cstdlib>
#include <iostream>
#include <fstream>                    //include library for file processing

const int MAXNUMBER = 10000;

using namespace std;

// Bubble Sort
void bubble(int x[], int n)
{
	int hold, j, pass,comparison,swap;
	bool switched = true;

	for (pass = 0; pass < n-1 && switched == true; pass++) {
		//     outer loop controls the number of passes
		switched = false;   	              // initially no interchanges
										      // have been made on this pass
		for (j = 0; j < n-pass-1; j++){
	
		
			comparison++;
			
			//    inner loop governs each individual pass 
			if (x[j] > x[j+1]) {
				//           elements out of order 
				//        an interchange is necessary
				
				switched = true;
				hold = x[j];
				x[j] = x[j+1];
				x[j+1] = hold;
				//swap++;
	
			}  // end if
	}
	}  // end for
	
	cout << "swap:" << pass <<"\n";
	cout << "comparison:" << comparison;
}  // end bubble




int main(int argc, char *argv[])
{
    int i, count, number[MAXNUMBER];
    void bubble(int [], int);
    
	ifstream infile;                 //create the file infile for input
    infile.open("NumbersData.txt");  //open the file
                                     
    if ( !infile.is_open() ) {       //checks to see if file was opened
       // The file could not be opened
       cout << endl << "ERROR: Unable to open file" << endl;
       system ("PAUSE");
       exit(1);
    }
    
    i = 0;
	while (!infile.eof() && infile >> number[i])
		++i;
	count = i;
	bubble(number, count);
	cout << "\nThe array contains " << count << " elements." << endl;
	cout << "\nThe array sorted" << endl;
    for (i = 0; i < count; ++i)
	    cout << number[i] << endl;

	
    infile.close();                   //close the file
    cout << endl << endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
