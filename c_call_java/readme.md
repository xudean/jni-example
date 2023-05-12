- how to run
1. compile java code, use command:
```bash
javac MyJavaClass.java
```
2. modify CMakeLists.txt: replace you JAVA_HOME 
3. modify main.cpp, replace you class path 
4. execute command:
```bash
$ cmake .
$ make
$ ./c_call_java
```