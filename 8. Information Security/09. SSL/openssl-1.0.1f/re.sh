#!/bin/bash

make
echo make DONE!
make install
echo make install DONE!
g++ -L/home/sec11/12181879/openssl/lib -I/home/sec11/12181879/openssl/include -fpermissive -o /home/sec11/12181879/openssl-1.0.1f/demos/ssl/serv /home/sec11/12181879/openssl-1.0.1f/demos/ssl/serv.cpp -lssl -lcrypto -ldl
g++ -L/home/sec11/12181879/openssl/lib -I/home/sec11/12181879/openssl/include -fpermissive -o /home/sec11/12181879/openssl-1.0.1f/demos/ssl/cli /home/sec11/12181879/openssl-1.0.1f/demos/ssl/cli.cpp -lssl -lcrypto -ldl
echo compile serv.cpp and cli.cpp DONE!
gcc -L/home/sec11/12181879/openssl/lib -I/home/sec11/12181879/openssl/include -o hb hb.c -lssl -lcrypto -ldl
echo compile hb.c DONE!

exit 0
