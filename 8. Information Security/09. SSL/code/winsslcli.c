// ssl client in windows:

#include <iostream>
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <memory.h>
#include <errno.h>
#include <sys/types.h>

#include <openssl/crypto.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/rand.h>

#define CHK_NULL(x)  \
    if ((x) == NULL) \
    exit(1)
#define CHK_ERR(err, s) \
    if ((err) == -1)    \
    {                   \
        perror(s);      \
        exit(1);        \
    }
#define CHK_SSL(err)                 \
    if ((err) == -1)                 \
    {                                \
        ERR_print_errors_fp(stderr); \
        exit(2);                     \
    }

using namespace std;
int main(int argc, char *argv[])
{
    int err = 0;
    int sd;
    struct sockaddr_in sa;
    SSL_CTX *ctx;
    SSL *ssl;
    X509 *server_cert;
    char *str;
    char buf[4096];
    const SSL_METHOD *meth;

    SSLeay_add_ssl_algorithms();
    meth = TLSv1_client_method();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(meth);
    CHK_NULL(ctx);

    CHK_SSL(err);

    /* Initialise Windows Sockets */

    WORD wVersionRequested;
    WSADATA wsaData;

    wVersionRequested = MAKEWORD(2, 2);

    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0)
    {
        /* Tell the user that we could not find a usable */
        /* WinSock DLL.                                  */
        return 0;
    }

    /* Confirm that the WinSock DLL supports 2.2.*/
    /* Note that if the DLL supports versions greater    */
    /* than 2.2 in addition to 2.2, it will still return */
    /* 2.2 in wVersion since that is the version we      */
    /* requested.                                        */

    if (LOBYTE(wsaData.wVersion) != 2 ||
        HIBYTE(wsaData.wVersion) != 2)
    {
        /* Tell the user that we could not find a usable */
        /* WinSock DLL.                                  */
        WSACleanup();
        return 0;
    }

    /* The WinSock DLL is acceptable. Proceed. */

    /*---------------------------------------------*/
    /*  Initialize PRNG							   */

    RAND_screen();

    /* ----------------------------------------------- */
    /* Create a socket and connect to server using normal socket calls. */

    sd = socket(AF_INET, SOCK_STREAM, 0);

    if (sd == -1)
    {
        err = WSAGetLastError();
        cout << err << endl;
        exit(err);
    }
    // CHK_ERR(sd, "socket");

    memset(&sa, '\0', sizeof(sa));
    sa.sin_family = AF_INET;
    inet_pton(AF_INET, "165.246.38.151", &(sa.sin_addr.s_addr)); // target IP
    sa.sin_port = htons(12194);                                  /* Server Port number */

    err = connect(sd, (struct sockaddr *)&sa,
                  sizeof(sa));
    CHK_ERR(err, "connect");

    /* ----------------------------------------------- */
    /* Now we have TCP conncetion. Start SSL negotiation. */

    ssl = SSL_new(ctx);
    CHK_NULL(ssl);
    SSL_set_fd(ssl, sd);
    err = SSL_connect(ssl);
    CHK_SSL(err);

    /* Following two steps are optional and not required for
    data exchange to be successful. */

    /* Get the cipher - opt */

    printf("SSL connection using %s\n", SSL_get_cipher(ssl));

    /* Get server's certificate (note: beware of dynamic allocation) - opt */

    server_cert = SSL_get_peer_certificate(ssl);
    CHK_NULL(server_cert);
    printf("Server certificate:\n");

    str = X509_NAME_oneline(X509_get_subject_name(server_cert), 0, 0);
    CHK_NULL(str);
    printf("\t subject: %s\n", str);
    free(str);

    str = X509_NAME_oneline(X509_get_issuer_name(server_cert), 0, 0);
    CHK_NULL(str);
    printf("\t issuer: %s\n", str);
    free(str);

    /* We could do all sorts of certificate verification stuff here before
    deallocating the certificate. */

    X509_free(server_cert);

    /* --------------------------------------------------- */
    /* DATA EXCHANGE - Send a message and receive a reply. */

    err = SSL_write(ssl, "Hello World!", strlen("Hello World!"));
    CHK_SSL(err);

    err = SSL_read(ssl, buf, sizeof(buf) - 1);
    CHK_SSL(err);
    buf[err] = '\0';
    printf("Got %d chars:'%s'\n", err, buf);
    SSL_shutdown(ssl); /* send SSL/TLS close_notify */

    /* Clean up. */

    closesocket(sd);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    WSACleanup();

    printf("Hello World!\n");
    return 0;
}
