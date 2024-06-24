#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define  ARG_ERR             (-1)
#define  SRC_OPEN_ERR        (-2)
#define  DST_OPEN_ERR        (-3)
#define  DST_WRITE_ERR       (-4)
#define  OUT_OF_MEMORY_ERR   (-5)


int main(int argc, char** argv) {
	if (argc != 3) {
		fprintf(stderr, "Invalid number of arguments\n");
		fprintf(stderr, "call it as %s <src> <dst>\n", argv[0]);
		return ARG_ERR;
	}
	
	char* src = argv[1];
	char* dst = argv[2];

	// If destenation is a directory, use same source name file
	if (dst[strlen(dst) - 1] == '/') {
		int dstLen = strlen(dst);
		int srcLen = strlen(src);
		
		// Search for the last '/' in src argument
		int srcNameIdx = 0;
		for (int i = srcLen - 1; i >= 0; i--) {
			if (src[i] == '/') {
				srcNameIdx = i + 1;
				break;
			}
		}

		// use destenation as [dst]/[src-org-name]
		int srcNameLen = srcLen - srcNameIdx;
		dst = malloc(dstLen + srcNameLen + 2);
		strcpy(dst, argv[2]);
		strcat(dst, "/");
		strcat(dst, src + srcNameIdx);
	}

	int srcFd = open(src, O_RDONLY);
	if (srcFd == -1) {
		fprintf(stderr, "source file %s doesn't exsist\n", src);
		return SRC_OPEN_ERR;
	}

	int dstFd = open(dst, O_WRONLY | O_CREAT);
	if (dstFd == -1) {
		fprintf(stderr, "destenation file %s can't be opened\n", dst);
		return DST_OPEN_ERR;
	}

	char buf[100];
	int bufSize = 100;
	int readCnt;
	int writeCnt;
	while ((readCnt = read(srcFd, buf, bufSize)) > 0) {
		writeCnt = write(dstFd, buf, readCnt);
		if (writeCnt == -1) {
			fprintf(stderr, "unable to write into destenation file %s\n", dst);
			return DST_WRITE_ERR;
		}
		else if (writeCnt < readCnt) {	// partial data written
			// try to rewrite remaning data
			int rem = readCnt = readCnt - writeCnt;
			writeCnt = write(dstFd, buf + writeCnt, rem);
			
			if (writeCnt < rem) {
				fprintf(stderr, "No suffiecient memory\n");
				return OUT_OF_MEMORY_ERR;
			}
		}
	}
	
	close(dstFd);
	close(srcFd);
	
	return 0;
}

