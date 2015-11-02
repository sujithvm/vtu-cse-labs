#include <stdio.h>
#include <fcntl.h>

int main() {
	char fname[50], buffer[1025];
	int request, response, file, n;
	mkfifo("request.fifo", 0777);
	mkfifo("response.fifo", 0777);
	printf("Waiting for request... \n");
	request = open("request.fifo", O_RDONLY);
	response = open("response.fifo", O_WRONLY);
	read(request, fname, sizeof(fname), 0);
	printf("Received request for %s \n", fname);
	file = open(fname, O_RDONLY);
	if(file < 0) {
		write(response, "File not found. \n", 18, 0);
	} else {
		while((n = read(file, buffer, sizeof(buffer), 0)) > 0) {
			write(response, buffer, n, 0);
		}
	}
	printf("Response sent. \n");
	close(request);
	close(response);
	unlink("request.fifo");
	unlink("response.fifo");
	return 0;
}
