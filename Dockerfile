from gcc:latest
copy . /app
workdir /app
run g++ -std=c++2a -O2 -pthread -lstdc++fs -o myapp main.cpp
cmd ./myapp
