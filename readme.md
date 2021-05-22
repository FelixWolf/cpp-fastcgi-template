# C++ FastCGI application template
The template I use for building FastCGI applications.

## Why?
I wanted a template for FastCGI applications, couldn't find one. Made one and 
figured I might as well make it public for anyone else who wants to make C++ 
FastCGI applications.

## Dependencies
* Boost
* CMake
* spawn-fcgi

## Submodules
You'll need to init submodules to get the FastCGI library:
`git submodules init`

## Building
Starting inside the pulled repo:
1. `mkdir build`
2. `cd build`
3. `cmake ..`
4. `make`

## Editing
The project files you want to edit start at `src/web/main.cpp` and 
`src/web/main.h`

## Main.in
`Main.in` is a init.d template, it generates automatically for you.

## Data folder
Data folder is anything the fastcgi application may want to reference. It is 
copied into into the output folder as `data/`.

## Where is the build?
`build/src/bin/`. You'll want everything in that directory, including the
`data` subfolder if you are using the data folder.

## How do I test my code?
Use `spawn-fcgi` to create a fastcgi instance, then tell nginx or apache to 
send queries to the resulting socket. Unfortunately I don't have a solution to 
test code without doing this yet.

## Questions?
Feel free to put a question in the issue tracker.

## Broken?
This is tested on Debian Stable. <br/>
Unless I archive this repo, I am using it in production. I should know if it 
breaks and release a fix soon. If not, feel free to open a issue.

## Contributions
Contributions are welcome and encouraged. I don't really know what I am doing so improvemenets are greatly appreciated.<br/>
For those of you who want a code of conduct: be nice.<br/>
If you don't know what be nice means: just follow [GNU Kind](https://www.gnu.org/philosophy/kind-communication.en.html) instead.<br/>
If you don't like the concept of code of conducts: that's fine, follow [No Code of Conduct](https://github.com/domgetter/NCoC/blob/master/CODE_OF_CONDUCT.md).