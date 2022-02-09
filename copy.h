//@wingxel

#ifndef COPY_H
#define COPY_H

#define false 0
#define true 1

// length of the buffer to read into.
#define BUFFER_LEN 2048

typedef int bool;

/**
* Copy source file to destination file.
* @param source: src.
* @param destination: dest.
* @param replace: replace the destination file if it exists (1 for true 0 for false).
* @param info: character array where to write error/information.
* @param inf_length: length of info (for bound checking).
**/
int copyF(const char *const source, const char *const destination, bool replace, char *info, const size_t inf_length);

/**
* @param fp: pointer to the file you want to  close.
* @param fileName: name of the file you are closing (to indicate which file caused error while closing).
* @param info: character array where to write closing error.
* @param inf_length: length of info (for bound checking).
**/
void closeF(FILE *fp, const char *const fileName, char *info, const size_t inf_length);

#endif
