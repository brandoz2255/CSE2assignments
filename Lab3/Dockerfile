# use the official C++ image 
FROM gcc:latest

# sets the working directory in the container 
WORKDIR /app

# copies the current directory into the container
COPY . .

# Compiles the code for us 
RUN g++ Vector20Main.cpp -o Lab4_new

CMD ["/bin/bash"]