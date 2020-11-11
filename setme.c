
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void fail(char** argv, char* error_message) {
if (errno != 0) {
fprintf("Error code %s", error_message);
}

if (error_message != NULL) {
fprintf(stderr, error_message);
}

fprintf(stderr, "Usage: %s userid groupid\n", argv[0]);
exit(1);
}

int main(int argc, char **argv) {
if (argc < 3) {
fail(argv, NULL);
}

char *check = argv[1];
int userid = strtol(argv[1], &check, 0);
if (check == argv[1]) {
// no conversion was performed
fail(argv, "Cannot parse userid - should be a integer in base-10, octal (prefix 0), or hexadecimal (prefix 0x)\n");
}

check = argv[2];
int groupid = strtol(argv[2], &check, 0);
if (check == argv[2]) {
// no conversion was performed
fail(argv, "Cannot parse groupid - should be a integer in base-10, octal (prefix 0), or hexadecimal (prefix 0x)\n");
}

if (setgid(groupid) | setuid(userid) != 0) {
fail(argv, "Cannot set setgid\n");
}
if (execl("/bin/sh","sh",0) != 0) {
fail(argv, "Cannot execute /bin/sh");
}

return 0; // never reached if success
}
