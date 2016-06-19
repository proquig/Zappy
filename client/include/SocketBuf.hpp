//
// Created by cloquet on 18/06/16.
//

#ifndef CLIENT_SOCKETBUF_HPP
#define CLIENT_SOCKETBUF_HPP

#include <streambuf>
#include <iostream>
#include <fcntl.h>

class 		Socket
{
  int 		_fd_socket;
  std::string 	_command;
 public:
  Socket(){};

  ~Socket()
  { };

  void	setFdSocket(int fd)
  {
    _fd_socket = fd;
  }

  std::string &read()
  {
    FILE *f;
    char *buf;
    size_t len;
    int a;

    buf = NULL;
    if (!(f = fdopen(this->_fd_socket, "r")))
    {
      perror("fdopen");
      exit(-1);
    }
    if ((a = getline(&buf, &len, f)) == -1)
      exit(0);
    buf[a] = 0;
    _command = buf;
    free(buf);
    return _command;
  };

  void write()
  { }
};


#endif //CLIENT_SOCKETBUF_HPP
