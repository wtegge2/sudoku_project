#include "sudoku.h"

// Introduction Paragraph
// 
// This program solves a sudoku puzzle. It uses recursion and backtracking to solve the sudoku puzzle. There are 5 functions. Is_val_in_row
// function will check if a certain number already appears in the row or not. The is_val_in_col function checks to see if the value already 
// appears in the column or not. The is_val_in_3x3_zone function checks to see if the value appears in the 3x3 zone you are in. The
// is_val_valid function will call the 3 previous functions and checks if the value appears in the row, column, or 3x3 zone. Lastly, 
// the function solve_sudoku uses the backtracking and recursion algorithm given to us in order to finally solve the sudoku puzzle.  

// Function: is_val_in_row
// Return true if "val" already existed in ith row of array sudoku.
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {	

  assert(i>=0 && i<9);				

  // BEG TODO
  for(int c=0; c<9; c++){			// for loop that loops through the values of the row	
      if (sudoku[i][c] == val)			// checks to see if the value appears in the row
          return 1;				// returns 1 if the value appears
  }
  return 0;					// returns 0 if the value does not appear
  // END TODO
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {

  assert(j>=0 && j<9);

  // BEG TODO
  for(int r=0; r<9; r++){			// for loop that loops through the values of the column
    if (sudoku[r][j] == val)			// checks to see if the value already appears in the column
        return 1;				// returns 1 if the value already appears
  }
  return 0;					// returns 0 if the value does not appear
  // END TODO
}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {
   
  assert(i>=0 && i<9);
  
  // BEG TODO
  int start_r = i/3;				// divides the 9 rows into 3 sub zones
  int start_c = j/3;				// divides the 9 columns into 3 sub zones

  for(int r=0; r<3; r++){			// for loop that loops through the 3 row sub zones
    for(int c=0; c<3; c++){			// for loop that loops through the 3 column sub zones
        if (sudoku[((start_r*3)+r)][((start_c*3)+c)] == val){		// checks to see if the value is in the current sub zone
            return 1;				// returns 1 if the value appears in the 3x3 zone 
	}
    }
  }
  return 0;					// returns 0 if the value does not appear in the 3x3 zone
  // END TODO
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9 && j>=0 && j<9);

  // BEG TODO
  if(is_val_in_row(val, i, sudoku) == 1)		// calls is_val_in_row function to check if the value is in the row or not
         return 0;					// returns 0 if the value was seen in the row

  if(is_val_in_col(val, j, sudoku) == 1)		// calls is_val_in_col function to check if the value is in the column or not
         return 0;					// returns 0 if the value was seen in the column

  if(is_val_in_3x3_zone(val, i, j, sudoku) == 1)	// calls is_val_in_3x3_zone function to see if the value is in the 3x3 zone already
         return 0;					// returns 0 if the value was seen in the 3x3 zone already

  return 1;						// returns 1
  // END TODO
}

// Procedure: solve_sudoku
// Solve the given sudoku instance.
int solve_sudoku(int sudoku[9][9]) {

  // BEG TODO.
int i;							// initializes i variable
int j;							// initializes j variable
int num;						// initializes num variable

for(i=0; i<9; i++){					// for loop that loops through the rows
  for(j=0; j<9; j++){					// for loop that loops through the columns
    if(sudoku[i][j]!=0){				// checks to see if every spot has a value or not
      continue;						// goes to the next iteration of the for loop
    }
    for( num=1; num<=9; num++){				// for loop that loops through each available value
	
       if (!is_val_valid(num, i, j, sudoku)){		// skips if not valid
         continue;					// goes to next iteration of the for loop
       }
       sudoku[i][j] = num;				// place number at spot
       if (solve_sudoku(sudoku)){			// recursive part
         return 1;					// returns 1 if it is solved and we are done
       }
       sudoku[i][j] = 0;				
    }
    return 0;						// backtrack
  }
}
  return 1;						// no empty cell is found and it is done
  // END TODO.
}

// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}

