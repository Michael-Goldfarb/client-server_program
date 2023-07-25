# client-server_program
This project implements a local server that efficiently stores files using serialization and encryption. It also includes functionalities for sending files to clients and supports various algorithms for serialization and deserialization. Additionally, it provides a client application that allows users to interact with the server, sending and requesting files with built-in serialization and deserialization capabilities.

With this project, you can expect a robust file storage solution with secure encryption, smart data structures, and streamlined file transfers for a seamless user experience.

## How to run:
1. Open two system terminals
2. Run this command: cd server
3. Run this command: make clean
4. Run this command: make

### Starting a local server
6. Run this command: ./executable/server --hostname localhost:8081

### Connecting client to local server
8. Go to second terminal
9. Run this command: cd client
10. Run this command: make clean
11. Run this command: make

#### Sending files to server
13. Run this command: ./build/bin/release/client --hostname localhost:8081 --send (desired file you want to send to local server and make sure it is in the files folder)

#### Requesting files from server
15. Run this command: ./build/bin/release/client --hostname localhost:8081 --request (desired folder you want to pull from server) 
