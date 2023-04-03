# AndroidJniDemo
A Android demo project with JNI support.

## Environment setting
CMake seams can find JNI header files automatically。
```shell
export JAVA_VERSION=14
export JAVA_HOME=$(/usr/libexec/java_home)
export CPATH=$CPATH:$JAVA_HOME/include:$JAVA_HOME/include/darwin
export C_INCLUDE_PATH=$C_INCLUDE_PATH:$JAVA_HOME/include:$JAVA_HOME/include/darwin
export CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:$JAVA_HOME/include:$JAVA_HOME/include/darwin
```

## Demo functions
- class mapping
- byte array input and output 

