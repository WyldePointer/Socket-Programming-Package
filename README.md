# Socket-Programming-Package

<p align="center">
  <img src="http://uupload.ir/files/whf6_3-electric-logo-design.jpg">
</p>

Learn how to use sockets in IPC, TCP/IP and Advanced Network Programming.

# Introduction: What is a Socket?	
Well, To be simple, Socket is a way of communication between two things. Like the sockets which are used in the electrical accessories that connect that accessory to the power source, the socket concept in programming and networking easily connect two computers, processes or two other things which are present in computer and networking, which will be covered soon.

# Introduction: What is a client-Server model?
Imagine someone who is calling his friend on the phone. The one who is calling is called a **client** and the one who is going to respond to this action and pick the phone up, is called a **server**.

# What is the relation between Sockets and Client-Server model?
Sockets are meant to be used on Client-Server models. By saying "Client Server", I mean any model that is going to setup a communication path between two processes or etc. 
So the most important usage of sockets are introduced in the Client-Server model as **channels** in the communication.
Notice that the client does need to know the address(phone number :D) of the server but the server doesn't need that for just responding to him prior to that connection. But as soon as the communication is established between them, they both can send and recieve the data and they can grab each other's ip and each other status information.

# Establishing a Socket
To communicate, both server and the client need to create a Socket connection on their sides. So the Socket connection is opened by client and the server. You will get familiar of working with these sockets and passing the data through them very soon.

# Creating the Socket: The client side
Keep up with the following steps to create a new socket on the client side:
* Create a socket with the socket() system call.
* Connect the socket to the address of the server using the connect() system call.
* Send and recieve data. The simplest way is to use the read() and write() system calls.

# Creating the Socket: The server side
* Create a socket with the socket() system call.
* Bind the socket to an address using the bind() system call. This address will consist of the port number for a socket on the internet.
* Listen for connections with the listen() system call.
* Accept a connection with the accept() system call. This call is blocked untill a connection is successfully created.
* Send and recieve data.

# Socket Details
There are two critical things that each program must define after creating a new socket. Those are:
* Address Domain
* Socket Type
Remember that two processes are able to communicate with each other if they have the same socket types in the same domain.

## Address Domain Types
There are two most important domain types:
* UNIX Domain
* Internet Domain

In the  **UNIX Domain**, two processes share a common **file system** communication, Since the UNIX is using the file system to share the data between the processes.
The **Internet Domain** is the domain in which two processes runnning on any two hosts on the internet communicate.

## Address Domain Type Formats
Each of the domain types discussed above, has it's own address format.
* The address of a socket in the UNIX domain is a character string which is basically an entry in the file system.
* The address of a socket in the Internet domain consist of IP Address of the host + Port Number on that host.

## Review: IP Address and Port Number
Every computer on the internet has a unique 32 bit address which is called IP Address.
Each port number is a 16 bit unsigned integer which shows the doors through that host or computer.

## Socket Types
Two major sockets are:
* Stream Sockets
* Datagram Sockets

Stream sockets treat communications as a continuous **stream of characters**, while the Datagram sockets have to read the **entire messages at once**.
Each of these sockets has its own **communication protocol**.

## Communication Protocols: TCP vs UDP
Stream sockets use TCP(Transmission Control Protocol), which is a a reliable and stream oriented protocol.
Datagram sockets use UDP(Unix Datagram Protocol), which is unreliable and message oriented.

## Review of some important structures
1. **sockaddr_in** - Connection information. Used by connect , send , recv etc.
2. **in_addr** - Ip address in long format
3. **sockaddr**
4. **hostent** - The ip addresses of a hostname. Used by gethostbyname

# Listen system call
The listen system call allows the process to listen on the socket for connections. The first argument is the socket file descriptor, and the second is the size of the backlog queue, i.e., the number of connections that can be waiting while the process is handling a particular connection. This should be set to 5, the maximum size permitted by most systems. If the first argument is a valid socket, this call cannot fail, and so the code doesn't check for errors.

# Live(always alive) Server
While trying to set up a server to listen for the connections, Its better to set it up as a Live Server, Meaning that it should wait for all of the connections to connect, until its shut down manually.
We can do this by keeping the accept system call in a loop until its manually shuts down.

# Handle multiple socket connections with threads
To handle every connection we need a separate handling code to run along with the main server accepting connections.
One way to achieve this is using threads. The main server program accepts a connection and creates a new thread to handle communication for the connection, and then the server goes back to accept more connections. On Linux threading can be done with the pthread (posix threads) library. It would be good to read some small tutorial about it if you dont know anything about it. However the usage is not very complicated.