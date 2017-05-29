# Native Node Modules

Native modules sample. It's executing Mandelbrot set on native module.

## Documentations

* Node.js Documentation
  * https://nodejs.org/api/addons.html

* Using Native Node Modules
   * https://github.com/electron/electron/blob/master/docs/tutorial/using-native-node-modules.md


## Install module
```
$ npm install -g node-gyp
```


## Build
```
$ sw_vers
ProductName:	Mac OS X
ProductVersion:	10.11.6

$ electron -v
v1.6.2

$ python --version
Python 2.7.9
```

### Module
```
$ node-gyp configure
$ node-gyp build
$ HOME=~/.electron-gyp node-gyp rebuild --target=1.6.2 --arch=x64 --dist-url=https://atom.io/download/electron
```

## Run
```
$ electron .
```
