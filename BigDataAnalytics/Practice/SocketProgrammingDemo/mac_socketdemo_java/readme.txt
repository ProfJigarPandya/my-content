https://docs.oracle.com/javase/tutorial/networking/sockets/index.html
wget https://docs.oracle.com/javase/tutorial/networking/sockets/examples/EchoClient.java
wget https://docs.oracle.com/javase/tutorial/networking/sockets/examples/EchoServer.java


javac EchoServer.java
javac EchoClient.java

One Terminal Window/Tab
java EchoServer 5005

Another Terminal Window/Tab
java EchoClient localhost 5005

On client type text which will be echo back to you from server as is.
