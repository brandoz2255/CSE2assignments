# Use the official C++ image 
FROM gcc:latest

# Set the working directory in the container 
WORKDIR /app

# Copy the current directory into the container
COPY . .

# Compile the code
RUN g++ -c Lab5Main.cpp && g++ -c Random.cpp && \
    g++ -o lab5 Lab5Main.o Random.o && \

# Set the default command to run the compiled binary
CMD ["./lab5"]
