# use the official C++ image 
FROM gcc:latest

# sets the working directory in the container 
WORKDIR /app

# copies the current directory into the container
COPY ..

# Compiles the code for us 
RUN g++ main.cpp greetings.cpp -o Lab1

CMD["./myProgram"]
