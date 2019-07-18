#include "string_path_in_matrix.h"
#include <cstdlib>
#include <cstring>

static bool has_path_core(const char *matrix, char *bitmap, int rows, int cols, int c_row, int c_col, const char *str);

bool has_path(const char *matrix, int rows, int cols, const char *str)
{
    int m_len = 0;
    char *bitmap = NULL;	
	
	if (matrix == NULL || rows < 1 || cols < 1 || str == NULL) {
		return false;
	}
	     
    m_len = strlen(matrix);
    bitmap = (char *) calloc(1, m_len);

    int c_row = 0, c_col = 0;
    for (c_row = 0; c_row < rows; c_row++) {
        for (c_col = 0; c_col < cols; c_col++) {
            memset(bitmap, 0, m_len);
            if (has_path_core(matrix, bitmap, rows, cols, c_row, c_col, str)) {
                return true;
            }
        }
    }
    return false;
}

static bool has_path_core(const char *matrix, char *bitmap, int rows, int cols, int c_row, int c_col, const char *str)
{
    bool retval = false;

    if (c_row < 0 || c_row == rows || c_col < 0 || c_col == cols) {
        return false;
    }

	if (*(bitmap+c_row*cols+c_col) == 1) {
		return false;
	}

    if (*(matrix+c_row*cols+c_col) != *str) {
        return false;
    }
    
    if (strlen(str) == 1) {
        return true;
    }

    *(bitmap+c_row*cols+c_col) = 1;
    retval =  has_path_core(matrix, bitmap, rows, cols, c_row+1, c_col, str+1) == true ? true :\
              has_path_core(matrix, bitmap, rows, cols, c_row, c_col+1, str+1) == true ? true :\
              has_path_core(matrix, bitmap, rows, cols, c_row-1, c_col, str+1) == true ? true :\
              has_path_core(matrix, bitmap, rows, cols, c_row, c_col-1, str+1) == true ? true : false;

	if (retval == false) {
    	*(bitmap+c_row*cols+c_col) = 0;
	}

	return retval;
    
}
