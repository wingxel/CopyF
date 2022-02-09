/**
* Test copy file
**/

#include <stdio.h>
#include <string.h>
#include "copy.h"

int main (int argc, char* argv[]) {

	char source[256];
	char destination[256];
	char info[256];

	if (argc >= 3) {

		strncpy(source, argv[1], 255);
		strncpy(destination, argv[2], 255);
		printf("Source: (%s)\n Destination: (%s)\n", argv[1], argv[2]);

	} else {

		printf("%s: ", "Enter source");
		fgets(source, 255, stdin);
		source[strcspn(source, "\n")] = 0;
		printf("%s: ", "Enter detination file");
		fgets(destination, 255, stdin);
		destination[strcspn(destination, "\n")] = 0;
		printf("Source: (%s)\n Destination: (%s)\n", source, destination);

	}

	if (strlen(source) > 0 && strlen(destination) > 0) {
		int r = copyF(source, destination, false, info, 255);
		if (r != 0) {
			printf("Error occurred : %s\n", info);
		} else {
			printf("Done copying file (%s) to (%s)\n", source, destination);
		}
	} else {
		puts("Filed to get source and destination files");
	}
	return 0;
}
