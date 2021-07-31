#include <iostream>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#include <netdb.h>
#include <vector>
#include <thread>


using namespace std;

void *task1(void *);
void handle_connection (int conn);

// static int connFd;
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[])
{
    int pId, portNo, listenFd;
    socklen_t len; //store size of the address
    bool loop = false;
    struct sockaddr_in svrAdd, clntAdd;

    pthread_t threadA[3];
    std::vector<std::thread> threads;

    if (argc < 2)
    {
        cerr << "Syntam : ./server <port>" << endl;
        return 0;
    }

    portNo = atoi(argv[1]);

    if((portNo > 65535) || (portNo < 2000))
    {
        cerr << "Please enter a port number between 2000 - 65535" << endl;
        return 0;
    }

    //create socket
    listenFd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    std::cout << "socket file descriptor value:" << listenFd << std::endl;

    if(listenFd < 0)
    {
        cerr << "Cannot open socket" << endl;
        return 0;
    }

    bzero((char*) &svrAdd, sizeof(svrAdd));

    svrAdd.sin_family = AF_INET;
    svrAdd.sin_addr.s_addr = INADDR_ANY;
    svrAdd.sin_port = htons(portNo);

    //bind socket
    if(bind(listenFd, (struct sockaddr *)&svrAdd, sizeof(svrAdd)) < 0)
    {
        cerr << "Cannot bind" << endl;
        return 0;
    }

    listen(listenFd, 5);

    int noThread = 0;

    while (noThread < 3)
    {
        socklen_t len = sizeof(clntAdd);
        cout << "Listening" << endl;

    //this is where client connects. svr will hang in this mode until           client conn
        int connFd = accept(listenFd, (struct sockaddr *)&clntAdd, &len);
        
        if (connFd < 0)
        {
            cerr << "Cannot accept connection" << endl;
            return 0;
        }
        else   
        {
            cout << "Connection successful" << endl;
        }

        // pthread_create(&threadA[noThread], NULL, task1, NULL); 
        threads.push_back(std::thread(&handle_connection, connFd));

        noThread++;
    }

    // for(int i = 0; i < 3; i++)
    // {
    //     pthread_join(threadA[i], NULL);
    // }  
    for (auto&& t : threads)
    t.join();
}


void handle_connection (int conn)
{
    cout << "Thread No: " << pthread_self() << endl;
    std::cout << "connection accept descriptor value:" << conn << std::endl;

    char test[256];
    bzero(test, 256);
    bool loop = false;

    while(!loop)
    {       
        bzero(test, 256);     
        int n = read(conn, test, 255);
      
        if (n < 0) {
            error("ERROR reading from socket");
        }
        printf("[Thread-%d]: %s\n", conn, test);  

        if(0 == strcmp("Done", test)){
            std::cout << "Client requested to close the connection!" << std::endl;
            break;
        }
              
        // Write a code in such way that individual clients can request to close the socket connections.
        // if test == done
        // then exit the loop
        // std::cout << "Closing the socket channel for client:" << pthread_self() << std::endl;         
    }

    cout << "\n[Thread-" << conn << "]: Closed\n" << endl;

    close(conn);
}
