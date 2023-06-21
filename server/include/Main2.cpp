/*

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include "pack109.hpp"
#include "hostname.hpp"
#include "send.hpp"
#include "request.hpp"


using namespace std;
int main(int argc, char **argv)
{
    std::string hostString;
    std::string portString;
    char *hostChars = NULL;
    char *portChars = NULL;
    int port;
    char *sendChars;
    char *requestChars;
    bool callSend = false;
    bool callRequest = false;
    bool hostFlag = false;

    //parse hostname
        std::string givenHost = hostname(argc, argv);
        for(int i=0; i<givenHost.size(); i++) {
            if(givenHost[i] == ':') {
                for(int j=0; j<i; j++) {
                    hostString += givenHost[j];
                }
                for(int j=i+1; j<givenHost.size(); j++) {
                    portString += givenHost[j];
                }
            }
        }
        hostChars = (char *)hostString.c_str();
        portChars = (char *)portString.c_str();


        port = atoi(portChars);

        std::cout << hostString;
        printf("\n-------\n");


        if(send(argc, argv) != -1) {
            sendChars = argv[send(argc, argv)];
            callSend = true;
        }

        else if(request(argc, argv) != -1) {
            requestChars = argv[request(argc, argv)];
            callRequest = true;
        }

        if (callRequest && callSend)
        { 
        printf("ERROR: Can't include both send and request\n");
        return 1;
        }

    


int sockfd, portno, n;
/*
    if(callSend == true) {
        //open the file and read it into memory
        std::ifstream file(sendChars);
        std::string str;
        std::string fileString;
        while (std::getline(file, str))
        {
            fileString += str;
        }
        FILE *fileP;
            long lSize;
            char *buffer;
            size_t result;
            printf("Sending File \"%s\".\n", sendChars);
            fileP = fopen(sendChars, "rb");
            if (fileP == NULL)
            {
                printf("Failed to open file: \"%s\"\nDone.\n", sendChars);
                exit(1);
            }
            fseek(fileP, 0, SEEK_END);
            lSize = ftell(fileP);
            printf("Read File: %d bytes.\n", lSize);
            rewind(fileP);
            buffer = (char *)malloc(sizeof(char) * lSize);
            if (buffer == NULL)
            {
                printf("Memory error\n");
                exit(2);
            }
            result = fread(buffer, 1, lSize, fileP);
            if (result != lSize)
            {
                printf("Reading error\n");
                exit(3);
            }
            int counter = 0;
            std::vector<unsigned char> file_bytes;
            while (buffer[counter] != NULL)
            {
                file_bytes.push_back(buffer[counter]);
                counter++;
            }
            fclose(fileP);
            free(buffer);

            
            // store file in File struct
            std::string sendString = std::string(sendChars);
            std::string fileName = sendString.substr(sendString.find_last_of("/") + 1);
            struct File myFile = {.name = fileName, .bytes = file_bytes};  
    
            // serialize using PACK109 protocol
            printf("original file btye size is %d\n", myFile.bytes.size());
            std::vector<unsigned char> serialized_file = pack109::serialize(myFile);
            //  encrypt
            std::vector<unsigned char> encryptedFile = pack109::encrypt(serialized_file);


            //connect to remote host

            //print port
            printf("Port: %d\n", port);
            //print host
            printf("Host: %s\n", hostChars);
            //print file name
            printf("File: %s\n", sendChars);

            

            printf("Connecting to %s:%d.\n", hostChars, port);
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            struct sockaddr_in serv_addr;
            struct hostent *server;
            portno = port;
            printf("Port: %d\n", portno);
            server = gethostbyname(hostChars);

            if (sockfd < 0)
            {
                printf("ERROR opening socket\n");
                exit(1);
            }
            if (server == NULL)
            {
                printf("ERROR, no such host\n");
                exit(0);
            }

            bzero((char *)&serv_addr, sizeof(serv_addr));
            serv_addr.sin_family = AF_INET;
            bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
            serv_addr.sin_port = htons(portno);
    

            // now connect to the server

            //print sockfd
            printf("Socket: %d\n", sockfd);
            // print (struct sockaddr*)&serv_addr
            printf("serv_addr: %s\n", (struct sockaddr*)&serv_addr);
            // print sizeof(serv_addr)
            printf("serv_addr size: %d\n", sizeof(serv_addr));
           
            if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
                perror("ERROR connecting");
                exit(1);
            }
int count = 0;
    while (true)
    {
        //printf("count is %d\n",count);
        if (count != 0)
        { // check for input
            printf("Enter a new flag and file name.\n");
            string input;
            std::cin >> input;
            size_t sendPos = input.find("--send");
            size_t requestPos = input.find("--request");
            //printf("sendPos is: %d\n", sendPos);
            if (sendPos != string::npos)
            {
                printf("send flag caught\n");
                std::cin >> input;
                sendChars = (char *)input.c_str();
                callSend = true;
            }
            else if (requestPos != string::npos)
            {
                printf("request flag caught\n");
                std::cin >> input;
                requestChars = (char *)input.c_str();
                callRequest = true;
            }
        }

    if(callSend == true) {
        //open the file and read it into memory
        std::ifstream file(sendChars);
        std::string str;
        std::string fileString;
        while (std::getline(file, str))
        {
            fileString += str;
        }
        FILE *fileP;
            long lSize;
            char *buffer;
            size_t result;
            printf("Sending File \"%s\".\n", sendChars);
            fileP = fopen(sendChars, "rb");
            if (fileP == NULL)
            {
                printf("Failed to open file: \"%s\"\nDone.\n", sendChars);
                exit(1);
            }
            fseek(fileP, 0, SEEK_END);
            lSize = ftell(fileP);
            printf("Read File: %d bytes.\n", lSize);
            rewind(fileP);
            buffer = (char *)malloc(sizeof(char) * lSize);
            if (buffer == NULL)
            {
                printf("Memory error\n");
                exit(2);
            }
            result = fread(buffer, 1, lSize, fileP);
            if (result != lSize)
            {
                printf("Reading error\n");
                exit(3);
            }
            int counter = 0;
            std::vector<unsigned char> file_bytes;
            while (buffer[counter] != NULL)
            {
                file_bytes.push_back(buffer[counter]);
                counter++;
            }
            fclose(fileP);
            free(buffer);

            
            // store file in File struct
            std::string sendString = std::string(sendChars);
            std::string fileName = sendString.substr(sendString.find_last_of("/") + 1);
            struct File myFile = {.name = fileName, .bytes = file_bytes};  
    
            // serialize using PACK109 protocol
            printf("original file btye size is %d\n", myFile.bytes.size());
            std::vector<unsigned char> serialized_file = pack109::serialize(myFile);
            //  encrypt
            std::vector<unsigned char> encryptedFile = pack109::encrypt(serialized_file);


            // send byte vector over socket
            unsigned char sendBuffer[encryptedFile.size()];
            for (int i = 0; i < encryptedFile.size(); i++)
            {
                sendBuffer[i] = encryptedFile[i];
            }
            printf("Sending %d bytes.\n", encryptedFile.size());
            n = write(sockfd, sendBuffer, encryptedFile.size());
            printf(" bytes sent.%d\n", n);
            if (n < 0)
            {
                perror("ERROR writing to socket\n");
                printf("Done.\n");
                exit(1);
            }
            printf("Message sent\nDone.\n");
        }




        else if (callRequest)
        { // request a file
            // store into request struct
            std::string requestString = std::string(requestChars);
            std::string requestName = requestString.substr(requestString.find_last_of("/") + 1);
            struct Request myRequest = {.name = requestName};
            // serialize
            std::vector<unsigned char> serializedRequest = pack109::serialize(myRequest);
            // encrypt
            std::vector<unsigned char> encryptedRequest = pack109::encrypt(serializedRequest);
            // send encypted byte vector over socket
            printf("Requesting file \"%s\".\n", requestChars);
            printf("Sending %d bytes.\n", encryptedRequest.size());
            unsigned char requestBuffer[encryptedRequest.size()];
            for (int i = 0; i < encryptedRequest.size(); i++)
            {
                requestBuffer[i] = encryptedRequest[i];
            }
            n = write(sockfd, requestBuffer, encryptedRequest.size());
            if (n < 0)
            {
                perror("ERROR writing to socket\n");
                printf("Done.\n");
                exit(1);
            }
            printf("Message Sent.\n");
            // Now read server response
            std::vector<unsigned char> encryptedResponse;
            unsigned char responseBuffer[1000];
            bzero(responseBuffer, 1001);
            ssize_t readBytes = 1;
            while (true)
            {
                readBytes = recv(sockfd, responseBuffer, sizeof(responseBuffer), 0);
                if (readBytes > 0)
                {
                    for (int i = 0; i < readBytes; i++)
                    {
                        encryptedResponse.push_back(responseBuffer[i]);
                    }
                    bzero(responseBuffer, sizeof(responseBuffer));
                    break;
                }
            }
            if (n < 0)
            {
                perror("ERROR reading from socket\n");
                printf("Done.\n");
                exit(1);
            }
            if (encryptedResponse.empty())
            {
                printf("No file received, not stored in server.\n");
                return 0;
            }
            else
            {
                printf("Received %d bytes.\n", encryptedResponse.size());
                // decrypt
                std::vector<unsigned char> decryptedResponse = pack109::encrypt(encryptedResponse);
                File responseFile = pack109::deserialize_file(decryptedResponse);
                // save file in folder called received
                FILE *newFileP;
                string newName = "received/" + responseFile.name;
                newFileP = fopen(newName.c_str(), "wb");
                if (newFileP == NULL)
                {
                    printf("Failed to open file: \"%s\"\nDone.\n", responseFile.name.c_str());
                    exit(1);
                }
                for (int i = 0; i < responseFile.bytes.size(); i++)
                {
                    fputc(responseFile.bytes[i], newFileP);
                }
                fclose(newFileP);
                printf("Saved file in \"%s\"\n", newName.c_str());
            }        
        }
        callSend = false;
        callRequest = false;
        count++; 
    }    
}

*/