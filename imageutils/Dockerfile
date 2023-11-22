FROM ubuntu:latest
WORKDIR /app
RUN apt update
RUN apt install -y cmake g++ conan
COPY . .
RUN conan install .
RUN conan build .
RUN conan create .
