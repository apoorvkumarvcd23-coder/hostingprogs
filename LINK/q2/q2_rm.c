/* ===================================================================
 * Q2 (part 3 of 3): rm  -  delete a file (UNIX file APIs)
 * -------------------------------------------------------------------
 * HOW TO RUN  (copy-paste each line into the terminal):
 *
 *     gcc q2_rm.c
 *     ./a.out renamed.txt   # deletes renamed.txt
 *
 * Prints nothing on success; the file is removed.
 * ===================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int output_fd = unlink(argv[1]);
    if (output_fd == -1) { perror("unlink error"); return 3; }
}
