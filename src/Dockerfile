FROM ubuntu:16.04  
MAINTAINER light "glee-0413@163.com" 

RUN apt-get update
RUN apt-get install -y vim gcc binutils g++ make 
ADD ./third_src/libevent-2.1.8-stable.tar.gz /home/build/third_src

WORKDIR /
CMD ["/bin/bash"]
