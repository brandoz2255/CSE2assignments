# Use the official C++ image 
FROM gcc:latest

# Set the working directory in the container 
WORKDIR /app

# Copy the current directory into the container
COPY . .

# Compile the code
RUN g++ -o stackmain StackMain.cpp\
    g++ -o stacktest StackTest.cpp\

# Set the default command to run the compiled binary
CMD ["./lab5"]