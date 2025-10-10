# Rashunal

C implementation of basic integer arithmetic

To install (after cloning):
```
$ mkdir build
$ cd build
$ make ..
$ make && make test
```
If you like what you see,
`sudo cmake --install .`

I've only tested the build, compilation, testing, and installation on my Mac. CMake is supposed to be cross-platform, but YMMV.

Update: I've been using this library to test calling native code from other languages, and took the plunge to get it to work on Windows. It's not easy, though, and still has some specific paths to it.

I wanted to minimize the additional tools I had to install in Windows. So CMake from Chocolatey was all I added. NMake is part of Visual Studio, so I used that in a Visual Studio Developer PowerShell window.

Running the tests will require some more messing around with the paths. I haven't taken the time to fully explore that.

There seems to be no standard Windows installation directory. If you don't specify it seems to try to go to `C:/Program Files (x86)`. I don't know how to get Admin privileges in a Visual Studio Developer PowerShell window, so with ChatGPT's help I modified the CMake command to prepend a directory I have write permissions to.

```
> mkdir build-shell
> cd build-shell
> cmake .. -G "NMake Makefiles" -DCMAKE_INSTALL_PREFIX=C:/Users/john.todd/local/rashunal
> nmake
> nmake install
```
