//
// Created by cloquet on 15/06/16.
//

#if defined (WIN32)
#include <winsock2.h>
    typedef int socklen_t;
#elif defined (linux)
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <unistd.h>
  #define INVALID_SOCKET -1
  #define SOCKET_ERROR -1
  #define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
#endif

#include <stdio.h>
#include <stdlib.h>
#define PORT 9090



int main(void)
{
#if defined (WIN32)
  WSADATA WSAData;
        int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
#else
  int erreur = 0;
#endif

  int fd;
  SOCKET sock;
  SOCKADDR_IN sin;

  if(!erreur)
    {
      /* Création de la socket */
      sock = socket(AF_INET, SOCK_STREAM, 0);

      /* Configuration de la connexion */
      sin.sin_addr.s_addr = inet_addr("0.0.0.0");
      sin.sin_family = AF_INET;
      sin.sin_port = htons(PORT);

      /* Si le client arrive à se connecter */
      if((fd = connect(sock, (SOCKADDR*)&sin, sizeof(sin))) != SOCKET_ERROR)
	printf("Connexion à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
      else
	{
	  perror("connect");
	  printf("Impossible de se connecter\n");
	}
      send(fd, "TEAM TROU DE BALLE", strlen("TEAM TROU DE BALLE"), 0);
      /* On ferme la socket précédemment ouverte */
      while (1)
	;
      closesocket(sock);

#if defined (WIN32)
      WSACleanup();
#endif
    }
  return EXIT_SUCCESS;
}