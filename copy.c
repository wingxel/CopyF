/**
* Copy file
**/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "copy.h"


int copyF(const char *const source, const char *const destination, bool replace, char *info, const size_t inf_length) {

	int error = 0;

	if (access(destination, F_OK) == 0 && !replace) {
		snprintf(info, inf_length, "%s (%s) %s", "Destination file", destination, "already exists! Aborting");
		error = -1;
	} else if (access(source, F_OK) != 0) {
		snprintf(info, inf_length, "%s (%s) %s", "Source file", source, "Does not exist!");
		error = -2;
	} else if (access(destination, W_OK) && access(destination, R_OK)){

		FILE *sourceFile = fopen(source, "rb");
		FILE *destinationFile;

		if (sourceFile == NULL) {
			snprintf(info, inf_length, "%s %s%s %s", "Failed to open source file", source, "\nError =>", strerror(errno));
			error = -3;
		} else {
			destinationFile = fopen(destination, "wb");

			if (destinationFile == NULL) {
				snprintf(info, inf_length, "%s %s%s %s", "Failed to open destination file", destination, "\nError =>", strerror(errno));
				closeF(sourceFile, source, info, inf_length);
				error = -4;
			}
		}

		if (error == 0) {

			char buffer[BUFFER_LEN];
			size_t chars_read;

			do {

				chars_read = fread(buffer, sizeof(char), BUFFER_LEN, sourceFile);
				fwrite(buffer, sizeof(char), chars_read, destinationFile);

				if (ferror(sourceFile) != 0 || ferror(destinationFile) != 0) {
					snprintf(info, inf_length, "%s %s", "An error occurred", strerror(errno));
					error = -5;
					break;
				}

			} while (chars_read == BUFFER_LEN);

			closeF(destinationFile, destination, info, inf_length);
			closeF(sourceFile, source, info, inf_length);
		}
	} else {
		snprintf(info, inf_length, "%s %s", "File access error :", strerror(errno));
	}
	return error;
}

void closeF(FILE *fp, const char *const fileName, char *info, const size_t inf_length) {
	int closer = fclose(fp);
	if (closer == EOF) {
		snprintf(info, inf_length, "%s (%s)\n%s %s\n", "Error closing file", fileName, "\nError =>", strerror(errno));
	}
}
