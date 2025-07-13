#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
   char write_msg[BUFFER_SIZE] = "Greetings";
   char read_msg[BUFFER_SIZE];
   int fd[2];
   pid_t pid;

   /* Create the pipe */
   if (pipe(fd) == -1)
   {
      fprintf(stderr, "Pipe failed\n");
      return 1;
   }

   /* Fork a child process */
   pid = fork(); // the return code for the fork() is zero for the new (child) process, whereas the (nonzero) >0 process identifier of the child is returned to the parent.
   if (pid < 0)
   { /* Error occurred */
      fprintf(stderr, "Fork Failed\n");
      return 1;
   }

   if (pid > 0)
   { /* Parent process */
      printf("Parent process:\n");

      /* Close the unused read end of the pipe */
      close(fd[READ_END]);
      /* Write to the pipe */
      if (write(fd[WRITE_END], write_msg, strlen(write_msg) + 1) == -1)
      {
         fprintf(stderr, "Write to pipe failed\n");
         return 1;
      }

      printf("write successful\n");

      /* Close the write end of the pipe */
      close(fd[WRITE_END]); // If the parent closes its write end (fd[1]), then a read() call in the child will return 0, signaling end-of-file (EOF).
      printf("write end closed\n\n");
   }


   else
   { /* Child process */
      printf("Child process:\n");

      /* Close the unused write end of the pipe */
      close(fd[WRITE_END]); // If the child does not close fd[1], the pipe stays open, and the parent might keep waiting indefinitely for the child to finish.
      /* Read from the pipe */
      ssize_t bytes_read = read(fd[READ_END], read_msg, BUFFER_SIZE);
      printf("bytes_read: %ld\n", bytes_read);

      if (bytes_read == -1)
      {
         fprintf(stderr, "Read from pipe failed\n");
         return 1;
      }
      else if (bytes_read == 0)
      {
         fprintf(stderr, "EOF reached\n");
      }
      /* Print the read message */
      printf("Rcved msg--> %s\n", read_msg);

      bytes_read = read(fd[READ_END], read_msg, BUFFER_SIZE);
      if(bytes_read == 0)
      {
         fprintf(stderr, "EOF reached\n");
         printf("bytes_read: %ld\n", bytes_read);
      }
   }

   /* Close the read end of the pipe */
   close(fd[READ_END]); //

return 0;
}