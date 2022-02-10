#include <stdio.h>
#include "lib_copy_LibCopy.h"
#include "../copy.h"

JNIEXPORT jstring JNICALL Java_lib_copy_LibCopy_copyF(JNIEnv *env, jobject thisObject, jstring src, jstring dest) {

	char info[256];

	const char *const source = (*env)->GetStringUTFChars(env, src, NULL);

	if (NULL == source) {
		return NULL;
	}

	const char *const destination = (*env)->GetStringUTFChars(env, dest, NULL);

	if (NULL == destination) {
		(*env)->ReleaseStringUTFChars(env, src, source);
		return NULL;
	}

	int copyResult = copyF(source, destination, false, info, 255);

	(*env)->ReleaseStringUTFChars(env, src, source);
	(*env)->ReleaseStringUTFChars(env, dest, destination);

	if (copyResult != 0) {
		return (*env)->NewStringUTF(env, info);
	}

	return (*env)->NewStringUTF(env, "Done Copying file.");
}
