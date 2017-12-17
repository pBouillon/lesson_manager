# Lesson manager

School project in C++ to manage lessons. 

## Requirements
* SQLite3 (since Sprint n°1)
* GTest (for Sprint n°4)
* Qt (for Sprint n°5)

### GTest installation
```shell
~$ apt-get install libgtest-dev
~$ apt-get install cmake
~$ cd /usr/src/gtest
~$ cmake CMakeLists.txt
~$ make
~$  cp *.a /usr/lib
```
### Default credentials:
(as "role: login password")
- Admin   : admin admin
- Teacher : teach teach
- Student : student student 

### Default credentials:
(as "role: login password")
  - Admin:   
  - Teacher: 
  - Student: 

## Sprint n°1
- [x] SQLite implementation
- [x] SQLite connectivity
- [x] SQL `user` table
- [x] Rights implementation
### Launch
```shell
~$ make
~$ ./lesson_manager
```

## Sprint n°2
- [x] Admin implementation
- [x] Student implementation
- [x] Teacher implementation
- [x] Rights management 
- [x] Login functionnal
### Launch
```shell
~$ make
~$ ./lesson_manager <user> <login>
```

## Sprint n°3
Work in progress...
- [x] Lesson implementation
- [x] Lesson creation
- [x] Lesson saving
- [ ] Unit tests
### Launch
```shell
~$ make
~$ ./lesson_manager <user> <login>
```

# Sprint n°4
- [x] CLI for lesson_manager
- [x] Database reworking
- [x] Connection from terminal
- [x] Admin management from terminal
- [x] Teacher management from terminal
- [x] Student management from terminal

# Sprint n°5
Work in progress...
- [ ] Qt implementation

## Credits
* [Bouillon Pierre](https://pierrebouillon.tech/)
* [Choffé Damien](https://github.com/ChoffeD)
* [Nicolas Maxime](https://github.com/NicolasMaxime)
