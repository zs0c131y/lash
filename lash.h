/* functions and structual definitions */
struct thread_opts {
    char host[INET_ADDRSTRLEN];
    unsigned int port, timeout, thread_id, start, end;
};

int lash_err(const char *s, int sock);
void *worker(void *thread_args);
int scanner(const char * host, unsigned int *port, unsigned int timeout, unsigned int *start, unsigned int *end);