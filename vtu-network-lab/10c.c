#include <stdio.h>
#include <fcntl.h>

int main() {
	char fname[50], buffer[1025];
	int request, response, n;
	request = open("request.fifo", O_WRONLY);
	response = open("response.fifo", O_RDONLY);
	printf("Enter a filename to request: ");
	scanf("%s", fname);
	write(request, fname, sizeof(fname), 0);
	printf("Received response: \n");
	while((n = read(response, buffer, sizeof(buffer), 0)) > 0) {
		write(1, buffer, n);
	}
	close(request);
	close(response);
	return 0;
}
