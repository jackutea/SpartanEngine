==== Build ====
```
Compiler: GCC 13.2.0
Program Language: C99/C++17
```

==== Style ====
```
C++ -> C with classes
PascalCase/camelCase notation
```

==== Package Relation ====
```
main.cpp {
    User.dll {
        SpartanEngine.dll
    }

    SpartanEditor.dll {
        SpartanEngine.dll
    }

    SpartanEngine.dll {

    }
}
```