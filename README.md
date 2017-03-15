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

# Socket Information
There are two critical things that each program must define after creating a new socket. Those are:
* Address Domain
* Socket Type
Remember that two processes are able to communicate with each other if they have the same socket types in the same domain.

# Address Domain Types
There are two most important domain types:
* UNIX Domain
* Internet Domain
In the  **UNIX Domain**, two processes share a common **file system** communication, Since the UNIX is using the file system to share the data between the processes.
The **Internet Domain** is the domain in which two processes runnning on any two hosts on the internet communicate.

## Address Domain Type Formats
Each of the domain types discussed above, has it's own address format.
* The address of a socket in the UNIX domain is a character string which is basically an entry in the file system.
* The address of a socket in the Internet domain consist of IP Address of the host + Port Number on that host.
